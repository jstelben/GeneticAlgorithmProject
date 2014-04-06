#pragma once
#include <stdlib.h>
#include "Constants.h"
#include <random>
#include <iostream>



class Chromosome
{
public:
	Chromosome(void);
	Chromosome(Chromosome* parent);
	~Chromosome(void);
	
	float GetFitness();
	void SetFitness(float f);
	int GetPower();
	void SetPower(int p);

	int GetLevel();
	int GetGender();
	int GetRace();
	int GetClass();
	int GetHand1();
	int GetHand2();
	int GetArmor();
	int GetHeadgear();
	int GetFootgear();

	void PrintChromosome();
private:
	int* gene;
	float fitness;
	int power;

	void mutate(void);
	void makeRandomGene(void);
};

