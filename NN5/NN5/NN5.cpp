// NN5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Neuron.h"
#include <string>
#include <vector>
#include <iostream>


int main(int argc, char *argv[]) {
	std::vector<int> pic{ 1,-1,-1,-1,-1, -1,1,-1,1,-1, -1,-1,-1,-1,-1, 1,1,-1,1,-1, 1,-1,-1,-1,1 };

	Neuron neur;
	neur.study_neuron();
	neur.printW();
	neur.printL();
	std::cout << std::endl << " X =" << std::endl;
	neur.check(pic);
	int pause;
	std::cin >> pause;
	return 0;
}


