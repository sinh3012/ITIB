// NN2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Neuron.h"
#include <string>
#include <vector>
#include <iostream>



int main(int argc, char *argv[]) {
	if (argc == 2) {
		int n = atoi(argv[1]);
		if (n <= 0) n = 4000;
		Neuron neur;
		neur.get_real_func();
		neur.study_neuron(n);
		neur.work_neuron();
	}
	else {
		Neuron neur;
		neur.get_real_func();
		neur.study_neuron(4000);
		neur.work_neuron();
	}
	
	int pause;
	std::cin >> pause;
	return 0;
}


