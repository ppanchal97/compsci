## CS50 Course Notes

### Week 1 - Lecture 1 - C

**General Knowledge**
- `Machine code` - technical term to refer to binary digits. Contrasts with `source code` that humans write.
- Side effects are consequences of function calls.
- Escape sequence `\n` tells the compiler to print a blank line once the program is done.
- Preprocessor directives such as `stdio.h` are used to declare which libraries the program needs.
    - back in the day, resources were limited and so only the required libraries and components were imported to reduce bloat.
- `%%` - will print one percent sign, e.g., `printf("I got %i%% in my test, 99);"`
- `%s`, `%d` etc are format codes, they are placeholders for variables that can be passed in later and are type dependant e.g., `%s` for string, `%d` for double etc. See https://www.tutorialspoint.com/format-specifiers-in-c.
- The compiler analyses the program from top to bottom, left to right.
- Constants guard against mistakenly changing a variable e.g., `const int a = 2`;
- Do / while loops allow you to run logic *only* when a condition evaluates to true.
- Put main function at top of the file for better readability.

**Loops**
- While loops are used until a condition is met.
- For loops are used to repeat an expression a finite number of times.

**Integer Overflow & Underflow**
- Signed `ints` can be between 2 billion and. -2 billion on a 32 bit machine.
- Unsigned bits can be around 4 billion. Unsigned can only store positive values.
    - these are vulnerable to integer overflow if the correct data type is not used/first most bit indicates the sign of the integer.
    - first bit (most significant bit) denotes whether integer is positive / negative.
- Underflow - storing a value lesser than the minimum allowed value.

**Year 2038 Problem**
- Y2K - computers only used 2 digits to represent year. E.g., 1999 = 99. So when 2000 came, it would be 00, i.e., 1900.
- Unix time stores seconds since 1 jan 1970. **signed** 32 bit integers can store up values up to 4 billion, this will be reached on 19th Jan 2038 as 4b seconds would have passed.

**Algorithm Types**
- A greedy algorithm is one “that always takes the best immediate, or local, solution while finding an answer. Greedy algorithms find the overall, or globally, optimal solution for some optimization problems, but may find less-than-optimal solutions for some instances of other problems.”


### Week 2 - Lecture 2 - Arrays

**General Knowledge**
- Ciphertext is just plaintext that has been encrypted through an algorithm
- gcc and clang are compilers used to convert source code to machine code
- clang `filename.c` will output `a.out` file e.g., `clang hello.c` -> `a.out`. Command line arguments / flags modify the behaviours of a command
- A more succinct command is `clang -o hello hello.c`
- `a.out` is the conventional output file for assembler output
-  clang accepts linking libraries that do not ship with the C standard library, e.g., cs50 -> `clang -o hello hello.c -lcs50`

**Compilation Process**
- The compilation process consists of: pre-processing, compiling, assembling and linking (PCAL).
- **Pre-processing** - resolves all of the pre-processor directives (`#include <stdio.h>`) - basically copies and pastes all the libraries included as headers in the main file e.g., `#include <stdio.h>`.
- **Compiling** - convert C code to assembly code. This contains instructions that the CPU understands.
- **Linking** - link all the code that was referenced by pre-processor directives (libraries that were imported by the main file).
- De-compiling is the process of converting machine code to source code. Compilers don't remember function or variable names - this makes it harder to reverse engineer it.

**Debugging**
- Use a `printf()` statement to check state of the program.
- Breakpoints allow you to slow execution to step through the program line by line.
- The CALL STACK shows the currently running function (top-most) and which functions will run once the current one exits.
- `step over` -> run the line of code currently highlighted by the debugger. Useful when you are confident the line will work. E.g., a method is about to be invoked, but you're not interested in debugging this particular invocation, so you want the debugger to execute that method completely as one entire step.
- `step into` -> inspect the line of code currently highlighted by the debugger. Useful when you need to investigate further. E.g., a method is about to be invoked, and you want to debug into the code of that method, so the next step is to go into that method and continue debugging step-by-step.

**Data Types**
Each data type has a specific number of bits assigned to it by the machine. 8 bits is 1 byte.

**bool** - 1 byte

**int** - 4 bytes

**long** - 8 bytes

**float** 4 bytes

**double** - 8 bytes

**char** - 1 byte

*Note: the finite number of numbers that can be stored in 4 bytes causes floating point imprecision.*

- An array is stored contiguously in memory (data is stored next to each other).

```
// declaration and initializing
int scores[3] = {1,2,3};

// initializing through indexing
int nums[2];
nums[0] = 1;
nums[1] = 2;
```

A string is like an array - a contiguous block of characters. Memory taken in bytes can be calculated by `(length * size_of_data_type) + 1 byte` - one extra byte for the null character `\0`

**ASCII Encoding**
- 0 maps to NUL.
- Chart: https://cs.smu.ca/~porter/csc/ref/asciifull.gif
- Characters are ASCII encoded, means their corresponding integer value can be printed.
- *ASCII is case sensitive*

**Memory**
- A finite number of bytes. Has addresses where data is stored.

**Command Line Arguments**
- Users can provide arguments whilst running the program through the terminal. The program can use these values at runtime as part of the program logic.
- To support command line arguments, the main method must accept the following: `int main(int argc, char *argv[])`
- `argc` is argument count - counts the number of args passed in when the program was invoked. ` char *argv[]` is an array of the arguments passed in.

