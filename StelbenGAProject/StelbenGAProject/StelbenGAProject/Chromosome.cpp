#include "stdafx.h"
#include "Chromosome.h"


//Makes a random Chromosome
Chromosome::Chromosome(void)
{
	gene = (int*) malloc(sizeof(int) * CHROMOSOME_LENGTH);
	fitness = 0;
	power = 0;
	makeRandomGene();
}

//Makes a Chromosome by crossingover two others
Chromosome::Chromosome(Chromosome* x, Chromosome* y)
{
	gene = (int*) malloc(sizeof(int) * CHROMOSOME_LENGTH);
	fitness = 0;
	power = 0;

	//Choose random crossover index
	int crossoverIndex = rand() % (CHROMOSOME_LENGTH - 1);
	for(int i = 0; i < CHROMOSOME_LENGTH; i++)
	{
		if(i < crossoverIndex)
		{
			gene[i] = x->GetGeneAt(i);
		}
		else
		{
			gene[i] = y->GetGeneAt(i);
		}
	}
	mutate();
}

//Deconstructor
Chromosome::~Chromosome(void)
{
	delete(gene);
}

//Gives each gene a chance to change
void Chromosome::mutate(void)
{
	for(int i = 0; i < CHROMOSOME_LENGTH; i++)
	{
		int mutateAt = rand() % 100;
		if(mutateAt <= MUTATE_CHANCE)
		{
			switch(i)
			{
				case LEVEL:
					{
						gene[LEVEL] = (1 + rand() % 9);
						break;
					}
				case GENDER:
					{
						gene[GENDER] = rand() % GENDER_SIZE;
						break;
					}
				case RACE:
					{
						gene[RACE] = rand() % RACE_SIZE;
						break;
					}
				case CLASS:
					{
						gene[CLASS] = rand() % CLASS_SIZE;
						break;
					}
				case HAND1:
					{
						gene[HAND1] = rand() % WEAPONS_SIZE;
						if(gene[HAND1] < TWO_HANDED_WEAPONS)
						{
							gene[HAND2] = EMPTY;
						}
						break;
					}
				case HAND2:
					{
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
						break;
					}
				case ARMOR:
					{
						gene[ARMOR] = rand() % ARMOR_SIZE;
						break;
					}
				case HEADGEAR:
					{
						gene[HEADGEAR] = rand() % HEADGEAR_SIZE;
						break;
					}
				case FOOTGEAR:
					{
						gene[FOOTGEAR] = rand() % FOOTGEAR_SIZE;
						break;
					}
			}
		}
	}
}

//Randomly sets each gene
void Chromosome::makeRandomGene(void)
{
	gene[LEVEL] = (1 + rand() % 9);
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

//Get fitness score
float Chromosome::GetFitness(void)
{
	return fitness;
}

//Set fitness score
void Chromosome::SetFitness(float f)
{
	fitness = f;
}

//Get power
int Chromosome::GetPower(void)
{
	return power;
}

//Set power
void Chromosome::SetPower(int p)
{
	power = p;
}


int Chromosome::GetLevel(void)
{
	return gene[LEVEL];
}

int Chromosome::GetGender(void)
{
	return gene[GENDER];
}

int Chromosome::GetRace(void)
{
	return gene[RACE];
}


int Chromosome::GetClass(void)
{
	return gene[CLASS];
}


int Chromosome::GetHand1(void)
{
	return gene[HAND1];
}


int Chromosome::GetHand2(void)
{
	return gene[HAND2];
}


int Chromosome::GetArmor(void)
{
	return gene[ARMOR];
}


int Chromosome::GetHeadgear(void)
{
	return gene[HEADGEAR];
}

int Chromosome::GetFootgear(void)
{
	return gene[FOOTGEAR];
}

//Prints every number in the Shromosome
void Chromosome::PrintChromosome(void)
{
	for(int i = 0; i < CHROMOSOME_LENGTH; i++)
	{
		std::cout << gene[i] << " ";
	}
}

//Returns gene at given index
int Chromosome::GetGeneAt(int index)
{
	return gene[index];
}
