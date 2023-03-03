# Principles of Programming: Part A Course Notes

### ML Specific Notes
- All values in SML are immutable by default.
- Standard ML (Meta Language) supports compile-time type checking as well as type-inference.
- An ML program is a **sequence of bindings**. Each binding first gets it's syntax verified, type-checked and then (assuming it has legal syntax and type-checks) evaluated.
- What type (if any) a binding has depends on a `static environment`, which is roughly the `types` of all of the preceding bindings in the file. 
- How a binding is evaluated depends on a `dynamic environment`, which is roughly the `values` of the preceding bindings in the file.
- A value is an expression that, “has no more computation to do,” i.e., there is no way to simplify it. E.g., 17 is a value, but 8+9 is not. All values are expressions. Not all expressions are values. All expressions are recursively simplified until they become values.
- Bindings are immutable i.e., once a binding has been created, it cannot be modified.
- In the `if a then b else c` construct, `a` must evaluate to type `bool`. `b` and `c` can be any primitive e.g., `bool`, `int` etc as long as `type b == type c`.
- Negative values e.g., -5 in ML are represented as `~5`. Similarly, division between integers needs to use the `div` keyword e.g., `5 div 10`.

#### Whenever you learn a new construct in a programming language, you should ask these three questions: What is the syntax? What are the type-checking rules? What are the evaluation rules?

### Data Types in ML

| Data Type | Description                                   |
| --------- | --------------------------------------------- |
| `int`       | Integers (default size is platform-dependent) |
| `real`      | Floating-point numbers                        |
| `bool`      | Boolean values (true or false)                |
| `char`      | Single characters                             |
| `string`    | Strings of characters                         |
| `word8`     | Unsigned 8-bit integers                       |
| `byte`      | Synonym for word8                             |
| `word16`    | Unsigned 16-bit integers                      |
| `word32`    | Unsigned 32-bit integers                      |
| `word64`    | Unsigned 64-bit integers                      |
| `int8`      | Signed 8-bit integers                         |
| `int16`     | Signed 16-bit integers                        |
| `int32`     | Signed 32-bit integers                        |
| `int64`     | Signed 64-bit integers                        |

### Steps for Evaluating Programs (a bunch of bindings)
1. **Syntax**: e1+e2 where e1 and e2 are expressions
2. **Type-checking**: type int but only if e1 and e2 have type int in the same static environment, else does not type-check.
3. **Evaluation**: evaluate e1 to v1 and e2 to v2 in the same dynamic environment and then produce the sum of v1 and v2.

### General Knowledge
- **Syntax** refers to the characters of a particular language.
- **Semantics** refers to the meaning behind the syntax of a language.
- **Idioms** refer to the 'way' of doing things in a particular language.
- A large reason there are bugs in programs is because even though they are syntactically correct, they are semantically incorrect.
- A `repl` or read, eval, print, loop is a simple programming environment that accepts inputs, executes them and returns the result line by line.

### Static / Dynamic Environments
1. **Static Environment** - stores a map of the bindings and their data `types`.
2. **Dynamic Environment** - stores a map of bindings and their data `values`.

### Bindings / Shadowing
- All Bindings in ML are **immutable**. Given val x = 8+9; we produce a dynamic environment where x maps to 17. In this environment, x will always map to 17; there is no “assignment statement” in ML for changing what x maps to. 
- That is very useful if you are using x. **You can have another binding later**, say val x = 19;, but that just creates a *new environment* where the later binding for x shadows the earlier one (shadowing).
- Any changes in a variable creates a new dynamic environment that has
  - All values from the previous dynamic environment.
  - The changed variable shadowing the original variable.

### Compound Data Types
- Lists are homogenous data collections, meaning that all elements are of the same data type.
- `null l1` return true if `l1` is empty. `null` in ML != null in other languages.
- `hd` is a function that returns the head of the list - the 0th element in a list. Is used as `hd l1`.
- `tl` is a function that returns the tail of the list - all elements in a list apart from the first one. Is used as `tl l1`.
- The `"cons"` operator `2::l1` is used to prepend an element to a list.
- Empty list `[]` has type `'a list` (alpha list). Elements can be "consed" to an empty list - in turn changing the empty list's type.


### List Functions
- Are almost always recursive - as recursion is the **only way that each element in the list can be accessed.**
- The majority of base cases for lists will check if the list is empty.

### Recursion Steps
- When thinking about recursion - think about what the answer should be for the empty list and what the generalization should be for a non-empty list (typically with regards to the tail of the list).
- Use a **Recurrence Relation** to prove that the function has a base case and a decreasing recursive step. E.g., the relation for the Fibonacci sequence is:

```
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1
```

#### 1. Think about the base case - inputs that can’t be decomposed any further - this is usually what the function will do in case of "emptyness" - the empty string, the empty list, the empty set, the empty tree, zero, etc.
#### 2. Use **Recurrence Relations** to break each problem down into it's base case and recursive step.
#### 3.Prove that the input passed into the recursive steps reduces in size to reach to the base case.
#### 4. Implement and test.


### Let Expressions
- Allow you to create a binding within a fixed scope in the environment (local variables).
- Follow the `let in end` syntax where `let` defines a set of bindings, `in` uses the bindings and `end` demarcates the end of the local scope for those bindings.
- Let expressions can be inserted anywhere in the program - even nested within `in` of an existing let expression.
- Any bindings defined in the let expressions e.g., function bindings are available only in subsequent bindings of the let-expression and the body ("in" part) of the let expression.


### Nested Functions
- Limits / Contains the scope of helper functions defined in a let expression within a function.
- Limits helper functions from being modified inadvertently, misused by other functions.
- Think about the refactoring tradeoff: re-using helper functions (calling from other functions) reduces effort and code complexity, but makes the single helper function harder to change later as many functions depend on it.

### Options

### Comparison Operators
#### Inequality
- In C, Python `!=` is used to test inequality. In SML this becomes `<>`.



#### `andalso`

e.g.,
```
val z = 3;
val x = if (z = 2) andalso (4 + 5 < 10)
        then 5
        else 0
```

- The semantics of `andalso` dictate that given e1 andalso e2, you evaluate e2 only if e1 evaluates to true; otherwise, the full e1 andalso e2 expression evaluates to false. Therefore, in this case, since z is not equal to 2, the second part of the andalso expression, 4 + 5 < 10), is not evaluated.
- `andalso` is interchangeable with the `if / then / else` construct. But it is better style to use the concise `andalso` and `orelse` statements.