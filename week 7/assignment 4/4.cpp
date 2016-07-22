
#include<iostream>
#include<cstdlib>
#include<string>
//#include<conio.h>
#include <ctime>
#include <ctype.h>

//using namespace std;
using std::cin;
using std::endl;
using std::cout;
using std::string;
class CHARECTOR{
protected:
	string name;
	int atackNumberOfDiceRoles;
	int atackDiceSides;
	int armor;
	int defenceNumberOfDiceRoles;
	int defenceDiceSides;
	int damage;
	int strength;
	int ststore;// this variable will be used to calculate the % of the strenght points left
public:
/************************************************
** Function: int getarmor()
** Description: function that will return armor points
*************************************************/
	int getarmor(){return(armor);}

/************************************************
** Function: int getstrength()
** Description: function that will return strength points
*************************************************/
	int getstrength(){return(strength);}

/************************************************
** Function: void setstrength(int s){
** Description: function that will set strength points
** if the stren
*************************************************/
    void setstrength(int strength2){
    strength=strength2;
    }

/************************************************
** Function: int attack()
** Description: function that will calculate attack points
*************************************************/
    int attack(){
        int sum=0;
        int randomAttackPoints;// variable to keep track of atack points
        cout << endl << name << " - attack ";// will display a message who is attacking
        for(int i=0; i<atackNumberOfDiceRoles; i++){// the dice will be rolled as many times as indicated for each character
            randomAttackPoints = rand()%atackDiceSides + 1; // the values of atack will be between 1 and sides of atack points
            cout << randomAttackPoints << " ";// message that will display how many atack points are generated
            sum+=randomAttackPoints;
        }
        cout<<"Sum : " << sum << endl;// message that will indicate total attack points
        return(sum);
    }

/************************************************
** Function: deffence(){
** Description: function that will calculate deffence points
*************************************************/
    int deffence(){
        int sum=0;
        int randomDeffencePoints;// variable to keep track of deffence points
        cout << endl << name << " - defence ";// will display a message who is defending
        for(int i=0; i<defenceNumberOfDiceRoles; i++){// the dice will be rolled as many times as indicated for each character
        randomDeffencePoints = rand()%defenceDiceSides+1;// the values of defence will be between 1 and sides of defence points
            cout << randomDeffencePoints << " "; // message that will display how many defence points are generated
            sum+=randomDeffencePoints;
        }
        cout<<"Sum : "<<sum<<endl;// message that will indicate total defence points
        return(sum);
    }
/************************************************
** Function: int getstnstore()
** Description: function that returns strength points
*************************************************/
    int getstnstore(){return(ststore);}
/************************************************
** Function: int getdamage()
** Description: function that returns damage points
*************************************************/
    int getdamage(){return(damage);}
/************************************************
** Function: string getname(
** Description: function that returns name of the character
*************************************************/
string getname(){return(name);}
}; // endl of class character


///CLASS GOBLIN
class Goblin:public CHARECTOR{
public:
	Goblin(){name="Goblin";armor=3;strength=ststore=8;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=1;defenceDiceSides=6;}
};
///CLASS BARBARIAN
class Barbarian:public CHARECTOR{
public:
	Barbarian(){name="Barbarian";armor=0;strength=ststore=12;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=2;defenceDiceSides=6;}
};
///CLASS REPTILEPEOPLE
class ReptilePeople:public CHARECTOR{
public:
	ReptilePeople(){name="ReptilePeople";armor=7;strength=ststore=18;atackNumberOfDiceRoles=3;atackDiceSides=6;defenceNumberOfDiceRoles=1;defenceDiceSides=6;}
};
///CLASS BLUEMEN
class BlueMen:public CHARECTOR{
public:
	BlueMen(){name="BlueMen";armor=3;strength=ststore=12;atackNumberOfDiceRoles=2;atackDiceSides=10;defenceNumberOfDiceRoles=3;defenceDiceSides=6;}
};

/************************************************
** Function: void displayChart(){
** Description: displays chart with the statistics
** of each character
*************************************************/
void displayChart(){
	    cout<<"\t\t\tSimple Combat Game\n\nYour Universe :-\n\n";
		cout<<"\t\tTYPE\tATTACK\tDEFENSE\tARMOR\tSTRENGTH POINTS\n\n";
		cout<<"\t       Goblin     2d6     1d6      3          8\n";
		cout<<"\t     Barbarian    2d6     1d6      0         12\n";
		cout<<"\t   Reptile People 3d6     1d6      7         18\n";
		cout<<"\t     Blue Men     2d10    3d6      3         12\n\n\n";
}

/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered
*************************************************/
int integerCheck (string INPUT, int min, int max);


