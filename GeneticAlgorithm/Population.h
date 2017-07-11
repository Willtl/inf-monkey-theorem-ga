/*
 * Population.h
 *
 *  Created on: 31 de mai de 2017
 *      Author: willi
 */

#ifndef GENETICALGORITHM_POPULATION_H_
#define GENETICALGORITHM_POPULATION_H_

#include<vector>
#include "Individual.h"

using namespace std;

class Population {
private:
	void createPopulation();
	void defineChromosomePlate();
public:
	Population(bool, int, vector<char>);
	virtual ~Population();

	void printIndividuals();
	void sortIndividuals();

	int numberOfIndividuals;
	vector<char> chromosomePlate;
	vector<Individual> individuals;
};

#endif /* GENETICALGORITHM_POPULATION_H_ */
