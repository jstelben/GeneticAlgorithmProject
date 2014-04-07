#pragma once
#include <stdlib.h>
#include "Constants.h"
#include <random>
#include <iostream>



class Chromosome
{
public:
	Chromosome(void);
	Chromosome(Chromosome* x, Chromosome* y);
	~Chromosome(void);
	
	float GetFitness(void);
	void SetFitness(float f);
	int GetPower(void);
	void SetPower(int p);

	int GetLevel(void);
	int GetGender(void);
	int GetRace(void);
	int GetClass(void);
	int GetHand1(void);
	int GetHand2(void);
	int GetArmor(void);
	int GetHeadgear(void);
	int GetFootgear(void);
	int GetGeneAt(int index);

	void PrintChromosome();
private:
	int* gene;
	float fitness;
	int power;

	void mutate(void);
	void makeRandomGene(void);
};

