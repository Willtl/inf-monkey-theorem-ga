/*
 * GeneticAlgorithm.cpp
 *
 *  Created on: 1 de jun de 2017
 *      Author: willi
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(bool elitism, int populationSize,
		int numbGenerations, vector<char> vectorPhrase) {
	cout << "Generating " << populationSize << " monkeys!" << endl;
	Population *pop = new Population(true, populationSize, vectorPhrase);
	
	// Check optimal fitness 
 

	for (int i = 0; i < vectorPhrase.size(); i++) {
		int gene = (int) vectorPhrase[i];
		int genePlate = (int) vectorPhrase[i];
		if (gene == genePlate && gene != 32) {
			optimal++;
		}
	}


	cout << "Starting evolutionary proceedure..." << endl << endl;
	
	for (int i = 0; i < numbGenerations; i++) {
		pop->sortIndividuals();

		Population *newPop = new Population(false, populationSize,
				vectorPhrase);

		if (elitism)
			newPop->individuals.push_back(pop->individuals[0]);

		printBestMonkey(i, pop->individuals[0], vectorPhrase);

		if (pop->individuals[0].chromosome == vectorPhrase){
			cout << "" << endl;
			exit(0);
		}

		while (newPop->individuals.size() < (unsigned) populationSize) {
			Individual parent1 = tournamentSelection(2, pop);
			Individual parent2 = tournamentSelection(2, pop);
			float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			float m = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			if (r < 0.9) {
				vector<Individual> offspring = crossover(parent1, parent2,
						vectorPhrase);
				if (m < 0.01) {
					mutate(offspring[0]);
					mutate(offspring[1]);
				}
				offspring[0].calculateFitness(vectorPhrase);
				offspring[1].calculateFitness(vectorPhrase);
				newPop->individuals.push_back(offspring[0]);
				newPop->individuals.push_back(offspring[1]);
			} else {
				if (m < 0.01) {
					mutate(parent1);
					mutate(parent2);
					parent1.calculateFitness(vectorPhrase);
					parent2.calculateFitness(vectorPhrase);
				}
				newPop->individuals.push_back(parent1);
				newPop->individuals.push_back(parent2);
			}
			pop = newPop;
		}
	}
}

GeneticAlgorithm::~GeneticAlgorithm() {
}

Individual GeneticAlgorithm::tournamentSelection(int int1, Population *pop) {
	int min = 0, max = pop->individuals.size() - 1;
	int idParent1 = rand() % (max - min + 1) + min;
	int idParent2 = rand() % (max - min + 1) + min;
	while (idParent1 == idParent2)
		idParent2 = rand() % (max - min + 1) + min;

	Individual ind1 = pop->individuals[idParent1];
	Individual ind2 = pop->individuals[idParent2];

	if (ind1.fitness >= ind2.fitness)
		return ind1;
	else
		return ind2;
}

vector<Individual> GeneticAlgorithm::crossover(Individual parent1,
		Individual parent2, vector<char> vectorPhrase) {
	int min = 0, max = parent1.chromosome.size();

	int startRange = rand() % ((max - 1) - min + 1) + min;
	int endRange = rand() % (max - startRange + 1) + startRange;
	while (startRange == endRange)
		endRange = rand() % (max - startRange + 1) + startRange;

	vector<char> offChromo1(parent1.chromosome.size());
	vector<char> offChromo2(parent1.chromosome.size());

	for (int i = 0; (unsigned) i < parent1.chromosome.size(); i++) {
		if (i < startRange || i > endRange) {
			offChromo1[i] = parent1.chromosome[i];
			offChromo2[i] = parent2.chromosome[i];
		} else {
			offChromo1[i] = parent2.chromosome[i];
			offChromo2[i] = parent1.chromosome[i];
		}
	}

	Individual offspring1(false, offChromo1);
	Individual offspring2(false, offChromo2);

	vector<Individual> offspring { offspring1, offspring2 };

	return offspring;
}

void GeneticAlgorithm::mutate(Individual& ind) {
	int min = 0, max = ind.chromosome.size();
	int placeToMutate = rand() % ((max - 1) - min + 1) + min;
	while (true)
		if (32 == (int) ind.chromosome[placeToMutate])
			placeToMutate = rand() % ((max - 1) - min + 1) + min;
		else
			break;
	int charNumber = rand() % (122 - 97 + 1) + 97;
	char mutatedCharacter = (char) charNumber;
	ind.chromosome[placeToMutate] = mutatedCharacter;
}

void GeneticAlgorithm::printBestMonkey(int generation, Individual& monkey, vector<char> vectorPhrase) {
	// cout << "Best \"monkey\" of generation " << (generation + 1) << ": " << monkey.fitness << " (optimal = " << optimal << ")" << endl;
	
	for(size_t i = 0; i < monkey.chromosome.size(); i++){
		if(monkey.chromosome[i] != vectorPhrase[i])
			cout << "\033[1;31m" << monkey.chromosome[i] << "\033[0m";
		else
			cout << "\033[1;32m" << monkey.chromosome[i] << "\033[0m";
	}
	cout << endl; 
}
