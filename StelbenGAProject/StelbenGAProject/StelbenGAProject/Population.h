#pragma once
#include "Chromosome.h"

class Population
{
public:
	Population(void);
	~Population(void);

	void PrintChromosomes(void);
	void GeneratePopulation(void);
	void GeneratePopulation(Chromosome x, Chromosome y);


private:
	Chromosome population[];

};

