#include "FootballTicket.h"
#include "FootballEvent.h"

//Implements a leave method 
void FootballTicket::leave() {
	
	FootballEvent* actual_event = dynamic_cast<FootballEvent*>(the_event); //down-cast from base class to derived class
	actual_event->remove(me); //Uses the iterator "me" to identify the goer and calls the FootballEvent remove method 
}