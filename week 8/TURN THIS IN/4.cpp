
#include<iostream>
#include<cstdlib>
#include<string>
#include <ctime>
#include <ctype.h>

using std::cin;
using std::endl;
using std::cout;
using std::string;
/************************************************
** Function: void integerCheck(int &integer)
** Description: function to make sure that int was intered
*************************************************/
void integerCheck(int &integer);

class CREATURE{
protected:
	string name;//name of the charector
	int atackNumberOfDiceRoles;//number of dices for attack
	int atackDiceSides;//Dice sides for attack
	double armor;
	int defenceNumberOfDiceRoles;//number of dices for defence
	int defenceDiceSides;//Dice sides for defence
	double damage;
//	int poisonVials;//for venom
public:
	double getarmor();
	virtual double attack()=0; // PURE virtual function
	double deffence();
	double getdamage();
	string getname();
};

class CHARECTOR:public CREATURE{
protected:
    int poisonVials;//for venom
	double spinach;
	double strength;//dynamically change strength power
	double ststore;// this variable will be used to calculate the % of the strenght points left
public:
/************************************************
** Function: int getarmor()
** Description: function that will return armor points
*************************************************/
	double getarmor(){return(armor);}

/************************************************
** Function: int getstrength()
** Description: function that will return strength points
*************************************************/
	double getstrength(){return(strength);}

/************************************************
** Function: void setstrength(int s){
** Description: function that will set strength points
** if the stren
*************************************************/
    void setstrength(double strength2){
    strength=strength2;
    }

/************************************************
** Function: int attack()
** Description: function that will calculate attack points
*************************************************/
	//virtual function
    virtual double attack(){
        double sum=0;
        int randomAttackPoints;// variable to keep track of atack points
        cout << endl << name << " - attack ";// will display a message who is attacking
        for(int i=0; i<atackNumberOfDiceRoles; i++){// the dice will be rolled as many times as indicated for each character
            randomAttackPoints = rand()%atackDiceSides + 1; // the values of atack will be between 1 and sides of atack points
            cout << randomAttackPoints << " ";// message that will display how many atack points are generated
            sum+=randomAttackPoints;
        }
        sum = static_cast<double>(sum);
        cout<<"Sum of ATTACK points: " << sum << endl;// message that will indicate total attack points

		return(sum);
    }

/************************************************
** Function: deffence(){
** Description: function that will calculate deffence points
*************************************************/
    double deffence(){
       double sum=0;
        double randomDeffencePoints;// variable to keep track of deffence points
        cout << endl << name << " - defence ";// will display a message who is defending
        for(int i=0; i<defenceNumberOfDiceRoles; i++){// the dice will be rolled as many times as indicated for each character
        randomDeffencePoints = rand()%defenceDiceSides+1;// the values of defence will be between 1 and sides of defence points
            cout << randomDeffencePoints << " "; // message that will display how many defence points are generated
            sum+=randomDeffencePoints;
        }
        cout<<"Sum of DEFFENCE points: "<<sum<<endl;// message that will indicate total defence points

		return(sum);
    }
/************************************************
** Function: int getstnstore()
** Description: function that returns strength points
*************************************************/
    double getstnstore(){return(ststore);}
/************************************************
** Function: int getdamage()
** Description: function that returns damage points
*************************************************/
    double getdamage(){return(damage);}
/************************************************
** Function: string getname(
** Description: function that returns name of the character
*************************************************/
string getname(){return(name);}

/************************************************
** Function: double getSpinach(){return(spinach);}
** Description: function that returns spinach
*************************************************/
double getSpinach(){return(spinach);}
/************************************************
** Function: virtual double defencePoisoned()
** Description: function that will calculate deffence points
if poison is used
*************************************************/
virtual double defencePoisoned()= 0;
/************************************************
** Function: double getPoison()
** Description: function that returns # of vials
if mega man uses poison
*************************************************/
double getPoison(){return(poisonVials);}
/************************************************
** Function: virtual void setPoison()
** Description: function that updates  number of
poison vials
*************************************************/
virtual void setPoison(){  }; // endl of class character

};

///CLASS GOBLIN
class Goblin:public CHARECTOR{
public:
	Goblin(){name="Goblin";spinach=3;armor=3;strength=ststore=8;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=1;defenceDiceSides=6;}
/************************************************
** Function: virtual double defencePoisoned()
** Description: function that will calculate deffence points of GOLBIN
if poison is used by mega man
OVERRIDING
*************************************************/
    virtual double defencePoisoned(){
        double poisonedDefense;
        poisonedDefense = deffence();
        poisonedDefense = 0.1 *poisonedDefense;
        cout<<"Sum of POISONED DEFENSE points: " << poisonedDefense << endl;// message that will indicate total attack points
		return(poisonedDefense);
    }
};

