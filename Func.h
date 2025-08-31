#pragma once
#include "Structures.h"
#include <vector>

void booking();
vector<VenueDetails> getFacility(string& filename);
void Availability(Booking custBook);
void Payment(Booking custBook);
void printVenue(vector<VenueDetails>* venues);