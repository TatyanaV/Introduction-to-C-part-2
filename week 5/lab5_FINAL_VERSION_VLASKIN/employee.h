//This is the header file employee.h.
//This is the interface for the class Employee.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of employees.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace SavitchEmployees
{

    class Employee
    {
    public:
        Employee( );
        Employee(const string& theName, const string& theSsn);
        string getName( ) const;
        string getSsn( ) const;
        double getNetPay( ) const;
        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay(double& newNetPay);
        void printCheck( ) const;
   // private:
    protected: // we are allowed to change it to protected per instructions
        string name;
        string ssn;
        double netPay;
    };

}//SavitchEmployees

#endif //EMPLOYEE_H
