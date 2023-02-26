### UBC HtC1 Course Notes

### Racket Specific Features
- Use `(check-expect())` to assert and test return values of functions.
- Racket has implicit returns - no explicit `return` keyword is necessary as in C and Python.


### How to Design Functions (HtDF Recipe)
- Helps to break down complex functions into smaller components and increases code confidence.

1. Think about the `Function Signature` - what does the function accept (arguments and their data types) and what does it return?
2. Think about the `Purpose` of the function - what is the big picture this function is trying to achieve?
3. Think about `Examples` - these are input / output pairs when the function is called.
4. Think about `Template / Inventory` - what arguments do you have access to and what are the constraints around them that you have to work with.
5. Code the `Body` of the function.
6. Write `Tests` and `Debug` to verify that the function behaves as expected.

### Handling Test Failures
Causes
- Function definition is incorrect.
- Test implementation is incorrect.
- They are both incorrect.

### Testing Best Practices
1. **Check test first before modifying the function itself**
2. Check the code coverage tool to ensure that all paths within the functions are covered by unit tests.
3. When encountering a corner case:
   1. Think if purpose / signature need to change
   2. Think if code implementation needs to change