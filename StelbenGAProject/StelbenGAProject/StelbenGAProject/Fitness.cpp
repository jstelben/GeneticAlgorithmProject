#include "stdafx.h"
#include "Fitness.h"

#define LEVEL_WORTH 1
#define TREASURE_WORTH 0.34f
#define DEATH 5 * TREASURE_WORTH
#define BUFFER 40

Fitness::Fitness(void)
{
}


Fitness::~Fitness(void)
{
}



bool canUseBig(bool bigUsed, bool isDwarf)
{
	if(!bigUsed || isDwarf)
	{
		return true;
	}
	return false;
}

bool playerWins(int playerPower, int monsterPower, bool isWarrior)
{
	if(playerPower == monsterPower && isWarrior)
	{
		return true;
	}
	else if(playerPower > monsterPower)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getDieRoll()
{
	return (1 + rand() % 5);
}

int Fitness::GetPower(Chromosome* c)
{
	int power = 0;
	bool bigUsed = false;
	bool isDwarf = (c->GetClass() == DWARF);
	power += c->GetLevel();
	switch(c->GetHand1())
	{
		case BOW_WITH_RIBBONS:
			{
				if(c->GetRace() == ELF)
				{
					power += 4;
				}
				break;
			}
		case ELEVEN_FOOT_POLE:
			{
				power += 1;
				break;
			}
		case CHAINSAW_OF_BLOODY_DISMEMBERMENT:
			{
				if(canUseBig(bigUsed, isDwarf))
				{
					bigUsed = true;
					power += 3;
				}
				break;
			}
		case SWISS_ARMY_POLEARM:
			{
				if(c->GetRace() == HUMAN)
				{
					if(!bigUsed)
					{
						bigUsed = true;
						power += 4;
					}
				}
				break;
			}
		case HUGE_ROCK:
			{
				if(canUseBig(bigUsed, isDwarf))
				{
					bigUsed = true;
					power += 3;
				}
				break;
			}
		case MACE_OF_SHARPNESS:
			{
				if(c->GetClass() == CLERIC)
				{
					power += 4;
				}
				break;
			}
		case SNEAKY_BASTARD_SWORD:
			{
				power += 2;
				break;
			}
		case BROAD_SWORD:
			{
				if(c->GetGender() == FEMALE)
				{
					power += 3;
				}
				break;
			}
		case SHIELD_OF_UBIQUITY:
			{
				if(c->GetClass() == WARRIOR)
				{
					if(canUseBig(bigUsed, isDwarf))
					{
						bigUsed = true;
						power += 4;
					}
				}
				break;
			}
		case CHEESE_GRATER_OF_PEACE:
			{
				if(c->GetClass() == CLERIC)
				{
					power += 3;
				}
				break;
			}
		case RAT_ON_A_STICK:
			{
				power += 1;
				break;
			}
		case RAPIER_OF_UNFAIRNESS:
			{
				if(c->GetRace() == ELF)
				{
					power += 3;
				}
				break;
			}
		case GENTLEMENS_CLUB:
			{
				if(c->GetGender() == MALE)
				{
					power += 3;
				}
				break;
			}
		case HAMMER_OF_KNEECAPPING:
			{
				if(isDwarf)
				{
					power += 4;
				}
				break;
			}
		case STAFF_OF_NAPALM:
			{
				if(c->GetClass() == WIZARD)
				{
					power += 5;
				}
				break;
			}
		case DAGGER_OF_TREACHERY:
			{
				if(c->GetClass() == THIEF)
				{
					power += 3;
				}
				break;
			}
		case BUCKLER_OF_SWASHING:
			{
				power += 2;
				break;
			}
		case TUBA_OF_CHARM:
			{
				bigUsed = true;
				break;
			}
	}
	if(c->GetHand1() < TWO_HANDED_WEAPONS)
	{
		switch(c->GetHand2())
		{
			case MACE_OF_SHARPNESS:
			{
				if(c->GetClass() == CLERIC)
				{
					power += 4;
				}
				break;
			}
		case SNEAKY_BASTARD_SWORD:
			{
				power += 2;
				break;
			}
		case BROAD_SWORD:
			{
				if(c->GetGender() == FEMALE)
				{
					power += 3;
				}
				break;
			}
		case SHIELD_OF_UBIQUITY:
			{
				if(c->GetClass() == WARRIOR)
				{
					if(canUseBig(bigUsed, isDwarf))
					{
						bigUsed = true;
						power += 4;
					}
				}
				break;
			}
		case CHEESE_GRATER_OF_PEACE:
			{
				if(c->GetClass() == CLERIC)
				{
					power += 3;
				}
				break;
			}
		case RAT_ON_A_STICK:
			{
				power += 1;
				break;
			}
		case RAPIER_OF_UNFAIRNESS:
			{
				if(c->GetRace() == ELF)
				{
					power += 3;
				}
				break;
			}
		case GENTLEMENS_CLUB:
			{
				if(c->GetGender() == MALE)
				{
					power += 3;
				}
				break;
			}
		case HAMMER_OF_KNEECAPPING:
			{
				if(isDwarf)
				{
					power += 4;
				}
				break;
			}
		case STAFF_OF_NAPALM:
			{
				if(c->GetClass() == WIZARD)
				{
					power += 5;
				}
				break;
			}
		case DAGGER_OF_TREACHERY:
			{
				if(c->GetClass() == THIEF)
				{
					power += 3;
				}
				break;
			}
		case BUCKLER_OF_SWASHING:
			{
				power += 2;
				break;
			}
		case TUBA_OF_CHARM:
			{
				bigUsed = true;
				break;
			}
		}
	}

	switch(c->GetArmor())
	{
		case FLAMING_ARMOR:
			{
				power += 2;
				break;
			}
		case SLIMY_ARMOR:
			{
				power += 1;
				break;
			}
		case SHORT_WIDE_ARMOR:
			{
				if(isDwarf)
				{
					power += 3;
				}
				break;
			}
		case MITHRIL_ARMOR:
			{
				if(c->GetClass() != WIZARD)
				{
					if(canUseBig(bigUsed, isDwarf))
					{
						bigUsed = true;
						power += 3;
					}
				}
				break;
			}
		case LEATHER_ARMOR:
			{
				power += 1;
				break;
			}
	}
	switch(c->GetHeadgear())
	{
		case HORNY_HELMET:
			{
				if(c->GetRace() == ELF)
				{
					power += 3;
				}
				else 
				{
					power += 1;
				}
				break;
			}
		case POINTY_HAT_OF_POWER:
			{
				if(c->GetClass() == WIZARD)
				{
					power += 3;
				}
				break;
			}
		case HELM_OF_COURAGE:
			{
				power += 1;
				break;
			}
		case BAD_ASS_BANDANA:
			{
				if(c->GetRace() == HUMAN)
				{
					power += 3;
				}
				break;
			}

	}
	switch(c->GetFootgear())
	{
		case BOOTS_OF_RUNNING_REALLY_FAST:
			{
				break;
			}
		case BOOTS_OF_BUTT_KICKING:
			{
				power += 2;
				break;
			}
		case SANDALS_OF_PROTECTION:
			{
				break;
			}
	}

	return power;
}

float Fitness::GetFitness(Chromosome* c)
{
	//fitness addition is level + treasure gained
	//Lose fitness based on badstuff

	float fitness = 0;
	bool isWarrior = (c->GetClass() == WARRIOR);
	int power = c->GetPower();
	int monsterPower = 0;

	//Large Angry Chicken
	monsterPower = 2;
	if(playerWins(power, monsterPower, isWarrior))
	{
		if(c->GetArmor() == FLAMING_ARMOR || c->GetHand1() == STAFF_OF_NAPALM || c->GetHand2() == STAFF_OF_NAPALM)
		{
			//Bonus level if killed with fire
			fitness += (2 * LEVEL_WORTH) + TREASURE_WORTH;
		}
		else
		{
			fitness += LEVEL_WORTH + TREASURE_WORTH;
		}
	}
	else
	{
		fitness -= LEVEL_WORTH;
	}
	//Face Sucker
	monsterPower = 8;
	if(c->GetRace() == ELF)
	{
		monsterPower += 6;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		//Lose Headgear
		fitness -= TREASURE_WORTH + LEVEL_WORTH;
	}
	//Snails on Speed
	monsterPower = 4;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		//Roll die lose that many cards
		fitness -= (getDieRoll() * TREASURE_WORTH);
	}
	//3872 Orcs
	monsterPower = 10;
	if(c->GetRace() == DWARF)
	{
		monsterPower += 6;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (3 * TREASURE_WORTH);
	}
	else
	{
		//Roll die if <3 death else lose that many levels
		int roll = getDieRoll();
		if(roll < 3)
		{
			fitness -= DEATH;
		}
		else
		{
			fitness -= (roll * LEVEL_WORTH);
		}
	}
	//Unspeakably Awful Indescribable Horror
	monsterPower = 14;
	if(isWarrior)
	{
		monsterPower += 4;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (4 * TREASURE_WORTH);
	}
	else
	{
		//If wizard lose class else death
		if(c->GetClass() == WIZARD)
		{
			fitness -= TREASURE_WORTH;
		}
		else
		{
			fitness -= DEATH;
		}
	}
	//Bigfoot
	monsterPower = 12;
	if(c->GetRace() == HALFLING || c->GetRace() == DWARF)
	{
		monsterPower += 3;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (3 * TREASURE_WORTH);
	}
	else
	{
		fitness -= TREASURE_WORTH;
	}
	//Drooling Slime
	monsterPower = 1;
	if(c->GetRace() == ELF)
	{
		monsterPower += 4;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + TREASURE_WORTH;
	}
	else
	{
		fitness -= TREASURE_WORTH;
	}
	//King Tut
	monsterPower = 16;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += (2 * LEVEL_WORTH) + (4 * TREASURE_WORTH);
	}
	else
	{
		//Won't pursue lvl 3 and below
		if(c->GetLevel() > 3)
		{
			//lose all items and cards
			fitness -= (10 * TREASURE_WORTH);
		}
	}
	//Lawyers
	monsterPower = 6;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		//Won't attack thief
		if(c->GetClass() != THIEF)
		{
			//lose hand
			fitness -= (5 * TREASURE_WORTH);
		}
	}
	//Insurance Salesman
	monsterPower = 14;
	//Your level does not matter
	monsterPower += c->GetLevel();
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (4 * TREASURE_WORTH);
	}
	else
	{
		//Lose 1000 gold (equivalent to a level)
		fitness -= LEVEL_WORTH;
	}
	//Stoned Golem
	monsterPower = 14;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (4 * TREASURE_WORTH);
	}
	else
	{
		//only fights halfling
		if(c->GetRace() == HALFLING)
		{
			fitness -= DEATH;
		}
	}
	//Net Troll
	monsterPower = 10;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (3 * TREASURE_WORTH);
	}
	else
	{
		//Lets higher level players take 1 item from you
		fitness -= (3 * TREASURE_WORTH);
	}
	//Undead Horse
	monsterPower = 4;
	if(c->GetRace() == DWARF)
	{
		monsterPower += 5;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		fitness -= (2 * LEVEL_WORTH);
	}
	//Shrieking Geek
	monsterPower = 6;
	if(isWarrior)
	{
		monsterPower += 6;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		//Lose Race and Class
		if(c->GetRace() != HUMAN)
		{
			fitness -= TREASURE_WORTH;
		}
		if(c->GetClass() != NOCLASS)
		{
			fitness -= TREASURE_WORTH;
		}
	}
	//Pukachu
	monsterPower = 6;
	if(playerWins(power, monsterPower, isWarrior))
	{
		//extra level when killed without help
		fitness += (2 * LEVEL_WORTH) + (2 * TREASURE_WORTH);
	}
	else
	{
		//Lose Hand
		fitness -= (5 * TREASURE_WORTH);
	}
	//Harpies
	monsterPower = 4;
	if(c->GetClass() == WIZARD)
	{
		monsterPower += 5;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		fitness -= (2 * LEVEL_WORTH);
	}
	//Bullrog
	monsterPower = 18;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += (2 * LEVEL_WORTH) + (5 * TREASURE_WORTH);
	}
	else
	{
		if(c->GetLevel() > 4)
		{
			fitness -= DEATH;
		}
	}
	//Mr. Bones
	monsterPower = 2;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + TREASURE_WORTH;
	}
	else
	{
		fitness -= (2 * LEVEL_WORTH);
	}
	//Lame Goblin
	monsterPower = 1;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + TREASURE_WORTH;
	}
	else
	{
		fitness -= LEVEL_WORTH;
	}
	//Squidzilla
	monsterPower = 18;
	if(c->GetRace() == ELF)
	{
		monsterPower += 4;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += (2 * LEVEL_WORTH) + (4 * TREASURE_WORTH);
	}
	else
	{
		//Won't fight non elves below level 5
		if(c->GetLevel() > 4)
		{
			fitness -= DEATH;
		}
		else if(c->GetRace() == ELF)
		{
			fitness -= DEATH;
		}
	}
	//Tongue Demon
	monsterPower = 12;
	if(c->GetClass() == CLERIC)
	{
		monsterPower += 4;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (3 * TREASURE_WORTH);
	}
	else
	{
		if(c->GetRace() == ELF)
		{
			fitness -= (3 * LEVEL_WORTH);
		}
		else
		{
			fitness -= (2 * LEVEL_WORTH);
		}
	}
	//Platycore
	monsterPower = 6;
	if(c->GetClass() == WIZARD)
	{
		monsterPower += 6;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		//Discard hand or lose 2 levels
		fitness -= (5 * TREASURE_WORTH);
	}
	//Potted Plant
	monsterPower = 1;
	if(playerWins(power, monsterPower, isWarrior))
	{
		if(c->GetClass() == ELF)
		{
			fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
		}
		else
		{
			fitness += LEVEL_WORTH + TREASURE_WORTH;
		}
		//No Bad Things
	}
	//Maul Rat
	monsterPower = 1;
	if(c->GetClass() == CLERIC)
	{
		monsterPower += 3;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + TREASURE_WORTH;
	}
	else
	{
		fitness -= LEVEL_WORTH;
	}
	//Crabs
	monsterPower = 1;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + TREASURE_WORTH;
	}
	else
	{
		//Lose armor and footgear
		fitness -= (2 * TREASURE_WORTH);
	}
	//Floating Nose
	monsterPower = 10;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (3 * TREASURE_WORTH);
	}
	else
	{
		//lose 3 levels or 200g item
		fitness -= TREASURE_WORTH;
	}
	//Wight Brothers
	monsterPower = 16;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += (2 * LEVEL_WORTH) + (4 * TREASURE_WORTH);
	}
	else
	{
		//If level > 3 Goto level 1
		if(c->GetLevel() > 3)
		{
			fitness -= (c->GetLevel() * LEVEL_WORTH);
		}
	}
	//Gazebo
	monsterPower = 8;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (3 * TREASURE_WORTH);
	}
	else
	{
		fitness -= (3 * LEVEL_WORTH);
	}
	//Gelatinous Octahedron
	monsterPower = 2;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + TREASURE_WORTH;
	}
	else
	{
		//drop all big items
		fitness -= TREASURE_WORTH;
	}
	//Leperchaun
	monsterPower = 4;
	if(c->GetClass() == ELF)
	{
		monsterPower += 5;
	}
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		fitness -= (2 * TREASURE_WORTH);
	}
	//Amazon
	monsterPower = 8;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		//Give females treasure
		if(c->GetGender() == FEMALE)
		{
			fitness += TREASURE_WORTH;
		}
		//lose class or 3 levels
		else
		{
			if(c->GetClass() == NOCLASS)
			{
				fitness -= (3 * LEVEL_WORTH);
			}
			else
			{
				fitness -= TREASURE_WORTH;
			}
		}
	}
	//Wannabe Vampire
	monsterPower = 12;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + (3 * TREASURE_WORTH);
	}
	else
	{
		//Clerics can just take treasure
		if(c->GetClass() == CLERIC)
		{
			fitness += (3 * TREASURE_WORTH);
		}
		else
		{
			fitness -= (3 * LEVEL_WORTH);
		}
	}
	//Ghoulfriends
	monsterPower = 8;
	//Level Only
	if(playerWins(c->GetLevel(), monsterPower, false))
	{
		fitness += LEVEL_WORTH + (2 * TREASURE_WORTH);
	}
	else
	{
		//level becomes lowest players level, so 1.
		fitness -= (c->GetLevel() * LEVEL_WORTH);
	}
	//Flying Frogs
	monsterPower = 2;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + TREASURE_WORTH;
	}
	else
	{
		fitness -= (2 * LEVEL_WORTH);
	}
	//Plutonium Dragon
	monsterPower = 20;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += (2 * LEVEL_WORTH) + (5 * TREASURE_WORTH);
	}
	else
	{
		//Only attack level > 5
		if(c->GetLevel() > 5)
		{
			fitness -= DEATH;
		}
	}
	//Pitbull
	monsterPower = 2;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += LEVEL_WORTH + TREASURE_WORTH;
	}
	else
	{
		fitness -= (2 * LEVEL_WORTH);
	}
	//Hippogriff
	monsterPower = 16;
	if(playerWins(power, monsterPower, isWarrior))
	{
		fitness += (2 * LEVEL_WORTH) + (4 * LEVEL_WORTH);
	}
	else
	{
		//only attack level > 3
		if(c->GetLevel() > 3)
		{
			//lose card to each player
			fitness -= (5 * TREASURE_WORTH);
		}
	}



	return fitness;
}

