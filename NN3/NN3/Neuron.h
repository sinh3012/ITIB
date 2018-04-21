#pragma once
#include <vector>
#include <iostream>

class Neuron
{
public:
	Neuron();
	Neuron(double v0, double v1, double v2, double v3);
	~Neuron();

	double func_phi(std::vector<int> X, std::vector<int> C);
	double func_net(std::vector<int> X);
	int func_y_net(double net);
	int func_delta(std::vector<int> X);
	int func_E();
	int study_neuron(std::vector<std::vector<int>> X);
	void printY();
	void printV();

	std::vector <std::vector<int>> C = { {0,0,0,0 },{0,0,0,1},{1,0,0,0} }; // Центры RBF нейроннов
	std::vector<double> V{ 0,0,0,0 }; // Значения весовых коэффициентов по умолчанию
	std::vector<int> real_func{ 1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0 }; // Значение вектора функции
	std::vector<std::vector<int>> all = { { 0,0,0,0 },{ 0,0,0,1 },{ 0,0,1,0 },{ 0,0,1,1 },
	{ 0,1,0,0 },{ 0,1,0,1 },{ 0,1,1,0 },{ 0,1,1,1 },
	{ 1,0,0,0 },{ 1,0,0,1 },{ 1,0,1,0 },{ 1,0,1,1 },
	{ 1,1,0,0 },{ 1,1,0,1 },{ 1,1,1,0 },{ 1,1,1,1 } }; // Все комбинации вектора Х

};

