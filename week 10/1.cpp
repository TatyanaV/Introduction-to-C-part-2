#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<list>
#include <ctime>

//using namespace std;
using std::cin;
using std::endl;
using std::cout;
using std::string;
int integerCheck (string INPUT, int min, int max);
void integerCheck(int &integer);
void newLine();
class CREATURE{
protected:
	string name;//name of the charector
	int atackNumberOfDiceRoles;//number of dices for attack
	int atackDiceSides;//Dice sides for attack
	int armor;
	int defenceNumberOfDiceRoles;//number of dices for defence
	int defenceDiceSides;//Dice sides for defence
	int damage;
public:
	int getarmor();
	virtual int attack()=0;
	int deffence();
	int getdamage();
	string getname();
};
class CHARECTOR:public CREATURE{
protected:
	int spinach;
	int strength;//dynamically change strength power
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
	//virtual function
    virtual int attack(){
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

int getSpinach(){return(spinach);}
}; // endl of class character

///CLASS GOBLIN
class Goblin:public CHARECTOR{
public:
	Goblin(){name="Goblin";spinach=3;armor=3;strength=ststore=8;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=1;defenceDiceSides=6;}

};
///CLASS BARBARIAN
class Barbarian:public CHARECTOR{
public:
	Barbarian(){name="Barbarian";spinach=3;armor=0;strength=ststore=12;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=2;defenceDiceSides=6;}
};
///CLASS REPTILEPEOPLE
class ReptilePeople:public CHARECTOR{
public:
	ReptilePeople(){name="ReptilePeople";spinach=3;armor=7;strength=ststore=18;atackNumberOfDiceRoles=3;atackDiceSides=6;defenceNumberOfDiceRoles=1;defenceDiceSides=6;}
};
///CLASS BLUEMEN
class BlueMen:public CHARECTOR{
public:
	BlueMen(){name="BlueMen";spinach=3;armor=3;strength=ststore=12;atackNumberOfDiceRoles=2;atackDiceSides=10;defenceNumberOfDiceRoles=3;defenceDiceSides=6;}
};
//CLASS MEGAMAN
class MegaMan:public Barbarian{
private:
	int venom;//for venom
public:
	MegaMan(){name="MegaMan";venom=5;armor=0;strength=ststore=12;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=2;defenceDiceSides=6;}
	//overridding
	int attack(){
	        int sum=0;
	        int randomAttackPoints;// variable to keep track of atack points
	        cout << endl << name << " - attack ";// will display a message who is attacking
	        for(int i=0; i<atackNumberOfDiceRoles; i++){// the dice will be rolled as many times as indicated for each character
	            randomAttackPoints = rand()%atackDiceSides + 1; // the values of atack will be between 1 and sides of atack points
	            cout << randomAttackPoints << " ";// message that will display how many atack points are generated
	            sum+=randomAttackPoints;
	        }
	       cout<<"Sum : " << sum <<"+ Venom : "<< venom<<"Total"<<(sum+venom) <<endl;// message that will indicate total attack points
	       sum=sum+venom;
	       return(sum);
	}
	int getVenom(){return(venom);}
};
//CLASS SAKTIMAN
class SaktiMan:public Goblin{
private:
	int venom;
public:
	SaktiMan(){name="SaktiMan";venom=4;armor=3;strength=ststore=8;atackNumberOfDiceRoles=2;atackDiceSides=6;defenceNumberOfDiceRoles=1;defenceDiceSides=6;}
	//overridding
	int attack(){
	        int sum=0;
	        int randomAttackPoints;// variable to keep track of atack points
	        cout << endl << name << " - attack ";// will display a message who is attacking
	        for(int i=0; i<atackNumberOfDiceRoles; i++){// the dice will be rolled as many times as indicated for each character
	            randomAttackPoints = rand()%atackDiceSides + 1; // the values of atack will be between 1 and sides of atack points
	            cout << randomAttackPoints << " ";// message that will display how many atack points are generated
	            sum+=randomAttackPoints;
	        }
	        cout<<"Sum : " << sum <<"+ Venom : "<< venom<<"Total"<<(sum+venom) <<endl;// message that will indicate total attack points
      	        sum=sum+venom;
	        return(sum);
	    }

