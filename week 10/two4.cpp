#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
#include<list>
#include <ctime>

//using namespace std;
using std::cin;
using std::endl;
using std::cout;
using std::string;

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
	string entered="";

	fflush(stdin);//
	getline(cin,entered);
	result = integerCheck(entered, '1', '6');
	    //choose for player
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
	return(c);
}


class TEAM{
private:
	string name;
	std::queue<CHARECTOR> v;
public:
	TEAM(){}
	TEAM(string n,int no){name=n;}
	void setVec(std::queue<CHARECTOR> x){v=x;}
	string getName(){return(name);}
	void yourTeam(){
		cout<<"\nName : "<<name;
		cout<<"\nCombat Team : ";
		for(int i=0;i<v.size();i++){
		cout<<"["<<v.at(i).getname()<<"] ";
		}
		cout<<endl;
	}
	std::queue<CHARECTOR> getVec(){return(v);}
};

///MAIN METHOD
int main(){

	cout<<"\t\t\t\tTEAM A Vs TEAM B";
	EnchantedHobbit e;
	int num=0;
	cout<<"\nNumber of player in each team : ";
	cin>>num;
	std::list<CHARECTOR> lt;
	std::queue<char> teamName;
	std::queue<CHARECTOR> v;

	cout<<"Choose Team a Players : \n";
		TEAM team1("Team a",num);
		displayChart();
		for(int j=0;j<num;j++){
			v.push_back(eachPlayer());//team a players
		}
		team1.setVec(v);
		v.clear();


	cout<<"Choose Team b Players : \n";
	TEAM team2("Team b",num);
		displayChart();
		for(int j=0;j<num;j++){
			v.push_back(eachPlayer());//team b players
		}
		team2.setVec(v);
		v.clear();


	cout<<"\n\nDisplay Both team :\n\n";
	team1.yourTeam();
	team2.yourTeam();

	system("pause");

	std::queue<CHARECTOR> firstTeam,sceoendTeam;
	firstTeam=team1.getVec();
	sceoendTeam=team2.getVec();

	CHARECTOR player,enemy;
	int index1,index2;
	int each=0;
	char choice;// takes the user input for charector 'f'

	int enemyNewStrength=0,playerNewStrength=0;

	for(;;){
		system("cls");//clear screen
		v.clear();
		std::queue<CHARECTOR>::iterator it;

		cout <<team1.getName()<<" STATISTICS: " <<"\t\t\t" <<team2.getName()<<" STATISTICS: " << endl;

		for(int i=0;i<num;i++){
			if(i<firstTeam.size()){cout<<endl<<firstTeam.at(i).getname()<<": "<<int(firstTeam.at(i).getstrength()*100/firstTeam.at(i).getstnstore())<<"%";}
			if(i<sceoendTeam.size()){cout<<"\t\t\t\t"<<sceoendTeam.at(i).getname()<<": "<<int(sceoendTeam.at(i).getstrength()*100/sceoendTeam.at(i).getstnstore())<<"%\n";}
			if(i<firstTeam.size()){cout<<firstTeam.at(i).getname()<<": Strength: "<<firstTeam.at(i).getstrength()<<"/"<<firstTeam.at(i).getstnstore();}
			if(i<sceoendTeam.size()){cout<<"\t\t\t"<<sceoendTeam.at(i).getname()<<" :Strength: "<<sceoendTeam.at(i).getstrength()<<"/"<<sceoendTeam.at(i).getstnstore();}
		}

	    bool ck1;

		if(each%2==0){v=sceoendTeam;}
		else{v=firstTeam;}


		if(each%2==0){cout<<"\n\nFight for "<<team1.getName();}
		else{cout<<"\n\nFight for "<<team2.getName();}


		// keeps asking the user to enter f for fight untill someone runs out of health
		cout<<"\n\nPress f for fight ";
		do{choice=std::cin.get();if(choice!='f'){// if the user enteres something else:
			cout<<"\nWrong input .(Press f)";}
		}while(choice!='f');
		// player is attacking and enemy is defending

		if(each%2==0){
		index1=rand()%firstTeam.size();
		index2=rand()%sceoendTeam.size();
		player=firstTeam.at(index1);
		enemy=sceoendTeam.at(index2);
		}
		else{
		int tmp1=index1,tmp2=index2;
		if(tmp2<sceoendTeam.size()){index1=tmp2;}
		else{index1=0;}
		if(tmp1<firstTeam.size()){index2=tmp1;}
		else{index2=0;}
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

		system("pause");
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

		cout<<endl<<index1<<":"<<index2<<endl;

		it=v.begin();
		cout<<"A";
		if(index2==0){
			cout<<"B";
			v.erase(it);
			v.insert(it,enemy);
			cout<<"C";
		}
		else{
			cout<<"D";
			v.erase(it+index2);
			v.insert(it+index2,enemy);
			cout<<"E";
		}

		system("pause");


		if(each%2==0){sceoendTeam=v;}
		else{firstTeam=v;}

		it=v.begin();

		if(v.at(index2).getstrength()==0){
			cout<<"F";
			if((firstTeam.size()+sceoendTeam.size())<=3){lt.push_back(v.at(index2));
			if(each%2==0){teamName.push_back('b');}
			else{teamName.push_back('a');}
			}
				cout<<"G";
				if(v.size()==1){cout<<"I";v.clear();}/////////
				else{
				if(index2==0){cout<<"J";v.erase(it);}
				else{cout<<"K";v.erase(it+index2);}
				}
		}
		cout<<"L";

		if(each%2==0){sceoendTeam=v;}
		else{firstTeam=v;}

		///

		ck1=true;
		for(int i=0;i<v.size();i++){
	   		if(v.at(i).getstrength()>0){ck1=false;break;}
		}

		if(ck1==true){
		if(each%2==0){v=firstTeam;}
		else{v=sceoendTeam;}
		system("cls");
		cout <<team1.getName()<<" STATISTICS: " <<"\t\t\t" <<team2.getName()<<" STATISTICS: " << endl;
        for(int i=0;i<num;i++){
			if(i<firstTeam.size()){cout<<endl<<firstTeam.at(i).getname()<<": "<<int(firstTeam.at(i).getstrength()*100/firstTeam.at(i).getstnstore())<<"%";}
			if(i<sceoendTeam.size()){cout<<"\t\t\t\t"<<sceoendTeam.at(i).getname()<<": "<<int(sceoendTeam.at(i).getstrength()*100/sceoendTeam.at(i).getstnstore())<<"%\n";}
			if(i<firstTeam.size()){cout<<firstTeam.at(i).getname()<<": Strength: "<<firstTeam.at(i).getstrength()<<"/"<<firstTeam.at(i).getstnstore();}
			if(i<sceoendTeam.size()){cout<<"\t\t\t"<<sceoendTeam.at(i).getname()<<" :Strength: "<<sceoendTeam.at(i).getstrength()<<"/"<<sceoendTeam.at(i).getstnstore();}
		}

			if(each%2==0){cout<<"\n\n\n"<<team1.getName()<<" WON THIS GAME." <<endl;}
			else{cout<<"\n\n\n"<<team2.getName()<<" WON THIS GAME." <<endl;}
			while(v.size()>0){
				it=v.begin();
				float max=0;
				int index=0;
				for(int i=0;i<v.size();i++){
					float tmp=v.at(i).getstnstore()/float(v.at(i).getstrength());
					if(tmp>max){max=tmp;index=i;}
				}
				lt.push_back(v.at(index));
				if(each%2==0){teamName.push_back('a');}
				else{teamName.push_back('b');}
				if(v.size()==1){v.erase(it);}
				else{
					if(index==0){v.erase(it);}
					else{v.erase(it+index);}
				}
			}
		system("pause");
		break;
		}

		///


		each++;
		system("pause");

		}

		cout<<"\nDisplaying Result : \n\n";
		lt.reverse();
		std::list<CHARECTOR>::iterator it;
		it=lt.begin();
		int size=lt.size();
		for(int i=0;i<size;i++){
		cout<<(i+1)<<" : position is "<<it->getname()<<" in team "<<teamName.at(i)<<endl;
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
int integerCheck (string INPUT, char min, char max){
	int NUM=0;
	//cout<<INPUT;
	do{
		if(INPUT.length()!=1){
			cout<<"\nInput is more than one charector .";
			getline(cin,INPUT);
			if(INPUT.at(0)>=min && INPUT.at(0)<=max){NUM=atoi(INPUT.c_str());break;}
		}
		else{
			if(INPUT.at(0)>=min && INPUT.at(0)<=max){NUM=atoi(INPUT.c_str());break;}
			else{
				cout<<"Unknow Input .";
				cout<<"Please place input between "<<min<<" and "<<max<<endl;
				getline(cin,INPUT);
				if(INPUT.at(0)>=min && INPUT.at(0)<=max){NUM=atoi(INPUT.c_str());break;}
				}
		}
	}while((INPUT.at(0)<min || INPUT.at(0)>max) || INPUT.length()!=1);
	return(NUM);
}


