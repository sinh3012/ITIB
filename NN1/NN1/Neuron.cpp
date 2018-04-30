#include "stdafx.h"
#include "Neuron.h"

Neuron::Neuron() {}

Neuron::Neuron(double w0, double w1, double w2, double w3, double w4) { // Çàäàåì íà÷àëüíûå çíà÷åíèå âåêòîðà âåñîâ
	W[0] = w0;
	W[1] = w1;
	W[2] = w2;
	W[3] = w3;
	W[4] = w4;
}

Neuron::~Neuron() {}

double Neuron::func_net(std::vector<int> X) {
	double net = 0;
	for (int i = 0; i < 5; i++) {
		net += X[i] * W[i];
	}
	return net;
}

double Neuron::func_out(double net) {
	double out = (1 + (net / (1 + abs(net))))/2;
	return out;
}

int Neuron::func_y_net(double net) {
	if (net >= 0) return 1;
	else return 0;
}

int Neuron::func_y_out(double out) {
	if (out >= 0.5) return 1;
	else return 0;
}

int Neuron::func_delta(std::vector<int> X) {
	int index = X[4] + 2 * (X[3] + 2 * (X[2] + 2 * (X[1]))); // Íàõîäèì èíäåêñ âåêòîðà Õ
	int delta=0;
	if (!logistic_activation_func) {
		delta = real_func[index] - func_y_net(func_net(X));
	}
	else {
		delta = real_func[index] - func_y_out(func_out(func_net(X)));
	}
	return delta;
}

int Neuron::func_E() {
	int E = 0;
	for (auto elem : all) {
		E += abs(func_delta(elem));
	}
	return E;
}

int Neuron::study_neuron(std::vector<std::vector<int>> X) { // Îáó÷åíèå íåéðîíà
	int k = 0; // Íîìåð ýïîõè
	while ((func_E() > 0) && (k < 200)) { // Ïîêà åñòü îøèáêà (è æèâà íàäåæäà)
		std::cout << "k = " << k << " E = " << func_E() << std::endl;
		printY();
		printW();
		std::vector<double> delta_w{ 0,0,0,0,0 }; // Âåêòîð ñìåùåíèÿ âåñîâ
		double n = 0.3; // Êîýôôèöèåíò îáó÷åíèÿ
		for (auto elem : X) {
			for (int i = 0; i < 5; i++) {
				delta_w[i] += n * func_delta(elem)*elem[i]*func_df(func_net(elem));
			}
		}
		for (int i = 0; i < 5; i++) {
			W[i] += delta_w[i];
		}
		k++;
	}
	std::cout << "k = " << k << " E = " << func_E() << std::endl;
	printY();
	printW();
	return k;
}

double Neuron::func_df(double net) {
	double df = 1 / (2 * (abs(net) + 1)*(abs(net) + 1));
	if (logistic_activation_func) {
		return df;
	}
	else {
		return 1;
	}
}

void Neuron::printY() { // Âûâîä âåêòîðà çíà÷åíèé ôóíêöèè íåéðîíà
	std::cout << "Y = ( ";
	for (auto elem : all) {
		if (!logistic_activation_func) {
			std::cout << func_y_net(func_net(elem)) << " ";
		}
		else {
			std::cout << func_y_out(func_out(func_net(elem))) << " ";
		}
	}
	std::cout << ")" << std::endl;
}

void Neuron::printW() { // Âûâîä âåêòîðà âåñîâ íåéðîíà
	std::cout << "W = ( ";
	for (int i = 0; i < 5; i++) {
		std::cout << W[i] << " ";
	}
	std::cout << ")" << std::endl;
}

void Neuron::this_logistic_func(bool key) { // Ôëàã ëîãèñòè÷åñêîé ÔÀ
	logistic_activation_func = key;
}
