## CS50 Course Notes

### Week 1 - Lecture 1 - C

**General Knowledge**
- Syntax highlighting - text editors colour different components of the program differently for readability. e.g., function names can be purple, protected keywords can be green etc
- Machine code - technical term to refer to binary digits. Contrasts with source code (humans write)
- Side effects are consequences of function calls
- Programs are a bunch of expressions and conditions
- Escape sequence `\n` tells the compiler to print a blank line once the program is done
- Header files such as `stdio.h` are used to include libraries
    - back in the day, resources were limited and so only the required libraries and components were imported to reduce bloat
- %% - will print one percent sign, %s. %d etc are format codes, they are placeholders for variables that can be passed in later
- The compiler analyses the program from top to bottom, left to right
- constants allow you to guard against mistakenly changing a variable e.g., const int a = 2;
- do / while loops allow you to run logic only when a condition evaluates to true
- If really confused, write pseudo-code
- Put main function at top of the file for better readability

**Loops**
- While loops are used until a condition is met
- For loops are used to repeat an expression a finite number of times

**Integer Overflow & Underflow**
- Signed ints can be between 2 billion and. -2 billion
- Unsigned bits can be around 4 billion. Unsigned can only store positive values
    - these are vulnerable to integer overflow if the correct data type is not used/first most bit indicates the sign of the integer
    - first bit (most significant bit) denotes whether integer is positive / negative
- Underflow - storing a value lesser than the minimum allowed value

**Year 2038 Problem**
- Y2K - computers only used 2 digits to represent year. E.g., 1999 = 99. So when 2000 came, it would be 00, i.e., 1900
- Unix time stores seconds since 1 jan 1970. **signed** 32 bit integers can store up values up to 4 billion, this will be reached on 19th Jan 2038 as 4b seconds would have passed.

**Algorithm Types**
- A greedy algorithm is one “that always takes the best immediate, or local, solution while finding an answer. Greedy algorithms find the overall, or globally, optimal solution for some optimization problems, but may find less-than-optimal solutions for some instances of other problems.”


### Week 1 - Lecture 2 - Arrays

**General Knowledge**
- Ciphertext is just plaintext that has been encrypted through an algorithm
- gcc and clang are compilers used to convert source code to machine code
- clang `filename.c` will output `a.out` file e.g., `clang hello.c` -> `a.out`. Command line arguments / flags modify the behaviours of a command
- A more succinct command is `clang -o hello hello.c`
- `a.out` is the conventional output file for assembler output
-  clang accepts linking libraries that do not ship with the C standard library, e.g., cs50 -> `clang -o hello hello.c -lcs50`

**Compilation Process**
- The compilation process consists of: pre-processing, compiling, assembling and linking (PCAL)
- **Pre-processing** - resolves all of the pre-processor directives (`#include <stdio.h>`) - basically copies and pastes all the libraries included as headers in the main file e.g., `#include <stdio.h>`
- **Compiling** - convert C code to assembly code. This contains instructions that the CPU understands.
- **Linking** - link all the code that was referenced by pre-processor directives (libraries that were imported by the main file)
- Decompiling is the process of converting machine code to source code. Compilers don't remember function or variable names - this makes it harder to reverse engineer it.

**Debugging**
- Use a `printf()` statement to check state of the program
- Breakpoints allow you to slow execution to step through the program line by line
- The CALL STACK shows the currently running function (top-most) and which functions will run once the current one exits
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

- An array is stored contiguously in memory (data is stored next to each other)

```
// declaration and initializing
int scores[3] = {1,2,3};

// initializing through indexing
int nums[2];
nums[0] = 1;
nums[1] = 2;
```

A string is like an array - a contiguous block of characters. Memory taken in bytes can be calculated by `(length * 1) + 1 ` - one extra byte for the null character `\0`
- In ASCII, 0 maps to NUL.

**ASCII Encoding**
Characters are ASCII encoded, means their corresponding integer value can be printed.
*ASCII is case sensitive*

**Memory**
- A finite number of bytes. Has addresses where data is stored.

**Command Line Arguments**
Users can provide arguments whilst running the program through the terminal. The program can use these values at runtime as part of the program logic.

To support command line arguments, the main method must accept the following:
`int main(int argc, char *argv[])`

**Program Exit Codes**
- Each error code corresponds to a type of error that has happened
- On the web, HTTP error codes help programmers figure out what went wrong
- Return 0 in the success case, else explicitly catch and return error messages

**Program Input**
- must use `fgets()` when need to accept string as a command line argument. Using `scanf()` suffices for characters, however fails after it encounters first space or empty character.
e.g.,
```
    int text_buffer_size = 1024;
    char *plaintext = malloc(text_buffer_size);
    printf("plaintext: ");
    fgets(plaintext, text_buffer_size, stdin);
```

### Problem Solving Method
1. Identify the core algorithm. I.e., what ignoring all else, what do I need to do to each character in a string or how do I need to transform x into y. 