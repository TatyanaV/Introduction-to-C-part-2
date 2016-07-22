#include <iostream>
#include <string>
#include "administrator.h"
#include "employee.h"
#include "salariedemployee.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

namespace SavitchEmployees
{
 Administrator::Administrator( ):SalariedEmployee()
    {
        //deliberately empty
    }

    Administrator::Administrator(string theName, string theSsn, double theAnnualSalary)
      :SalariedEmployee(theName, theSsn, theAnnualSalary)
    {
        //deliberately empty
    }

    void Administrator::setSupervisor(string supervisor){
        supervisorName = supervisor;
        setName(supervisor);// CHANGING NAME OF THE SUPERVISOR

    }


    void Administrator::inputAdminData()
    {
        cout << " Enter the details of the administrator " << getName() << endl;
        cout << " Enter the admin title" << endl;
        getline(cin, adminTitle);
        cout << " Enter the area of responsibility " << endl;
        getline(cin, workingArea);
        cout << " Enter the immediate supervisor's name " << endl;
        getline(cin, supervisorName);
    }

    void Administrator::outputAdminData()
    {
        cout << "Name: " << getName() << endl;
        cout << "Title: " << adminTitle << endl;
        cout << "Area of responsibility: " << workingArea << endl;
        cout << "Immediate supervisor: " << supervisorName << endl;
    }

    void Administrator::printCheck()
    {
        setNetPay(salary);
		cout << "\n___________________________________\n";
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of" << getNetPay() << "Dollars\n";
        cout << "______________________________________\n"
             << "Check Stub Not negotiable \n";
        cout << "Employee Number: " << getSsn() << endl;
        cout << "Salaried Employee(Administrator). Regular Pay: "
			 << salary << endl;
		cout << "______________________________________\n";
    }
}//SavitchEmployees
