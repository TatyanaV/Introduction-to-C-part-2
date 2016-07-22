
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "employee.h"

class Administrator: public SalariedEmployee{
    public:
        Administrator();
        Administrator(string aTitle,
                      string aResponsibilities,
                      string aSupervisor);
                      //change name of the supervisor
        void change_supervisor(string new_super);//setSupervisor
        // eads a new administrators data from the keyboard
        void get_admin_data();
        //outputs administrotors data to the screen
        void print();
        //prints a check with appropriate notation
        void print_check();
        //void
    protected:
        string title;
        string responsibility;
        string supervisor;//name of the immediate supervisor
        long double anual_salary;
};
#endif
