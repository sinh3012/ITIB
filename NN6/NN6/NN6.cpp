// NN6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Neuron.h"
#include<vector>
#include<string>
#include<fstream>
#include<iostream>

int main()
{
	setlocale(LC_CTYPE, "rus"); // Вызов функции настройки локали
	Neuron neur;
	std::ifstream fin("data-7361-2018-04-25.json");
	int k = 0; // Номер элемента
	int bol = 0; // Считываем имя или координаты
	int ch = 0; // Считываемый символ
	size_t pos1,pos2; // Позиция поиска 
	std::string s; // Строка - буфер
	std::string name1,name2,name3; 
	std::double_t a, b; // Значения координат
	std::string search1("CommonName");
	std::string search2("AdmArea");
	std::string search3("coordinates");
	while (((ch = fin.get()) != EOF)&&(k<200)) { // Читаем нужные исходные данные из файла
		s = s + char(ch);
		if (char(ch) == ']') {
			if (bol == 0) {
				pos1 = s.find(search1);
				if (pos1 != std::string::npos) {
					pos2 = s.find("\"", pos1+13);
					name1 = s.substr(pos1 + 13, pos2 - pos1 - 13);
					std::cout << "k = " << k << std::endl;
					std::cout << name1 << std::endl;
					bol = 1;
				}
				s = "";
			}
			else if (bol == 1) {
				pos1 = s.find(search2);
				if (pos1 != std::string::npos) {
					pos2 = s.find("\"", pos1 + 10);
					name2 = s.substr(pos1 + 10, pos2 - pos1 - 10);
					std::cout << "Жизнь: " << name2 << std::endl;
					bol = 2;
				}
				s = "";
			}
			else {
				pos1 = s.find(search3);
				if (pos1 != std::string::npos) {
					pos2 = s.find(",", pos1);
					a = stod(s.substr(pos1 + 15, 12));
					b = stod(s.substr(pos2+1, 12));
					name3 = neur.check(a, b);
					std::cout << "Сеть: " << name3 << " административный округ" << std::endl << std::endl;
					//std::cout << a << " " << b << std::endl;
					bol = 0;
					k++;
				}
				s = "";
			}
		}
	}
	int i;
	std::cin >> i;
    return 0;
}

