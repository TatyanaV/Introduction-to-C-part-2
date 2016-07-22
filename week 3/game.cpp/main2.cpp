/*
The MIT License (MIT)

Copyright (c) 2013 Daniel Mansfield

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <ctime>

/*#include "atlas.hpp"
#include "item.hpp"
#include "weapon.hpp"
#include "armour.hpp"
#include "inventory.hpp"
#include "creature.hpp"
#include "dialogue.hpp"
#include "area.hpp"
#include "battle.hpp"
*/
// Gameplay is expressed using dialogues, which present a piece of
// information and some responses, and the ask the user to pick one. If
// they do not pick a valid one then the dialogue loops until they do
class Dialogue
{
	private:

	// Initial piece of information that the dialogue displays
	std::string description;

	// A vector of choices that will be outputted. No numbering is
	// necessary, the dialogue does that automatically
	std::vector<std::string> choices;

	public:

	// Run the dialogue
	int activate()
	{
		// Output the information
		std::cout << description << std::endl;

		// Output and number the choices
		for(int i = 0; i < this->choices.size(); ++i)
		{
			std::cout << i+1 << ": " << this->choices[i] << std::endl;
		}

		int userInput = -1;

		// Repeatedly read input from stdin until a valid option is
		// chosen
		while(true)
		{
			std::cin >> userInput;
			// 'Valid' means within the range of numbers outputted
			if(userInput >= 0 && userInput <= choices.size())
			{
				return userInput;
			}
		}

		return 0;
	}

	Dialogue(std::string description, std::vector<std::string> choices)
	{
		this->description = description;
		this->choices = choices;
	}

	Dialogue()
	{
	}
};
class Creature
{
	public:

	// Name of the creature and the name of its class, if it has one
	// Class may be Fighter, Rogue etc
	std::string name;
	std::string className;

	// Creature stats. Reasonable values are in parentheses
	int health;		// Current hit points (10-1000+)
	int maxHealth;	// Maximum hit points (10-1000+)
	int str;		// Strength. Determines damage in battle (1-100)
	int end;		// Endurance. Determines maximum health (1-100)
	int dex;		// Dexterity. Determines speed in battle (1-100)
	double hitRate;	// Modifier to hit chance. (1-150)

	// Current level of the creature. Determines the amount of experience
	// that it gives to the victor when defeated (see Battle class for more)
	// and the amount of experience required to level up again. Upon
	// levelling up the creature will gain stat improvements.
	// 1-50 is reasonable
	unsigned int level;

	// Current experience. 0-1M is reasonable, see the levelup() function
	// for a decent scale
	unsigned int exp;

	// Items that the creature possesses
	Inventory inventory;

	// Currently equipped weapon. Used as a pointer to an atlas entry,
	// but not necessary. nullptr denotes that no weapon is equipped
	Weapon* equippedWeapon;

	// Armour currently equipped into each slot
	Armour* equippedArmour[Armour::Slot::N];

	Creature(std::string name, int health, int str, int end, int dex, double hitRate,
		unsigned int level = 1, std::string className = "")
	{
		this->name = name;
		this->health = health;
		this->maxHealth = health;
		this->str = str;
		this->end = end;
		this->dex = dex;
		this->hitRate = hitRate;
		this->className = className;
		this->equippedArmour[Armour::Slot::HEAD] = nullptr;
		this->equippedArmour[Armour::Slot::TORSO] = nullptr;
		this->equippedArmour[Armour::Slot::LEGS] = nullptr;
		this->equippedWeapon = nullptr;
		this->level = level;
		this->exp = 0;
	}

	Creature()
	{
		this->equippedArmour[Armour::Slot::HEAD] = nullptr;
		this->equippedArmour[Armour::Slot::TORSO] = nullptr;
		this->equippedArmour[Armour::Slot::LEGS] = nullptr;
		this->equippedWeapon = nullptr;
		this->level = 1;
		this->exp = 0;
	}

	// Equip a weapon by setting the equipped weapon pointer. Currently
	// a pointless function (simple enough to be rewritten each time)
	// but handy if dual wielding is ever added, or shields etc
	void equipWeapon(Weapon* weapon)
	{
		this->equippedWeapon = weapon;

		return;
	}

