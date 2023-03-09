# Principles of Programming: Part A Course Notes

### ML Specific Notes
- All functions in SML take and return only 1 argument by default which is a tuple of values - the values inside of the parentheses are then pattern matched so that the function body can read their values. Even functions that have no explicit arguments take exactly 1 argument - type `unit()`.
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

# Recursion
- When thinking about recursion - think about what the answer should be for the empty list and what the generalization should be for a non-empty list (typically with regards to the tail of the list).
- Use a **Recurrence Relation** to prove that the function has a base case and a decreasing recursive step. E.g., the relation for the Fibonacci sequence is:
```
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1
```
- n-step Recursion or, doing something recursively n times can be achieved by modifying the input to the recursive function.
```
(* 
 6. Write a function get_nth that takes a list of strings and an int n and returns the nth element of the list where the head of the list is 1st.
*)
fun get_nth(strings: string list, n : int) = 
  if null strings
  then ""
  else 
          (
                  if n = 1
                  then hd strings
                  else get_nth(tl strings, n-1)
          )
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

### Expressions and Operators

1. e1 andalso e2 is logical-and: It evaluates e2 only if e1 evaluates to true. The result is true if e1
and e2 evaluate to true. Naturally, e1 and e2 must both have type bool and the entire expression
also has type bool. In many languages, such expressions are written e1 && e2, but that is not the ML
syntax, nor is e1 and e2 (but and is a keyword we will encounter later for a different purpose). Using
e1 andalso e2 is generally better style than the equivalent if e1 then e2 else false.

e.g.,
```
val z = 3;
val x = if (z = 2) andalso (4 + 5 < 10)
        then 5
        else 0
```

- The semantics of `andalso` dictate that given e1 andalso e2, you evaluate e2 only if e1 evaluates to true; otherwise, the full e1 andalso e2 expression evaluates to false. Therefore, in this case, since z is not equal to 2, the second part of the andalso expression, 4 + 5 < 10), is not evaluated.
- `andalso` is interchangeable with the `if / then / else` construct. But it is better style to use the concise `andalso` and `orelse` statements.
`~
2. e1 `orelse` e2 is logical-or: It evaluates e2 only if e1 evaluates to false. The result is true if e1
or e2 evaluates to true. Naturally, e1 and e2 must both have type bool and the entire expression
also has type bool. In many languages, such expressions are written e1 || e2, but that is not
the ML syntax, nor is e1 or e2. Using e1 `orelse` e2 is generally better style than the equivalent
if e1 then true else e2.

3. `not e` is logical-negation. not is just a provided function of type bool->bool that we could have
defined ourselves as fun not x = if x then false else true. In many languages, such expressions
are written !e, but in ML the ! operator means something else (related to mutable variables, which
we will not use).

3. You can compare many values, including integers, for equality using e1 = e2.

4. Instead of writing `not (e1 = e2)` to see if two numbers are different, better style is e1 <> e2. In many
languages, the syntax is e1 != e2, whereas ML’s <> can be remembered as, “less than or greater than.”

5. The other arithmetic comparisons have the same syntax as in most languages: `>, <, >=, <=`.

6. Subtraction is written `e1 - e2`, but it must take two operands, so you cannot just write - e for
negation. For negation, the correct syntax is ~ e, in particular negative numbers are written like ~7,
not -7. Using ~e is better style than 0 - e, but equivalent for integers.


### Primitives / Compound Data Types
- Each language ships with a set of primitives (atomic) data types e.g., `int`, `string`, `bool` etc..
- A compound data type is composed of multiple individual primitives.
- Many compound types e.g., `tuple` and `pair` in Standard ML are `syntactic sugar` for underlying primitives or compounds e.g., `records`.
- Syntactic sugar allows for:
  - Easier understanding & implementation of the language.
  - Smaller and more concise core/base language.
  - Small formal model of the language so that proofs about it would be shorter.
- When a compiler encounters syntactic sugar in code, it first transforms the sugar into the underlying code that it represents. This is known as `desugaring` or `expanding` the syntactic sugar.


