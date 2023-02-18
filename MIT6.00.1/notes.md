# General Knowledge
- Turing complete means that 6 primitives (right, left, print, scan, erase, do nothing), can compute anything that is computable.
- Both functions and methods are used to define reusable code that can be called multiple times. However, there is a subtle difference between them: 
  - A function is a **standalone piece** of code that can be called by other parts of the program. It takes input arguments, performs some operation, and returns a value. Functions are typically defined outside of classes and can be called from any part of the program that has access to them.
  - On the other hand, a method is a function that is **associated with an object or class**. It is defined inside a class and operates on the data members of that class. A method is called on an instance of the class, and it can access and modify the state of the object it belongs to.
  - In summary, the main difference between a function and a method is that a **function is a standalone piece of code** that operates on input arguments, while a **method is a function that is associated with an object or class** and operates on the data members of that class.

# Python specific notes
- Pythonic means "Easier to Ask for Forgiveness than Permission" (EAFP) - a lackadaisical approach to programming where an operation is carried out regardless of verifying whether the inputs are correct and any exceptions are just handled along the way.
- It's important to note that the `==` operator is not the same as the `is` operator in Python. The `is` operator compares the memory addresses of two objects to determine if they are the same object, while the `==` operator compares their values.
- Variable bindings are evaluated right hand side to left hand side.
- Slicing with square brackets has the following syntax: [start, stop - 1, step]. A string can be reversed by `str[::-1]`. This sets the step to -1, traversing the string in a reverse order. If no ints are provided in the slice, they are considered as 0.
- Python supports `typeCasting` or changing the type of a variable from one to another. E.g., `int("2")` evaluates to 2.
- The default return type of `input()` is `str`. This can be changed to int / floats by casting it e.g., `int(input("input: "))`.
- Any numeric division in Python 3.x results in a floating point value.
- Python's `ZeroDivisionError` is raised when a numeric value is divided by zero. Note that zero can be divided by any value without this error being raised.


### Common Methods
- `.sort()` mutates an iterable data structure (list) in place whereas `sorted()` returns a copy of it.
- The return type of a function that does not explicitly declare a return is `NoneType`.
- The majority of methods accessed using the dot notation `.` return `NoneType`.
- The only method that have an explicit return are `pop()`, `count()`, `index()`, `find()`.
- Other common methods that do not have a return type are `insert()`, `append()`, `remove()`, `sort()`, `extend()`, `reverse()`.

### Data Types and Mutability

- A variable is a container that holds a value, and a data type is a specification of the kind of value that can be stored in that container. In general, an immutable data type is one where the value cannot be changed once it is created, while a mutable data type is one where the value can be changed after it is created.

- Immutable data types cannot be modified because they are designed to be constant. Once a value is assigned to an immutable variable, it cannot be changed. Any operation that appears to modify the value actually returns a new value, which can be assigned to a new variable if necessary. Examples of immutable data types in Python include numbers, strings, and tuples.

- Mutable data types, on the other hand, are designed to be changed. Once a value is assigned to a mutable variable, it can be modified in place. This means that any operation that modifies the value affects the original object, rather than creating a new object. Examples of mutable data types in Python include lists, dictionaries, and sets.

| Immutable Data Types | Mutable Data Types     |
| -------------------- | ---------------------- |
| `bool`               | `list`                 |
| `int`                | `dict`                 |
| `float`              | `set`                  |
| `tuple`              | `bytearray`            |
| `frozenset`          | `user-defined objects` |
| `str`                | `array`                |

*The term "immutable" in Python refers to the fact that the value of an object cannot be changed after it is created. However, the object itself can be replaced with a new object of the same type that has a different value. For example, you can't modify a string in place, but you can assign a new string to the same variable to replace the original string.*

# Common Formulas / Axioms

### Permutations
- A permutation is an arrangement of items in a specific order, whereas a combination is a selection of items without regard to the order in which they are arranged.

- For a set of 3 characters (A, B, and C). There are 6 possible permutations of these letters, including (A, B, C), (A, C, B), (B, A, C), (B, C, A), (C, A, B), and (C, B, A).

- The formula for working out the possible permutations is:
```
no. of permutations for n items P(n) = n!
e.g., 6 items can be re-arranged 6! or 720 times without repetition.
```

### Combinations
- Combinations are the different ways of selecting a subset of items from a larger set where the order of selection doesn't matter.
- Combinations are a collection of distinct elements, and the order of the elements does not matter.
On the other hand, there are 3 possible combinations of these letters taken 2 at a time, including (A, B), (A, C), and (B, C).

