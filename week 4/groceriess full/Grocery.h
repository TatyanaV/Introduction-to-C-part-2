#ifndef GROCERY_H
#define GROCERY_H
#ifndef DARRAY_H
#include "darray.h"
#endif
#ifndef __CSTRING_H
#include <cstring.h>
#endif

#ifndef __IOSTREAM_H
#include <iostream.h>
#endif

class GroceryItem
{
public:
	GroceryItem();
	GroceryItem(string name,string id,double cost, int howMany);
	double computeCost();
	void print(ostream &);
	void write(ostream &);
	void read(istream &);
   int operator ==(const GroceryItem &)const;
private:
    string readName(istream&);//needed to read all of item name.
	string _name;
	string _idNumber;
	double _unitCost;
	int _sizeOfOrder;
};

class GroceryList
{
public:
	GroceryList();
	double computeCost();
   void addItem(const GroceryItem &newItem);
	void print(ostream &);
	void write(ostream &);
	void read(istream &);
   void clearList();
private:
	Array<GroceryItem> _item;
};
#endif