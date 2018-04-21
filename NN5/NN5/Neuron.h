#pragma once
#include <vector>
#include <iostream>

class Neuron
{
public:
	Neuron();
	~Neuron();

	int study_neuron();
	int check(std::vector<int> X);
	void printW();
	void printL();

	std::vector<std::vector<int>> W; // Матрица весов
	std::vector<std::vector<int>> L{ { 1,-1,-1,-1,1, 1,-1,-1,-1,1, -1,1,-1,1,-1, -1,1,-1,1,-1, -1,-1,1,-1,-1 },
	{ -1,-1,1,-1,-1, -1,-1,1,-1,-1, -1,-1,1,-1,-1, -1,-1,1,-1,-1, -1,-1,1,-1,-1 } ,
	{ 1,-1,-1,-1,1, -1,1,-1,1,-1, -1,-1,1,-1,-1, -1,1,-1,1,-1, 1,-1,-1,-1,1 } }; // Образы-паттерны
};


