## C++ Output and Language Basics

```c++
#include <iostream>
using std::cout;

int main() {
	cout << "Hello!" << "\n";
}
```

`#include <iostream>`

- The `#include` is a preprocessor command which is executed before the code is compiled. It searches for the `iostream` header file and pastes its contents into the program. `iostream` contains the declarations for the input/output stream objects.


`using std::cout;`

- Namespaces are a way in C++ to group identifiers (names) together. They provide context for identifiers to avoid naming collisions. The `std` namespace is the namespace used for the standard library.
- The `using` command adds `std::cout` to the global scope of the program. This way we can use `cout` in our code instead of having to write `std::cout`.
- `cout` is an output stream we will use to send output to a terminal.
- Note that the second two lines in the example end with a semicolon `;`. Coding statements end with a semicolon in C++. The `#include` statement is a preprocessor command, so it doesn't need one.

`cout << "Hello!" << "\n";`

- In this line, the code is using cout to send output to the notebook. The `<<` operator is the stream insertion operator, and it writes what's on the right side of the operator to the left side. So in this case, `"Message here"` is written to the output stream `cout`.