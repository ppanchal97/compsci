## CS50 Course Notes

### The Problem Solving Method
1. Identify the core algorithm. e.g., ignoring all else, what do I need to do to each character in a string or how do I need to transform x into y.
2. Write down and populate data structures on paper.
3. Write down pseudo-code that solves most cases.
4. Look at edge cases and add guards.
5. Code the algorithm.

## Week 1 - Lecture 1 - C

### General Knowledge
- `Machine code` - technical term to refer to binary digits. Contrasts with `source code` that humans write.
- Side effects are consequences of function calls that can be unintended or desired. E.g., Printing to `stdout` is an example of a desired side effect, If functions have side effects of modifying state variables, the program's outcome depends on the history (order of evaluation) of these variables making understanding and debugging harder.
- Escape sequence `\n` tells the compiler to print a blank line.
- Preprocessor directives such as `#include <stdio.h>;` are used to declare which libraries the program needs.
    - back in the day, resources were limited and so only the required libraries and components were imported to reduce bloat.
- `%%` - will print one percent sign, e.g., `printf("I got %i%% in my test, 99);"`
- `%s`, `%d` etc are format specifiers / format codes, they are placeholders for variables that can be passed in later and are type dependant e.g., `%s` for `string`, `%d` for `double` etc. See https://www.tutorialspoint.com/format-specifiers-in-c.
- The compiler analyses and the program from top to bottom, left to right.
- Constants guard against erroneously changing a variable e.g., `const int a = 2`;
- Do / while loops allow you to run logic until the condition in the while statement evaluates to false. E.g., running do until user enters a valid input.
- The `main` function and custom data types defined using `typedef` are normally declared at top of the file for better readability.

**Loops**
- While loops are used to execute logic until a condition evaluates to true.
- For loops are used to repeat logic a finite number of times.

**Integer Overflow & Underflow**
- Signed `int`s can store values between 2 billion and. -2 billion on a 32 bit machine.
- Unsigned `int`s can store values of around 4 billion. Unsigned can only store positive values as they do not have a prefix sign bit.
- Integers are vulnerable to overflow if the correct data type is not used for the stored value. E.g., storing too large of a value in a 32 bit signed `int`.
- The first bit (most significant bit) denotes whether integer is positive / negative.
- Underflow - storing a value lesser than the minimum allowed value.

**Y2K / Year 2038 Problem**
- Y2K - programs customarily only used the last 2 digits to represent the year property to conserve memory. E.g., 1999 = 99. In case of 2000, last 2 digits would result in 00 as the year property, causing incorrect data to be stored. Effects mitigated by raising awareness.
- Unix time stores seconds since 1 jan 1970. **signed** 32 bit integers can store values up to 4 billion, this will be reached on 19th Jan 2038 as 4b seconds would have passed.

## Week 2 - Lecture 2 - Arrays

### General Knowledge
- Ciphertext is just plaintext that has been encrypted through an algorithm.
- `gcc` and `clang` are different compilers used to convert source code to machine code.
- Running `clang <filename>.c` will output and `a.out` file e.g., `clang hello.c` -> `a.out`. 
- Command line arguments / flags modify the behaviours of a command
- A more succinct command is `clang -o hello hello.c`
- `a.out` is the conventional output file for assembler output.
- Clang links libraries that do not ship with the C standard library, e.g., cs50 -> `clang -o hello hello.c -l cs50`

#### Compilation Process
- The compilation process consists of: **pre-processing, compiling, assembling and linking (PCAL).**
- **Pre-processing** - resolves all of the pre-processor directives e.g., `#include <stdio.h>` - basically copies and pastes all the libraries included as headers in the main file.
- **Compiling** - convert C code to assembly code. This contains instructions that the CPU understands.
- **Linking** - link all the code that was referenced by pre-processor directives (libraries that were imported by the main file).

De-compiling is the process of converting machine code to source code. Compilers don't remember function or variable names - this makes it harder to reverse engineer it.

