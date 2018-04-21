#include "stdafx.h"
#include "Neuron.h"

Neuron::Neuron() {
	std::vector<int> null = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (size_t i = 0; i < null.size(); i++) {
		W.push_back(null);
	}
}

Neuron::~Neuron() {}

int Neuron::check(std::vector<int> X) { // Распознование образа
	if (X.size() != W.size()) return 0;
	std::vector<int> Y(X); // Функция активации
	for (int k = 0; k < W.size(); k++) {
		int net = 0;
		for (int j = 0; j <= k - 1; j++) {
			net += W[j][k] * Y[j];
		}
		for (int j = k + 1; j < W.size(); j++) {
			net += W[j][k] * X[j];
		}
		if (net > 0) {
			Y[k] = 1;
		}
		else if (net < 0) {
			Y[k] = -1;
		}
		if (k % 5 == 0) std::cout << std::endl;
		if (Y[k] < 0) std::cout << "0";
		else std::cout << "" << "X"/*Y[k]*/;
	}

	

}

int Neuron::study_neuron() { // Вычисление матрицы весов
	for (size_t j = 0; j < W.size(); j++) {
		for (size_t i = 0; i < W.size(); i++) {
			if (i != j) {
				for (size_t l = 0; l < L.size(); l++) {
					W[j][i] += L[l][i] * L[l][j];
				}
			}
		}
	}
	return 0;
}

void Neuron::printW() { // Печать матрицы весов
	std::cout << " W = " << std::endl;
	for (auto elem1 : W) {
		for (auto elem2 : elem1) {
			if (elem2 >= 0) std::cout << " ";
			std::cout << " " << elem2;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Neuron::printL() { // Печать заданных образов-паттернов
	std::cout << " L = " << std::endl;
	for (auto elem1 : L) {
		int k = 0;
		for (auto elem2 : elem1) {
			if (k % 5 == 0) std::cout << std::endl;
			if (elem2 < 0) std::cout << "0";
			else std::cout << "" << "X"/*elem2*/;
			k++;
		}
		std::cout << std::endl;
	}
}