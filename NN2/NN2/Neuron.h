#pragma once
#include <vector>
#include <iostream>

class Neuron
{
public:
	Neuron();
	Neuron(double w0, double w1, double w2, double w3, double w4);
	~Neuron();

	void get_real_func();
	double func_delta(double real, double neur);
	double func_E();
	double study_neuron(int k);
	void work_neuron();
	void printW();

	std::vector<double> W{ 0,0,0,0,0 }; // Значения весовых коэффициентов по умолчанию
	std::vector<double> real_func; // Значение вектора функции
	std::vector<double> neur_func; // Спрогназированнное значение
};