**Debugging**
- Use a `printf()` statement to check state of the program.
- Breakpoints allow you to slow execution to step through the program line by line.
- The CALL STACK shows the currently running function (top-most) and which functions will run once the current one exits.
- `step over` -> run the line of code currently highlighted by the debugger. Useful when you are confident the line will work. E.g., a method is about to be invoked, but you're not interested in debugging this particular invocation, so you want the debugger to execute that method completely as one entire step.
- `step into` -> inspect the line of code currently highlighted by the debugger. Useful when you need to investigate further. E.g., a method is about to be invoked, and you want to debug into the code of that method, so the next step is to go into that method and continue debugging step-by-step.

### Data Types
Each data type has a specific number of bits assigned to it by the machine. 8 bits is 1 byte. Modern 64 bit machines have integers and memory addresses that are 8 bytes wide.

| Data Type    | Memory Requirement |
| -------------| ------------------ |
| `bool`       | 1 byte             |
| `int`        | 4 bytes            |
| `long`       | 8 bytes            |
| `float`      | 4 bytes            |
| `double`     | 8 bytes            |
| `char`       | 4 bytes            |
| `* (pointer)`| 8 bytes            |

### Arrays
- An array is a linear data structure used to store data contiguously in memory (data is stored next to each other).
- An array implements the list concrete data type.
- In C, an array must be declared with a certain memory size at compile time. e.g, `3 bytes`.

**2D Arrays**
- Contain arrays inside of an array.
- Useful data structure to group data that can also be iterated on.
- Requires nested for loops for iteration.

```
// declaration and initializing 1D array
int scores[3] = {1,2,3};

// initializing through indexing
int nums[2];

nums[0] = 1;
nums[1] = 2;
```

- The `string` data type is implemented like an array - a contiguous block of characters. Memory taken in bytes can be calculated by `(length * size_of_data_type) + 1 byte` - one extra byte for the null character `\0`

**ASCII Encoding**
- A character encoding standard for standardizing communication between systems.
- Individual characters are mapped to integers. Means their corresponding integer value can be printed.
- 0 maps to NUL.
- Chart: https://cs.smu.ca/~porter/csc/ref/asciifull.gif
- *ASCII is case sensitive*

**Memory**
- A system used to temporarily store data and instructions on how to manipulate that data. Is accessed by the CPU during the fetch-decode-execute cycle.
- Contains a finite number of bytes. Has addresses where data is stored.

**Floating Point Imprecision**
The finite number of numbers that can be stored in the float data type (4 bytes) causes floating point imprecision.

**Command Line Arguments**
- Users can provide arguments whilst running the program through the terminal. The program can use these values at runtime as part of the program logic.
- To support command line arguments, the main method must accept an array of string arguments: `int main(int argc, char *argv[])`. The main function can also block arguments by being initialized with the `void` data type.
- `argc` counts the number of args supplied when the program was invoked. ` char *argv[]` is an array of the supplied arguments.

**Program Exit Codes**
- User defined integers that map to error messages.
- Each error code corresponds to a type of error that has happened. E.g., HTTP Error Codes (400, 404, 500...).
- 0 conventionally signals the success case. If a failure occurs, explicitly catch and return error messages e.g., `return 3;`

**Program Input**
- `fgets()` is conventionally used to accept strings as a CLI argument. Using `scanf()` suffices for characters, however fails after it encounters first space or empty character.
e.g.,
```
char buf[1024];
if (fgets(buf, sizeof(buf), stdin) != NULL) {
  // Check that the input is not too long
  if (buf[strlen(buf) - 1] != '\n') {
    // Handle input that is too long
  } else {
    // Use the input string
  }
} else {
  // Handle error
}
```

**Structs**
- Custom data types that encapsulate some values.
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

## Week 3 - Lecture 3 - Algorithms

**Algorithm Types**
- A **greedy algorithm** is one “that always takes the best immediate, or local, solution while finding an answer. Greedy algorithms find the overall, or globally, optimal solution for some optimization problems, but may find less-than-optimal solutions for some instances of other problems.”


**Toy Algorithm Example: Checking for duplicates in a string using double for-loops.**
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

**Big O**
Refers to the asymptotic runtime complexity of an algorithm. Signifies how the runtime complexity changes as the size of n reaches infinity.
- `O(n)` is said as "order of n steps"

