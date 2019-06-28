#ifndef _BASEBALL_EVENT_H_
#define _BASEBALL_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "BaseballTicket.h"

// FIXME 2: Create BaseballEvent and BaseballTicket to for good baseball games!
// FIXME 2a: Create a function stretch so that the attendees can stand up an stretch for the 7th inning
// FIXME 3: Update EventFactory::factory() to allow it to be the ONLY method for creating a BaseballEvent

/**
* BaseballEvent is derived from Event
*/
class BaseballEvent : public Event
{
private:
	std::list<std::string> stadium;
	std::string hometeam;
	std::string visitingteam;


	//Base constructor for the baseball event class
	//Input: Two strings
	//		 hometeam = home
	//		 visitingteam = visiting
	BaseballEvent(std::string home, std::string visiting) {

		hometeam = home;
		visitingteam = visiting;
	}

	friend class EventFactory;

public:

	//Method to add people to a list of attendees
	//Input: String which is the name of attendee
	//Output: A pointer of the BaseballTicket class
	EventTicket* add(std::string name) {

		stadium.push_front(name);

		std::list<std::string>::iterator it;

		it = stadium.begin();

		BaseballTicket* ticket = new BaseballTicket(this, it);

		return ticket;
	}

	//Method to list all atendees of the event
	//Output: It outputs to user the list of all attendees which is just names
	void list() {

		//Uses the iterator to get the name of the attendees
		std::list<std::string>::iterator it;
		std::cout << "|" << hometeam << "| vs |" << visitingteam << "|\n";
		std::cout << "Listing attendees...\n";
		for (it = stadium.begin(); it != stadium.end(); it++) {
			std::cout << *it << std::endl;
		}
	}

	//Method to remove someone from the event
	//It firsts inform user who has beem removed
	//Then uses the erase method to erase the attendee from the list
	void remove(std::list<std::string>::iterator it) {


		std::cout << *it << " has been removed from the Baseball Game!!\n";
		stadium.erase(it);

	}

	//This is a method that when called all attendees stand up and stretch.
	//All attendees names will be printed out with whats below
	void stretch() {
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " stands up stretches and sings 'Take Me Out to the Ballgame!'" << std::endl;
		}
	}

};

#endif
