#pragma once
#include <string>
using namespace std;

//done as a header file for better sorting and 
//make sure my teammates (you all) dont add extra stuff into your own files and break things
struct VenueDetails {
	string venueId;
	string venueName;
	int holdableAmount;
	double halfDayPrice;
	double fullDayPrice;
};

struct Booking {
	string customerName;
	string phoneNo;
	string date;
	string time;
	VenueDetails venue;
	bool status;
};

struct Staff {

};

