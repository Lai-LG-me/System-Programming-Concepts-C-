#include <iostream>
#include <vector>
#include <sstream>
#include "Structures.h"
#include "Func.h"
using namespace std;

void Availability(Booking custBook);

void booking() {
	string filename = "VenueDetails.txt";
	Booking custBook;
	int venueNo;
	vector<VenueDetails> venues = getFacility(filename);
//let user input their wished venue and start booking using phone and name
//status will become confirmed if the system checks the system and sees that it is available
	printVenue(&venues);
	cout << "Please input the No. of the venue you wish to book: ";
	cin >> venueNo;
	cout << endl << "Please enter your name: ";
	cin.ignore();
	getline(cin, custBook.customerName);
	cout << "Please enter phone number (01234567891): ";
	cin >> custBook.phoneNo;
	cout << "Please enter date of event (12 August 2025): ";
	cin.ignore();
	getline(cin, custBook.date);
	cout << "Please enter time of event (12:00-15:00): ";
	getline(cin, custBook.time);

	custBook.venue = venues[venueNo - 1];

	Availability(custBook);
	Payment(custBook);
}

