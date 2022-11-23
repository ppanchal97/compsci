## CS50 Course Notes

### Week 1 - Lecture 1 - C
- syntax highlighting - text editors colour different componen˜ts of the program differently for redilibilty. e.g., function names can be purple, protected keywords can be green etc
    - machine code - technical term to refer to binary digits. Contrasts with source code (humans write)
- side effects are consequences of function calls
- programs are a bunch of expressions and conditions
- escape sequence `\n` tells the compiler to print a blank line once the program is done
- header files such as stdio.h are used to include libraries
    - back in the day, resources were limited and so only the required libraries and components were imported to reduce bloat
- %% - will print one percent sign, %s. %d etc are format codes, they are placeholders for variables that can be passed in later
- the compiler analyses the program from top to bottom, left to right
- While loops are used until a condition is met
- For loops are used to repeat an expression a finite number of times
- constants allow you to guard against mistakenly changing a variable e.g., const int a = 2;
- do / while loops allow you to run logic only when a condition evaluates to true
- If really confused, write pseudocode
- put main function at top of the file
- signed ints can be between 2 billion and. -2 billion
- Unsigned bits can be around 4 billion. Unsigned can only store positive values
    - these are vulnerable to integer overflow if the correct data type is not used/first most bit indicates the sign of the integer
    - first bit (most significant bit) denotes whether integer is positive / negative
- Underflow - storing a value lesser than the minimum allowed value
- Y2K - computers only used 2 digits to represent year. E.g., 1999 = 99. So when 2000 came, it would be 00, i.e., 1900
- Unix time stores seconds since 1 jan 1970. **signed** 32 bit integers can store up values up to 4 billion, this will be reached on 19th Jan 2038 as 4b seconds would have passed.
- According to the National Institute of Standards and Technology (NIST), a greedy algorithm is one “that always takes the best immediate, or local, solution while finding an answer. Greedy algorithms find the overall, or globally, optimal solution for some optimization problems, but may find less-than-optimal solutions for some instances of other problems.”