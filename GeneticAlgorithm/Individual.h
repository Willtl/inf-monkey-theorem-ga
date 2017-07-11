/*
 * Individual.h
 *
 *  Created on: 31 de mai de 2017
 *      Author: willi
 */

#ifndef GENETICALGORITHM_INDIVIDUAL_H_
#define GENETICALGORITHM_INDIVIDUAL_H_

#include <vector>

using namespace std;

class Individual {
private:
	void generateRandomChromosome(vector<char>);
	void createIndividualWithChromosome(vector<char>);
	char generateRandomCharacter(int, int);
public:
	Individual(bool,vector<char>);
	virtual ~Individual();

	void calculateFitness(vector<char>);

	vector<char> chromosome;
	int fitness;
};

#endif /* GENETICALGORITHM_INDIVIDUAL_H_ */
