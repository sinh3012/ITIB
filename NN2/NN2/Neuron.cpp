#include "stdafx.h"
#include "Neuron.h"
#include <math.h>

Neuron::Neuron() {}

Neuron::Neuron(double w0, double w1, double w2, double w3, double w4) { // ������ ��������� �������� ������� �����
	W[0] = w1;
	W[1] = w2;
	W[2] = w3;
	W[3] = w4;
	W[4] = w0;
}

Neuron::~Neuron() {}

void Neuron::get_real_func() { // ��������� �������� �������� �������
	double interval = (5.0-1.0) / (20.0-1.0); // ��������� �������� t
	//std::cout << interval;
	for (int i = 0; i < 40; i++) {
		real_func.push_back(log(1.0 + interval * i) - 1.0); // ��������� �������� �������
		//std::cout << real_func[i] << ' ';
	}
	neur_func.push_back(real_func[0]);
	neur_func.push_back(real_func[1]);
	neur_func.push_back(real_func[2]);
	neur_func.push_back(real_func[3]);
}

double Neuron::func_delta(double real, double neur) { // �������� �������� � ��������� ��������
	double delta = real - neur;
	return delta;
}

double Neuron::func_E() { // ������ �����
	double E = 0;
	for (int i = 0; i < neur_func.size(); i++) {
		double delta = func_delta(real_func[i], neur_func[i]);
		E += delta * delta;
	}
	E = sqrt(E);
	return E;
}

double Neuron::study_neuron(int max) { // �������� ����
	int k = 0;
	double n = 0.66; 
	while (((func_E() > 0.001) || (k == 0)) && (k < max)) { // ���� ���� ������ (� ���� �������)
		std::cout << "k = " << k << std::endl << "E = " << func_E() << std::endl;
		printW();
		for (int i = 4; i < 20; i++) { // ���� �� ��������� �������
			if (neur_func.size() < i + 1) {
				neur_func.push_back(0);
			}
			neur_func[i] = W[4];
			for (int j = 0; j < 4; j++) { // ��������������� 
				neur_func[i] += W[j] * neur_func[i-4+j];
			}
			for (int j = 0; j < 4; j++) { // ������������� ����
				W[j] += n * func_delta(real_func[i], neur_func[i])*neur_func[i-4+j];
			}
			W[4]+=n* func_delta(real_func[i], neur_func[i]);
			k++;
		}
	}
	std::cout << "k = " << k << std::endl << "E = " << func_E() << std::endl;
	printW();
	return k;
}

void Neuron::work_neuron() { // ��������������� ��������� �����
	for (int i = 20; i < 40; i++) { // ���� ���������
		if (neur_func.size() < i + 1) {
			neur_func.push_back(0);
		}
		neur_func[i] = 0;
		for (int j = 0; j < 4; j++) {
			neur_func[i] += W[j] * neur_func[i - 4 + j];
		}
		neur_func[i] += W[4];
	}
	std::cout << std::endl << "real               neur" << std::endl;
	for (int i = 0; i < 40; i++) {
		std::cout << real_func[i] << "        " << neur_func[i] << std::endl;
	}
}

void Neuron::printW() { // ����� ������� ����� ����
	std::cout << "W = ( " << W[4] << " ";
	for (int i = 1; i < 5; i++) {
		std::cout << W[i] << " ";
	}
	std::cout << ")" << std::endl;
}

