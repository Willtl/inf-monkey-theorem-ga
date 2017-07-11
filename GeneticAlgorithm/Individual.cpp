/*
 * Individual.cpp
 *
 *  Created on: 31 de mai de 2017
 *      Author: willi
 */

#include "Individual.h"
#include <iostream>
#include <stdlib.h>

Individual::Individual(bool random, vector<char> chromosomePlate) {
	if (random)
		generateRandomChromosome(chromosomePlate);
	else
		createIndividualWithChromosome(chromosomePlate);
}

Individual::~Individual() {
}

void Individual::generateRandomChromosome(vector<char> chromosomePlate) {
	this->chromosome = chromosomePlate;
	for (int i = 0; i < chromosome.size(); i++) {
		char gene = chromosome[i];
		if ((int) gene >= 97 && (int) gene <= 122) {
			char random = generateRandomCharacter(97, 122);
			chromosome[i] = random;
		}
	}
}

char Individual::generateRandomCharacter(int min, int max) {
	int mean = rand() % (max - min + 1) + min;
	return (char) mean;
}

void Individual::createIndividualWithChromosome(vector<char> chromosome) {
	this->chromosome = chromosome;
}

void Individual::calculateFitness(vector<char> chromosomePlate) {
	fitness = 0;

	for (int i = 0; i < chromosome.size(); i++) {
		int gene = (int) chromosome[i];
		int genePlate = (int) chromosomePlate[i];
		if (gene == genePlate && gene != 32) {
			fitness++;
		}
	}
}

