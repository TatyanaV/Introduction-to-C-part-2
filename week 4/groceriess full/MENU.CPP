#ifndef MENU_H
#include "menu.h"
#endif

void Menu::setChoices(int sz,const StringArray &s)
{
	StringArray temp(s);
	size = sz;
	choices = temp;
}

void Menu::showChoices()const
{
	for (int i = 0;i< size;i++)
		cout<<i<<' '<< choices[i]<<endl;
}

int Menu::readChoice()const
{
	string in;
	int val=0;
	cin>>in;
	in += " ";
	int i = 0;
	while (in[i] == ' ')
		i++;
	int sign = 1;//change to -1 if negative number
	if (in[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (in[i] == '+')
		i++;
	for (;i< in.length();i++)
	{
		if (in[i] ==' ')
			break;
		if (in[i]<'0' || in[i]>'9')
			return -1;
		val = 10*val + (in[i] - '0');
	}
   val *= sign;
	if (val >= 0 && val<= size)
		return val;
	else
		return  -1;
}

int Menu::makeChoice()const
{
	int ans; //value that is returned
	int ok = 0; //is the choice legal?
	do
	{
		cout<<"\nChoices\n";
		showChoices();
		cout<<endl<<"Enter the number of your choice ";
		ans = readChoice();
		if (ans >=0 && ans< size)
			ok =1; //legal choice
		else
			cout <<endl<<"*** please reenter using only numbers listed\n";
	} while(ok ==0);

	return ans;
}

