#pragma once
#include "Chromosome.h"
#include <iostream>
#include <fstream>
class Fitness
{
public:
	Fitness(void);
	~Fitness(void);
	static int GetPower(Chromosome* c);
	static float GetFitness(Chromosome* c);
	static void PrintChromosome(Chromosome* c);
	static void WriteChromosome(Chromosome* c, std::ofstream* file);
};

