# Funky Functors in Two Wonky Worlds

_(A rather interesting bridge between C++ callable objects and the mathematical realm of functors....on a very basic level...)_


When I first heard of the word "functor", the C++ version came to mind...where, as far as I am aware of, it is a reference to a class that overloads `operator()`.
However, after I got exposed to some topics covered in algebraic geometry, the same word refers to one of the most foundational structures of category theory -- a completely different notion built on identity preservation, arrow mapping, and algebraic consistency. 
As such matters go, this janky project here started from the desire to understand why these two ideas share the same name and to explore whether or not they share any meaningful tangents.


Thus far, what I have tried to implement is a tiny C++ playground that takes into account both interpretations:
the computational one from C++, the structural one from mathematics.
The objective here is not merely to compare them, but to let both perspectives illuminate each other via code, diagrams, and formal laws (and, as suggested above, to see if they have some interesting relationships between each other.)..


***

## What this Project Sets Out to Do....

At its core, I want to explore the tension and harmony between the two wonky worlds:

1. **C++ Functors**, callable objects used with STL algorithms

2. **Mathematical Functors**, mapping entire categories while respecting their structural laws


By combining implementations, visualizations, and small tests and demos, I try to give readers a little bit of sense into what mathematical functors really do/are, why they matter, and how close certain C++ patterns can get to them (at least, that is my intention.....not sure how close I could get though..).

Along the way, per inspiration from my work in the Wharton Generative AI Studio, I used LLMs such as ChatGPT (along with other AI Agents for that matter...) in the form of collaborators and aids in exploring, visualizing, and explaining more complicated abstractions. The diagram generator, for instance, started off as an AI-assisted idea, but indeed I did make sure I understood and refined everything that eventually entered the repository....


***




## A (Very Long) Overview of how I structured the project

I divided it into a few conceptual layers...

### 1\. Computational: C++ Functors

Here we start with what C++ calls "functors", which are callable objects, in a sense..
Rather than functioning like mathematical functors, these are operational mechanisms. 
They encapsulate behavior, allow local state, and interact naturally with STL algorithms such as (but not limited to) `std::transform` and `std::copy_if`...

I'd say in practice...they represent these:

* Action (rather than structure)
* Side effects (rather than algebraic preservation)
* Manipulation of values (rather than mappings and relationships between categories)


Probably sounds like a good starting point, I suppose..

### 2\. Structural: Mathematical Functors executed in C++

Insted of letting objects be callable, I attempt to model functors here:

* **Covariant Functors**: preserve arrow direction
* **Contravariant Functors**: reverse them essentially
* **Subfunctors**: restrict the domain
* **Endofunctors**: these are like `std::vector<T>` acting on C++ types



So the emphasis here is more on _structure_ rather than merely computation.
I tried to make it so that every functor implementation would respect the formal laws of **identity** and **composition** preservation.

I have not gone so far as to check these philosophically, as I enforced and tested them in the codebase itself.

I think a little bit of a surprise was that C++ containers somewhat fit this mold..
`std::vector<T>` seems to behave like the classical List functor, and `std::optional<T>` seems to mirror the Maybe functor from functional programming. 

### 3\. Diagrams and Attempting to Visualize Category Theory Programmatically....at an Extremely Basic Level....


Category theory is visual I suppose......we get arrows, commutative squares, and functor mappings that could lose their momentum when addressed in text only...

So, here I try to include a program that would generate Graphviz diagrams from the C++ code itself.

These diagrams include these:

* Simple categories with explicit compositions
* Covariant and Contravariant functor mappings
* Identity and Composition Laws
* Natural Transformations
* Functors Preserving Commutative Squares
* C++ containers shown as endofunctors

I reckon that the advantage of generating diagrams programmatically is that I could potentially make the visuals become reproducible artifacts that are tied directly to the code itself.
This follows from a key idea from my time being in the Generative AI Studio: **use automation and structured generation to illustrate reasoning** (not to replace it of course but...)..


***

## Project Layout

```
funky-functors-two-wonky-worlds/
│
├── include/        # Mathematical functors & abstractions
├── src/            # Demos + diagram generator
├── diagrams/       # All auto-generated diagrams (DOT + PNG)
├── tests/          # Functor law checks
│
├── CMakeLists.txt
├── README.md
├── notes.md
└── LICENSE
```

In principle, each directory is meant to reflect some sort of conceptual component:
definitions, demonstrations, visual explanations, formal tests.

I'd say that this mirrors the structure of category theory itself:
objects, morphisms, functors, proofs.

***

## What I hope you may be able to take away by Exploring the Code.....

### C++ Functors

This will be how the language uses functors for algorithm customization and why it does not directly have anything to do with category theory per se.......except maybe in spirit, surely enough....

### Mathematical Functors

This will be hopefully where categories are executable to a certain extent:
objects mapping to objects, morphisms to morphisms, preservation of structures.

### Contravariance

So...function types reversed by predicates in C++? This seems very demanding yet interesting.....


### Natural Transformations

Naturality square rendered visually and reflected in the code itself.

### Commutative Diagrams

The functorial images of commutative squares remain commutative in both diagrams and logic (or at least this was my intention..)

### Endofunctors in practice

`std::vector` and `std::optional` become recognizable as the List and Maybe functors of functional programming, but expressed in C++


*** 


## Diagram Generator

This is not crafted to illustrate the project in a sense, but rather to serve as a methodological principle of sorts:

> If a concept is more abundant in category theory, I try to illustrate it in a diagram..

> If a diagram illustrates structure, I try to generate it from the structure itself..


So the C++ program writes DOT files, Graphviz renders them into PNGs, and the repo would serve to be a notebook of sorts consisting of category-theoretic visuals..


***


## Testing the Functor Laws

So I included a small testing suite that would attempt to verify functor axioms via more concrete examples....I hope.

This means that:

* `F(id_X)` really does equal `id_{F(X)}`
* `F(g ∘ f)` really does equal `F(g) ∘ F(f)` (or the reversed form for contravariant functors)


I tried to implement this so that the mathematical definitions would hopefully not be as abstract (and somewhat more accessible) to others....



***


## Acknowledgments and Inspiration

This project is just a part of a reflection of a blend of personal programming practice and mathematical studies and exploration.


Portions of the diagram generator and some category-diagram scaffolding were created with especially ChatGPT...an approach I have since embraced after working extensively as a project developer in the Wharton Generative AI Studio, where structured use of AI tools is encouraged in the service of clarity, visualization, and educational tooling.

Every AI-generated component was reviewed, modified, and integrated manually, and all conceptual content was understood on a personal level to a certain extent prior to inclusion.

In principle, I never intended to offload the thinking, but rather I wanted to expand the expressive toolkit used to explore the material.....


Pull requests and other contributions are welcome.