void Fitness::PrintChromosome(Chromosome* c)
{
	char* level = (char*) malloc(sizeof(char) * BUFFER);
	switch(c->GetLevel())
	{
		case 1:
			{
				level = "1";
				break;
			}
		case 2:
			{
				level = "2";
				break;
			}
		case 3:
			{
				level = "3";
				break;
			}
		case 4:
			{
				level = "4";
				break;
			}
		case 5:
			{
				level = "5";
				break;
			}
		case 6:
			{
				level = "6";
				break;
			}
		case 7:
			{
				level = "7";
				break;
			}
		case 8:
			{
				level = "8";
				break;
			}
		case 9:
			{
				level = "9";
				break;
			}
	}

	char* gender = (char*) malloc(sizeof(char) * BUFFER);
	if(c->GetGender() == MALE)
	{
		gender = "Male";
	}
	else
	{
		gender = "Female";
	}

	char* race = (char*) malloc(sizeof(char) * BUFFER);
	switch(c->GetRace())
	{
		case HUMAN:
			{
				race = "Human";
				break;
			}
		case ELF:
			{
				race = "Elf";
				break;
			}
		case DWARF:
			{
				race = "Dwarf";
				break;
			}
		case HALFLING:
			{
				race = "Halfling";
				break;
			}
	}

	char* playerClass = (char*) malloc(sizeof(char) * BUFFER);
	switch(c->GetClass())
	{
		case WIZARD:
			{
				playerClass = "Wizard";
				break;
			}
		case WARRIOR:
			{
				playerClass = "Warrior";
				break;
			}
		case CLERIC:
			{
				playerClass = "Cleric";
				break;
			}
		case THIEF:
			{
				playerClass = "Thief";
				break;
			}
		case NOCLASS:
			{
				playerClass = "No Class";
				break;
			}
	}

	char* hand1 = (char*) malloc(sizeof(char) * BUFFER);
	switch(c->GetHand1())
	{
		case BOW_WITH_RIBBONS:
			{
				hand1 = "Bow With Ribbons";
				break;
			}
		case ELEVEN_FOOT_POLE:
			{
				hand1 = "Eleven Foot Pole";
				break;
			}
		case CHAINSAW_OF_BLOODY_DISMEMBERMENT:
			{
				hand1 = "Chainsaw of Bloody Dismemberment";
				break;
			}
		case SWISS_ARMY_POLEARM:
			{
				hand1 = "Swiss Army Polearm";
				break;
			}
		case HUGE_ROCK:
			{
				hand1 = "Huge Rock";
				break;
			}
		case MACE_OF_SHARPNESS:
			{
				hand1 = "Mace of Sharpness";
				break;
			}
		case SNEAKY_BASTARD_SWORD:
			{
				hand1 = "Sneaky Bastard Sword";
				break;
			}
		case BROAD_SWORD:
			{
				hand1 = "Broad Sword";
				break;
			}
		case SHIELD_OF_UBIQUITY:
			{
				hand1 = "Shield of Ubiquity";
				break;
			}
		case CHEESE_GRATER_OF_PEACE:
			{
				hand1 = "Cheese Grater of Peace";
				break;
			}
		case RAT_ON_A_STICK:
			{
				hand1 = "Rat on a Stick";
				break;
			}
		case RAPIER_OF_UNFAIRNESS:
			{
				hand1 = "Rapier of Unfairness";
				break;
			}
		case GENTLEMENS_CLUB:
			{
				hand1 = "Gentlemen's Club";
				break;
			}
		case HAMMER_OF_KNEECAPPING:
			{
				hand1 = "Hammer of Kneecapping";
				break;
			}
		case STAFF_OF_NAPALM:
			{
				hand1 = "Staff of Napalm";
				break;
			}
		case DAGGER_OF_TREACHERY:
			{
				hand1 = "Dagger of Treachery";
				break;
			}
		case BUCKLER_OF_SWASHING:
			{
				hand1 = "Buckler of Swashing";
				break;
			}
		case TUBA_OF_CHARM:
			{
				hand1 = "Tuba of Charm";
				break;
			}
	}
	char* hand2 = (char*) malloc(sizeof(char) * BUFFER);
	switch(c->GetHand2())
	{
		case MACE_OF_SHARPNESS:
			{
				hand2 = "Mace of Sharpness";
				break;
			}
		case SNEAKY_BASTARD_SWORD:
			{
				hand2 = "Sneaky Bastard Sword";
				break;
			}
		case BROAD_SWORD:
			{
				hand2 = "Broad Sword";
				break;
			}
		case SHIELD_OF_UBIQUITY:
			{
				hand2 = "Shield of Ubiquity";
				break;
			}
		case CHEESE_GRATER_OF_PEACE:
			{
				hand2 = "Cheese Grater of Peace";
				break;
			}
		case RAT_ON_A_STICK:
			{
				hand2 = "Rat on a Stick";
				break;
			}
		case RAPIER_OF_UNFAIRNESS:
			{
				hand2 = "Rapier of Unfairness";
				break;
			}
		case GENTLEMENS_CLUB:
			{
				hand2 = "Gentlemen's Club";
				break;
			}
		case HAMMER_OF_KNEECAPPING:
			{
				hand2 = "Hammer of Kneecapping";
				break;
			}
		case STAFF_OF_NAPALM:
			{
				hand2 = "Staff of Napalm";
				break;
			}
		case DAGGER_OF_TREACHERY:
			{
				hand2 = "Dagger of Treachery";
				break;
			}
		case BUCKLER_OF_SWASHING:
			{
				hand2 = "Buckler of Swashing";
				break;
			}
		case TUBA_OF_CHARM:
			{
				hand2 = "Tuba of Charm";
				break;
			}
		case EMPTY:
			{
				hand2 = "Empty Handed";
				break;
			}
	}

	char* armor = (char*) malloc(sizeof(char) * BUFFER);
	switch(c->GetArmor())
	{
		case FLAMING_ARMOR:
			{
				armor = "Flaming Armor";
				break;
			}
		case SLIMY_ARMOR:
			{
				armor = "Slimy Armor";
				break;
			}
		case SHORT_WIDE_ARMOR:
			{
				armor = "Short Wide Armor";
				break;
			}
		case MITHRIL_ARMOR:
			{
				armor = "Mithril Armor";
				break;
			}
		case LEATHER_ARMOR:
			{
				armor = "Leather Armor";
				break;
			}
	}
	char* headgear = (char*) malloc(sizeof(char) * BUFFER);
	switch(c->GetHeadgear())
	{
		case HORNY_HELMET:
			{
				headgear = "Horny Helmet";
				break;
			}
		case POINTY_HAT_OF_POWER:
			{
				headgear = "Pointy Hat of Power";
				break;
			}
		case HELM_OF_COURAGE:
			{
				headgear = "Helm of Courage";
				break;
			}
		case BAD_ASS_BANDANA:
			{
				headgear = "Bad Ass Bandana";
				break;
			}
	}
	char* footgear = (char*) malloc(sizeof(char) * BUFFER);
	switch(c->GetFootgear())
	{
		case BOOTS_OF_RUNNING_REALLY_FAST:
			{
				footgear = "Boots of Running Really Fast";
				break;
			}
		case BOOTS_OF_BUTT_KICKING:
			{
				footgear = "Boots of Butt Kicking";
				break;
			}
		case SANDALS_OF_PROTECTION:
			{
				footgear = "Sandals of Protection";
				break;
			}
	}

	std::cout << level << " " << gender << " " << race << " " << playerClass << "\n" << hand1 << "	" << hand2 << "\n" << armor << " " << headgear << " " << footgear << std::endl;

}
