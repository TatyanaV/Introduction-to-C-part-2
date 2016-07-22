
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <iostream>
#include "salariedemployee.h"
using std::string;
namespace SavitchEmployees
{
    class Administrator : public SalariedEmployee
    {
        public:
            Administrator();
           // Administrator(string theName,string theSsn, double salary);
            Administrator(string aName,
                 string anSSn,
                 double aSalary,
                 string aTitle,
                 string aResponsibilty,
                 string aSupervisor
                );

            void setSupervisor(string supervisorName);//changes the supervisors name
            string getSupervisor();
            void setSupervisorTitle(string adminTitle);
            string getSupervisorTitle();
		    void inputAdminData();// reads  the administrators data from the keyboard
		    void outputAdminData();//print function the outputs the objects data to the screen
		    void printCheck();//overloaded function to print check
        protected:
            string adminTitle;//administrator's title
            string workingArea;//area of responsibility//production, accounting, or personnel
	     	string supervisorName;//immediate supervisor
	     	//salary will not be defined because
	     	//I am using the  existing salary member by chaning the
	     	//private in the base class to protected
    };
}

#endif // ADMINISTRATOR_H_INCLUDED

