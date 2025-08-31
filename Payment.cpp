#include <iostream>
#include <iomanip>
#include <limits>
#include "Structures.h"
#include "Func.h"

using namespace std;

int daySelection() {
    int daySelect;
    while (true) {
        cout << "Enter 1 for Half Day, 2 for Full Day: ";
        cin >> daySelect;

        if (cin.fail() || (daySelect != 1 && daySelect != 2)) {
            cin.clear(); // clear error flag
            cin.ignore(10000, '\n'); // Remove bad input
            cout << "Invalid input! Please enter 1 or 2 only.\n";
        }
        else {
            break;
        }
    }
    return daySelect;
}


void paymentMethod() {
    int paymentMethodChoice;
    cout << "Choose your payment method (1 = Cash, 2 = Bank-in): ";
    cin >> paymentMethodChoice;

    switch (paymentMethodChoice) {
    case 1:
        cout << string(30, '-') << endl;
        cout << "You chose Cash payment.\n";
        cout << string(30, '-') << endl;
        break;
    case 2:
        cout << "You chose Bank-in payment.\n";
        break;
    default:
        cout << "Invalid choice.\n";
        break;
    }
}

// Show booking & payment details
void PaymentPage(const Booking& custBook, double totalPrice, int daySelected) {
    system("cls"); // clear screen
    cout << string(100, '+') << endl;
    cout << setw(46) << " " << "Payment" << endl;
    cout << string(100, '+') << endl;

    cout << left << setw(15) << "Venue ID"
        << setw(30) << "Venue Name"
        << setw(10) << "Pax."
        << setw(15) << "Day Type"
        << setw(15) << "Price (RM)" << endl;

    cout << string(100, '=') << endl;

    cout << left << setw(15) << custBook.venue.venueId
        << setw(30) << custBook.venue.venueName
        << setw(10) << custBook.venue.holdableAmount
        << setw(15) << (daySelected == 1 ? "Half Day" : "Full Day")
        << setw(15) << fixed << setprecision(2) << totalPrice << endl;

    cout << string(100, '=') << endl;

    cout << left << setw(20) << "Customer Name:" << custBook.customerName << endl;
    cout << left << setw(20) << "Phone Number:" << custBook.phoneNo << endl;
    cout << left << setw(20) << "Event Date:" << custBook.date << endl;
    cout << left << setw(20) << "Event Time:" << custBook.time << endl;

    cout << string(100, '=') << endl;

    paymentMethod();
}

void Payment(Booking custBook) {
    int daySelected = daySelection();
    double totalPrice = 0;

    if (daySelected == 1) {
        totalPrice = custBook.venue.halfDayPrice;
    }
    else if (daySelected == 2) {
        totalPrice = custBook.venue.fullDayPrice;
    }

    PaymentPage(custBook, totalPrice, daySelected);
}


