#pragma once

#define CHROMOSOME_LENGTH 9

enum ChromosomeDetails
{
	LEVEL,
	GENDER,
	RACE,
	CLASS,
	HAND1,
	HAND2,
	ARMOR,
	HEADGEAR,
	FOOTGEAR
};

#define GENDER_SIZE 2

enum Gender
{
	MALE,
	FEMALE
};

#define RACE_SIZE 4

enum Race
{
	HUMAN,
	ELF,
	DWARF,
	HALFLING,
};

#define CLASS_SIZE 5

enum Class
{
	WIZARD,
	WARRIOR,
	CLERIC,
	THIEF,
	NOCLASS
};

#define WEAPONS_SIZE 18
#define TWO_HANDED_WEAPONS 5

enum Weapons
{
	BOW_WITH_RIBBONS,
	ELEVEN_FOOT_POLE,
	CHAINSAW_OF_BLOODY_DISMEMBERMENT,
	SWISS_ARMY_POLEARM,
	HUGE_ROCK,
	MACE_OF_SHARPNESS,
	SNEAKY_BASTARD_SWORD,
	BROAD_SWORD,
	SHIELD_OF_UBIQUITY,
	CHEESE_GRATER_OF_PEACE,
	RAT_ON_A_STICK,
	RAPIER_OF_UNFAIRNESS,
	GENTLEMENS_CLUB,
	HAMMER_OF_KNEECAPPING,
	STAFF_OF_NAPALM,
	DAGGER_OF_TREACHERY,
	BUCKLER_OF_SWASHING,
	TUBA_OF_CHARM,
	EMPTY
};

#define ARMOR_SIZE 5

enum Armor
{
	FLAMING_ARMOR,
	SLIMY_ARMOR,
	SHORT_WIDE_ARMOR,
	MITHRIL_ARMOR,
	LEATHER_ARMOR
};

#define HEADGEAR_SIZE 4

enum Headgear
{
	HORNY_HELMET,
	POINTY_HAT_OF_POWER,
	HELM_OF_COURAGE,
	BAD_ASS_BANDANA
};

#define FOOTGEAR_SIZE 3

enum Footgear
{
	BOOTS_OF_RUNNING_REALLY_FAST,
	BOOTS_OF_BUTT_KICKING,
	SANDALS_OF_PROTECTION
};


class Constants
{
public:
	Constants(void);
	~Constants(void);
};

