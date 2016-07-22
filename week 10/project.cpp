
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<list>
#include <ctime>
#include <ctype.h>

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
	    cout<<"\t\t\tSimple Combat Game\n\nYour Universe :-\n\n";
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


void tournament(){
	cout<<"\n\t\tTeam A \t\t Team B";
	cout<<"\n\t\t   |\t\t    |\n\n";
	cout<<"\t\tPLAYER a1 \tPLAYER b1\n";
	cout<<"\t\tPLAYER a2 \tPLAYER b2\n";
	cout<<"\t\tPLAYER a3 \tPLAYER b3\n\n\t\t\t      SEMI FINAL";
	cout<<"\n  [Semi Final 1]  Team A 1st place   Vs   Team B 2nd place\n";
	cout<<"\n  [Semi Final 2]  Team B 2nd place   Vs   Team B 1st place\n";
	cout<<"\n\t\t\t\tFinal\n\n\t   [Semi Final 1 winner] Vs [Semi Final 2 winner]\n\n";
}

class TEAM{
private:
	string name;
	std::vector<CHARECTOR> v;
	int point;
	int play;
	int win;
	int lost;
	int tie;
	char type;
public:
	TEAM(){}
	TEAM(string n){name=n;point=0;play=0;win=0;lost=0;tie=0;}
	void setVec(std::vector<CHARECTOR> x){v=x;}
	void setPoint(int p){point=p;}
	void setType(char c){type=c;}
	void setPlay(int p){play=p;}
	void setWin(int s){win=s;}
	void setLost(int l){lost=l;}
	void setTie(int t){tie=t;}
	string getName(){return(name);}
	int getWin(){return(win);}
	int getLost(){return(lost);}
	int getTie(){return(tie);}
	int getPlay(){return(play);}
	void yourTeam(){
		cout<<"\nName : "<<name;
		cout<<"\nCombat Team : ";
		for(int i=0;i<v.size();i++){
		cout<<"["<<v.at(i).getname()<<"] ";
		}
		cout<<endl;
	}
	int getPoint(){return(point);}
	char getType(){return(type);}
	std::vector<CHARECTOR> getVec(){return(v);}
};

void Table(std::list<TEAM> t){
	cout<<"\n\t\tTeam A";
	cout<<"\n\t\tTEAM\tPLAY\tWIN\tLOST\tPOINT";
	for(std::list<TEAM>::const_iterator ci =t.begin();ci!=t.end();++ci){
		TEAM tm;tm=*ci;
		if(tm.getType()=='a'){
			cout<<"\n\t\t"<<tm.getName()<<"\t"<<tm.getPlay()<<"\t"<<tm.getWin()<<"\t"<<tm.getLost()<<"\t"<<tm.getTie();
		}
	}
	cout<<"\n\n\t\tTeam B";
	cout<<"\n\t\tTEAM\tPLAY\tWIN\tLOST\tPOINT";
	for(std::list<TEAM>::const_iterator ci =t.begin();ci!=t.end();++ci){
		TEAM tm;tm=*ci;
		if(tm.getType()=='b'){
			cout<<"\n\t\t"<<tm.getName()<<"\t"<<tm.getPlay()<<"\t"<<tm.getWin()<<"\t"<<tm.getLost()<<"\t"<<tm.getTie();
		}
	}
}

