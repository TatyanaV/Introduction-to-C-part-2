
/************************************************
** Tatyana Vlaskin
** Lab 3
*************************************************/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using std::string;
using std::cout;
using std::cin;
using std::endl;
// used inforamtion http://www.penguinprogrammer.co.uk/rpg-tutorial-2/
class Monster;// se below for class definition.
///CLASS CHARACTER
class Character
	{
	public:// I know this is a bad practice to expose variables, but I already spend so much time on this program, that I do not have energy to remake it
		string name;
		short health;
		short damage;
		short spears;// will be used in thrust attack. once characters runs out of spears, they will be able to do only swung attack with the bat.
    public:
		Character(string newname, int health1, int damage1, int spears1);
		void attackSwung(Monster& target);
		void attackThrust(Monster& target);
		void display();
	};
/************************************************
** Constructor: Character::Character(string newname, int health1, int damage1, int spears1)
** Description: will be used to set up different fighter classes
*************************************************/
Character::Character(string newname, int health1, int damage1, int spears1)
    {
        name=newname;
        health=health1;
        damage=damage1;
        spears = spears1;
    }

/************************************************
** Function: Character characterSelection()
** Description: Player has a choice to choose a figheter class
*************************************************/
Character characterSelection(){
    cout<< endl << "Choose your figher class. " << endl;
    cout<< "1. Fighter." << endl << "2. Rogue "<<endl << "3. Adventure" << endl;
    int result;
    cin >> result;
    switch(result){
        case 1:
           return Character("Fighter", 100,25,10);
           break;
        case 2:
            return Character("Rogue", 120,38,6);
            break;
        case 3:
            return Character("Adenturer", 12,5,3);
        break;
    }
}

/************************************************
** Function: void Character::display()
** Description: Inforamtion about player is displayed to the user
*************************************************/
void Character::display(){
        cout << name << "  health: " << health << "  spears: " << spears << endl;
}
//used information http://www.dreamincode.net/forums/topic/159864-c-rpg-game/
///CLASS MONSTER
class Monster{
	public:
		string name;
		short health;
		short damage;
		Monster(string newName, int newHealth, int newDamage);
		void attack(Character&);
};

/************************************************
** Function: void Monster::attack(Character& target)
** Description: Used by monster to attack the user.
*************************************************/
void Monster::attack(Character& target){
        //target.health = health - damage;
        target.health-=damage;
        cout << name << " attacks " << target.name << " doing " << damage << " damage!" << endl;
        cout << name << " health: " << health << endl;
        cout << target.name << " health: " << target.health << endl;
}
/************************************************
** Constructor: Monster::Monster(string newname, int newHealth, int newDamage){
** Description: will be used to set up different monsters
*************************************************/
Monster::Monster(string newname, int newHealth, int newDamage){
    name=newname;
    health=newHealth;
    damage=newDamage;
}

///CLASS COMBAT
class Combat{
    public:
		Monster& ActiveMonster;
		Combat(Monster& newM);
		void combatChoice(Character& Fighter);
		void combat1(Character& Fighter);
};
// used infromation http://www.kirupa.com/forum/showthread.php?300341-Creating-simple-RPG-Stats-not-so-simple
Combat::Combat(Monster& newM) : ActiveMonster(newM){}

/************************************************
** void Combat::combatChoice(Character& Fighter){
** Description: Asks the user if they want to use swung
** or thrust weapons. Swung weapon will last forver,
** for thrust weapon, the user will use spears,
**and there is a limited ammount of spears that
** the user has.
*************************************************/
void Combat::combatChoice(Character& Fighter){
	Fighter.display();
	cout << endl<< "What king of weapon do you want to use to attack the monster?" <<endl
	<< "1. Use baseball bat - SWUNG WEAPON" << endl
	<< "2. Use spears - THRUST WAPON" << endl;

	short choice;
	cin >> choice;

	switch (choice)	{
		case 1:
			Fighter.attackSwung(ActiveMonster);
			break;
		case 2:
			Fighter.attackThrust(ActiveMonster);
			break;
	}
 }
/************************************************
** Function: void Character::attackSwung(Monster& target)
** Description: Lets the user use Swung weapon
*************************************************/
void Character::attackSwung(Monster& target)
    {
        target.health-=damage;
        cout <<endl<< name << " attacks the " << target.name << " with the baseball bat doing " << damage << " damage!" << endl;
    }
/************************************************
** Function: void Character::attackThrust(Monster& target)
** Description: Lets the user use Thrust weapon
*************************************************/
void Character::attackThrust(Monster& target)
{
	if (spears == 0){
		cout << name << " is out of spears!" << endl;
		cout <<"You can only fight with your baseball bat." <<endl;
	}
    else
	{
		short thrustDamage=15;// 15 is some random number
		target.health -= thrustDamage;
		spears--;
		cout << endl;
		cout << name << " throws a spear at the " << target.name << " which inflicts " << thrustDamage << " damage!" << endl;
	}
}

/************************************************
void Combat::combat1(Character& Fighter){
** Description: Lets the user use Thrust weapon
*************************************************/
void Combat::combat1(Character& Fighter){
	while  (ActiveMonster.health>0 && Fighter.health>0){
	    combatChoice(Fighter);
		ActiveMonster.attack(Fighter);
		//combatChoice(Fighter);
	}
	if (ActiveMonster.health<=0){
		cout <<endl<< "Congratulations! You killed the monster!" << endl;}
	if (Fighter.health<=0){
		cout << "You are dead! You lost." << endl;
    }
}

int main () {
    cout << "Welcome to the Fantazy Combat Game! " << endl;
    Character Fighter = characterSelection();
    //Character::Character(string newname, int health1, int damage1, int spears1)
    std::cout << "You'll be fighting as an " << Fighter.name << endl << "You have "
    << Fighter.health << " health points." << endl << "You have "  << Fighter.spears << " spears." << endl;
    //Monster::Monster(string newname, int newHealth, int newDamage)
    std::vector<Monster*> monsters;
    monsters.push_back(new Monster("Dragon", 50,40));// we can do arbitrary number of monsters
    monsters.push_back(new Monster("Hobbib", 30,10));
    monsters.push_back(new Monster("Goblin", 10,2));
    srand(time(0)); // each time a game is played a different monster will be generated.
    // Select a random monster from the array
    // used infomarmation on http://gamedev.stackexchange.com/questions/33705/how-can-i-randomly-choose-a-monster-from-an-array-of-monsters
    int random_index = rand() % (monsters.size());// randomly chooses an element from the arrray
    Monster* selected_monster = monsters[random_index];// player will finght againts that raendom monster
    //measage to let the player know what monsters they've encountered
    std::cout << endl<< "Your encountered " << selected_monster->name << " with "
    << selected_monster->health << " health points." << endl
    <<selected_monster->name <<" will inflict " << selected_monster-> damage
    <<" damage points each time it hits you."<<std::endl;
   	Combat combat(*selected_monster);
	combat.combat1(Fighter);
	return 0;
}




