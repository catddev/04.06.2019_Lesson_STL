#pragma once
#include"Train.h"
#include"Ticket.h"

class SortBy {
	string prop;
public:
	SortBy(string prop) {
		this->prop = prop;
	}
	bool operator()(train t1, train t2) {
		if (prop == "number")
			return (t1.getNumber() < t2.getNumber());
		else if (prop == "departure")
			return (t1.getDepartureTime() < t2.getDepartureTime());
		else if (prop == "destination")
			return(t1.getDestination() < t2.getDestination());
	}
};

class SortBy2 {
	string prop;
public:
	SortBy2(string prop) {
		this->prop = prop;
	}
	bool operator()(ticket t1, ticket t2) {
		if (prop == "flight")
			return (t1.getFlight() < t2.getFlight());
		else if (prop == "departure")
			return (t1.getDeparture() < t2.getDeparture());
		else if (prop == "passenger")
			return(t1.getPassenger() < t2.getPassenger());
	}
};