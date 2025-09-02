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
int deposit(double hallPrice);
void Payment_BookingDetailPage(Booking custBook, double hallPrice, int daySelected, double totalPrice = 0);
void PaymentPage(Booking custBook, double hallPrice, int daySelected);
void Payment(Booking custBook);
void printReceipt(const Booking& custBook, double hallPrice, int daySelected, int paymentChoice, double userPaid = 0, double change = 0);


void printVenue(vector<VenueDetails>* venues);