### Each of / One of Types
- Each of types have every single (each of the) values defined in a type - e.g., Records, Tuples, Pairs.
- One of types have one of n values defined in a type - e.g., Datatype bindings, Options.

#### Each-of”
- A compound type t describes values that contain each of values of type t1, t2, ..., and tn.
- Each-of types are the most familiar to most programmers. Tuples are an example: int * bool describes
values that contain an int and a bool. A Java class with fields is also an each-of sort of thing. int option is a simple example: A value of this type contains an int or it does not.
#### One-of”
- A compound type t describes values that contain a value of one of the types t1, t2, ..., or
tn.
#### Self-reference”
- A compound type t may refer to itself in its definition in order to describe recursive data structures like lists and trees.
- Self-reference allows types to describe recursive data structures. This is useful in combination with each-of and one-of types. For example, int list describes values that either contain nothing or contain an int and another int list. A list of integers in any programming language would be described in terms of or, and, and self-reference because that is what it means to be a list of integers.

### Records
- Key / value pair construct - are an `EACH OF` data type.
- Expressions assigned to a key are evaluated. Each key is then alphabetized.
- Record are accessed using the `# <KEY_NAME>` syntax.
- Records > tuples when there is a lot of data that is stored - easier to access by key name rather than position. Tuples > records for readability for small data.
- Tuples and pairs = records under the hood.


### Datatype Bindings
- Custom data type construct - are a `ONE OF` data type.
- Datatype bindings in the Standard ML language are used to define new datatypes or to create aliases for existing datatypes. They provide a way to define complex data structures with a concise syntax that is easy to read and understand.
- Each datatype binding contains a set of `constructors` with tags. Tags refer to the `of <type>` syntax after a binding is declared.
- A `constructor` is two different things. First, it is either a function for creating values of the new type (if the variant has of t for some type t) or it is actually a value of the new type (otherwise). 
- One of the primary uses of datatype bindings in Standard ML is to create algebraic data types. An algebraic data type is a composite data type that is composed of two or more other data types. By using datatype bindings, developers can create algebraic data types with minimal boilerplate code.

For example, consider the following datatype binding in Standard ML:
```
datatype 'a tree = Empty | Node of 'a * 'a tree * 'a tree
```
This defines a new datatype called 'a tree, which is an algebraic data type that can represent a binary tree. The tree can either be Empty or it can be a Node with a value of type 'a, a left subtree of type 'a tree, and a right subtree of type 'a tree.

Another use of datatype bindings is to create aliases for existing datatypes. This can be useful for improving code readability or for simplifying complex type signatures. For example, consider the following datatype binding:
```
type name = string
```
This creates an alias name for the string datatype. Anywhere in the code where a name is expected, a string can be used instead.

### Case Expressions (Pattern Matching)
- Are used to use / access values from datatypes e.g., find the sum of the nodes of a binary tree datatype
- A case-expression is like a more powerful if-then-else expression: Like a conditional expression, it evaluates two of its subexpressions: first the expression between the case and of keywords and second the
expression in the first branch that matches. But instead of having two branches (one for true and one for false), we can have one branch for each variant of our datatype (and we will generalize this further below).
- Like conditional expressions, each branch’s expression must have the same type (int in the example above) because the type-checker cannot know what branch will be used. Each branch has the form p => e where p is a pattern and e is an expression, and we separate the branches with the | character. Patterns look like expressions, but do not think of them as expressions. Instead they are used to match against the result of evaluating the case’s first expression (the part after case). This is why evaluating a case-expression is called pattern-matching.
- Follow the following syntax where each pattern `pn` matches to some expression `en`
```
case e0 of p1 => e1
  |p2 => e2
  ...
  |pn => en

```
- Each pattern in a pattern expression must match the possibilities defined in the respective datatype - else a `warning: match nonexhaustive` warning is raised
- Are used to access the data inside of a particular data type.
- Are just functions that ingest a data type and then use a 'switch / case' to return some data.
-  If a case expression forgets a variant, then the type-checker will give a warning message. This indicates that evaluating the case-expression could find no matching branch, in which case it will raise an exception. If you have no such warnings, then you know this does not occur.
  