///MAIN METHOD
int main(){
    srand(time(0));
    //creating object for each character
	Goblin goblin1;
	Barbarian barbarian1;
	ReptilePeople reptile1;
	BlueMen blueMen1;
    Goblin goblin2;
	Barbarian barbarian2;
	ReptilePeople reptile2;
	BlueMen blueMen2;
	CHARECTOR player,enemy; // creates 2 character objects
	displayChart();
    cout<< endl << "Choose your figher class. " << endl;
    cout<< "1. Golbin." << endl << "2. Barbarian "<<endl << "3. Reprile" << endl << "4. Blue Man " << endl;
    int result;
    string entered;
    getline(cin,entered);
    result = integerCheck(entered, 1, 4);
    switch(result){
        case 1:
            player=goblin1;
           break;
        case 2:
            player =barbarian1;
            break;
        case 3:
            player = reptile1;
            break;
        case 4:
            player = blueMen1;
            break;
}
    cout<< endl << "Choose your enemy class. " << endl;
    cout<< "1. Golbin." << endl << "2. Barbarian "<<endl << "3. Reprile" << endl << "4. Blue Man " << endl;
    int result1;
    string entered1;
    getline(cin,entered1);
    result1 = integerCheck(entered1, 1, 4);
    switch(result1){
        case 1:
            enemy=goblin2;
           break;
        case 2:
            enemy =barbarian2;
            break;
        case 3:
            enemy = reptile2;
            break;
        case 4:
            enemy = blueMen2;
        break;
    }

    char choice;// takes the user input  only z,x and f will be accepted
	string selectionPlayer="",selectionEnemy="";// will be used to display which charactes are selected
    int enemyNewStrength=0,playerNewStrength=0;
    for(;;){
        cout <<"PLAYER STATISTICS: " <<"\t\t\t" <<"ENEMY STATISTICS: " << endl;
        cout<<player.getname()<<": "<<int(player.getstrength()*100/player.getstnstore())
            <<"%\t\t\t\t" <<enemy.getname()<<": "<<int(enemy.getstrength()*100/enemy.getstnstore())<<"%\n";
        //displays strenght points
        cout<<player.getname()<<": Strength: "<<player.getstrength()<<"/"<<player.getstnstore()<<"\t\t\t"
            <<enemy.getname()<<" :Strength: "<<enemy.getstrength()<<"/"<<enemy.getstnstore();
        //if enemy ran out of energy
        if(enemy.getstrength()==0 || enemy.getstrength() <0 ){
            cout<<"\n\n\nYOU WON THIS GAME." <<endl;
            std::cin.get();
            std::cin.get();
            break;
        }
    //if user  ran out of energy
    if(player.getstrength()==0 || player.getstrength() < 0 ){
        cout<<"\n\n\nYOUR LOST THIS GAME" <<endl;
        break;
    }
    // keeps asking the user to enter f for fight untill someone runs out of health
    cout<<"\n\nPress f for fight ";
    do{
        choice=std::cin.get();
        if(choice!='f'){// if the user enteres something else:
        cout<<"\nWrong input .(Press f)";
        }
    }while(choice!='f');
    // player is attacking and enemy is defending
    cout << endl <<endl<< player.getname() << " is attacking and " << enemy.getname() << " is defending: " <<endl;
    int netAttackPoints=player.attack()-enemy.deffence();
    cout << endl<< "Total damage - armor is " << netAttackPoints << " - " << enemy.getarmor();
    netAttackPoints= netAttackPoints - enemy.getarmor();
    cout << " = " << netAttackPoints <<endl;
    cout << "Please note that if TOTAL DAMAGE IS < 0,"<<endl
        << "this might happend when armore points exceed damage,"<<endl
        << "the TOTAL DAMAGE will be set to 0. " <<endl;
    // if damage is less than armor, net attack will be negative.
    //this does not make sense. so if netatack is negative, it will be set to 0.
    if(netAttackPoints<0){
        netAttackPoints=0;
    }
    enemyNewStrength=enemy.getstrength()-netAttackPoints;
    enemy.setstrength(enemyNewStrength) ;
    //now enemy is atacking and player is defending
    cout <<endl<<endl << enemy.getname() << " is attacking and " << player.getname() << " is defending: " <<endl;
    cout <<"Press Enter" <<endl;
    std::cin.get();
    netAttackPoints=enemy.attack()-player.deffence();
    cout << endl<<"Total damage - armor is " << netAttackPoints << " - " << player.getarmor();
    netAttackPoints= netAttackPoints - player.getarmor();
    cout << " = " << netAttackPoints <<endl;
    cout << "Please note that if TOTAL DAMAGE IS < 0," <<endl
        << "this might happend when armore points exceed damage,"<<endl
        << "the TOTAL DAMAGE will be set to 0. " <<endl;
    cout<< "Prease press enter";
    // if damage is less than armor, net attack will be negative.
    //this does not make sense. so if netatack is negative, it will be set to 0.
    if(netAttackPoints<0){
        netAttackPoints=0;
    }
    playerNewStrength=player.getstrength()-netAttackPoints;
    player.setstrength(playerNewStrength);
    std::cin.get();

    }
    //resets strength for each character
    goblin1.setstrength(goblin1.getstnstore());
    barbarian1.setstrength(goblin1.getstnstore());
    reptile1.setstrength(goblin1.getstnstore());
    blueMen1.setstrength(goblin1.getstnstore());
    goblin2.setstrength(goblin2.getstnstore());
    barbarian2.setstrength(goblin2.getstnstore());
    reptile2.setstrength(goblin2.getstnstore());
    blueMen2.setstrength(goblin2.getstnstore());
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


