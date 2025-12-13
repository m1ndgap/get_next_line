_This project has been created as part of the 42 curriculum by tchumbas._

# Description
get_next_line project for 42Lisboa. Using static variables to access the same file using a file descriptor with multiple calls of the function during the program runtime. Returning new line (characters before `\n` each time) or null in case of an error or reaching end of file.

Static variables automatically iterate on call and preserve their state between calls.

Bonus task is to implement the same function capable of maintaining more multiple files as file descriptors.

# Instructions
## [Tests I wrote](https://github.com/m1ndgap/get_next_line/tree/8fd3103a14c141cc5e716f76b5144aed9aba981e/TESTS)
Copy in the root of the project and run 
```
make <command> -f TESTS/Makefile
```
#### Commands:
- `run` - execute tests
- `valgrind` - execute tests with valgrind output
- `clean`, `fclean`, `re`

## [GNL tester](https://github.com/Tripouille/gnlTester) by [Tripouille](https://github.com/Tripouille)
Clone to the root of the project and run `make a` inside the cloned folder.

# Resources
https://www.sanfoundry.com/c-tutorials-eof-fopen-max-filename-max-constants-uses/

https://stackoverflow.com/questions/20000077/fopen-max-and-sc-open-max

https://www.geeksforgeeks.org/c/static-variables-in-c/

https://en.wikipedia.org/wiki/Static_variable

AI was used to clarify difference between `FOPEN_MAX` and `OPEN_MAX`. Confirming correct `fd > FOPEN_MAX` protection for the bonus tasks.