#ifndef APPLIC_H
#include "applic.h"
#endif

#ifndef GROCERY_H
#include "grocery.h"
#endif
#ifndef MENU_H
#include "menu.h"
#endif

#ifndef __CSTRING_H
#include <cstring.h>
#endif

#include <fstream.h>
class MyMenu :public Menu
{
public:
	MyMenu();
};

MyMenu::MyMenu()
{
	StringArray myChoices;
	myChoices.insertItem("Add an item");
	myChoices.insertItem("Compute Cost");
	myChoices.insertItem("Print list");
	myChoices.insertItem("Quit");
	setChoices(4,myChoices);
}
void MyApplication::addItem()
{
	cout<<"Enter the item name";
    char inval[255];
    cin.getline(inval,255);
	string name(inval);
	cout<<"Enter the items id number";    
    cin.getline(inval,255);
	string id(inval);
	cout<<"What is the cost per item?"; 
    cin.getline(inval,255);
	string costString(inval);
	double cost = atof(costString.c_str());
	cout<<"How many do you need?";
	int howMany;
	cin>>howMany;
	GroceryItem newOne(name,id,cost,howMany);
	groceries.addItem(newOne);

}

void MyApplication::printList()
{   
	cout.precision(2); // two place accuracy on output
	cout.setf(ios::fixed);// fixed point notation
	groceries.print(cout);
}

void MyApplication::computeCost()
{
	cout.precision(2); // two place accuracy on output
	cout.setf(ios::fixed);// fixed point notation
	cout<<"The cost of this list is $"<<groceries.computeCost()<<endl;
}

void MyApplication::run()
{
	MyMenu menu;
	ifstream in("grocery.dat");
	if (!in)
		throw "File of groceries not found";
	groceries.read(in);
	in.close();
	int choice;
	do {
		  choice = menu.makeChoice();
		  switch (choice) {
			case 0:  addItem();break;
			case 1:	computeCost();break;
			case 2:  printList();break;
			}
	}while (choice != 3);
   ofstream out("grocery.dat");
	if(!out)
		throw "File of groceries not found";
	groceries.write(out);
	out.close();
}