#pragma once
#include<string>
#include<iostream>
using namespace std;

//Написать программу «Автоматизированная информационная система ЖД вокзала».
//Система содержит : сведения об отправлении поездов дальнего следования.
//Для каждого поезда указываем : номер, время отправления, станцию назначения.
//Обеспечить :
//		Ввод данных в систему
//		Вывод информации о всех поездах
//		Вывод информации о запрашиваемом поезде
//	Использовать контейнерный класс vector.

class train {
	int number;
	string departure_time;
	string destination;
public:
	train();
	train(int n, string s1, string s2);
	int &getNumber();
	string &getDepartureTime();
	string &getDestination();
	friend ostream& operator<<(ostream& os, train t);
};
