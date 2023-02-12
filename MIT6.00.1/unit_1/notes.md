# Python specific notes
- It's important to note that the `==` operator is not the same as the `is` operator in Python. The `is` operator compares the memory addresses of two objects to determine if they are the same object, while the `==` operator compares their values.
- Variable bindings are evaluated right hand side to left hand side.
- Slicing with square brackets has the following syntax: [start, stop - 1, step]. A string can be reversed by `str[::-1]`. This sets the step to -1, traversing the string in a reverse order. If no ints are provided in the slice, they are considered as 0.
- Python supports `typeCasting` or changing the type of a variable from one to another. E.g., `int("2")` evaluates to 2.
- The default return type of `input()` is `str`. This can be changed to int / floats by casting it e.g., `int(input("input: "))`.
- Any numeric division in Python 3.x results in a floating point value.
- Python's `ZeroDivisionError` is raised when a numeric value is divided by zero. Note that zero can be divided by any value without this error being raised.

# Lecture 1: TIME
### General Knowledge
- Algorithms have a sequence of steps, a flow control of steps and a means of determining when to stop.
- Turing complete means that 6 primitives (right, left, print, scan, erase, do nothing), can compute anything that is computable.
- Guess and check algorithms == exhaustive enumeration algorithms.

### Conditionals and Loops
- In conditional branching using `if` `else if` etc, the first branch that evaluates to `true` returns. Thus, it is important to add sensitive cases to the top so that they can be evaluated first. e.g., Fizzbuzz.

### Loops
- A `while` loop is generally used for an unbounded number of iterations. A `for` loop is used when the number of iterations is known.
- The `break` keyword halts evaluation of the loop at that point e.g., the innermost loop and passes control to the next expression.

### Modulus Operator
- The modulo operator `a % b` is used to compare a number with the modulus and get the equivalent number constrained to the range of the modulus. E.g., a 12 hour clock or letter in a 26 character alphabet.
- It can also be used to check if a given number is evenly divisible.

Common use cases:
    - check for even / odd integers
    - check for prime numbers

**Turing Complete Primitives**
**Right**: Move the Machine’s head to the right of the current square

**Left**: Move the Machine’s head to the left of the current square

**Print**: Print a symbol on the current square

**Scan**: Identify any symbols on the current square

**Erase**: Erase any symbols presented on the current square

**Nothing/halt**: Do nothing

**Types of knowledge**
1. Declarative - statement of fact / expresses the desired end state of the system.
2. Imperative - a series of instructions for the computer to change it's state / a recipe for computation. e.g., deducing square root of a number using guesses.

**Types of computers**
1. Fixed program - are designed to only compute one thing. e.g., calculators, Turing's Bombe.
2. Stored program - store the data and the instructions to operate on the data in memory. Are capable of computing an infinite range of things.

### Path variable
- An environment variable that instructs a Linux system in which directories to search for executables. The PATH variable enables the user to run a command **without specifying a path** to the original installation of the tool.
- To add a path e.g., `usr/bin/local/...` to PATH, insert it into the `.zshrc` / `.bashrc` (terminal session profile) files.
- Turing Halting Problem: impossible for computers to predict if a program will **always halt** with an answer for any given input.