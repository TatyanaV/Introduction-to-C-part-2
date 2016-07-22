#ifndef GROCERY_H
#include "grocery.h"
#endif

GroceryItem::GroceryItem(){}
GroceryItem::GroceryItem(string name,string id,double cost, int howMany)
{
	_name = name;
	_idNumber = id;
	_unitCost = cost;
	_sizeOfOrder = howMany;
}
double GroceryItem::computeCost()
{
	return _unitCost * _sizeOfOrder;
}
void GroceryItem::print(ostream &out)
{
	out<<_name<<"\t\t"<<_idNumber<<'\t'<<_unitCost<< '\t'<<_sizeOfOrder;
}
void GroceryItem::write(ostream &out)
{
	out<<_name<<endl<<_idNumber<<endl<<_unitCost<< endl<<_sizeOfOrder<<endl;
}
string GroceryItem::readName(istream &in)
{
    long int eoln;
	char inval[255];
	char *ptr;
	do
	{
		in.getline(inval,255);
		ptr = strchr(inval,'\0');
		eoln = ptr -inval;
	} while (!eoln && !in.eof());
	return string(inval);

}
void GroceryItem::read(istream &in)
{
    _name=readName(in);
	_idNumber=readName(in);
	in>>_unitCost;
	in>>_sizeOfOrder;
}

int GroceryItem::operator ==(const GroceryItem &g)const
{
	return _idNumber == g._idNumber;
}
GroceryList::GroceryList(){}
double GroceryList::computeCost()
{
	double total = 0.0;
	ArrayIterator<GroceryItem> next(_item);
	while (next)
	{
		total += next().computeCost();
		next++;
	}
	return total;
}


void GroceryList::addItem(const GroceryItem &newItem)
{
	_item.insertItem(newItem);
}

void GroceryList::print(ostream & out)
{

	ArrayIterator<GroceryItem> next(_item);
    int count = 0;
	while (next)
	{
        out<<++count<<"  ";
		next().print(out);
		out<<endl<<endl;
		next++;
	}
   //out<<'\0';//needed since we are actually creating a string here
}
void GroceryList::write(ostream &out)
{

	ArrayIterator<GroceryItem> next(_item);
	out<<_item.numberInArray()<<endl;
	while (next)
	{
		next().write(out);
		next++;
	}
   // This is not a string, so no terminator included.
}
void GroceryList::read(istream &in)
{
	int size;
	in>> size;
	for(int i = 0;i<size;i++)
	{
		GroceryItem oneItem;
		oneItem.read(in);
		addItem(oneItem);
	}
}

void GroceryList::clearList()
{
	_item.clearArray();
}
