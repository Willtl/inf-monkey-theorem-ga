/*
 * GeneticAlgorithm.h
 *
 *  Created on: 1 de jun de 2017
 *      Author: willi
 */

#ifndef GENETICALGORITHM_GENETICALGORITHM_H_
#define GENETICALGORITHM_GENETICALGORITHM_H_

#include <vector>
#include "Population.h"
#include "Individual.h"

using namespace std;

class GeneticAlgorithm {
public:
	GeneticAlgorithm(bool, int, int, vector<char>);
	virtual ~GeneticAlgorithm();

	Individual tournamentSelection(int, Population*);
	vector<Individual> crossover(Individual, Individual, vector<char>);
	void mutate(Individual&);
	void printBestMonkey(int, Individual&, vector<char>);

	int optimal = 0;
};

#endif /* GENETICALGORITHM_GENETICALGORITHM_H_ */