- The formula for working out the possible combinations are:
```
no. of combinations of n items taken k at a time = C(n, k) = n! / (k! * (n - k)!).
e.g., nCr = 10! / (3!(10-3)!) = (10 x 9 x 8) / (3 x 2 x 1) = 120 
(there are 120 different combinations of 3 elements that can be selected from a set of 10)
```

### Induction
- Mathematical induction is a method of proving statements that are true for all natural numbers (positive integers). The method involves two steps:

    - **Base case**: Show that the statement is true for the first natural number, typically 1 or 0.

    - **Inductive step**: Show that if the statement is true for some natural number k, then it must also be true for the next natural number k+1.

By using these two steps, one can prove that the statement is true for all natural numbers. This is because the base case establishes that the statement is true for the smallest possible natural number, and the inductive step ensures that if the statement is true for any natural number, it must also be true for the next natural number. Therefore, the statement must be true for all natural numbers.

Induction is a powerful tool in mathematics and is used to prove many important theorems, including formulas for summations and divisibility properties.


### "Everything is an object in Python"
- All values and data structures are instances of objects, and they are all treated as objects, regardless of their type or structure.
- This means that dot notation give access methods that can be used on that particular object. E.g., `count` for iterables like `list`, `tuple` or `capitalize` for `str` objects.
- This design philosophy of treating everything as an object has several advantages. It provides a consistent and intuitive way of interacting with data, it makes it easy to extend the language by creating new types of objects, and it enables object-oriented programming techniques, such as inheritance and polymorphism, to be used in a natural way.
- This is in stark contrast to procedural languages such as C where the dot notation is used to access values inside a `struct` and any data type must be passed to a function e.g., `strlen()` and `toupper()` for strings.

### Python Scopes
- The interpreter checks for a variable in the following order:
  1. Local scope
  2. Function scope
  3. Global scope

**1. Local Scope**
Demonstrates accessing variables in global and local scopes:

```
# A global variable
x = 10

def my_function():
    # A local variable
    y = 20
    print(x) # Accessing the global variable
    print(y) # Accessing the local variable

print(x) # Accessing the global variable
# print(y) # This will cause an error because y is a local variable and is not accessible outside of the function

my_function()
```

**2. Global Scope**
Demonstrates how to modify a global variable using the `global` keyword

```
x = 10

def my_function():
    global x # This tells Python that we want to modify the global variable x
    x = 20
    print(x) # Output: 20

my_function()
print(x) # Output: 20

```
**3. Function Level Scope**
Demonstrates how a variable defined in the innermost block can be accessed outside of it:

```
def f():
    for i in range(5):
        x = i
        print(x)
    
    print(x)

f()
```

### Guess and Check Algorithms
- Exhaustive enumeration algorithms. 
- Implemented linear growth guess and check whilst comparing result with an acceptable margin of error: epsilon
- Implemented Heron's Algorithm - an optimized way of forming a guess.
- Implemented Newton / Rahpson - most efficient method of forming a guess.

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


### Ordered Iterables (list, tuple)
**Similarities**
- Both lists and tuples can contain heterogenous elements (mixed types) e.g., ints and strings. This is unlike C.
- Ordered != sorted. Ordered just means that the items in the iterables can be accessed in order. Order supports indexing.
- Support indexing using `[]`.
- Support slicing using `:`.
- Support negative indexing e.g., `t[-1]` to access elements in reverse order.
- Support concatenation e.g., `t1 = (1,), t2 = (2,), t3 = t1 + t2`. Concatenation is only supported between variables of the same data type.
*Strings also support indexing, slicing and negative indexing*
*Indexing / Slicing actually returns the data type that it was performed on. E.g., `t[0:1]` returns a tuple.*

**Differences**
- Tuples are `immutable` data types
- Tuples do not support item assignment - raise `TypeError` when attempted.
- Tuples do not support insertion / deletion. All modification must be done either through type-casting to a list first or through tuple concatenation.
- Lists support item assignment and are `mutable`.
- A tuple of len 1 must be initialized with a comma e.g., `t = (1,)` else it is stored as the data type of the first variable in the tuple.

**Other Points**
- Indexing can close a list e.g.,

```
l1 = [1,2,3]
l2 = l1[:] # cloning
l2.append(4)
print(l1) # [1,2,3]
```