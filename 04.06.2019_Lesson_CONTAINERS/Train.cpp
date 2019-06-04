#include "Train.h"

train::train()
{
	number = 0;
	departure_time = "";
	destination = "";
}

train::train(int n, string s1, string s2)
{
	this->number = n;
	this->departure_time = s1;
	this->destination = s2;
}

int train::getNumber()
{
	return number;
}

string train::getDepartureTime()
{
	return departure_time;
}

string train::getDestination()
{
	return destination;
}

ostream & operator<<(ostream & os, train t)
{
	os << "Train " << t.number << " departure time: " << t.departure_time << " destination: " << t.destination << endl;
	return os;
}
