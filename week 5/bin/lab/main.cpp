#include <iostream>
#include <string>
#include "salariedemployee.h"
#include "administrator.h"
using std::cout;
using std::cin;
using std::endl;
using SavitchEmployees::SalariedEmployee;
using SavitchEmployees::Administrator;

int main()
{
    cout << "Information about the Current Supervisor:" <<endl<<endl;
	SalariedEmployee boss("CURRENT SUPERVISOR", "987-65-4321", 10500.50);
	cout << "Check for " << boss.getName() << endl;
	boss.printCheck();
    Administrator admin("WILL BE ASSIGNED SHORTLY","13-14-520", 1.00);
	cout << endl<< "Please enter information of the new Supervisor:" <<endl;
	string namesupervisor2;
    cout << "Enter the name of the new Supervisor:" << endl;
    getline(cin, namesupervisor2);
    admin.setSupervisor(namesupervisor2);
	//Administrator admin(name, "13-14-520", 1.00);
	admin.inputAdminData();
	admin.outputAdminData();
	admin.printCheck();

	return 0;
}
