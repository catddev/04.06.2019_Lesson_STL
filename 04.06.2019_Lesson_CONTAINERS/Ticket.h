#pragma once
#include<string>
#include<iostream>
using namespace std;

//Написать программу учета заявок на авиабилеты.Каждая заявка содержит : номер рейса, дату вылета, ФИО пассажира.Обеспечить :
	//		Добавление заявки в список //push_back
	//		Удаление заявки //erase + remove_if
	//		Вывод всех заявок //sort, for_each
	//		Вывод заявок на указанную дату //functor, for_each
	//	Использовать контейнерный класс list

class ticket {
	int flight;
	string departure;
	string passenger;
public:
	ticket();
	ticket(int n, string s1, string s2);
	int &getFlight();
	string &getDeparture();
	string &getPassenger();
	bool operator==(ticket obj)const;
	friend ostream& operator<<(ostream& os, ticket t);
	friend istream& operator>>(istream& is, ticket &t);
};