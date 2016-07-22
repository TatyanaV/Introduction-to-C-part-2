#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
#include "administrator.h"
#include "employee.h"
#include "salariedemployee.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

namespace SavitchEmployees{
Administrator::Administrator( ):SalariedEmployee()  {}

Administrator::Administrator(string aName,
              string anSSn,
              double aSalary,
              string aTitle,//
              string aResponsibilty,//
              string aSupervisor//
             // double aSalary
             ):SalariedEmployee(aName, anSSn, aSalary),adminTitle(aTitle),
              workingArea(aResponsibilty),supervisorName(aSupervisor){}


    void Administrator::setSupervisor(string supervisor){
        supervisorName = supervisor;
    }

    string Administrator::getSupervisor(){
        return supervisorName;
    }

void Administrator:: setSupervisorTitle(string administratorTitle){
    adminTitle = administratorTitle;
}

string Administrator:: getSupervisorTitle(){
    return adminTitle;
}

    void Administrator::inputAdminData(){
        cout << "Enter the area of responsibility of " << getName() << endl;
        getline(cin, workingArea);
	    cout << "Enter SSN: " <<endl;
        getline(cin, ssn);
        cout <<"Enter salary: " <<endl;
        double pay;
        cin >> pay;
        setNetPay(pay);
        cout <<getNetPay();
    }

    void Administrator::outputAdminData(){
        cout << endl << "SUMMARY OF THE EMPLOYER THAT YOU JUST ENTERED:" <<endl;
        cout << "Name: " << getName() << endl;
        cout << "Title: " << adminTitle << endl;
        cout << "Area of responsibility: " << workingArea << endl;
        cout << "Immediate supervisor: " << supervisorName << endl;
    }

void Administrator::printCheck() {

		cout << "\n___________________________________\n";
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of " << getNetPay() << " Dollars\n";
        cout << "______________________________________\n"
             << "Check Stub Not negotiable \n";
        cout << "Employee Number: " << getSsn() << endl;
        cout << "Salaried Employee: " << adminTitle << endl << " Regular Pay: "
			 << getNetPay() << endl;
		cout << "______________________________________\n";
    }
}//SavitchEmployees


