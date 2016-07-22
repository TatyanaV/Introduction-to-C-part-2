
#pragma hdrstop
#include <condefs.h>


//---------------------------------------------------------------------------
#ifndef APPLIC_H
#include "applic.h"
#endif
#include <iostream.h>
//---------------------------------------------------------------------------
USEUNIT("..\..\cppcors99\Exam5e\Menu.cpp");
USEUNIT("..\..\cppcors99\Exam5e\Grocery.cpp");
USEUNIT("..\..\cppcors99\Exam5e\Applic.cpp");
//---------------------------------------------------------------------------
void main()
{
	MyApplication application;
	try
	{
		application.run();
	}
	catch (char * mess)
	{
		cerr<<mess;
	}
}
