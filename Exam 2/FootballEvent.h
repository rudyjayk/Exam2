#ifndef FOOTBALLEVENT_H
#define FOOTBALLEVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "FootballTicket.h"

//This class is derived from the Event class
class FootballEvent : public Event
{
private:
	std::list<std::string> stadium;
	std::string hometeam;
	std::string visitingteam;

	//Base constructor of the football event
	//Input: Two strings
	//		 hometeam = home
	//		 visitingteam = visiting
	FootballEvent(std::string home, std::string visiting) {

		hometeam = home;
		visitingteam = visiting;
	}

	friend class EventFactory;

public:

	//Method to add an attendee to the list of attendees
	//Input: A string which is the name of the attendee
	//Output: returns a ticket pointer from the same event
	EventTicket* add(std::string name) {

		stadium.push_front(name);

		std::list<std::string>::iterator it;

		it = stadium.begin();

		FootballTicket* ticket = new FootballTicket(this, it);

		return ticket;
	}

	//Method to list out the list of atendees
	//Output: The list of names that was stored in the stadium list or list of attendees
	void list() {

		std::list<std::string>::iterator it;
		std::cout << "|" << hometeam << "| vs |" << visitingteam << "|\n";
		std::cout << "Listing attendees...\n";
		for (it = stadium.begin(); it != stadium.end(); it++) {
			std::cout << *it << std::endl;
		}
	}

	//Method to remove someone who is prompted from the event
	//Outputs a message to user which informs who was remvoed
	//Then uses the erase method to erase prompted user
	void remove(std::list<std::string>::iterator it) {

		std::cout << *it << " has been removed from the Football Game!!\n";
		stadium.erase(it);

	}

	//Method for the attendees actions
	//This method will make the attendees sing the national anthem
	//It lists out all attendees and for each attendee follows the message below
	void sing() {
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " sings the 'National Anthem!'" << std::endl;
		}
	}

};

#endif
