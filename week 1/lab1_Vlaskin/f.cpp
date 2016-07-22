/***************************************************
Tatyana Vlaskin
Lab#1
Problem 1
06.29.2014
name: f.cpp
This program demonstrate 2 functions that are declared
in separate header files in namespace A. Those 2 functions
are defined in 2 separate implementation files in namespace A.
Those 2 functions are called in main.cpp
program using local using declarations.
**************************************************************/
//header files
#include <iostream>
//includes a user defined function f.h enclodes in double quotes
#include "f.h"
using std::cout;
using std::endl;

//definition of the f() function in namespace A
namespace A
{
    void f()
    {

        //prints the message that f() function was called
        cout << "Function f() was called" << endl;
        return;
    }//end of function
}//end of namespace
