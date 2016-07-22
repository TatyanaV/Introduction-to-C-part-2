//#include "employee.h"
#include "administrator.h"
#include <iostream>

administrator::adminstrator(): SalariedEmployee(){
    using namespave std;
    cout <<endl<< "Administrative Employee data is entered: " <<endl;
    get_admin_data();
}

administrator::administrator(string aTitle,
                             string aResponsibility,
                             string aSupervisor):
                             SalariedEmployee(), title(aTitle),responsibility(aResponsibility),
                             supervisor(aSupervisor)
                             {}//left empty

                             //change name of immediate supervisor
void administrator:change_supervisor(string new_super){
    supervisor = new_super;
}

//reading all of a new administrotors data from the keyboard
void administrator:::get_admin_data(){
    using namespace std;
    cout <<"Enter title of the supervisor: "
    getline(cin,title);
    cout<<endl<< "Enter area of responsibility: "
    getline(cin, responsibility);
    cout<< endl<< "Enter supervisors name: ";
    getline (cin, supervisor);
}

//outputs administrotors data to the screen
void administrator::print(){
    using namespace std;
    cout<< endl << "Supervisor Information: " <<endl;
    cout <<"Name: " <<name<< endl;
    cout <<"Anual Salary: $ " << annual_salary <<endl;
    cout << "Social Security Number: " <<ssn <<endl;
    cout <<"Title: " <<titele <<endl;
    cout <<"Responsibility: " <<responsibility<< endl;
    cout <<"Supervisor: " <<supervisor<<endl;
}

//prints a check with appropriate notation on the check
void administrator::print_check(){
    using namespace std;
    long double monthly_pay = annual_salary/12;
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << name << endl;
    cout << "The sum of " << monthly_pay << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << ssn << endl;
    cout << "_________________________________________________\n";
}
