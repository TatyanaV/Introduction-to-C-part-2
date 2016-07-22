/***************************************************
Tatyana Vlaskin
Lab#1
Problem 1
06.29.2014
name: main.cpp
This program demonstrate 2 functions that are declared
in separate header files in namespace A. Those 2 functions
are defined in 2 separate implementation files in namespace A.
Those 2 functions are called in main.cpp
program using local using declarations.
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;
#include "f.h"
#include "g.h"

int main() {
    cout << "*** Namespaces and Separate Compilation***" <<endl;
    cout << endl<< "Calling functions f() and g()from namespace A with ** A:: **" <<endl;
    A::f();
    A::g();
    cout << endl <<"Calling functions f() and g() from namespace A with ** using namespace A ** directive in a block" <<endl;
    {
        using namespace A;
        f();
        g();
    }

    cout << endl << "Calling functions f() and g() from namespace A with ** using A:: ** declarations " <<endl;
    using A::f;
    using A::g;
    f();
    g();
    return 0;
}


