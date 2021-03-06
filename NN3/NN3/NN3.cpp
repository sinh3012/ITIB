// NN3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Neuron.h"
#include <string>
#include <vector>
#include <iostream>


int main(int argc, char *argv[]) {
	std::vector<std::vector<int>> min1 = { { 0,0,0,1 },{ 1,1,1,0 },{ 1,0,0,0 },{ 1,0,0,1 } };
	std::vector<std::vector<int>> min2 = { { 0,0,0,1 },{ 0,1,1,0 },{ 1,0,0,0 },{ 1,0,0,1 } };
	std::vector<std::vector<int>> min0 = { { 0,0,0,0 },{ 1,1,1,1 } };
	std::vector<std::vector<int>> study_vectors = { { 0,0,0,0 },{ 0,0,0,1 },{ 0,0,1,0 },{ 0,0,1,1 },
	{ 0,1,0,0 },{ 0,1,0,1 },{ 0,1,1,0 },{ 0,1,1,1 },
	{ 1,0,0,0 },{ 1,0,0,1 },{ 1,0,1,0 },{ 1,0,1,1 },
	{ 1,1,0,0 },{ 1,1,0,1 },{ 1,1,1,0 },{ 1,1,1,1 } }; // Все комбинации вектора Х

	Neuron neur;
	neur.study_neuron(min0);

	int pause;
	std::cin >> pause;
	return 0;
}


