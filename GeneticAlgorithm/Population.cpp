/*
 * Population.cpp
 *
 *  Created on: 31 de mai de 2017
 *      Author: willi
 */

#include <iostream>
#include "Population.h"
#include <algorithm>

struct comparator {
	inline bool operator()(const Individual& obj1, const Individual& obj2) {
		return (obj1.fitness > obj2.fitness);
	}
};

Population::Population(bool randomize, int _numberOfIndividuals,
		vector<char> _chromosomePlate) {
	this->numberOfIndividuals = _numberOfIndividuals;
	this->chromosomePlate = _chromosomePlate;
	defineChromosomePlate();
	if (randomize)
		createPopulation();
}

Population::~Population() {
}

void Population::createPopulation() {
	for (int i = 0; i < numberOfIndividuals; i++) {
		Individual ind(true, chromosomePlate);
		ind.calculateFitness(chromosomePlate);
		individuals.push_back(ind);
	}
}

void Population::defineChromosomePlate() {

}

void Population::sortIndividuals() {
	sort(individuals.begin(), individuals.end(), comparator());
}

void Population::printIndividuals() {
	cout << "Printing individuals!" << endl;
	for (auto i : individuals) {
		cout << i.fitness << endl;
	}
}