**Program Exit Codes**
- Each error code corresponds to a type of error that has happened.
- On the web, HTTP error codes help programmers figure out what went wrong/
- Return 0 in the success case, else explicitly catch and return error messages.

**Program Input**
- Must use `fgets()` when need to accept string as a command line argument. Using `scanf()` suffices for characters, however fails after it encounters first space or empty character.
e.g.,
```
    int text_buffer_size = 1024;
    char *plaintext = malloc(text_buffer_size);
    printf("plaintext: ");
    fgets(plaintext, text_buffer_size, stdin);
```

### The Problem Solving Method
1. Identify the core algorithm. I.e., what ignoring all else, what do I need to do to each character in a string or how do I need to transform x into y.


**Algorithms**
1. Checking for duplicates in a string using double for-loops.
- First for loop (i) iterates over each character in the string.
- Nested for loop (j) iterates over each character in the string for each Ith character. Nesting allows for comparison.
- Nested for loop (j) terminates before length of the string `strlen(key) - 1` to avoid out of bounds error.
- Nested for loop (j) is initialized with i's value to prevent redundantly comparing digits before i.
- Comparison occurs between i and j + 1 to compare `key[i]` to the next value in the string.

```
for (int i = 0; i < strlen(key); i++)
{
    for (int j = i; j < strlen(key) - 1; j++)
    {
        printf("checking %c with %c\n", key[i], key[j + 1]);
    }
}
```


### Week 3 - Lecture 3 - Algorithms
- Recall that an array is simply a contiguous block of memory that contains some values.
- "Closed doors" analogy - that a computer can only do one thing at a time.

**Big O**
Refers to the runtime complexity of an algorithm. Signifies how the runtime complexity as the size of n increases.
- `O(n)` is said as "order of n steps"
Runtimes by speed
1. `O(n^2)` (quadratic growth)
2. `O(n log n)`
3. `O(n)` - runtime grows linearly with the value with n
4. `O(log n)`
5. `O(1)` - constant time (a finite number of steps, each and every time)

*Dominant Term* - the term in the algorithm that experiences the most growth.

*Best / Worst / Average Cases* - the bounds for an algorithm.

*Best Case* is defined using the Ω symbol. The best case for linear search is Ω(1) or the first element checked. Best case for binary search is also Ω(1) or the first middle element that is checked.
- An algorithm with running time of `O(1)` means that a constant number of steps is required, no matter how big the problem is.

*Θ* theta symbol signifies the *same* upper / lower bounds for an algorithm. E.g., Selection Sort has a best and worst case runtime complexity of Θ(n^2) because even if it is passed a sorted list, it needs to search the list for the smallest element, each time to verify.

**Run-time Complexity Calculation**
```
Total number of steps * number of steps at each iteration;
```

*Asymptotically* - As `n` approaches infinity / "gets really large".

**Searching Algorithms**
1. Linear Search: searching each box one compartment at a time. Analogous to searching a phone book one page at a time.
2. Binary Search: searching a set of boxes from the middle of the array. *Requires the array to be pre-sorted*. Analogous to searching a phone book by tearing one half each time.

**Structs**
- Custom data types that encapsulate custom values.
- Should be declared at top of file to allow all functions to access it.
- Supports dot notation to access encapsulated properties and attributes.
- Does not support default values as it is just a type definition and these do not accept values, only data types..

e.g.,
```
typedef struct
{
    char *name;
    char *phone_number;
}
person;
```

- In computer science, encapsulation is the idea that related data is grouped together, and here we’ve encapsulated two pieces of information, `name` and `phone_number` into the same data structure. The color of a pixel, with red, green, and blue values, might also be well-represented by a data structure as well.

**Sorting Algorithms**
- Consider whether sorting is worth it if only going to search once.

1. Selection Sort
- Iterate across each element in an array. Find the smallest value, then swap it with the element current accessed.
- Both `i` and `j` nested for loops should run until the length of the array
- Declare `current_min` and `min_position` inside the `i` for loop. Allows you to change the Ith element with the value of j.
- Initialize `current_min` with the current Ith value e.g., `int current_min = nums[i]`.

*Performance*
`O(n^2)` best case, `O(n^2)` worst case as for each element, algorithm will have to find the smallest element, regardless if the array is sorted or not.
Can be represented as Ω(n^2).

2. Bubble Sort
- Iterate across each element in an array whilst swapping the position of a larger element with a smaller one until it bubbles to the end.
- `i` for loop should run until the length of the array. `j` nested for loop should run to the length of the array - 1. This avoids a segfault.
- Compare `nums[j]` with `nums[j + 1]` and swap if `nums[j] > nums[j + 1]`.

*Optimization*
- Since Bubble Sort makes n-1 comparisons, n-1 times, if an array is pre-sorted, using an `is_sorted` flag to exit early prevents n-1 iterations. This changes the lower bound from `O(n^2)` to `O(n)`

*Performance*
`O(n^2)` worst case, as the algorithm will have to swap n -1 elements n - 1 times. `O(n)` best case if optimization of `is_swapped` flag. Program will terminate after only one pass as no swaps has been made.

**Recursion**
- Recursion is calling a function within itself on a smaller and smaller problem space.
- A recursive function defines a base case and a recursive step. The base case is needed to exit so a function does not run forever. The recursive step calls the function again with some new parameter.
- The functions keep getting pushed to the call stack until the base case is triggered, then they are run one by one from last added to first and are popped off the stack in this order.