/**
* CS-273 Exam 2 Summer 2018
* Who doesn't like sports ?!
*
* @authors Everyone!
*/
#include <iostream>
#include <string>
#include <typeinfo>
#include "Event.h"
#include "EventTicket.h"
#include "EventFactory.h"

using std::cout;
using std::endl;

const int EVENT_COUNT = 3;

int main()
{
	// FIXME 5: Create a third kind of event, and test it 

	Event* events[EVENT_COUNT]; //Create a worldcup match and a baseball game
	events[0] = EventFactory::factory("worldcup", "Germany", "Mexico"); // Create a worldcup match with the event factory
	events[1] = EventFactory::factory("baseball", "Everett", "Spokane"); // Creates a Baseball match with event factory
	//FIXME 5a: generate an event object for your new kind of event
	events[2] = EventFactory::factory("football", "Whitworth", "Linfield"); // Creates a football match with event factory

	//Let's go through and test each one
	for (int i = 0; i < EVENT_COUNT; i++) {
		// Let's add a couple of people to the match, and store their tickets in variables
		EventTicket* ticket1 = events[i]->add("Mike");
		EventTicket* ticket2 = events[i]->add("Jane");
		EventTicket* ticket3 = events[i]->add("Antonio");
		EventTicket* ticket4 = events[i]->add("Sue");

		cout << "Event before Jane leaves:\n";
		events[i]->list(); // List the people currently at the event

		// Jane decides to leave the event. Darn! She was really fun to have around!
		ticket2->leave();
		
		//This piece of code vary's depending on what event is happeneing
		//It checks to see if the id matches and then down-cast the unique methods
		if (typeid(WorldcupEvent) == typeid(*events[i]))
			dynamic_cast<WorldcupEvent*>(events[i])->chant();
		else if (typeid(BaseballEvent) == typeid(*events[i]))
			dynamic_cast<BaseballEvent*>(events[i])->stretch();
		else if (typeid(FootballEvent) == typeid(*events[i]))
			dynamic_cast<FootballEvent*>(events[i])->sing();
		//FIXME 5b: if this is a baseball game, include a call to have attendees at the baseball game stretch
		//FIXME 5c: if this is your event, include a call to your event's special behavior

		cout << "\n\nEvent after Jane leaves:\n";
		events[i]->list(); // List the people remaining
		cout << "------------------------------------------------------------------------------------------------------------------------\n";

		
	}
}