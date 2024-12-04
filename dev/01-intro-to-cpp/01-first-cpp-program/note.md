## Write and Run First C++ Program

C++ is a *compiled* language; there is a separate program - the compiler - that converts code to an executable program that the computer can run. This means that running a new C++ program is normally a two step process:

1. Compile code with a compiler.
2. Run the executable file that the compiler outputs.

### C++ Main()

In C++, every program contains a `main` function which is executed automatically when the program is run. Every part of a C++ program is run directly or indirectly from `main`, and the most basic program that will compile in C++ is just a `main` function with nothing else.

`main()` should return an integer (an `int` in C++), which indicates if the program exited successfully. This is specified in code by writing the return type, followed by the `main` function name, followed by empty arguments:

```
int main()
```

The body of the `main()`, which comes after the `main` function name and arguments, is enclosed in curly brackets: `{` and `}`. In this exercise, we will write the smallest possible C++ program, which is a `main` function with empty body.

And we can compile and run program with the following:

1. To compile, use the following command: `g++ main.cpp`
2. To run, use: `./a.out`