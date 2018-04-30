#include "stdafx.h"
#include "Neuron.h"
#include<iostream>

std::string Neuron::check(double a, double b) { // Определяем принадлежность к кластеру
	std::vector<double> out{ 0,0,0,0,0,0,0,0,0,0,0 };
	int min = 0;
	for (size_t i = 0; i < 11; i++) {
		out[i] = pow((x[i] - b), 2) + pow((y[i] - a), 2);
		if (out[min] > out[i]) min = i;
	}
	return name[min];
}

