#ifndef FOOTBALLTICKET_H
#define FOOTBALLTICKET_H

#include <list>
#include <string>
#include "Event.h"
#include "EventTicket.h"

//This class is derived from the EventTicket class
class FootballTicket : public EventTicket
{
private:
	Event* the_event;
	std::list<std::string>::iterator me;

public:

	//Base constructor for class
	//Input: Event pointer and iterator
	//		 Event pointer is used to identify what event the ticket belongs too
	//		 Iterator is used to identify the person the ticket belongs too
	FootballTicket(Event* the_event, std::list<std::string>::iterator& me) :
		the_event(the_event), me(me) {}

	void leave();
};

#endif
