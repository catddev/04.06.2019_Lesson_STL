#pragma once
#include"Train.h"

class filter {
	string prop;
	train obj;
public:
	filter();//
	filter(string prop, train obj) {
		this->prop = prop;
		this->obj = obj;
	}
	bool operator()() {
		if (prop == "number") {
			int n;
			cin >> n;
			return (obj.getNumber() != n);
				//cout << obj;
		}
		else if (prop == "dep_time") {
			string s;
			cin >> s;
			return (obj.getDepartureTime() != s);
				//cout << obj;
		}
		else if (prop == "destination") {
			string s;
			cin >> s;
			return (obj.getDestination() != s);
				//cout << obj;
		}
	}
};