	// Equip the armour into it's correct slot. A slightly more useful
	// function!
	void equipArmour(Armour* armour)
	{
		this->equippedArmour[(int)armour->slot] = armour;

		return;
	}

	// Calculates the experience required to reach a certain level,
	// *in total*. Really this is class specific and not object specific
	unsigned int expToLevel(unsigned int level)
	{
		// Exp to level x = 128*x^2
		return 128 * level * level;
	}

	// Level the creature to the next level if it has enough experience
	// to do so, returning true if it could level up and false otherwise.
	bool levelUp()
	{
		// We want the experience to the next level, not the current level
		if(this->exp >= expToLevel(this->level+1))
		{
			// Advance to the next level
			++level;

			// Variables to keep track of stat changes. Neater than
			// having a bunch of stat increases all over the place,
			// and removes the issue of the next level's stats affecting
			// themselves (increasing endurance then increasing health
			// based on the boosted instead of the original value, for
			// example
			unsigned int healthBoost = 0;
			unsigned int strBoost = 0;
			unsigned int endBoost = 0;
			unsigned int dexBoost = 0;

			// Give a large boost to health every third level
			if(level % 3 == 0)
			{
				// Randomly increase health, but always give a sizeable
				// chunk proportional to the creature's endurance
				healthBoost = 10 + (rand() % 4) + this->end / 4;
			}
			else
			{
				// Just increase health by a small amount
				healthBoost = this->end / 4;
			}
			// If the creature is a fighter, then favour strength and
			// endurance boosts over dexterity, but increase dexterity
			// 50% of the time too
			if(this->className == "Fighter")
			{
				strBoost = 1;
				endBoost = 1;
				if(rand() % 2 == 0) dexBoost = 1;
			}
			// Same as for fighter but favour dexterity and endurance
			// instead. Rogue's favour endurance too in order to keep
			// them at roughly the same capability
			else if(this->className == "Rogue")
			{
				endBoost = 1;
				dexBoost = 1;
				if(rand() % 2 == 0) strBoost = 1;
			}

			// Adjust all of the variables accordingly
			this->maxHealth += healthBoost;
			this->str += strBoost;
			this->end += endBoost;
			this->dex += dexBoost;

			// Tell the user that they grew a level, what the boosts where
			// and what their stats are now
			std::cout << this->name << " grew to level " << level << "!\n";
			std::cout << "Health +" << healthBoost << " -> " << this->maxHealth << std::endl;
			std::cout << "Str +" << strBoost << " -> " << this->str << std::endl;
			std::cout << "End +" << endBoost << " -> " << this->end << std::endl;
			std::cout << "Dex +" << dexBoost << " -> " << this->dex<< std::endl;
			std::cout << "----------------\n";

			return true;
		}
		return false;
	}
};

// Weapons are items, so they should inherit their properties
class Weapon : public Item
{
	public:

	// Weapon damage. See the Battle class for formula, but values
	// between 1-50 are reasonable
	unsigned damage;

	// Modifier to hit chance. Small values are encouraged, e.g.
	// 5-30%
	double hitRate;

	// Pass inherited qualities to the normal item constructor
	Weapon(std::string name, std::string description, int damage, double hitRate) :
		Item(name, description)
	{
		this->damage = damage;
		this->hitRate = hitRate;
	}

	Weapon()
	{
	}
};
class Battle
{
	public:

	// Dialogue used to ask the player battle choices
	Dialogue dialogue;

	// Creatures in combat. creatures[0] is the player
	Creature* creatures[2];

	Battle()
	{
	}

	Battle(Creature* player, Creature* b)
	{
		// Start a battle with the player and another creature
		this->creatures[0] = player;
		this->creatures[1] = b;

		// Set up the dialogue. Defending offers no tactical advangtages
		// in this battle system
		this->dialogue = Dialogue("What will you do?",
		{
			"Attack",
			"Defend"
		});
	}