///CLASS BARBARIAN
class Barbarian:public CHARECTOR{
public:
	Barbarian(){name="Barbarian";spinach=3;armor=0;strength=ststore=12;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=2;defenceDiceSides=6;}
/************************************************
** Function: virtual double defencePoisoned()
** Description: function that will calculate deffence points of Barbarian
if poison is used by mega man
OVERRIDING
*************************************************/
    virtual double defencePoisoned(){
        double poisonedDefense;
        poisonedDefense = deffence();
        poisonedDefense = 0.2 *poisonedDefense;
        cout<<"Sum of POISONED DEFENSE points: " << poisonedDefense << endl;// message that will indicate total attack points
		return(poisonedDefense);
    }
};

///CLASS REPTILEPEOPLE
class ReptilePeople:public CHARECTOR{
public:
	ReptilePeople(){name="ReptilePeople";spinach=3;armor=7;strength=ststore=18;atackNumberOfDiceRoles=3;atackDiceSides=6;defenceNumberOfDiceRoles=1;defenceDiceSides=6;}
/************************************************
** Function: virtual double defencePoisoned()
** Description: function that will calculate deffence points of REPLITE
if poison is used by mega man
OVERIDING
*************************************************/
    virtual double defencePoisoned(){
        double poisonedDefense;
        poisonedDefense = deffence();
        poisonedDefense = 0.3 *poisonedDefense;
        cout<<"Sum of POISONED DEFENSE points: " << poisonedDefense << endl;// message that will indicate total attack points
		return(poisonedDefense);
        }
};
///CLASS BLUEMEN
class BlueMen:public CHARECTOR{
public:
	BlueMen(){name="BlueMen";spinach=3;armor=3;strength=ststore=12;atackNumberOfDiceRoles=2;atackDiceSides=10;defenceNumberOfDiceRoles=3;defenceDiceSides=6;}
/************************************************
** Function: virtual double defencePoisoned()
** Description: function that will calculate deffence points of BLUE MAN
if poison is used by mega man
OVERIDING
*************************************************/
    virtual double defencePoisoned(){
        double poisonedDefense;
        poisonedDefense = deffence();
        poisonedDefense = 0.4 *poisonedDefense;
        cout<<"Sum of POISONED DEFENSE points : " << poisonedDefense << endl;// message that will indicate total attack points
		return(poisonedDefense);
        }

};

//CLASS MEGAMAN
class MegaMan:public Barbarian{

public:
	MegaMan(){name="MegaMan"; poisonVials=2;armor=0;strength=ststore=12;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=2;defenceDiceSides=6;}
    //redefining(
/************************************************
** Function: deffence(){
** Description: function that will calculate deffence points OF TH
MEGA MAN. there is another ranomd # introduced. If randome # is
>50, than sum will be the deffence, if its not >50, sum/2 will
be the deffence points
REDEFINING
*************************************************/
    double deffence(){
        double sum=0;
        int randomDeffencePoints;// variable to keep track of deffence points
        cout << endl << name << " - defence ";// will display a message who is defending

        for(int i=0; i<defenceNumberOfDiceRoles; i++){// the dice will be rolled as many times as indicated for each character
        randomDeffencePoints = rand()%defenceDiceSides+1;// the values of defence will be between 1 and sides of defence points
            cout << randomDeffencePoints << " "; // message that will display how many defence points are generated
            sum+=randomDeffencePoints;
        }
         if ((rand()%100 +1) >50){
             sum = sum;
         }
         else{
                sum = sum/2;
         }
        cout<<"Sum of Mega Man Deffence points: "<<sum<<endl;// message that will indicate total defence points
		return(sum);
    }
/************************************************
** Function:  virtual void setPoison()
** Description: function that will decrement vials
of poison, if the mega man decides to use it
OVERIDING
*************************************************/
    virtual void setPoison(){
        int poisonVials1;
        poisonVials--;
        poisonVials1= poisonVials;}
    };



