#include "stdafx.h"
#include "Neuron.h"

Neuron::Neuron() {}

Neuron::Neuron(double w00, double w01, double w02, double w10, double w11, double w20, double w21 ) { // Задаем начальные значение вектора весов
	W0[0] = w00;
	W0[1] = w01;
	W0[2] = w02;
	W01[0] = w10;
	W01[1] = w11;
	W02[0] = w20;
	W02[1] = w21;
}

Neuron::~Neuron() {}

double Neuron::func_f(double net) { // Функция активации нейронов
	double f = (1 - exp(-net)) / (1 + exp(-net));
	return f;
}

double Neuron::func_df(double f) { // Производная функции активации
	double df = (1 - f * f) / 2;
	return df;
}

int Neuron::study_neuron() { // Обучение нейронной сети
	int k = 0; // Номер эпохи
	double net0, net01, net02, xj, y01, y02;
	double delta0, delta01, delta02;
	std::vector<double> delta_w0{ 0,0,0 };
	std::vector<double> delta_w01{ 0,0 };
	std::vector<double> delta_w02{ 0,0 };


	while (k < 2000) {
		// Расчет выхода нейронной сети
		net0=W0[0];
		for (size_t i = 1; i < W0.size(); i++) {
			net0 += W0[i] * x[i];
		}
		xj = func_f(net0);
		net01 = W01[1] * xj + W01[0];
		net02 = W02[1] * xj + W02[0];
		y01 = func_f(net01);
		y02 = func_f(net02);

		double Er = sqrt(pow((t[0] - y01), 2) + pow((t[1] - y02), 2));
		if (Er < E) break;
		std::cout << "k = " << k << "  E = " << Er << "  y = ( " << y01 << " " << y02 << " )" << std::endl;

		// Обучение с учителем
		delta01 = func_df(net01)*(t[0] - y01);
		delta02 = func_df(net02)*(t[1] - y02);
		delta0 = func_df(net0)*(delta01*W01[1] + delta02 * W02[1]);
		for (size_t i = 0; i < delta_w0.size(); i++) {
			delta_w0[i] = n * x[i] * delta0;
		}
		delta_w01[0] = n * delta01;
		delta_w02[0] = n * delta02;
		delta_w01[1] = n * xj * delta01;
		delta_w02[1] = n * xj * delta02;
		for (size_t i = 0; i < delta_w0.size(); i++) {
			W0[i] += delta_w0[i];
		}
		for (size_t i = 0; i < delta_w01.size(); i++) {
			W01[i] += delta_w01[i];
			W02[i] += delta_w02[i];
		}
		k++;
	}
	return k;	
}