**Runtimes by speed (slowest / most inefficient first)**

| Complexity  | Explanation                                                                                                          |
| ----------- | -------------------------------------------------------------------------------------------------------------------- |
| `O(n!)`     | Most inefficient. May never reach the end of the data sequence.                                                      |
| `O(n^2)`    | Highly inefficient. The average complexity of naive sorting algorithms (bubble-sort, insertion-sort, selection-sort).|
| `O(n log n)`| Average runtime of efficient sorting algorithms e.g., merge-sort.                                                    |
| `O(n)`      | Runtime grows linearly with the value with n. Average runtime of naive searching algorithms e.g., linear search.     |
| `O(log n)`  | Average runtime of efficient searching algorithms e.g., binary-search.                                               |
| `O(1)`      | Represents constant time (a finite number of steps for any input size)                                               |

**Dominant Term** - the term in the algorithm that experiences the most growth.

**Best / Worst / Average Cases** - the bounds for an algorithm.

**Best Case** is defined using the Ω symbol. The best case for linear search is Ω(1) or the first element checked. Best case for binary search is also Ω(1) or the first middle element that is checked.
- An algorithm with running time of `O(1)` means that a constant number of steps is required, no matter how big the problem is.

**Θ** theta symbol signifies the *same* upper / lower bounds for an algorithm. E.g., Selection Sort has a best and worst case runtime complexity of Θ(n^2) because even if it is passed a sorted list, it needs to search the list for the smallest element, each time to verify.

**Run-time Complexity Calculation**
```
Total number of steps * number of steps or comparisons at each iteration;
```

**Asymptotically** - As `n` approaches infinity / "gets really large".

### Searching Algorithms

### 1. Linear Search
#### Description
Searching each individual value at a time. Analogous to searching a phone book one page at a time from the first page.

#### Implementation
```
#include <stdio.h>

int main(int argc, char *argv[])
{
    int nums[4] = {1, 2, 3, 4};
    int target = 3;

    for (int i = 0; i < 4; i++)
    {
        if (nums[i] == target)
        {
            printf("%i was found on index %i\n", target, i);
            return 0;
        }
    }

    printf("Not found");
    return 1;
}
```

### 2. Binary Search
#### Description
Searching a pre-sorted array whilst reducing the problem space by half. **Requires the array to be pre-sorted**. Analogous to searching a phone book by starting in the middle then discarding one half each time.

#### Implementation
```
#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(array) / sizeof(array[0]);
  int x = 4;
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}
```

