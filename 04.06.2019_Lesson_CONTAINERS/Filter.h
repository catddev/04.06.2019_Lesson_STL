#pragma once
#include"Train.h"
#include"Ticket.h"

class filter {
	string prop;
	train t;
public:
	
	filter(string prop, train t) {
		this->prop = prop;
		this->t = t;
	}
	void operator()(train t) {
		if (prop == "number") {
			if(this->t.getNumber()==t.getNumber())
				cout << t;
		}
		else if (prop == "dep_time") {
			if (this->t.getDepartureTime() == t.getDepartureTime())
				cout << t;
		}
		else if (prop == "destination") {
			if (this->t.getDestination() == t.getDestination())
				cout << t;
		}
	}
};

class filter2 {
	string prop;
	ticket t;
public:

	filter2(string prop, ticket t) {
		this->prop = prop;
		this->t = t;
	}
	void operator()(ticket t) {
		if (prop == "flight") {
			if (this->t.getFlight() == t.getFlight())
				cout << t;
		}
		else if (prop == "departure") {
			if (this->t.getDeparture() == t.getDeparture())
				cout << t;
		}
		else if (prop == "passenger") {
			if (this->t.getPassenger() == t.getPassenger())
				cout << t;
		}
	}
};