	// Creature a attacks creature b, and b takes damage accordingly
	void attack(Creature* a, Creature* b)
	{
		std::cout << a->name << " attacks!\n";

		// Damage that a will inflict on b
		int damage = 0;

		// Cumulative modifier to hitRate
		double hitRate = a->hitRate;

		// If a has equipped a weapon, then add the weapon damage on
		// to the current damage and add the hit rate of the weapon on to
		// the current hit rate
		if(a->equippedWeapon != nullptr)
		{
			damage += a->equippedWeapon->damage;
			hitRate += a->equippedWeapon->hitRate;
		}

		// Increase the damage by half the attacker's strength
		damage += a->str / 2;

		// Damage that b will block
		int defense = 0;

		// Sum the defense values of the armour that b has equipped, and
		// increase the defense by the summed value
		for(int i = 0; i < Armour::Slot::N; ++i)
		{
			if(b->equippedArmour[i] != nullptr)
				defense += b->equippedArmour[i]->defense;
		}

		// Decrease the damage by the damage blocked, then ensure that
		// damage is always inflicted (we do not want battles to last
		// forever, nor to we want attacks to heal the wounded!)
		damage -= defense;
		if(damage < 1) damage = 1;

		// Add the hit rate to the base hit rate and subract the target's
		// dexterity from it. Instead of halving it to normalise it into
		// a percentage, we just double the range of randomly generated
		// values
		if(rand() % 201 <= 170 + hitRate - b->dex)
		{
			// The attack hit, so subtract the damage
			std::cout << b->name << " takes " << damage << " damage!\n";
			b->health -= damage;
		}
		else
		{
			// The attack missed
			std::cout << a->name << " missed!\n";
		}

		return;
	}

	// Allow the player to act
	void playerTurn()
	{
		// Activate the dialogue and allow the player to choose their
		// battle option
		int result = this->dialogue.activate();

		switch(result)
		{
			// Attack the enemy
			case 1:
				attack(creatures[0], creatures[1]);
				break;
			// Defend, skipping to the enemy's turn
			case 2:
				std::cout << creatures[0]->name << " defends!\n";
				break;
			default:
				break;
		}

		return;
	}

	// Allow the enemy to attack
	void enemyTurn()
	{
		// Battle system does not currently allow for any kind of
		// tactics, so make the enemy attack blindly
		attack(creatures[1], creatures[0]);

		return;
	}

	// Return true if the creature is dead. Split into it's own function
	// to allow easy addition of effects which simulate death, such as
	// petrifaction or banishment
	bool isdead(Creature* creature)
	{
		if(creature->health <= 0)
		{
			return true;
		}
		return false;
	}

	// Run a round of the battle
	bool activate()
	{
		// The creature with the highest dexterity attacks first, with
		// preference to the player
		if(creatures[0]->dex >= creatures[1]->dex)
		{
			// Run each turn and check if the foe is dead at the end of
			// each
			this->playerTurn();
			if(isdead(creatures[1]))
			{
				std::cout << creatures[1]->name << " was vanquished!\n";
				return true;
			}

			this->enemyTurn();
			if(isdead(creatures[0]))
			{
				std::cout << creatures[0]->name << " was vanquished!\n";
				return true;
			}
		}
		else
		{
			this->enemyTurn();
			if(isdead(creatures[0]))
			{
				std::cout << creatures[0]->name << " was vanquished!\n";
				return true;
			}

			this->playerTurn();
			if(isdead(creatures[1]))
			{
				std::cout << creatures[1]->name << " was vanquished!\n";
				return true;
			}
		}

		return false;
	}

	// Begin the battle
	void run()
	{
		std::cout << creatures[1]->name << " appears!" << std::endl;

		// Run the battle until one creature dies
		while(!this->activate());

		// If the enemy is dead, then allocate experience to the player
		if(isdead(creatures[1]))
		{
			// Give experience to the player equal to one eigth of the
			// experience the enemy gained to reach it's next level
			unsigned int expGain = creatures[1]->expToLevel(creatures[1]->level+1) / 8;
			std::cout << "Gained " << expGain << " exp!\n";
			creatures[0]->exp += expGain;

			// Repeatedly level up the player until they are the highest
			// level they can be for their experience
			while(creatures[0]->levelUp());
		}

		return;
	}
};
// Armour should also inherit item properties
class Armour : public Item
{
	public:

	// Armour can go into one of three slots, and only one piece of
	// armour may occupy each slot at a time. The N is there to quickly
	// retrieve the number of slots, without having to use another variable
	enum Slot { TORSO, HEAD, LEGS, N };

	Slot slot;

	// See Battle class for exact formula, values from 1-50 are reasonable
	int defense;

	// Usual constructor
	Armour(std::string name, std::string description, int defense, Armour::Slot slot) :
		Item(name, description)
	{
		this->defense = defense;
		this->slot = slot;
	}

	Armour()
	{
	}
};































// New character menu
Creature dialogue_newchar();

// Character information menu, displays the items the player has, their
// current stats etc.
void dialogue_menu(Creature& player);

int main(void)
{
	std::vector<Creature> creatureAtlas;
	std::vector<Item> itemAtlas;
	std::vector<Weapon> weaponAtlas;
	std::vector<Armour> armourAtlas;
	std::vector<Area> areaAtlas;

	Creature player;

	// Build the atlases
	buildatlas_creature(creatureAtlas);
	buildatlas_item(itemAtlas);
	buildatlas_weapon(weaponAtlas);
	buildatlas_armour(armourAtlas);
	buildatlas_area(areaAtlas, itemAtlas, weaponAtlas, armourAtlas, creatureAtlas);

	// Seed the random number generator with the system time, so the
	// random numbers produced by rand() will be different each time
	srand(time(NULL));

	// Main game menu dialogue
	int result = Dialogue(
		"Welcome!",
		{"New Game"}).activate();

	switch(result)
	{
		case 1: player = dialogue_newchar(); break;
		default: return 0; break;
	}

	// Set the current area to be the first area in the atlas, essentially
	// placing the player there upon game start
	Area* currentArea = &(areaAtlas[0]);

	// Play the game until a function breaks the loop and closes it
	while(1)
	{
		// If the player has died then inform them as such and close
		// the program
		if(player.health <= 0)
		{
			std::cout << "\t----YOU DIED----\n    Game Over\n";
			return 0;
		}

		// If the area the player is in has any creatures inside it,
		// then begin a battle with the last creature in the list
		// before moving on the next one. This makes the creature
		// list act like a stack
		if(currentArea->creatures.size() > 0)
		{
		    for(int i = currentArea->creatures.size() - 1; i >= 0; --i)
		    {
			    Battle(&player, currentArea->creatures[i]).run();
			    // Remove the creature from the area. This is fine to do
			    // because if the player wins the creature will not respawn,
			    // and if the creature wins the player isn't around to see it
			    // (This does break the 'non-mutable' feature of the atlases,
			    // but doing so saves a lot of memory, as we don't need to keep
			    // two versions of each area)
			    currentArea->creatures.pop_back();
		    }
        }

		// Activate the current area's dialogue
		result = currentArea->dialogue.activate();

		// These could be moved inside of the area code using an event
		// style system, but that allows for much less flexibility with
		// what happens in each area. Since we're defining the areas in
		// code anyway, sticking with this isn't too much of a problem,
		// and it keeps things easy to understand
		if(currentArea == &(areaAtlas[0]))
		{
			switch(result)
			{
				// Open the menu
				case 0:
					dialogue_menu(player);
					break;
				case 1:
				// Move to area 1
					currentArea = &(areaAtlas[1]);
					break;
				case 2:
				// Search the area
					currentArea->search(player);
					break;
				default:
					break;
			}
		}
		else if(currentArea == &(areaAtlas[1]))
		{
			switch(result)
			{
				// Open the menu
				case 0:
					dialogue_menu(player);
					break;
				// Move to area 0
				case 1:
					currentArea = &(areaAtlas[0]);
					break;
				// Search the area
				case 2:
					currentArea->search(player);
					break;
				default:
					break;
			}
		}
	}

	return 0;
}

