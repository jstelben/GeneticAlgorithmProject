#include "stdafx.h"
#include "Population.h"

//Creates a population of a given size
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
	for(int i = 0; i < popSize; i++)
	{
		delete(population[i]);
	}
	delete(population);
}

//Returns Chromosome with highest Fitness score
Chromosome* Population::GetFittest(void)
{
	return population[0];
}

//Creates a new population
void Population::NewPopulation(bool elitism)
{
	Chromosome** newPop = (Chromosome**) malloc(sizeof(Chromosome*) * popSize);
	int i = 0;
	//if elitism is actived save the fittest chromosome
	if(elitism)
	{
		newPop[0] = population[0];
		i++;
	}
	for(i; i < popSize; i++)
	{
		//Gets two chromosomes based on ranking
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
		population[i]->SetPower(Fitness::GetPower(population[i]));
		population[i]->SetFitness(Fitness::GetFitness(population[i]));
	}
	sortPopulation();
}

//Selection Sort based on Fitness scores
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

//Prints every Chromosome's Fitness score
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

//Uses ranking system to return a Chromosome
//Picks a random number between 0 and popSize^2
//The sorted chromosome list has the rankings as (popSize - index - 1) ^ 2
//Fitter chromosomes have a better chance at selection than less fit.
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