//CLASS SAKTIMAN
class SaktiMan:public Goblin{
private:
	double venom;
public:
	SaktiMan(){name="SaktiMan";venom=4;armor=3;strength=ststore=8;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=1;defenceDiceSides=6;}
	//overridding
/************************************************
** Function: double attack()
** Description: function that will calculate attack points of the Sakti Man
** satki man has a venom that will be automatically added to the attack points
OVERIDING
*************************************************/
    double attack(){
        double sum=0;
        double randomAttackPoints;// variable to keep track of atack points
        cout << endl << name << " - attack ";// will display a message who is attacking
        for(int i=0; i<atackNumberOfDiceRoles; i++){// the dice will be rolled as many times as indicated for each character
            randomAttackPoints = rand()%atackDiceSides + 1; // the values of atack will be between 1 and sides of atack points
            cout << randomAttackPoints << " ";// message that will display how many atack points are generated
            sum+=randomAttackPoints;
        }
        cout<<"Sum of Sakti Man attack points: " << sum <<"+ Venom : "<< venom<<"Total"<<(sum+venom) <<endl;// message that will indicate total attack points
		sum=sum+venom;
        return(sum);
    }
/************************************************
** Function: double getVenom()
** Description: function that will display how much venom was added
to the attack
*************************************************/
	double getVenom(){return(venom);}
};
//CLASS ENCHANTEDHOBBIT for double damage
class EnchantedHobbit{
private:
	double doubleDamage;
public:
	EnchantedHobbit(){doubleDamage=2;}
/************************************************
** Function: double getEnchantedHobbit()
** Description: funcion will increase attack by a
factor of 2, when spinach is used
*************************************************/
	double getEnchantedHobbit(){return(doubleDamage);}
};

/************************************************
** Function: void displayChart(){
** Description: displays chart with the statistics
** of each character
*************************************************/
void displayChart(){
	    cout<<"\t\t\tSimple Combat Game\n\nYour Universe :-\n\n";
		cout<<"\tTYPE\tATTACK\tDEFENSE\tARMOR\tSTRENGTH\tPOISON VIALS\tVENOM\n\n";
		cout<<"      Goblin      2d6     1d6      3          8          0          0\n";
		cout<<"     Barbarian    2d6     1d6      0         12          0          0\n";
		cout<<"   Reptile People 3d6     1d6      7         18          0          0\n";
		cout<<"     Blue Men     2d10    3d6      3         12          0          0\n";
		cout<<"     SaktiMan     2d6     1d6      3          8          0          4\n";
		cout<<"     MegaMan      2d6     1d6      0         12          2          0\n\n\n";
}