	int getVenom(){return(venom);}
};
//CLASS ENCHANTEDHOBBIT for double damage
class EnchantedHobbit{
private:
	int dbl;
public:
	EnchantedHobbit(){dbl=2;}
	int getEnchantedHobbit(){return(dbl);}
};

/************************************************
** Function: void displayChart(){
** Description: displays chart with the statistics
** of each character
*************************************************/
void displayChart(){
	    cout<<"\t\t\t\tCombat Game\n\nYour Universe :-\n\n";
  	    cout<<"\t\tTYPE\tATTACK\tDEFENSE\tARMOR\tSTRENGTH POINTS\tVENOM\n\n";
	    cout<<"\t       Goblin     2d6     1d6      3          8          0\n";
	    cout<<"\t     Barbarian    2d6     1d6      0         12          0\n";
	    cout<<"\t   Reptile People 3d6     1d6      7         18          0\n";
	    cout<<"\t     Blue Men     2d10    3d6      3         12          0\n";
	    cout<<"\t     SaktiMan     2d6     1d6      3          8          4\n";
	    cout<<"\t     MegaMan      2d6     1d6      0         12          5\n\n\n";
}

/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered
*************************************************/
int integerCheck (string INPUT, char min,char max);

CHARECTOR eachPlayer(){
	Goblin g;
	Barbarian ba;
	ReptilePeople r;
	BlueMen bl;
	SaktiMan s;
	MegaMan m;
	CHARECTOR c;

	cout<< endl << "Choose your figher class. " << endl;
	cout<< "1. Golbin\n2. Barbarian\n3. Reprile\n4. Blue Man\n5. Sakti Man\n6. Mega Man" << endl;
	int result;
	string entered;
	getline(cin,entered);
	result = integerCheck(entered, 1, 6);
	    //choose for player
    //do{
	switch(result){
	        case 1:
	            c=g;
	           break;
	        case 2:
	            c =ba;
	            break;
	        case 3:
	            c = r;
	            break;
	        case 4:
	            c = bl;
	            break;
	        case 5:
	             c=s;
	             break;
	        case 6:
	             c=m;
	            break;
	}

   // }while (result !=1 || result !=2 ||result !=3 ||result !=4 ||result !=5 ||result !=6);

	return(c);
}


class TEAM{
private:
	string name;
	std::vector<CHARECTOR> v;
public:
	TEAM(){}
	TEAM(string n,int no){name=n;}
	void setVec(std::vector<CHARECTOR> x){v=x;}
	string getName(){return(name);}
	void yourTeam(){
		cout<<"\nName : "<<name;
		cout<<"\nCombat Team : ";
		for(int i=0;i<v.size();i++){
		cout<<"["<<v.at(i).getname()<<"] ";
		}
		cout<<endl;
	}
	std::vector<CHARECTOR> getVec(){return(v);}
};

///MAIN METHOD
int main(){

    srand(time(0));
	cout<<"\t\t\t\tTEAM A Vs TEAM B";
	EnchantedHobbit e;
	int num=0;
	cout<<"\nNumber of player in each team : ";
	cin>>num;
	integerCheck(num);
    newLine();
	std::list<CHARECTOR> lt;
	std::vector<char> teamName;
	std::vector<CHARECTOR> v;

	cout<<"Choose Team a Players : \n";
		TEAM team1("Team a",num);//team a
		displayChart();

		for(int j=0;j<num;j++){
			v.push_back(eachPlayer());//add players in 'v'
		}
		team1.setVec(v);// set all players for team a
		v.clear();


	cout<<"Choose Team b Players : \n";
	TEAM team2("Team b",num);//team b
		displayChart();
		for(int j=0;j<num;j++){
			v.push_back(eachPlayer());//add players in 'v'
		}
		team2.setVec(v);//set all players for team b
		v.clear();

	//display all team information
	cout<<"\n\nDisplay Both team :\n\n";
	team1.yourTeam();
	team2.yourTeam();

	//system("pause");
	//firstTeam for team a players and sceoendTeam for team b players
	std::vector<CHARECTOR> firstTeam,sceoendTeam;

	firstTeam=team1.getVec();
	sceoendTeam=team2.getVec();

	CHARECTOR player,enemy;
	int index1,index2;// choose 'index1' for team a player index and 'index2' for team b player index
	int each=0;// use for team in tournament
	char choice;// takes the user input for charector 'f'

	int enemyNewStrength=0,playerNewStrength=0;

	for(;;){
		//system("cls");//clear screen
		v.clear();// here v use for either firstTeam players or sceoendTeam players
		std::vector<CHARECTOR>::iterator it;// a list use for add top 3 players in the tournament

		cout <<team1.getName()<<" STATISTICS: " <<"\t\t\t" <<team2.getName()<<" STATISTICS: " << endl;
        //display all player information

		for(int i=0;i<num;i++){
		    // this will be true at the begining of the game
		    //both teams start with the same number of characters
			if(i<firstTeam.size() && i<sceoendTeam.size()){
                cout<<endl<<firstTeam.at(i).getname()<<": "<<int(firstTeam.at(i).getstrength()*100/firstTeam.at(i).getstnstore())<<"%\t\t\t\t"<<sceoendTeam.at(i).getname()<<": "<<int(sceoendTeam.at(i).getstrength()*100/sceoendTeam.at(i).getstnstore())<<"%\n";
                cout<<firstTeam.at(i).getname()<<": Strength: "<<firstTeam.at(i).getstrength()<<"/"<<firstTeam.at(i).getstnstore()<<"\t\t\t"<<sceoendTeam.at(i).getname()<<" :Strength: "<<sceoendTeam.at(i).getstrength()<<"/"<<sceoendTeam.at(i).getstnstore();
			}

			//as characters loose, they do not have same number of characters any more
			else{
			    //if team A is smaller
				if(firstTeam.size()<sceoendTeam.size()){
                    cout<<endl<<"\t\t\t\t\t\t\t"<<sceoendTeam.at(i).getname()<<": "<<int(sceoendTeam.at(i).getstrength()*100/sceoendTeam.at(i).getstnstore())<<"%\n";
                    cout<<"\t\t\t\t\t\t"<<sceoendTeam.at(i).getname()<<" :Strength: "<<sceoendTeam.at(i).getstrength()<<"/"<<sceoendTeam.at(i).getstnstore();
				}
				//if team B is smaler
				if(firstTeam.size()>sceoendTeam.size()){
                    cout<<endl<<firstTeam.at(i).getname()<<": "<<int(firstTeam.at(i).getstrength()*100/firstTeam.at(i).getstnstore())<<"%\n";
                    cout<<firstTeam.at(i).getname()<<": Strength: "<<firstTeam.at(i).getstrength()<<"/"<<firstTeam.at(i).getstnstore();
				}
			}
		}
		bool ck1;
		//when 'each' is even team a player and team b enemy 'v' store enemy team players
		//when 'each' is odd team b player and team a enemy
		if(each%2==0){v=sceoendTeam;}
		else{v=firstTeam;}

		if(each%2==0){cout<<"\n\n "<<team1.getName() << " STARTS ATTACKING 1ST.";}
		else{cout<<"\n\n "<<team2.getName()<< " STARTS ATTACKING 1ST.";}

		// keeps asking the user to enter f for fight untill someone runs out of health
		cout<<"\n\nPress F for fight ";
		//newLine();
		do{
		    cin>> choice;
		    if(choice!='F'){// if the user enteres something else:
			cout<<"\nWrong input .(Press F)";}
		}while(choice!='F');
		// player is attacking and enemy is defending

		if(each%2==0){
		if(each==0){index1=0;index2=0;}// intially top order player start tuornament

            player=firstTeam.at(index1);
			enemy=sceoendTeam.at(index2);
		}

		else{
			int tmp1=index1,tmp2=index2;
			index1=tmp2;//index for  altering enemy as player from receint fight
			index2=tmp1;//index for  altering player as enemy from receint fight
			player=sceoendTeam.at(index1);
			enemy=firstTeam.at(index2);
		}

		cout << endl <<endl<< player.getname() << " is attacking and " << enemy.getname() << " is defending: " <<endl;
		int netAttackPoints;
		cout<<"Do you need spinach (Y|N): ";

		char c;
		do{cin>>c;
			if(c!='Y' && c!='N'){cout<<"\nWrong Input put(Y|N)";}
			if(c=='Y'){netAttackPoints=player.getSpinach()*player.attack();}
			if(c=='N'){netAttackPoints=player.attack();}
		}while(c!='Y' && c!='N');

		int def=enemy.deffence();
		cout << endl<< "Attack - damage is " << netAttackPoints << " - " << def;
		netAttackPoints=netAttackPoints-def;
		cout<<"="<<netAttackPoints;
		cout << endl<< "Total damage - armor is " << netAttackPoints << " - " << enemy.getarmor();
		netAttackPoints= netAttackPoints - enemy.getarmor();
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

		cout<<"Do you add enchanted weapons (Y|N): ";
		do{
			cin>>c;
			if(c!='Y' && c!='N'){cout<<"\nWrong Input put(Y|N)";}
			if(c=='Y'){netAttackPoints=netAttackPoints*e.getEnchantedHobbit();}
			if(c=='N'){netAttackPoints=netAttackPoints;}
		}while(c!='Y' && c!='N');

		cout << "\nTotal damage : " << netAttackPoints <<endl;
        enemyNewStrength=enemy.getstrength()-netAttackPoints;
		if(enemyNewStrength<0){enemyNewStrength=0;}//set 0 for -ve strength
	    enemy.setstrength(enemyNewStrength) ;
		//now enemy is atacking and player is defending


		//store in constant iteration to traverse from beginning
		it=v.begin();
		if(index2==0){
			v.erase(it);//delete old content from begining
			v.insert(it,enemy);//add new content at begining
			}
			///POSSIBLY NEED TO PUT THIS BACK IN THE CODE
		//else{
			//v.erase(it+index2);//delete old content from this position
			//v.insert(it+index2,enemy);//add new content in same position
		//}

		//store update information in both team players
		if(each%2==0){sceoendTeam=v;}
		else{firstTeam=v;}

		it=v.begin();
		// if strength is 0 delete this charector
		if(v.at(index2).getstrength()==0){
			// if this charector exist betwwen top three add in list
			if((firstTeam.size()+sceoendTeam.size())<=3){
			    lt.push_back(v.at(index2));
			if(each%2==0){
			    teamName.push_back('b');
			    }// add corresponding team information
			else{
			    teamName.push_back('a');
			    }
			}
			// delete charector form 'v' safely
			if(v.size()==1){v.clear();}/////////
				else{
				if(index2==0){v.erase(it);}
				else{v.erase(it+index2);}
				}
		}

		// store update team players
		if(each%2==0){sceoendTeam=v;}
		else{firstTeam=v;}

		//////////////////////
		if (firstTeam.size()>sceoendTeam.size()){


		ck1=true;
		for(int i=0;i<v.size();i++){
			//check team players in the battle or not .
			// 'ck1' is true mean all player's in corresponding team are 0
			// 'ck1' is false mean at least one player in corresponding team is in battle
	   		if(v.at(i).getstrength()>0){ck1=false;break;}
		}

		if(ck1==true){
		// now 'v' store players for winner team
		if(each%2==0){v=firstTeam;}
		else{v=sceoendTeam;}
		system("cls");
		cout <<team1.getName()<<" STATISTICS: " <<"\t\t\t" <<team2.getName()<<" STATISTICS: " << endl;

		int max=0;
		if(firstTeam.size()<sceoendTeam.size()){max=sceoendTeam.size();}
		else{max=firstTeam.size();}
		for(int i=0;i<max;i++){
			if(i<firstTeam.size() && i<sceoendTeam.size()){
			cout<<endl<<firstTeam.at(i).getname()<<": "<<int(firstTeam.at(i).getstrength()*100/firstTeam.at(i).getstnstore())<<"%\t\t\t\t"<<sceoendTeam.at(i).getname()<<": "<<int(sceoendTeam.at(i).getstrength()*100/sceoendTeam.at(i).getstnstore())<<"%\n";
			cout<<firstTeam.at(i).getname()<<": Strength: "<<firstTeam.at(i).getstrength()<<"/"<<firstTeam.at(i).getstnstore()<<"\t\t\t"<<sceoendTeam.at(i).getname()<<" :Strength: "<<sceoendTeam.at(i).getstrength()<<"/"<<sceoendTeam.at(i).getstnstore();
			}
			else{
				if(firstTeam.size()<sceoendTeam.size()){
				cout<<endl<<"\t\t\t\t\t\t\t"<<sceoendTeam.at(i).getname()<<": "<<int(sceoendTeam.at(i).getstrength()*100/sceoendTeam.at(i).getstnstore())<<"%\n";
				cout<<"\t\t\t\t\t\t"<<sceoendTeam.at(i).getname()<<" :Strength: "<<sceoendTeam.at(i).getstrength()<<"/"<<sceoendTeam.at(i).getstnstore();
				}
				if(firstTeam.size()>sceoendTeam.size()){
				cout<<endl<<firstTeam.at(i).getname()<<": "<<int(firstTeam.at(i).getstrength()*100/firstTeam.at(i).getstnstore())<<"%\n";
				cout<<firstTeam.at(i).getname()<<": Strength: "<<firstTeam.at(i).getstrength()<<"/"<<firstTeam.at(i).getstnstore();
				}
			}
		}
		if(each%2==0){cout<<"\n\n\n"<<team1.getName()<<" WON THIS GAME." <<endl;}
			else{cout<<"\n\n\n"<<team2.getName()<<" WON THIS GAME." <<endl;}
			while(v.size()>0){
				it=v.begin();
				float max=0;//use for minimum strenth charector in remainning winner players
				int index=0;
				// find top strength charector
				for(int i=0;i<v.size();i++){
					float tmp=v.at(i).getstnstore()/float(v.at(i).getstrength());
					if(tmp>max){max=tmp;index=i;}
				}
				lt.push_back(v.at(index));//add in list
				if(each%2==0){teamName.push_back('a');}
				else{teamName.push_back('b');}
				if(v.size()==1){v.erase(it);}// after add delete
				else{
					if(index==0){v.erase(it);}
					else{v.erase(it+index);}
				}
			}
		//system("pause");
		break;
		}

		///
		each++;
		//system("pause");

		}

		cout<<"\nDisplaying Result : \n\n";
		lt.reverse();
		std::list<CHARECTOR>::iterator it;
		it=lt.begin();
		int size=lt.size();
		// top 3 players
		for(int i=0;i<size;i++){
		cout<<(i+1)<<" : position is "<<it->getname()<<" in team "<<teamName.at(size-i-1)<<endl;
		it++;
		}


		system("pause");
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


void newLine( )
 {
 char symbol;
do
 {
 cin.get(symbol);
 } while (symbol != '\n');
 }
