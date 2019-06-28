#ifndef _BASEBALL_TICKET_H_
#define _BASEBALL_TICKET_H_

#include <list>
#include <string>
#include "Event.h"
#include "EventTicket.h"
 
//This class is derived from the EventTicket class
class BaseballTicket : public EventTicket
{
private:
	Event* the_event;
	std::list<std::string>::iterator me;

public:

	//Base Constructor for the class
	//Input:Event pointer and an iterator
	//		Event pointer is to identify what event the ticket belongs too
	//		The iterator is the event goer who the ticket belongs too
	BaseballTicket(Event* the_event, std::list<std::string>::iterator& me) :
		the_event(the_event), me(me) {}

	//This is a method that is used when an attendee wants to leave.
	//The implementation of this method is in the BaseballTicket.cpp file
	void leave();
};

#endif
