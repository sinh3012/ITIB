#pragma once
#include <vector>
#include <iostream>

class Neuron
{
public:
	Neuron();
	Neuron(double w00, double w01, double w03, double w10, double w11, double w20, double w21);
	~Neuron();

	double func_f(double net);
	double func_df(double f);
	int study_neuron();
	
	std::vector<double> W0{ 0,0,0 }; // �������� ������� ������������� �� ���������
	std::vector<double> W01{ 0,0 }; // �������� ������� ������������� �� ���������
	std::vector<double> W02{ 0,0 }; // �������� ������� ������������� �� ���������

	std::vector<double> t{ -0.1, - 0.1 }; // �������� �������� �������
	std::vector<double> x{ 1,2,1 }; // �������� �������� ������� 
	double E = 0.001; // ����� ������������������ ������
	double n = 0.66; // ����� ��������
};


