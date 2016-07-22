
//Tatyana Vlaskin
//Lab5
#include <iostream>
#include <string>
#include "salariedemployee.h"
#include "administrator.h"
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using SavitchEmployees::SalariedEmployee;
using SavitchEmployees::Administrator;
void newLine();
void ValidSupervisor(string &supervisorName1,string adminTitle2, vector<Administrator>& database);

int main(){

   std::vector<Administrator> database;

//Administrator(string aName,string anSSn,double aSalary,string aTitle,
                 //string aResponsibilty,string aSupervisor);

    database.push_back( Administrator("Linda","13-14-520", 100, "Director", "Production", "MikesBoss"));
    database.push_back(Administrator("Bob","13-14-521", 1000, "Vice President", "Accounting", "BobsBoss"));
    database.push_back(Administrator("Mike","13-14-523", 200, "Title1", "Persoanl", "LindasBoss"));
	//cout <<database.size();
	Administrator admin;
	string name2;
    cout << "Enter the name of the new Administrator:" << endl;
    getline(cin, name2);
    admin.setName(name2);
    string adminTitle2;
    cout << "Enter the title of the " <<admin.getName() << endl;
    getline(cin, adminTitle2);
    admin.setSupervisorTitle(adminTitle2);
	admin.inputAdminData();
		//cout << database.size()<<endl; debugging
	newLine();
	if(admin.getSupervisorTitle() == "Director"){
	    cout<< "There is nobody higher in postion than you." <<endl;
	    cout <<"You will NOT have a supervisor" <<endl;
	}
    else {
    cout << "Enter the immediate supervisor's name " << endl;
    		////////////////FOR DEBUGGIN
    cout << "Current Employees that can be assigned as Supervisors: " <<endl;
    for(vector<Administrator>::iterator it = database.begin(); it != database.end(); ++it)
	{
		cout << it->getName() << endl;
	}
///////////////////////
    string supervisorName1;
    getline(cin, supervisorName1);
    ValidSupervisor(supervisorName1, adminTitle2, database);
    admin.setSupervisor(supervisorName1);
    }
	admin.outputAdminData();
	admin.printCheck();
	return 0;
}

/************************************************
** Function: void newLine()
** Description:Function taken from the book. Reads
all charactes untill it see new life
*************************************************/
void newLine()
{
   char symbol;
   do
   {
      cin.get(symbol);
   } while (symbol != '\n');
}

/************************************************
** Function: void ValidSupervisor(string supervisorName1,vector<Administrator> database)
** Description:Function to check if the name exists in the database.
** If the name exists, the person will be assinged as a supervisor.
** If the name does not exist, the user will be asked to reenter the
** supervisors name.
*************************************************/
void ValidSupervisor(string &supervisorName1, string adminTitle2,vector<Administrator>& database){

		cout << database.size();
        for(vector<Administrator>::iterator it = database.begin(); it != database.end(); ++it){
            if(it->getName().compare(supervisorName1) == 0)
            {
                if (adminTitle2 == "Vice President" && it->getSupervisorTitle() != "Director"){
                cout << "This person is not a Director. " <<endl;
                cout <<"Becuase you are a Vice President, you can be supervised only by Director"<<endl;
                cout <<"Please enter valid supervisor. " <<endl;
                getline(cin, supervisorName1);
                 ValidSupervisor(supervisorName1, adminTitle2, database);
                 return;
                }
                else{

               cout << "Supervisor assinged successfully" << endl;
               return;
            }

        }
        }

           cout <<"Employee does not exist in our database." <<endl;
            cout <<"Please enter valid supervisor. " <<endl;
            getline(cin, supervisorName1);

            ValidSupervisor(supervisorName1, adminTitle2, database);
            }


