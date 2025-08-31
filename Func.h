#pragma once
#include "Structures.h"
#include <vector>

void booking();
vector<VenueDetails> getFacility(string& filename);
void Availability(Booking custBook);

// Payment
int daySelection();
void paymentMethod(double totalPrice, Booking custBook, int daySelected);
void cashPayment(double totalPrice, Booking custBook, int daySelected);
void bankInPayment(double totalPrice, Booking custBook, int daySelected);
void Payment_BookingDetailPage(Booking custBook, double totalPrice, int daySelected);
void PaymentPage(Booking custBook, double totalPrice, int daySelected);
void Payment(Booking custBook);
void printReceipt(const Booking& custBook, double totalPrice, int daySelected, int paymentChoice, double userPaid, double change);


void printVenue(vector<VenueDetails>* venues);
