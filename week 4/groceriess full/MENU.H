#ifndef MENU_H
#define MENU_H
#endif

#ifndef __IOSTREAM_H
#include <iostream.h>
#endif

#ifndef DARRAY_H
#include "../darray.h"
#endif


#ifndef __CSTRING_H
#include <cstring.h>
#endif

typedef Array<string> StringArray;

class Menu
{
public:
	Menu(){}
	Menu(const StringArray &s):choices(s){size = s.numberInArray();}
	int makeChoice()const;
	void setChoices(int sz,const StringArray &s);
private:
	void showChoices()const;
	int readChoice()const;
	StringArray choices;
	int size;
};
