## Write and Run Your First C++ Program

C++ is a *compiled* language; there is a separate program - the compiler - that converts your code to an executable program that the computer can run. This means that running a new C++ program is normally a two step process:

1. Compile your code with a compiler.
2. Run the executable file that the compiler outputs.

### C++ Main()

In C++, every program contains a `main` function which is executed automatically when the program is run. Every part of a C++ program is run directly or indirectly from `main`, and the most basic program that will compile in C++ is just a `main` function with nothing else.

`main()` should return an integer (an `int` in C++), which indicates if the program exited successfully. This is specified in code by writing the return type, followed by the `main` function name, followed by empty arguments:

```
int main()
```

The body of the `main()`, which comes after the `main` function name and arguments, is enclosed in curly brackets: `{` and `}`. In this exercise, you will write the smallest possible C++ program, which is a `main` function with empty body. If you have trouble, have a look at the `solution.cpp` file in the workspace below.

Remember that you can compile and run your program with the following:

1. To compile, use the following command: `g++ main.cpp`
2. To run, use: `./a.out`