#### In Standard ML, `datatypes` and `case expressions` are closely related. Datatypes are used to define new types of data, while case expressions are used to match and manipulate those data types.


### Type Aliases (Synonyms)
- A type synonym maps a name to an existing type that is fully interchangeable with the existing type. If a function accepts an argument of type `card -> int` and the REPL reports your solution has type `suit * rank -> int`, this is okay because the types are “the same.” 
E.g.,
```
datatype suit = Club | Diamond | Heart | Spade
datatype rank = Jack | Queen | King | Ace | Num of int

type card = suit * rank

type name_record = { student_num : int option,
                     first : string,
                     middle : string option,
                     last : string }
```
- Similar to using the `typedef` keyword in C to map a `uint8_t` to a `BYTE` for convenience and better code readability.
- `datatype` bindings create new types, and `type` synonyms map an existing type to a new, more convenient to use and readable type.



Nested Patterns
It turns out the definition of patterns is recursive: anywhere we have been putting a variable in our patterns,
we can instead put another pattern. Roughly speaking, the semantics of pattern-matching is that the value
being matched must have the same “shape” as the pattern and variables are bound to the “right pieces.”
(This is very hand-wavy explanation which is why a precise definition is described below.) For example,
the pattern a::(b::(c::d)) would match any list with at least 3 elements and it would bind a to the first
element, b to the second, c to the third, and d to the list holding all the other elements (if any). The pattern
a::(b::(c::[])) on the other hand, would match only lists with exactly three elements. Another nested
patterns is (a,b,c)::d, which matches any non-empty list of triples, binding a to the first component of
the head, b to the second component of the head, c to the third component of the head, and d to the tail of
the list.
In general, pattern-matching is about taking a value and a pattern and (1) deciding if the pattern matches
the value and (2) if so, binding variables to the right parts of the value. Here are some key parts to the
elegant recursive definition of pattern matching:
• A variable pattern (x) matches any value v and introduces one binding (from x to v).
• The pattern C matches the value C, if C is a constructor that carries no data.
• The pattern C p where C is a constructor and p is a pattern matches a value of the form C v (notice
the constructors are the same) if p matches v (i.e., the nested pattern matches the carried value). It
introduces the bindings that p matching v introduces.
• The pattern (p1,p2,...,pn) matches a tuple value (v1,v2,...,vn) if p1 matches v1 and p2 matches
v2, ..., and pn matches vn. It introduces all the bindings that the recursive matches introduce.
• (A similar case for record patterns of the form {f1=p1,...,fn=pn} ...)
This recursive definition extends our previous understanding in two interesting ways. First, for a constructor
C that carries multiple arguments, we do not have to write patterns like C(x1,...,xn) though we often
do. We could also write C x; this would bind x to the tuple that the value C(v1,...,vn) carries. What is
really going on is that all constructors take 0 or 1 arguments, but the 1 argument can itself be a tuple. So
C(x1,...,xn) is really a nested pattern where the (x1,...,xn) part is just a pattern that matches all tuples
with n parts. Second, and more importantly, we can use nested patterns instead of nested case expressions
when we want to match only values that have a certain “shape.”
There are additional kinds of patterns as well. Sometimes we do not need to bind a variable to part of a
value. For example, consider this function for computing a list’s length:
fun len xs =
case xs of
[] => 0
| x::xs’ => 1 + len xs’
We do not use the variable x. In such cases, it is better style not to introduce a variable. Instead, the wildcard
pattern _ matches everything (just like a variable pattern matches everything), but does not introduce a
binding. So we should write:
fun len xs =
case xs of
[] => 0
| _::xs’ => 1 + len xs’
In terms of our general definition, wildcard patterns are straightforward:
• A wildcard pattern (_) matches any value v and introduces no bindings.
Lastly, you can use integer constants in patterns. For example, the pattern 37 matches the value 37 and
introduces no bindings.