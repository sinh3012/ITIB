// NN1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Neuron.h"
#include <string>
#include <vector>
#include <iostream>

/*
class Neuron
{
public:
	Neuron() {}

	Neuron(int w0, int w1, int w2, int w3, int w4) { // Задаем начальные значение вектора весов
		W[0] = w0;
		W[1] = w1;
		W[2] = w2;
		W[3] = w3;
		W[4] = w4;
	}

	double func_net(std::vector<int> X) {
		double net = 0;
		for (int i = 0; i < 5; i++) {
			net += X[i] * W[i];
		}
		return net;
	}

	int func_y(double net) {
		if (net >= 0) return 1;
		else return 0;
	}

	int func_delta(std::vector<int> X) {
		int index = X[4] + 2 * (X[3] + 2 * (X[2] + 2 * (X[1]))); // Находим индекс вектора Х
		int delta = real_func[index] - func_y(func_net(X));
		return delta;
	}

	int func_E() {
		int E = 0;
		for (auto elem : all) {
			E += abs(func_delta(elem));
		}
		return E;
	}

	int study_neuron(std::vector<std::vector<int>> X) { // Обучение нейрона
		int k = 0; // Номер эпохи
		while ((func_E() > 0) && (k < 100)) { // Пока есть ошибка (и жива надежда)
			std::cout << "k = " << k << " E = " << func_E() <<  std::endl;
			printY();
			printW();
			std::vector<double> delta_w{ 0,0,0,0,0 }; // Вектор смещения весов
			double n = 0.3; // Коэффициент обучения
			for (auto elem : X) {
				for (int i = 0; i < 5; i++) {
					delta_w[i] += n * func_delta(elem)*elem[i];
				}
			}
			for (int i = 0; i < 5; i++) {
				W[i] += delta_w[i];
			}
			k++;
		}
		return k;
	}

	double func_df(double net) {
		double df = 1 / (2 * (abs(net) + 1)*(abs(net) + 1));
		return df;
	}

	void printY() { // Вывод вектора значений функции нейрона
		std::cout << "Y = ( ";
		for (auto elem : all) {
			std::cout << func_y(func_net(elem)) << " ";
		}
		std::cout << ")" << std::endl;
	}

	void printW() { // Вывод вектора весов нейрона
		std::cout << "W = ( ";
		for (int i = 0; i < 5; i++) {
			std::cout << W[i] << " ";
		}
		std::cout << ")" << std::endl;
	}

	std::vector<double> W{ 0,0,0,0,0 }; // Значения весовых коэффициентов по умолчанию
	std::vector<int> real_func { 1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0 }; // Значение вектора функции
	std::vector<std::vector<int>> all = { { 1,0,0,0,0 },{ 1,0,0,0,1 },{ 1,0,0,1,0 },{ 1,0,0,1,1 },
	{ 1,0,1,0,0 },{ 1,0,1,0,1 },{ 1,0,1,1,0 },{ 1,0,1,1,1 },
	{ 1,1,0,0,0 },{ 1,1,0,0,1 },{ 1,1,0,1,0 },{ 1,1,0,1,1 },
	{ 1,1,1,0,0 },{ 1,1,1,0,1 },{ 1,1,1,1,0 },{ 1,1,1,1,1 } }; // Все комбинации вектора Х
	
};
*/



int main(int argc, char *argv[]) {
	std::vector<std::vector<int>> min1 = { { 1,0,0,0,1 },{ 1,1,1,1,0 },{ 1,1,0,0,0 },{ 1,1,0,0,1 }};
	std::vector<std::vector<int>> min2 = { { 1,0,0,0,1 },{ 1,0,1,1,0 },{ 1,1,0,0,0 },{ 1,1,0,0,1 } };
	std::vector<std::vector<int>> study_vectors = { { 1,0,0,0,0 },{ 1,0,0,0,1 },{ 1,0,0,1,0 },{ 1,0,0,1,1 },
	{ 1,0,1,0,0 },{ 1,0,1,0,1 },{ 1,0,1,1,0 },{ 1,0,1,1,1 },
	{ 1,1,0,0,0 },{ 1,1,0,0,1 },{ 1,1,0,1,0 },{ 1,1,0,1,1 },
	{ 1,1,1,0,0 },{ 1,1,1,0,1 },{ 1,1,1,1,0 },{ 1,1,1,1,1 } }; // Все комбинации вектора Х

	if ((argc == 6) || (argc == 7)){
		std::string s = argv[1];
		double w0 = std::stod(s);
		s = argv[2];
		double w1 = std::stod(s);
		s = argv[3];
		double w2 = std::stod(s);
		s = argv[4];
		double w3 = std::stod(s);
		s = argv[5];
		double w4 = std::stod(s);
		Neuron neur(w0,w1,w2,w3,w4);
		if (argc == 7) {
			s = argv[6];
			std::string s0("1");
			if (s == s0) {
				neur.this_logistic_func(true);
			}
		}
		neur.study_neuron(study_vectors);
	}
	else if (argc == 2) {
		Neuron neur;
		std::string s = argv[1];
		std::string s0("1");
		if (s == s0) {
			neur.this_logistic_func(true);
		}
		neur.study_neuron(study_vectors);
	}
	else {
		Neuron neur;
		neur.study_neuron(study_vectors);
	}
	
	int pause;
	std::cin >> pause;
    return 0;
}

