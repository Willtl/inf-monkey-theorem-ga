//============================================================================
// Name        : ToBeOrNotToBe.cpp
// Author      : Willtl
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <math.h>
#include "GeneticAlgorithm/GeneticAlgorithm.h"


using namespace std;

// GA configuration
static int populationSize = 250;
static int numberOfGenerations = 1000; // 0 to evolve until final solution
static bool elitism = true;

vector<char> parseStringToCharArray(string str);
string readPhrase(bool showPhrase);
void removeWhiteSpaces(vector<char>& phrase);
void calculateRandomProbability(vector<char> phrase);

int main() {
	srand(time(NULL));
	string phrase = readPhrase(false);
	transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
	vector<char> vectorPhrase = parseStringToCharArray(phrase);
	calculateRandomProbability(vectorPhrase);
	GeneticAlgorithm ga(elitism, populationSize, numberOfGenerations,
			vectorPhrase);
	return 0;
}

vector<char> parseStringToCharArray(string str) {
	vector<char> data(str.begin(), str.end());
	return data;
}

string readPhrase(bool showPhrase) {
	string phrase;
	cout << "Enter a Shakespeare Poem or phrase:";
	getline(cin, phrase);
	if (showPhrase)
		cout << phrase << endl;
	return phrase;
}

void removeWhiteSpaces(vector<char>& phrase) {
	for (int i = 0; (unsigned) i < phrase.size(); i++) {
		if (isspace(phrase[i])) {
			cout << "espaco" << endl;
			phrase.erase(phrase.begin() + i);
		}
	}
}

void calculateRandomProbability(vector<char> phrase) {
	int exponent = 0;
	for (int i = 0; (unsigned) i < phrase.size(); i++) {
		char gene = phrase[i];
		if ((int) gene >= 97 && (int) gene <= 122) {
			exponent++;
		}
	}

	cout << endl << "Ignoring punctuation, spacing, and capitalization, "
			"a monkey typing letters uniformly at random has a chance of one in 26^" << exponent << " (" << (pow(26,exponent)) << ")" << " of correctly typing your poem: ";

	for(auto i : phrase)
		cout << i;
	cout << endl << endl;
}
