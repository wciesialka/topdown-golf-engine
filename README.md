# topdown-golf-engine
Topdown 2D Golf Engine for the Game Engine assignment for Andy Harris's CSCI 43700.

## Things I Learned

There are many things that I learned while working on this project. One of the things I learned was why we trust git - I had an incident with adjusting my [Makefile](Makefile)'s `clean` target, and deleted my entire local copy of the project. Thankfully, `git restore` had me covered. Consequentially, I also learned a __lot__ about Makefiles. I once dreaded writing them and having to laboriously write dependencies and file names by hand, but no more! By learning how to properly utilize Make's patterns and functions, I was able to write a general-purpose Makefile that I can set and forget! It is easily configurable and, with a few minor changes to some variables, can be suited to fit many different projects!

## Installation

### Requirements

- [SFML](https://www.sfml-dev.org/)
- C++11[^1]
- G++[^2]

[^1]: Note that this project makes use of some features of C++ introduced in [C++11](https://en.cppreference.com/w/cpp/11) and therefore it is required.
[^2]: Build requirement only.

### Executable

The latest release of a working executable can be found on the [Releases](releases/latest) page.

### Building

If you wish to build from source, clone the repository to your system and run `make all`.

## Running

The executable may be run on Linux machines with `./golf_engine.out`. Additionally, if you wish to build from source, you can also build and run the project with `make run`.

## Author

Willow Ciesialka