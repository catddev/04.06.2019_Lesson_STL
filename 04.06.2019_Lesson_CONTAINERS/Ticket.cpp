#include "Ticket.h"

ticket::ticket()
{
	flight = 0;
	departure = "";
	passenger = "";
}

ticket::ticket(int n, string s1, string s2)
{
	this->flight = n;
	this->departure = s1;
	this->passenger = s2;
}

int & ticket::getFlight()
{
	return flight;
}

string & ticket::getDeparture()
{
	return departure;
}

string & ticket::getPassenger()
{
	return passenger;
}

bool ticket::operator==(ticket obj) const
{
	return (this->flight==obj.flight && this->departure==obj.departure && this->passenger==obj.passenger);
}

ostream & operator<<(ostream & os, ticket t)
{
	os << "Flight " << t.flight << " departure time: " << t.departure << " Passenger name: " << t.passenger << endl;
	return os;
}

istream & operator>>(istream & is, ticket & t)
{
	is >> t.flight >> t.departure >> t.passenger;
	return is;
}
