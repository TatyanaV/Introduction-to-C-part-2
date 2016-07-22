#ifndef APPLIC_H
#define APPLIC_H
#ifndef GROCERY_H
#include "grocery.h"
#endif

class MyApplication
{
public:
	void run();
private://These functions only need be known by MyApplicaton
	void addItem();
	void printList();
	void computeCost();
	// we will read the list at the start of run
	// and save at the end of run
	GroceryList groceries;
};
#endif