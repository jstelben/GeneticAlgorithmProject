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
	std::ofstream resultFile;
	resultFile.open("results.txt");


	Population* pop = new Population(50);
	for(int i = 0; i < 5000; i++)
	{
		Chromosome* c = pop->GetFittest();
		resultFile << "Fitness: " << c->GetFitness() << std::endl;
		resultFile << "Power: " << c->GetPower();
		Fitness::WriteChromosome(c, &resultFile);

		pop->NewPopulation(true);
	}
	
	resultFile.close();
	return 0;
}

