// StelbenGAProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));

	std::ofstream resultFile;
	resultFile.open("results2.txt");

	Population* pop = new Population(1000);
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