// Create a new character
Creature dialogue_newchar()
{
	// Ask for a name and class
	// Name does not use a dialogue since dialogues only request options,
	// not string input. Could be generalised into its own TextInput
	// class, but not really necessary
	std::cout << "Choose your name" << std::endl;
	std::string name;
	std::cin >> name;

	int result = Dialogue(
		"Choose your class",
		{"Fighter", "Rogue"}).activate();

	switch(result)
	{
		// Fighter class favours health and strength
		case 1:
			return Creature(name, 35, 20, 10, 5, 10.0, 1, "Fighter");
			break;

		// Rogue class favours dexterity and hit rate
		case 2:
			return Creature(name, 30, 5, 10, 20, 15.0, 1, "Fighter");
			break;

		// Default case that should never happen, but it's good to be safe
		default:
			return Creature(name, 30, 10, 10, 10, 10.0, 1, "Adventurer");
		break;
	}
}

void dialogue_menu(Creature& player)
{
	// Output the menu
	int result = Dialogue(
		"Menu\n====",
		{"Items", "Equipment", "Character"}).activate();

	switch(result)
	{
		// Print the items that the player owns
		case 1:
			std::cout << "Items\n=====\n";
			player.inventory.print();
			std::cout << "----------------\n";
			break;
		// Print the equipment that the player is wearing (if they are
		// wearing anything) and then ask if they want to equip a weapon
		// or some armour
		case 2:
		{
			std::cout << "Equipment\n=========\n";
			std::cout << "Head: "
				<< (player.equippedArmour[Armour::Slot::HEAD] != nullptr ?
					player.equippedArmour[Armour::Slot::HEAD]->name : "Nothing")
				<< std::endl;
			std::cout << "Torso: "
				<< (player.equippedArmour[Armour::Slot::TORSO] != nullptr ?
					player.equippedArmour[Armour::Slot::TORSO]->name : "Nothing")
				<< std::endl;
			std::cout << "Legs: "
				<< (player.equippedArmour[Armour::Slot::LEGS] != nullptr ?
					player.equippedArmour[Armour::Slot::LEGS]->name : "Nothing")
				<< std::endl;
			std::cout << "Weapon: "
				<< (player.equippedWeapon != nullptr ?
					player.equippedWeapon->name : "Nothing")
				<< std::endl;

			int result2 = Dialogue(
				"",
				{"Equip Armour", "Equip Weapon", "Close"}).activate();

			// Equipping armour
			if(result2 == 1)
			{
				int userInput = 0;

				// Cannot equip armour if they do not have any
				// Print a list of the armour and retrieve the amount
				// of armour in one go
				int numItems = player.inventory.print_armour(true);
				if(numItems == 0) break;

				while(!userInput)
				{
					// Choose a piece of armour to equip
					std::cout << "Equip which item?" << std::endl;
					std::cin >> userInput;
					// Equipment is numbered but is stored in a list,
					// so the number must be converted into a list element
					if(userInput >= 1 && userInput <= numItems)
					{
						int i = 1;

						for(auto it : player.inventory.armour)
						{
							if(i++ == userInput)
							{
								// Equip the armour if it is found
								player.equipArmour(it.first);
								break;
							}
						}
					}
				}
			}
			// Equip a weapon, using the same algorithms as for armour
			else if(result2 == 2)
			{
				int userInput = 0;
				int numItems = player.inventory.print_weapons(true);

				if(numItems == 0) break;

				while(!userInput)
				{
					std::cout << "Equip which item?" << std::endl;
					std::cin >> userInput;
					if(userInput >= 1 && userInput <= numItems)
					{
						int i = 1;

						for(auto it : player.inventory.weapons)
						{
							if(i++ == userInput)
							{
								player.equipWeapon(it.first);
								break;
							}
						}
					}
				}
			}
			std::cout << "----------------\n";
			break;
		}
		// Output the character information, including name, class (if
		// they have one), stats, level, and experience
		case 3:
			std::cout << "Character\n=========\n";
			std::cout << player.name;
			if(player.className != "") std::cout << " the " << player.className;
			std::cout << std::endl;

			std::cout << "HP: " << player.health << " / " << player.maxHealth << std::endl;
			std::cout << "Str: " << player.str << std::endl;
			std::cout << "End: " << player.end << std::endl;
			std::cout << "Dex: " << player.dex << std::endl;
			std::cout << "Lvl: " << player.level << " (" << player.exp;
			std::cout <<  " / " << player.expToLevel(player.level+1) << ")" << std::endl;
			std::cout << "----------------\n";
			break;
		default:
			break;
	}

	return;
}
