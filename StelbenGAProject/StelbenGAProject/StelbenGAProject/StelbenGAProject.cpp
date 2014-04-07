// StelbenGAProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	/*
	Chromosome* c = new Chromosome();
	c->SetPower(Fitness::GetPower(c));
	c->SetFitness(Fitness::GetFitness(c));
	std::cout << c->GetFitness() << std::endl;
	std::cout << c->GetPower() << std::endl;
	c->PrintChromosome();
	Fitness::PrintChromosome(c);
	*/
	


	Population* pop = new Population(30);
	for(int i = 0; i < 300; i++)
	{
		Chromosome* c = pop->GetFittest();
		std::cout << c->GetFitness() << std::endl;
		std::cout << c->GetPower() << std::endl;
		c->PrintChromosome();
		Fitness::PrintChromosome(c);

		pop->NewPopulation(true);
	}
	
	
	return 0;
}