///MAIN METHOD
int main(){
 //   //srand(time(0));
 //   //creating object for each character

	tournament();
	EnchantedHobbit e;
	int num=0;
	cout<<"\nNumber of player in each team : ";
	cin>>num;
	std::list<TEAM> lt;
	std::vector<CHARECTOR> v;
	for(int i=0;i<6;i++){
		cout<<"\nEnter name of player ";
		string s;
		cin>>s;
		TEAM t(s);
		if(i%2==0){t.setType('a');}
		else{t.setType('b');}
		displayChart();
		for(int j=0;j<num;j++){
			v.push_back(eachPlayer());
		}
		t.setVec(v);
		v.clear();
		lt.push_back(t);
	}


	cout<<"\n\nDisplay ALL team :\n\n";
	for(std::list<TEAM>::const_iterator ci =lt.begin();ci!=lt.end();++ci){
	TEAM t=*ci;
	t.yourTeam();
	if(t.getType()=='a'){cout<<"\nTeam A";}
	else{cout<<"\nTeam B";}
	cout<<endl;
	}

	system("pause");

	////my combad

	for(int each=1;each<=12;each++){
	std::vector<CHARECTOR> firstTeam,sceoendTeam;
	TEAM team1,team2;
	std::list<TEAM>::iterator lit1,lit2;
	lit1=lt.begin();
	lit2=lt.begin();
	if(each==1){
		for(int y=1;y<1;y++){lit1++;}
		for(int y=1;y<2;y++){lit2++;}
		team1=*lit1;team2=*lit2;
	}
		if(each==2){
			for(int y=1;y<3;y++){lit1++;}
			for(int y=1;y<4;y++){lit2++;}
			team1=*lit1;team2=*lit2;
		}
		if(each==3){
			for(int y=1;y<5;y++){lit1++;}
			for(int y=1;y<6;y++){lit2++;}
			team1=*lit1;team2=*lit2;
		}
		if(each==4){
			for(int y=1;y<1;y++){lit1++;}
			for(int y=1;y<4;y++){lit2++;}
			team1=*lit1;team2=*lit2;
		}
		if(each==5){
			for(int y=1;y<3;y++){lit1++;}
			for(int y=1;y<6;y++){lit2++;}
			team1=*lit1;team2=*lit2;
		}
		if(each==6){
			for(int y=1;y<5;y++){lit1++;}
			for(int y=1;y<2;y++){lit2++;}
			team1=*lit1;team2=*lit2;
		}
		if(each==7){
			for(int y=1;y<1;y++){lit1++;}
			for(int y=1;y<6;y++){lit2++;}
			team1=*lit1;team2=*lit2;
		}
		if(each==8){
			for(int y=1;y<3;y++){lit1++;}
			for(int y=1;y<2;y++){lit2++;}
			team1=*lit1;team2=*lit2;
		}
		if(each==9){
			for(int y=1;y<5;y++){lit1++;}
			for(int y=1;y<4;y++){lit2++;}
			team1=*lit1;team2=*lit2;
		}
		if(each==10){
			TEAM t1[3];
			TEAM t2[3];
			for(int t=0;t<6;t++){
				if(lit1->getType()=='a'){t1[t/2]=*lit1;}
				else{t1[t/2]=*lit1;}
				lit1++;
			}
			lit1=lt.begin();
			for(int z=0;z<6;z++){lit1++;}
			if(t1[0].getPoint()>t1[1].getPoint() && t1[0].getPoint()>t1[2].getPoint()){team1=t1[0];for(int z=0;z<1;z++){lit1++;}}
			else{
				if(t1[1].getPoint()>t1[2].getPoint()){team1=t1[1];for(int z=0;z<3;z++){lit1++;}}
				else{team1=t1[2];for(int z=0;z<5;z++){lit1++;}}
			}

			lit2=lt.begin();
			if(t2[0].getPoint()>t2[1].getPoint() && t2[0].getPoint()>t2[2].getPoint() && t2[1].getPoint()>t2[2].getPoint()){team2=t2[1];for(int z=0;z<4;z++){lit2++;}}
			if(t2[0].getPoint()>t2[1].getPoint() && t2[0].getPoint()>t2[2].getPoint() && t2[1].getPoint()<=t2[2].getPoint()){team2=t2[2];for(int z=0;z<6;z++){lit2++;}}
			if(t2[1].getPoint()>t2[2].getPoint() && t2[1].getPoint()>t2[0].getPoint() && t2[2].getPoint()>t2[0].getPoint()){team2=t2[2];for(int z=0;z<6;z++){lit2++;}}
			if(t2[1].getPoint()>t2[2].getPoint() && t2[1].getPoint()>t2[0].getPoint() && t2[2].getPoint()<=t2[0].getPoint()){team2=t2[0];for(int z=0;z<2;z++){lit2++;}}
			if(t2[2].getPoint()>t2[0].getPoint() && t2[2].getPoint()>t2[1].getPoint() && t2[0].getPoint()>t2[1].getPoint()){team2=t2[0];for(int z=0;z<2;z++){lit2++;}}
			if(t2[2].getPoint()>t2[0].getPoint() && t2[2].getPoint()>t2[1].getPoint() && t2[0].getPoint()<=t2[1].getPoint()){team2=t2[1];for(int z=0;z<4;z++){lit2++;}}

		}
		if(each==11){
			TEAM t1[3];
			TEAM t2[3];
			for(int t=0;t<6;t++){
				if(lit1->getType()=='a'){t1[t/2]=*lit1;}
				else{t1[t/2]=*lit1;}
				lit1++;
			}
			lit2=lt.begin();
			for(int z=0;z<6;z++){lit2++;}
			if(t2[0].getPoint()>t2[1].getPoint() && t2[0].getPoint()>t2[2].getPoint()){team1=t2[0];for(int z=0;z<1;z++){lit2++;}}
			else{
				if(t2[1].getPoint()>t2[2].getPoint()){team1=t2[1];for(int z=0;z<3;z++){lit2++;}}
				else{team1=t2[2];for(int z=0;z<5;z++){lit2++;}}
			}

			lit1=lt.begin();
			if(t1[0].getPoint()>t1[1].getPoint() && t1[0].getPoint()>t1[2].getPoint() && t1[1].getPoint()>t1[2].getPoint()){team2=t2[1];for(int z=0;z<4;z++){lit1++;}}
			if(t1[0].getPoint()>t1[1].getPoint() && t1[0].getPoint()>t1[2].getPoint() && t1[1].getPoint()<=t1[2].getPoint()){team2=t2[2];for(int z=0;z<6;z++){lit1++;}}
			if(t1[1].getPoint()>t1[2].getPoint() && t1[1].getPoint()>t1[0].getPoint() && t1[2].getPoint()>t1[0].getPoint()){team2=t2[2];for(int z=0;z<6;z++){lit1++;}}
			if(t1[1].getPoint()>t1[2].getPoint() && t1[1].getPoint()>t1[0].getPoint() && t1[2].getPoint()<=t1[0].getPoint()){team2=t2[0];for(int z=0;z<2;z++){lit1++;}}
			if(t1[2].getPoint()>t1[0].getPoint() && t1[2].getPoint()>t1[1].getPoint() && t1[0].getPoint()>t1[1].getPoint()){team2=t2[0];for(int z=0;z<2;z++){lit1++;}}
			if(t1[2].getPoint()>t1[0].getPoint() && t1[2].getPoint()>t1[1].getPoint() && t1[0].getPoint()<=t1[1].getPoint()){team2=t2[1];for(int z=0;z<4;z++){lit1++;}}

		}
		if(each==12){
			bool b=false;
			for(;lit1!=lt.end();++lit1){
				if(b==true && lit1->getType()=='f'){team2=*lit1;break;}
				if(lit1->getType()=='f'){team1=*lit1;b=true;}
			}
		}

	firstTeam=team1.getVec();
	sceoendTeam=team2.getVec();
	CHARECTOR player,enemy;
	int index1,index2;

	char choice;// takes the user input for charector 'f'

	string selectionPlayer="",selectionEnemy="";// will be used to display which charactes are selected
    int enemyNewStrength=0,playerNewStrength=0;

	for(;;){
		system("cls");//clear screen
		index1=rand()%num;
		index2=rand()%num;
		player=firstTeam.at(index1);
		enemy=sceoendTeam.at(index2);
        cout <<team1.getName()<<" STATISTICS: " <<"\t\t\t" <<team2.getName()<<" STATISTICS: " << endl;
       // cout<<player.getname()<<": "<<int(player.getstrength()*100/player.getstnstore())<<"%\t\t\t\t" <<enemy.getname()<<": "<<int(enemy.getstrength()*100/enemy.getstnstore())<<"%\n";
       //
		for(int i=0;i<num;i++){
		cout<<endl<<firstTeam.at(i).getname()<<": "<<int(firstTeam.at(i).getstrength()*100/firstTeam.at(i).getstnstore())<<"%\t\t\t\t" <<sceoendTeam.at(i).getname()<<": "<<int(sceoendTeam.at(i).getstrength()*100/sceoendTeam.at(i).getstnstore())<<"%\n";
		//displays strenght points
        cout<<firstTeam.at(i).getname()<<": Strength: "<<firstTeam.at(i).getstrength()<<"/"<<firstTeam.at(i).getstnstore()<<"\t\t\t" <<sceoendTeam.at(i).getname()<<" :Strength: "<<sceoendTeam.at(i).getstrength()<<"/"<<sceoendTeam.at(i).getstnstore();
		}
		//

        //if enemy ran out of energy
		bool ck1=true;
		for(int i=0;i<num;i++){
        if(sceoendTeam.at(i).getstrength()>0){ck1=false;break;}
		}
		if(ck1==true){cout<<"\n\n\n"<<team1.getName()<<" WON THIS GAME." <<endl;if(each==10 || each==11){team1.setType('f');}
		team1.setPoint(team1.getPoint()+2);team1.setWin(team1.getWin()+1);team2.setLost(team2.getLost()+1);system("pause");}
    //if user  ran out of energy
		ck1=true;
		for(int i=0;i<num;i++){
        if(firstTeam.at(i).getstrength()>0){ck1=false;break;}
		}
		if(ck1==true){cout<<"\n\n\n"<<team2.getName()<<" WON THIS GAME." <<endl;if(each==10 || each==11){team2.setType('f');}
		team2.setPoint(team2.getPoint()+2);team2.setWin(team2.getWin()+1);team1.setLost(team1.getLost()+1);system("pause");}
		cout<<"\nFight for "<<team1.getName();
    // keeps asking the user to enter f for fight untill someone runs out of health
    cout<<"\n\nPress f for fight ";
    do{choice=std::cin.get();if(choice!='f'){// if the user enteres something else:
        cout<<"\nWrong input .(Press f)";}
    }while(choice!='f');
    // player is attacking and enemy is defending

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
	std::vector<CHARECTOR>::iterator it;
	it=firstTeam.begin();
	firstTeam.insert(it+index1,player);
	it=sceoendTeam.begin();
	sceoendTeam.insert(it+index2,enemy);
	//team1.setVec(firstTeam);
	//team2.setVec(sceoendTeam);

    system("pause");

	//////////////////////////////
	    // keeps asking the user to enter f for fight untill someone runs out of health
	cout<<"\nFight for "<<team2.getName();
		index1=rand()%num;
		index2=rand()%num;
		player=sceoendTeam.at(index1);
		enemy=firstTeam.at(index2);
    cout<<"\n\nPress f for fight ";
    do{choice=std::cin.get();if(choice!='f'){// if the user enteres something else:
        cout<<"\nWrong input .(Press f)";}
    }while(choice!='f');
    // player is attacking and enemy is defending

	cout << endl <<endl<< player.getname() << " is attacking and " << enemy.getname() << " is defending: " <<endl;

	cout<<"Do you need spinach (Y|N): ";

	do{cin>>c;
	if(c!='Y' && c!='N'){cout<<"\nWrong Input put(Y|N)";}
	if(c=='Y'){netAttackPoints=player.getSpinach()*player.attack();}
	if(c=='N'){netAttackPoints=player.attack();}
	}while(c!='Y' && c!='N');

	def=enemy.deffence();
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

	it=firstTeam.begin();
	firstTeam.insert(it+index1,player);
	it=sceoendTeam.begin();
	sceoendTeam.insert(it+index2,enemy);
	//team2.setVec(firstTeam);
	//team1.setVec(sceoendTeam);
    }
	lt.insert(lit1,team1);
	lt.insert(lit2,team2);
	cout<<"\n";
	Table(lt);
	system("pause");
	}



	return(0);
}

/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered
*************************************************/
int integerCheck (string INPUT, char min, char max){
	int NUM=0;
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


