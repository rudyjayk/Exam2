#ifndef _WORLDCUP_EVENT_H_
#define _WORLDCUP_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>
#include "Event.h"
#include "WorldcupTicket.h"


/**
* WorldcupEvent is derived from Event
*/
class WorldcupEvent : public Event
{
private:
	std::list<std::string> stadium; // Data structure for containing the event goers in this worldcup event
	std::string hometeam;
	std::string visitingteam;

	/**
	* Constructor for creating a WorldcupEvent
	* Input: Two strings
			 hometeam  = home
			 visitingteam = visiting
	*/
	WorldcupEvent(std::string home, std::string visiting) {
		/**
		 *  FIXME 1a:
		 *    store the home team and visiting team names
		 */
		hometeam = home;
		visitingteam = visiting;
	}

	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket* add(std::string name) {
		/**
		* FIXME 1b:
		*   Pseudo-code
		*    1. add name to the front of stadium
		*    2. get iterator to the front of the stadium (this points to the recently added event goer)
		*    3. create a new worldcup ticket (WorldcupTicket) with its constructor
		*            Pass to the constructor "this" event, and the iterator from step 2
		*    4. return this new event ticket
		*/
		stadium.push_front(name); //Adds "name" to the front of the list 

		std::list<std::string>::iterator it; //Creates an iterator 

		it = stadium.begin(); //Sets iterator equal to the front of the stadium

		WorldcupTicket* ticket = new WorldcupTicket(this, it); //This creates a new Ticket

		return ticket;
	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		// FIXME 1c: Show the event's home team and visiting team, then iterate through all the persons here.

		//Uses the iterator to print out all attendees at the world cup
		std::list<std::string>::iterator it;
		std::cout << "|" << hometeam << "| vs |" << visitingteam << "|\n";
		std::cout << "Listing attendees...\n";
		for (it = stadium.begin(); it != stadium.end(); it++) {
			std::cout << *it << std::endl;
		}
	}

	/***
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		//FIXME 1d: someone's getting out of hand. Ushers have asked them to leave.

		//Informs user who has been removed then uses the erase method to erase prompted attendee
		std::cout << *it << " has been removed from the World Cup!!\n";
		stadium.erase(it);
	}

	/**
	 * Have world cup attendees chant
	 */
	void chant() {
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " says 'boom boom clap!'" << std::endl;
		}
	}
};
#endif
