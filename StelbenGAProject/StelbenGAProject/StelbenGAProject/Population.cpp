#include "stdafx.h"
#include "Population.h"

Population::Population(int size)
{
	population = (Chromosome**) malloc(sizeof(Chromosome*) * size);
	popSize = size;
	for(int i = 0; i < popSize; i++)
	{
		population[i] = new Chromosome();
		population[i]->SetPower(Fitness::GetPower(population[i]));
		population[i]->SetFitness(Fitness::GetFitness(population[i]));
	}
	sortPopulation();
}


Population::~Population(void)
{
}

Chromosome* Population::GetFittest(void)
{
	return population[0];
}

void Population::NewPopulation(bool elitism)
{
	Chromosome** newPop = (Chromosome**) malloc(sizeof(Chromosome*) * popSize);
	int i = 0;
	if(elitism)
	{
		newPop[0] = population[0];
		i++;
	}
	for(i; i < popSize; i++)
	{
		Chromosome* x = GetRankingChromosome();
		Chromosome* y = GetRankingChromosome();
		newPop[i] = new Chromosome(x,y);
	}
	delete(population);
	population = (Chromosome**) malloc(sizeof(Chromosome*) * popSize);
	for(int i = 0 ; i < popSize; i++)
	{
		population[i] = newPop[i];
	}
	delete(newPop);
	for(int i = 0; i < popSize; i++)
	{
		population[i] = new Chromosome();
		population[i]->SetPower(Fitness::GetPower(population[i]));
		population[i]->SetFitness(Fitness::GetFitness(population[i]));
	}
	sortPopulation();
}

void Population::sortPopulation(void)
{
	for(int i = 0; i < popSize; i++)
	{
		float fitness = -FLT_MAX;
		int fittest = i;
		for(int j = i; j < popSize; j++)
		{
			if(population[j]->GetFitness() > fitness)
			{
				fitness = population[j]->GetFitness();
				fittest = j;
			}
		}
		std::swap(population[i], population[fittest]);
		
	}
}

void Population::PrintPopulationFitness(void)
{
	for(int i = 0; i < popSize; i++)
	{
		if(i % 10 == 0)
		{
			std::cout << "\n";
		}
		std::cout << population[i]->GetFitness() << " ";
	}
}

Chromosome* Population::GetRankingChromosome(void)
{
	int chosen = rand() % ((int) pow(popSize, 2));
	int chromosome = 0;
	for(int i = 0; i < popSize; i++)
	{
		if(chosen >= pow((popSize - i - 1), 2))
		{
			chromosome = i;
			break;
		}
	}
	return population[chromosome];
}

