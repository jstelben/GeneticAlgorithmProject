#include "stdafx.h"
#include "Chromosome.h"



Chromosome::Chromosome(void)
{
	gene = (int*) malloc(sizeof(int) * CHROMOSOME_LENGTH);
	fitness = 0;
	power = 0;
	makeRandomGene();
}


Chromosome::~Chromosome(void)
{
	delete(gene);
}

void Chromosome::mutate()
{

}

void Chromosome::makeRandomGene()
{
	gene[LEVEL] = (1 + rand() % 8);
	gene[GENDER] = rand() % GENDER_SIZE;
	gene[RACE] = rand() % RACE_SIZE;
	gene[CLASS] = rand() % CLASS_SIZE;
	gene[HAND1] = rand() % WEAPONS_SIZE;
	if(gene[HAND1] < TWO_HANDED_WEAPONS)
	{
		gene[HAND2] = EMPTY;
	}
	else
	{
		gene[HAND2] = gene[HAND1];
		while(gene[HAND2] == gene[HAND1])
		{
			gene[HAND2] = TWO_HANDED_WEAPONS + rand() % (WEAPONS_SIZE - TWO_HANDED_WEAPONS);
		}
	}
	gene[ARMOR] = rand() % ARMOR_SIZE;
	gene[HEADGEAR] = rand() % HEADGEAR_SIZE;
	gene[FOOTGEAR] = rand() % FOOTGEAR_SIZE;
}

float Chromosome::GetFitness()
{
	return fitness;
}

void Chromosome::SetFitness(float f)
{
	fitness = f;
}

int Chromosome::GetPower()
{
	return power;
}

void Chromosome::SetPower(int p)
{
	power = p;
}


int Chromosome::GetLevel()
{
	return gene[LEVEL];
}

int Chromosome::GetGender()
{
	return gene[GENDER];
}

int Chromosome::GetRace()
{
	return gene[RACE];
}


int Chromosome::GetClass()
{
	return gene[CLASS];
}


int Chromosome::GetHand1()
{
	return gene[HAND1];
}


int Chromosome::GetHand2()
{
	return gene[HAND2];
}


int Chromosome::GetArmor()
{
	return gene[ARMOR];
}


int Chromosome::GetHeadgear()
{
	return gene[HEADGEAR];
}

int Chromosome::GetFootgear()
{
	return gene[FOOTGEAR];
}

void Chromosome::PrintChromosome()
{
	for(int i = 0; i < CHROMOSOME_LENGTH; i++)
	{
		std::cout << gene[i] << " ";
	}
}

