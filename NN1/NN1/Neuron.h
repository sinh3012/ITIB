#pragma once
#include <vector>
#include <iostream>

class Neuron
{
public:
	Neuron();
	Neuron(double w0, double w1, double w2, double w3, double w4);
	~Neuron();

	double func_net(std::vector<int> X);
	double func_out(double net);
	int func_y_net(double net);
	int func_y_out(double out);
	int func_delta(std::vector<int> X);
	int func_E();
	int study_neuron(std::vector<std::vector<int>> X);
	double func_df(double net);
	void printY();
	void printW();
	void this_logistic_func(bool key);

	bool logistic_activation_func = false;
	std::vector<double> W{ 0,0,0,0,0 }; // Значения весовых коэффициентов по умолчанию
	std::vector<int> real_func { 1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0 }; // Значение вектора функции
	std::vector<std::vector<int>> all = { { 1,0,0,0,0 },{ 1,0,0,0,1 },{ 1,0,0,1,0 },{ 1,0,0,1,1 },
	{ 1,0,1,0,0 },{ 1,0,1,0,1 },{ 1,0,1,1,0 },{ 1,0,1,1,1 },
	{ 1,1,0,0,0 },{ 1,1,0,0,1 },{ 1,1,0,1,0 },{ 1,1,0,1,1 },
	{ 1,1,1,0,0 },{ 1,1,1,0,1 },{ 1,1,1,1,0 },{ 1,1,1,1,1 } }; // Все комбинации вектора Х
	
};

