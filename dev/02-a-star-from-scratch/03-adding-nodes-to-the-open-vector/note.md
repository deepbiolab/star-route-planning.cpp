## Pass by Reference

In the previous exercises, we've written functions that accept and return various kinds of objects. However, in all of the functions we've written so far, the objects returned by the function are different from the objects provided to the function. In other words, when the function is called on some data, a copy of that data is made, and the function operates on a copy of the data instead of the original data. This is referred to as **pass by value**, since only a copy of the values of an object are passed to the function, and not the actual objects itself.

To see how to use a function to operate directly on a given object, have a look at the cell below.

```cpp
#include <iostream>
using std::cout;


int MultiplyByTwo(int i) {
    i = 2*i;
    return i;
}

int main() {
    int a = 5;
    cout << "The int a equals: " << a << "\n";
    int b = MultiplyByTwo(a); // 10
    cout << "The int b equals: " << b << "\n";
    cout << "The int a still equals: " << a << "\n";
}
```

```bash
$ g++ -std=c++14 ./code/pass_by_value.cpp && ./a.out
The int a equals: 5
The int b equals: 10
The int a still equals: 5
```

In the code above, `a` is **passed by value** to the function, so the variable `a` is not affected by what happens inside the function.

But what if we wanted to change the value of `a` itself? For example, it might be that the variable you are passing into a function maintains some state in the program, and you want to **write the function to update that state.** 

It turns out, it is possible to **modify `a` from within the function**. To do this, you must pass a _reference_ to the variable `a`, instead of the _value_ of `a`. In C++, _a reference is just an alternative name for the same variable_.

To pass by reference, you simply need to **add an ampersand `&` before the variable** in the function declaration. Try the code below to see how this works:

```cpp
#include <iostream>
using std::cout;


int MultiplyByTwo(int &i) {
    i = 2*i;
    return i;
}

int main() {
    int a = 5;
    cout << "The int a equals: " << a << "\n";
    int b = MultiplyByTwo(a);
    cout << "The int b equals: " << b << "\n";
    cout << "The int a now equals: " << a << "\n";
}
```

```bash
$ g++ -std=c++14 ./code/pass_by_reference.cpp && ./a.out
The int a equals: 5
The int b equals: 10
The int a now equals: 10
```

In the code above, `a` is **passed by reference** to the function `MultiplyByTwo` since the argument to `MultiplyByTwo` is a reference: `&i`. This means that `i` is becomes another name for whatever variable that is passed into the function. When the function changes the value of `i`, then the value of `a` is changed as well.

In the next exercises we will write some functions that require passing variables by reference. This will allow helper functions in the A* search program to **modify the state of the board without having to copy the entire board**, for instance.

Note that if you've encountered references before in C++, you are aware that they can be used in many other scenarios, aside from just passing variables to functions. In the next sections, we will learn about references more generally, along with closely related ***pointers***. 