#### Implementation Trick
- Keep throwing away half the array until the start > end (they don't cross).


### Sorting Algorithms
- Consider whether sorting is worth it if only going to search once as linear search may be more efficient than first sorting then searching.

|   Algorithm	 |    Best     |   Average   | 	  Worst    | Worst (Space) |
| -------------- | ----------- | ---------   | ----------- | -----------   |
| Selection Sort | 	Ω(n^2)     | θ(n^2)      | O(n^2)       | O(1)         |
| Bubble Sort    | 	Ω(n)       | θ(n^2)      | O(n^2)       | O(1)         |
| Insertion Sort | 	Ω(n)       | θ(n^2)      | O(n^2)       | O(1)         |
| Heap Sort      | 	Ω(n log(n))| θ(n log(n)) | O(n log(n))  | O(1)         |
| Quick Sort     | 	Ω(n log(n))| θ(n log(n)) | O(n^2)	    | O(n)         |
| Merge Sort     | 	Ω(n log(n))| θ(n log(n)) | O(n log(n))  | O(n)         |
| Bucket Sort    | 	Ω(n +k)    | θ(n +k)     | O(n^2)       | O(n)         |
| Radix Sort     | 	Ω(nk)      | θ(nk)	     | O(nk)	    | O(n + k)     |
| Count Sort     | 	Ω(n +k)    | θ(n +k)     | O(n +k)      | O(k)         |
| Shell Sort     | 	Ω(n log(n))| θ(n log(n)) | O(n^2)	    | O(1)         |
| Tim Sort       | 	Ω(n)       | θ(n log(n)) | O(n log (n)) | O(n)         |
| Tree Sort      | 	Ω(n log(n))| θ(n log(n)) | O(n^2)       | O(n)         |
| Cube Sort      | 	Ω(n)       | θ(n log(n)) | O(n log(n))  | O(n)         |

### 1. Selection Sort
#### Description
- Iterate across each element in an array. Find the smallest value, then swap it with the element current accessed.
- Both `i` and `j` nested for loops should run until the length of the array
- Declare `current_min` and `min_position` inside the `i` for loop. Allows you to change the Ith element with the value of j.
- Initialize `current_min` with the current Ith value e.g., `int current_min = nums[i]`.

#### Implementation
```
#include <stdio.h>

int selection_sort(int nums[], int arr_len);

const int NUMS_LENGTH = 8;

/*
- C implementation of the selection sort algorithm.
*/
int main(void)
{
    int nums[NUMS_LENGTH] = {10, 11, 90, 21, 29, 2, 1, 0};

    selection_sort(nums, NUMS_LENGTH);

    return 0;
}

int selection_sort(int nums[], int arr_len)
{
    // selection sort;
    for (int i = 0; i < arr_len; i++)
    {
        int current_min = nums[i];
        int min_position = i;
        // find minimum value
        for (int j = i; j < arr_len; j++)
        {
            if (nums[j] < current_min)
            {
                current_min = nums[j];
                min_position = j;
            }
        }
        // swap current position's value with the minimum value
        int holder = nums[min_position];
        nums[min_position] = nums[i];
        nums[i] = current_min;
        printf("%i ", nums[i]);
    }

    printf("\n");
    return 0;
}
```

#### Performance
`O(n^2)` best case, `O(n^2)` worst case as for each element, algorithm will have to find the smallest element, regardless if the array is sorted or not.
Can be represented as Ω(n^2).

#### Implementation Trick
- the i `for` loop is initialized at 0 and terminates at n.
- the h `for` loop is initialized at i and terminates at n. i.e., `for (int j = i ...`
- initialize a `minimum` variable inside the i `for` loop to keep track of the min value during each pass.
- Initialize a `min_position` variable inside the i `for` loop to keep track of the min value's position during each pass.

### 2. Bubble Sort
#### Description
- Iterate across each element in an array whilst swapping the position of a larger element with a smaller one until it bubbles to the end.
- `i` for loop should run until the length of the array. `j` nested for loop should run to the length of the array - 1. This avoids a segfault.
- Compare `nums[j]` with `nums[j + 1]` and swap if `nums[j] > nums[j + 1]`.

#### Implementation
```
#include <stdio.h>

int bubble_sort(int nums[], int arr_len);

const int NUMS_LENGTH = 7;

int main(void)
{
    int nums[NUMS_LENGTH] = {1, 2, 3, 4, 5, 6, 7}; //{20, 8, 5, 30, 9, 4, 1};

    bubble_sort(nums, NUMS_LENGTH);

    return 0;
}

int bubble_sort(int nums[], int arr_len)
{
    int is_swapped = 0;
    for (int i = 0; i < arr_len; i++)
    {
        // terminates at 1 position before the end to avoid comparing last element with one out of the array
        // ..preventing a segfault.
        for (int j = 0; j < arr_len - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                // swap
                int holder = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = holder;
                is_swapped = 1;
            }
        }
        for (int i = 0; i < arr_len; i++)
        {
            printf("%i ", nums[i]);
        }

        printf("\n");

        // optimization
        if (is_swapped == 0)
        {
            printf("Array sorted. no swaps made.\n");
            return 0;
        }
    }

    return 0;
}
```

#### Performance
`O(n^2)` worst case, as the algorithm will have to swap n -1 elements n - 1 times. `O(n)` best case if optimization of `is_swapped` flag. Program will terminate after only one pass as no swaps has been made.

#### Optimization
- Since Bubble Sort makes n-1 comparisons, n-1 times, if an array is pre-sorted, using an `is_sorted` flag to exit early prevents n-1 iterations. This changes the lower bound from `O(n^2)` to `O(n)`

#### Implementation Trick
- 2nd j `for` loop should terminate at n-1.
- Swaps only need to happen for elements being accessed by the j `for` loop.
- Use a `holder` integer variable to swap the nums.

### Recursion
- Recursion is calling a function within itself on a smaller and smaller problem space.
- A recursive function defines a base case and a recursive step. The base case is needed to exit so a function does not run forever. The recursive step calls the function again with some new parameter.
- The functions keep getting pushed to the call stack until the base case is triggered, then they are run one by one from last added to first and are popped off the stack in this order.

5 5tep process to solve any recursive problem
1. Determine simplest input for the function (Base case) - the case where an explicit answer is provided.
2. Draw example inputs and outputs to visualize the problem.
3. Relate hard cases to smaller and simpler cases. "If given answer for n(m - 1) case, can I solve for n(m)"
4. Generalize pattern into an expression.
5. Write code by combining the pattern with the base case.

*Recursive Leap of Faith*
Assume that simpler cases work out and can be extrapolated for more complex cases.

#### Examples
```
#include <stdio.h>

int collatz(int n);

int main(void)
{
    printf("%i\n", collatz(1));

    return 0;
}

int collatz(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + collatz(n / 2);
    }
    else {
        return 1 + collatz(3 * n + 1);
    }
}
```

## Week 4 - Lecture 4 - Memory
### General Knowledge
- Strings are implemented similarly to arrays in a contiguous block of memory.
- In C, double quotes automatically insert the `\0` character at the end of a string.

### Hexadecimal
- Hexadecimal notation makes it easy to read large numbers - helpful in the case of reading memory addresses or bytes.
- A color e.g., `FFFFFF` can signify the proportion of `RGB` values, in this case R: 255, G:255, B: 255.
- a.k.a base 16.
- Only has a 16^1 and 16^0 places. This way values from 0 to 255 can be represented.
- 1 hex digit is stored using 4 bits.
- Memory addresses are usually denoted using the hexadecimal system. These are denoted using the `0x` prefix. 

### Memory & Pointers
- Each "cell" in the abstract memory grid has an address e.g., `0x1001c4f9f` the `0x` prefix denotes that a number is a memory address.
- The `&` operator refers to an address in memory e.g., `0x1001c4f9a`.
- A pointer simply points to an address in memory. Is declared using the `*` operator and has a type e.g., `int *p;` creates an integer pointer. The `*` operator does the opposite of `&`, it looks inside the memory.
- The syntax `int *p` is read as integer pointer p.
- A pointer can store the value of an address in memory by "pointing" to it. E.g., `int *p = &n;`.
- A pointer data type needs to support the largest value supported by the CPU, hence it is `8 bytes`.
- Used the 'mail box' analogy that contained the address of a variable. Then used the address in the program.
- When defining string such as `char *s = "abc";`, `s` is a pointer to the first character in memory. Just need to know the first memory address as you can keep going until the null character `\0` is found.
- The `*` is used for both creating a pointer variable as well as dereferencing a pointer.

### Dereferencing Pointers
- Using the `*` operator on a pointer (i.e., a memory address) returns it's contents. E.g.,
```
#include <stdio.h>

int main(void)
{
    int n = 10;
    
    // a pointer variables stores the memory address of some other variable. '&' syntax means memory address.
    int *ptr = &n;

    // %p is the format code to print an address with printf. And we only need to use the name of the variable, p, after we’ve declared it.
    printf("%p\n", &n);

    printf("%p\n", ptr);

    // dereference (reading and modifying value at particular memory address)
    printf("initial: %i\n", *ptr);

}
```

### Custom data types
- syntax `typedef <PRIMITIVE> <TYPE_NAME>` maps a primitive to a more readable custom type. This is also how structs are defines.

**Array Indexing Syntactic Sugar**
- As an array is a contiguous chunk of memory, if it's starting address in memory and the number of elements are known, a `for` loop can be used to print the values present in the array.
- Array / string indexing is usually carried out by the square bracket syntax. This is just syntactic sugar for using pointers to iterate on the underlying elements.
e.g.,
```
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
```

### Strings
- Declaring a string by using `char *str = "abc";` returns the memory address of the first character of the string. The data in the first character can be accessed through dereferencing such as `printf("%c\n", *str);`.