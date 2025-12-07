#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

namespace catviz {

// A node in a category diagram (object in the category)
struct Node {
    std::string id;       // internal Graphviz id (no spaces)
    std::string label;    // displayed label, e.g. "X", "F(X)"
};

// A directed arrow (morphism) in the diagram
struct Arrow {
    std::string from;     // id of source node
    std::string to;       // id of target node
    std::string label;    // displayed label, e.g. "f", "g  f"
    bool dashed = false;  // dashed style for "functor-lifted" arrows, etc.
};

// A whole diagram that can be exported as Graphviz DOT
class Diagram {
public:
    explicit Diagram(std::string name = "G")
        : name_(std::move(name))
    {}

    void add_node(const Node& n) {
        nodes_.push_back(n);
    }

    void add_arrow(const Arrow& e) {
        arrows_.push_back(e);
    }

    // Export to a DOT file
    void write_dot(const std::string& filename) const {
        std::ofstream out(filename);
        if (!out) {
            throw std::runtime_error("Could not open " + filename + " for writing");
        }

        out << "digraph " << name_ << " {\n";
        out << "  rankdir=LR;\n";               // left-to-right layout
        out << "  node [shape=circle];\n\n";

        // Nodes
        for (const auto& n : nodes_) {
            out << "  " << n.id << " [label=\"" << n.label << "\"];\n";
        }
        out << "\n";

        // Arrows
        for (const auto& e : arrows_) {
            out << "  " << e.from << " -> " << e.to;
            out << " [label=\"" << e.label << "\"";
            if (e.dashed) {
                out << ", style=dashed";
            }
            out << "];\n";
        }

        out << "}\n";
    }

private:
    std::string name_;
    std::vector<Node>  nodes_;
    std::vector<Arrow> arrows_;
};

// ---------------------------------------------------------------------
// Convenience builders for the classic functor diagrams
// ---------------------------------------------------------------------

// 1) Base category: objects X, Y, Z and morphisms f, g, g  f
inline Diagram make_base_category_diagram() {
    Diagram D("BaseCategory");

    D.add_node({"X", "X"});
    D.add_node({"Y", "Y"});
    D.add_node({"Z", "Z"});

    // f: X -> Y
    D.add_arrow({"X", "Y", "f"});

    // g: Y -> Z
    D.add_arrow({"Y", "Z", "g"});

    // g  f: X -> Z
    D.add_arrow({"X", "Z", "g  f"});

    return D;
}

// 2) Covariant functor image: F(X), F(Y), F(Z),
//    with arrows F(f), F(g), F(g  f),
//    and dashed vertical arrows showing object mapping X -> F(X), etc.
inline Diagram make_covariant_functor_diagram() {
    Diagram D("CovariantFunctor");

    // Objects below
    D.add_node({"X", "X"});
    D.add_node({"Y", "Y"});
    D.add_node({"Z", "Z"});

    // Image objects above
    D.add_node({"FX", "F(X)"});
    D.add_node({"FY", "F(Y)"});
    D.add_node({"FZ", "F(Z)"});

    // Base arrows
    D.add_arrow({"X", "Y", "f"});
    D.add_arrow({"Y", "Z", "g"});
    D.add_arrow({"X", "Z", "g  f"});

    // Lifted arrows (covariant: direction preserved)
    D.add_arrow({"FX", "FY", "F(f)"});
    D.add_arrow({"FY", "FZ", "F(g)"});
    D.add_arrow({"FX", "FZ", "F(g  f)"});

    // Vertical "object mapping" arrows (dashed)
    D.add_arrow({"X", "FX", "F", true});
    D.add_arrow({"Y", "FY", "F", true});
    D.add_arrow({"Z", "FZ", "F", true});

    return D;
}

// 3) Contravariant functor: F(X), F(Y), F(Z),
//    with arrows F(f): F(Y)->F(X), F(g): F(Z)->F(Y),
//    F(g  f): F(Z)->F(X), all reversing direction.
//    We still draw base category X->Y->Z below.
inline Diagram make_contravariant_functor_diagram() {
    Diagram D("ContravariantFunctor");

    // Base objects
    D.add_node({"X", "X"});
    D.add_node({"Y", "Y"});
    D.add_node({"Z", "Z"});

    // Image objects
    D.add_node({"FX", "F(X)"});
    D.add_node({"FY", "F(Y)"});
    D.add_node({"FZ", "F(Z)"});

    // Base arrows
    D.add_arrow({"X", "Y", "f"});
    D.add_arrow({"Y", "Z", "g"});
    D.add_arrow({"X", "Z", "g  f"});

    // Contravariant arrows: directions reversed
    D.add_arrow({"FY", "FX", "F(f)"});
    D.add_arrow({"FZ", "FY", "F(g)"});
    D.add_arrow({"FZ", "FX", "F(g  f)"});

    // Vertical object mapping (still dashed)
    D.add_arrow({"X", "FX", "F", true});
    D.add_arrow({"Y", "FY", "F", true});
    D.add_arrow({"Z", "FZ", "F", true});

    return D;
}

} // namespace catviz
