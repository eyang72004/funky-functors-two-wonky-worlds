# Funky Functors in Two Wonky Worlds

_(A rather interesting bridge between C++ callable objets and the mathematical realm of functors....on a very basic level...)_


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

