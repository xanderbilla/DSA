#include<iostream>

// swapping usingwithuot using 3rd var
using std::cout;

int main()
{
    int a = 10;
    int b = 10;
    
    cout << "Before swapping: " << a << " " << b << "\n";

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "After swapping: " << a << " " << b << "\n";
    return 0;
}