/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered
*************************************************/
int integerCheck (string INPUT, int min, int max);
/************************************************
** Function: void combat()T
** Description:Function of the combat
*************************************************/
void combat(){
     srand(time(0));
    //creating object for each character
	//my combad
	Goblin goblin1;
	Barbarian barbarian1;
	ReptilePeople reptile1;
	BlueMen blueMen1;
	SaktiMan saktiMan1;
	MegaMan megaMan1;
	//enemy combad
    Goblin goblin2;
	Barbarian barbarian2;
	ReptilePeople reptile2;
	BlueMen blueMen2;
	SaktiMan saktiMan2;
	MegaMan megaMan2;
	CHARECTOR *player,*enemy; // creates 2 character pointers
	EnchantedHobbit e;// create enchanted object
	displayChart();
	cout<< endl << "Choose your figher class. " << endl;
    cout<< "1. Golbin\n2. Barbarian\n3. Reprile\n4. Blue Man\n5. Sakti Man\n6. Mega Man" << endl;
    int result;
    do{
    string entered;
    getline(cin,entered);
    result = integerCheck(entered, 1, 6);
    //choose for player
	switch(result){
        case 1:
            player=&goblin1;
           break;
        case 2:
            player =&barbarian1;
            break;
        case 3:
            player = &reptile1;
            break;
        case 4:
            player = &blueMen1;
            break;
		case 5:
			player=&saktiMan1;
			break;
		case 6:
			player=&megaMan1;
			break;
        default:
            cout << "INVALID ENTRY!! Please chose an option 1-6." <<endl;
}
    }while (result > 6 || result < 1);
    cout<< endl << "Choose your enemy class. " << endl;
    cout<< "1. Golbin\n2. Barbarian\n3. Reprile\n4. Blue Man\n5. Sakti Man\n6. Mega Man" << endl;
//chose an enemy
	int result1;
    string entered1;
    getline(cin,entered1);
    result1 = integerCheck(entered1, 1, 6);
    //choose for enemy
    do{
	switch(result1){
        case 1:
            enemy=&goblin2;
           break;
        case 2:
            enemy =&barbarian2;
            break;
        case 3:
            enemy = &reptile2;
            break;
        case 4:
            enemy = &blueMen2;
			break;
		case 5:
			enemy=&saktiMan2;
			break;
		case 6:
			enemy=&megaMan2;
			break;
        default:
            cout << "INVALID ENTRY!! Please chose an option 1-6." <<endl;
}
    }while (result1 > 6 || result1 < 1);

    char choice;// takes the user input for charector 'f'
	string selectionPlayer="",selectionEnemy="";// will be used to display which charactes are selected
    double enemyNewStrength=0,playerNewStrength=0;

	for(;;){
	    cout <<"PLAYER STATISTICS: " <<"\t\t\t" <<"ENEMY STATISTICS: " << endl;
        cout<<player->getname()<<": "<<double(player->getstrength()*100/player->getstnstore())
            <<"%\t\t\t\t" <<enemy->getname()<<": "<<double(enemy->getstrength()*100/enemy->getstnstore())<<"%\n";
        //displays strenght points
        cout<<player->getname()<<": Strength: "<<player->getstrength()<<"/"<<player->getstnstore()<<"\t\t"
            <<enemy->getname()<<" :Strength: "<<enemy->getstrength()<<"/"<<enemy->getstnstore();
        //if enemy ran out of energy
        if(enemy->getstrength()==0 || enemy->getstrength() <0 ){
            cout<<"\n\n\nYOU WON THIS GAME." <<endl;
            break;
        }
    //if user  ran out of energy
    if(player->getstrength()==0 || player->getstrength() < 0 ){
        cout<<"\n\n\nYOUR LOST THIS GAME" <<endl;
        break;
    }
    // keeps asking the user to enter f for fight untill someone runs out of health
    cout<<"\n\nPress F for fight ";
    do{
        cin>> choice;
        if(choice!='F'){// if the user enteres something else:
        cout<<"\nWrong input .(Press F)";
        }
    }while(choice!='F');
    // player is attacking and enemy is defending

	cout << endl <<endl<< player->getname() << " is attacking and " << enemy->getname() << " is defending: " <<endl;
	double netAttackPoints;
	cout<<"Do you need spinach (Y|N): ";
	char c;
	do{
	cin>>c;
	if(c!='Y' && c!='N'){cout<<"\nWrong Input put(Y|N)";}
	if(c=='Y'){netAttackPoints=player->getSpinach()*player->attack();}
	if(c=='N'){netAttackPoints=player->attack();}
	}while(c!='Y' && c!='N');
    double def;
        ///MEGA MAN CAN USE POISON TO REDUCE THE DEFENCE OF THE ENEMY
    if (player == &megaMan1 && player->getPoison()!=0) {
    cout << endl <<"Do you want to use poison? (Y|N): ";
    char answer;
	do{
	cin>>answer;
	if(answer!='Y' && answer!='N'){cout<<"\nWrong Input put(Y|N)";}
	if(answer=='Y'){
	    if (player->getPoison()>0){
            def=enemy->defencePoisoned();
            player->setPoison();
            cout<< "Poison vial left: " << player->getPoison() <<endl;
        }
        else{
            cout<< "You are out of venom you cannot attack with venom any more." <<endl;
            break;
        }
	}
	if(answer=='N'){def=enemy->deffence();}
	}while(answer!='Y' && answer!='N');
    }

    else {def=enemy->deffence();}

	cout << endl<< "Attack - damage is " << netAttackPoints << " - " << def;
	netAttackPoints=netAttackPoints-def;
	cout<<"="<<netAttackPoints;
	cout << endl<< "Total damage - armor is " << netAttackPoints << " - " << enemy->getarmor();
    netAttackPoints= netAttackPoints - enemy->getarmor();
    cout << " = " << netAttackPoints <<endl;

	//system("pause");
    cout << "Please note that if TOTAL DAMAGE IS < 0,"<<endl
        << "this might happend when armore points exceed damage,"<<endl
        << "the TOTAL DAMAGE will be set to 0. " <<endl;
    // if damage is less than armor, net attack will be negative.
    //this does not make sense. so if netatack is negative, it will be set to 0.
    if(netAttackPoints<0){
        netAttackPoints=0;
    }

	cout<<endl<<"Do you add enchanted weapons (Y|N): ";
	do{
	cin>>c;
	if(c!='Y' && c!='N'){cout<<"\nWrong Input put(Y|N)";}
	if(c=='Y'){
            netAttackPoints=netAttackPoints*e.getEnchantedHobbit();
	        playerNewStrength=player->getstrength()-1; // if enchanted weapon is used 1 point from the strength is deducted
            if(playerNewStrength<0){playerNewStrength=0;}//set 0 for -ve strength
            player->setstrength(playerNewStrength);

	    }
	if(c=='N'){netAttackPoints=netAttackPoints;}
	}while(c!='Y' && c!='N');

    cout << "\nTOTAL DAMAGE : " << netAttackPoints <<endl;
///////////////////////////////////////////////////////////////////////
    enemyNewStrength=enemy->getstrength()-netAttackPoints;
	if(enemyNewStrength<0){enemyNewStrength=0;}//set 0 for -ve strength
    enemy->setstrength(enemyNewStrength) ;
    /// ENEMIES TURN
    //now enemy is atacking and player is defending
    cout <<endl<<endl << enemy->getname() << " is attacking and " << player->getname() << " is defending: " <<endl;
	netAttackPoints=enemy->attack();

    ///MEGA MAN CAN USE POISON TO REDUCE THE DEFENCE OF THE ENEMY
    if (enemy == &megaMan1 && enemy->getPoison()!=0) {
    cout << endl<<"Do you want to use poison? " <<endl;
    char answer1;
	do{
	cin>>answer1;
	if(answer1!='Y' && answer1!='N'){cout<<"\nWrong Input put(Y|N)";}
	if(answer1=='Y'){
	    if (enemy->getPoison() >0){
            def=player->defencePoisoned();
            enemy->setPoison();
            cout<< "Poison vial left: " << enemy->getPoison() <<endl;
              }
        else{
            cout<< "You are out of venom you cannot attack with venom any more." <<endl;
            break;
        }
    }
	if(answer1=='N'){def=player->deffence();}
	}while(answer1!='Y' && answer1!='N');
    }

    else {def=player->deffence();}

	cout << endl<< "Attack - damage is " << netAttackPoints << " - " << def;
	netAttackPoints=netAttackPoints-def;
	cout<<"="<<netAttackPoints;
	cout << endl<< "Total damage - armor is " << netAttackPoints << " - " << player->getarmor();
    netAttackPoints= netAttackPoints - player->getarmor();
    cout << " = " << netAttackPoints <<endl;
	//system("pause");
    cout << "Please note that if TOTAL DAMAGE IS < 0," <<endl
        << "this might happend when armore points exceed damage,"<<endl
        << "the TOTAL DAMAGE will be set to 0. " <<endl;
    // if damage is less than armor, net attack will be negative.
    //this does not make sense. so if netatack is negative, it will be set to 0.

    if(netAttackPoints<0){
        netAttackPoints=0;
    }

    playerNewStrength=player->getstrength()-netAttackPoints;
	if(playerNewStrength<0){playerNewStrength=0;}//set 0 for -ve strength
	/////////////////////////////////////////////
    player->setstrength(playerNewStrength);
    //system("pause");
    }
}


