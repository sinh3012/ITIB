#include "stdafx.h"
#include "Neuron.h"

Neuron::Neuron() {}

Neuron::Neuron(double v0, double v1, double v2, double v3) { // Задаем начальные значение вектора весов
	V[0] = v0;
	V[1] = v1;
	V[2] = v2;
	V[3] = v3;
}

Neuron::~Neuron() {}

double Neuron::func_phi(std::vector<int> X, std::vector<int> C) { //Гауссовская ФА
	double phi = 0;
	for (size_t i = 0; i < X.size(); i++) {
		phi += pow((X[i] - C[i]),2);
	}
	phi = exp(-phi);
	return phi;
}

double Neuron::func_net(std::vector<int> X) { // Комбинированный (сетевой) вход
	double net = 0;
	for (size_t i = 0; i < C.size(); i++) {
		net += V[i+1] * func_phi(X,C[i]);
	}
	net += V[0];
	return net;
}

int Neuron::func_y_net(double net) { // Реальный выход нейронной сети
	if (net >= 0) return 1;
	else return 0;
}



int Neuron::func_delta(std::vector<int> X) { // Ошибка вектора выборки
	int index = X[3] + 2 * (X[2] + 2 * (X[1] + 2 * (X[0]))); // Находим индекс вектора Х
	int delta = 0;
	delta = real_func[index] - func_y_net(func_net(X));
	return delta;
}

int Neuron::func_E() { // Суммарная квадратичная ошибка
	int E = 0;
	for (auto elem : all) {
		E += abs(func_delta(elem));
	}
	return E;
}

int Neuron::study_neuron(std::vector<std::vector<int>> X) { // Обучение нейронной сети
	int k = 0; // Номер эпохи
	while ((func_E() > 0) && (k < 200)) { // Пока есть ошибка (и жива надежда)
		std::cout << "k = " << k << " E = " << func_E() << std::endl;
		printY();
		printV();
		std::vector<double> delta_v{ 0,0,0,0 }; // Вектор смещения весов
		double n = 0.3; // Коэффициент обучения
		for (auto elem : X) {
			delta_v[0] += n * func_delta(elem);
			for (size_t i = 0; i < C.size(); i++) {
				delta_v[i + 1] += n * func_delta(elem)*func_phi(elem, C[i]);
			}
			for (size_t i = 0; i < delta_v.size(); i++) {
				V[i] += delta_v[i];
			}
		}
		k++;
	}
	std::cout << "k = " << k << " E = " << func_E() << std::endl;
	printY();
	printV();
	return k;
}


void Neuron::printY() { // Вывод вектора значений функции нейронной сети
	std::cout << "Y = ( ";
	for (auto elem : all) {
		std::cout << func_y_net(func_net(elem)) << " ";
	}
	std::cout << ")" << std::endl;
}

void Neuron::printV() { // Вывод вектора весов нейронной сети
	std::cout << "V = ( ";
	for (int i = 0; i < V.size(); i++) {
		std::cout << V[i] << " ";
	}
	std::cout << ")" << std::endl;
}
