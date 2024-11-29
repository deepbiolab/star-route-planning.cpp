# How to Read From File

Now that we are able to print the board in our program, we will make the program more flexible by **reading the board from a file**. This will allow we to run our program with different board files to see the results.

Before we can read the contents of a file into our program, we'll need to learn the syntax for just a couple more parts of the C++ language: `if` statements and `while` loops.



## If Statements

C++ `if` statements work very similarly to if statements in other languages. In C++, the boolean condition is contained in parentheses `(` and `)`, and the body of the statement is enclosed in curly brackets `{` and `}`. 

```cpp
#include <iostream>
using std::cout;

int main() 
{

    // Set a equal to true here.
    bool a = true;

    if (a) {
      cout << "Hooray! we made it into the if statement!" << "\n";
    }
}
```

```bash
$ g++ -std=c++17 ./code/if_example.cpp && ./a.out
Hooray! we made it into the if statement!
```



## While Loops

The syntax for a `while` loop looks very similar to the syntax for the `if` statement: 

```cpp
#include <iostream>
using std::cout;

int main() 
{
    auto i = 0;

    while (i < 5) {
      cout << i << "\n";
      i++;
    }
}
```

```bash
$ g++ -std=c++17 ./code/while_example.cpp && ./a.out
0
1
2
3
4
```

We can also combine these two statements into together.

```cpp
#include <iostream>
using std::cout;

int main() 
{
    // A while loop to iterate over the integers from 1 to 10. 
    // If the integer is even, print it out.
    int i = 1;
    while (i <= 10) {
        if (i % 2 ==  0) {
            cout << i << "\n";
        }
        i++;
    }
}
```

```bash
$ g++ -std=c++17 ./code/if_while.cpp && ./a.out
2
4
6
8
10
```



## File Input Streams

### Creating an Input Stream Object

In C++, we can use the `std::ifstream` object to handle input file streams. To do this, we need to include the header file that provides the file streaming classes: `<fstream>`. 

Once the `<fstream>` header is included, a new input stream object can be declared and initialized using a file path `path`:
```cpp
std::ifstream my_file;
my_file.open(path);
```

Alternatively, the declaration and initialization can be done in a single line as follows:
```cpp
std::ifstream my_file(path);
```
C++ `ifstream` objects can also be used as a **Boolean** to check if the stream has been created successfully. If the stream were to initialize successfully, then the `ifstream` object would evaluate to `true`. If there were to be an error opening the file or some other error creating the stream, then the `ifstream` object would evaluate to `false`.

Suppose we have a file in this path and looks like below: `"files/1.board"` 

```txt
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,0,0,0,1,0,
```

We can use code in below cell to read this file:

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream my_file;
    my_file.open("files/1.board");
    if (my_file) {
      std::cout << "The file stream has been created!" << "\n";
    }    
}
```

```bash
$ g++ -std=c++17 ./code/read_file.cpp && ./a.out
The file stream has been created!
```



### Reading Data from the Stream

If the input file stream object has been successfully created, the lines of the input stream can be read using the `getline` method. In the cell below, a while loop has been added to the previous example to get each line from the stream and print it to the console.

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream my_file;
    my_file.open("files/1.board");
    if (my_file) {
        std::cout << "The file stream has been created!" << "\n";
        std::string line;
        while (getline(my_file, line)) {
            std::cout << line << "\n";
        }
    }
}
```

```bash
$ g++ -std=c++17 ./code/read_file_2.cpp && ./a.out
The file stream has been created!
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,0,0,0,1,0,
```

> The `getline` method takes two inputs: the `ifstream` object and a `string` to write the line to.
>
> `getline` returns a Boolean `false` if there are no more lines in the stream to write to the `string` and returns `true` otherwise.

### Recap

That's it! To recap, there are essentially four steps to reading a file:
1. `#include <fstream>`
2. Create a `std::ifstream` object using the path to our file.
3. Evaluate the `std::ifstream` object as a `bool` to ensure that the stream creation did not fail.
4. Use a `while` loop with `getline` to write file lines to a string.



## Example: Read the Board from a File

Until now, the board has been declared and initialized in the `main()` function. As discussed in the previous part, we need a function to read the board in from another file in order to make the program a little more flexible and user-friendly.

The first step in this process will be to write a `ReadBoardFile` function that reads in the file and prints each line to `cout`. The output should look like the `1.board` file:

```
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,0,0,0,1,0,
```

see implementation details in [`main.cpp`](./main.cpp) file.