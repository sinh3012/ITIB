// NN4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Neuron.h"
#include <string>
#include <vector>
#include <iostream>


int main(int argc, char *argv[]) {
	Neuron neur;
	neur.study_neuron();

	int pause;
	std::cin >> pause;
	return 0;
}
