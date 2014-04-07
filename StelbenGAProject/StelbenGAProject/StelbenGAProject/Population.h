#pragma once
#include "Chromosome.h"
#include "stdlib.h"
#include "Fitness.h"
#include <iostream>

class Population
{
public:
	Population(int size);
	~Population(void);

	void PrintChromosomes(void);
	void GeneratePopulation(void);
	void GeneratePopulation(Chromosome x, Chromosome y);

	Chromosome* GetFittest(void);
	void NewPopulation(bool elitism);
	void PrintPopulationFitness(void);

	Chromosome* GetRankingChromosome(void);


private:
	Chromosome** population;
	int popSize;

	void sortPopulation(void);
};

