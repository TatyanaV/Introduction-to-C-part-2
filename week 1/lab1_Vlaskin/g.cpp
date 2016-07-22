/***************************************************
Tatyana Vlaskin
Lab#1
Problem 1
06.29.2014
name: g.cpp
This program demonstrate 2 functions that are declared
in separate header files in namespace A. Those 2 functions
are defined in 2 separate implementation files in namespace A.
Those 2 functions are called in main.cpp
program using local using declarations.
**************************************************************/
//header files
#include<iostream>
#include<cstdlib>
//includes a user defined function f.h enclodes
//in double quotes
#include "g.h"

//definition of the g() function in namespace A

namespace A
{
    void g()
    {
        using std::cout;
        using std::endl;
        //prints the message that g() function was called
        cout << "Function g() was called" << endl;
    }//end of function
}//end of namespace

