#include <iostream>
#include <vector>
#include<iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "Structures.h"
#include "Func.h"
using namespace std;

void printVenue(vector<VenueDetails> *venues) {
    int i = 0;
    cout << string(100, '+') << endl;
    cout << setw(46) << " " << "Venues" << endl;
    cout << string(100, '+') << endl;
    cout << left << setw(6) << "No."
        << setw(15) << "Venue ID"
        << setw(30) << "Venue Name"
        << setw(10) << "Pax."
        << setw(20) << "Half Day (RM)"
        << setw(20) << "Full Day (RM)" << endl;

    cout << string(100, '=') << endl;
    for (VenueDetails& venue : *venues) {
        ++i;
        cout << left << setw(6) << i
            << setw(15) << venue.venueId
            << setw(30) << venue.venueName
            << setw(10) << venue.holdableAmount
            << setw(20) << fixed << setprecision(2) << venue.halfDayPrice
            << setw(20) << fixed << setprecision(2) << venue.fullDayPrice
            << endl;
    }
    cout << string(100, '=') << endl;
}

vector<VenueDetails> getFacility(string &filename) {
	vector<VenueDetails> venues;
	ifstream file(filename);

	string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, amount, halfDayPrice, fullDayPrice;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, amount, ',');
        getline(ss, halfDayPrice, ',');
        getline(ss, fullDayPrice);

        VenueDetails v;
        v.venueId = id;
        v.venueName = name;
        v.holdableAmount = stoi(amount);
        v.halfDayPrice = stod(halfDayPrice);
        v.fullDayPrice = stod(fullDayPrice);

        venues.push_back(v);
    }

    return venues;
}

void Availability(Booking custBook) {

}

void facility() {

}