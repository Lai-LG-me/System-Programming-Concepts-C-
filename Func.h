#pragma once
#include "Structures.h"
#include <vector>

void booking();
vector<VenueDetails> getFacility(string& filename);
void Availability(Booking custBook);
// Payment
void PaymentPage(Booking custBook, double totalPrice, int daySelected);
void paymentMethod(double totalPrice);
void cashPayment(double totalPrice);
void bankInPayment(double totalPrice);
void Payment(Booking custBook);

void printReceipt();



void printVenue(vector<VenueDetails>* venues);