///MAIN METHOD
int main(){
    combat();
	return(0);
}

/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered
*************************************************/
int integerCheck (string INPUT, int min, int max){
	int isanint = 'n'; // is it an integer loop condition
	int x; // used in the loop
	int isok ; // used to test for integer
	int NUM; // the integer to be returned
// test to yes if it is an int
				isanint = 'n';
				while (isanint == 'n')
					{
						isok = 1;
						for (x=0; x < INPUT.length(); x=x+1)
							{
// check for digits
								if (((INPUT.at(x) >= '0' && INPUT.at(x) <= '9')))
									{
										isok = 1;
									}
								else
								 	{
// flag as bad and set exit
								 		isok = 0;
								 		x = INPUT.length();
								 	}
							}

/// if it did not pass the test for integer
				if ( isok == 0)
					{	cout << endl<<"That was NOT an integer or integer was <1." << endl;
						cout << "Please enter an integer between: " <<min << " - " << max <<" inclusive: " ;
						getline(cin,INPUT);
						cout << endl;
					}
				else
					{
						NUM = atoi(INPUT.c_str());
						isanint = 'y';
						isok = 1;
					}
			}
 	return NUM;
}



void integerCheck(int &integer){
    while(cin.fail() ||!cin.good()|| integer!= static_cast<int>(integer) || integer <=0)
    {
        cout << "Error, invalid  enetered.  " << endl
             << "Pease make a different entry: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin.sync ();
        cin >> integer;
        cout << integer;
        }
}



