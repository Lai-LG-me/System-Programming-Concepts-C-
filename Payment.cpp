#include <iostream>
#include <iomanip>
#include "Structures.h"
#include "Func.h"

using namespace std;

// Choose full/half day
int daySelection() {
    int daySelect;
    while (true) {
        cout << "Enter 1 for Half Day, 2 for Full Day: ";
        cin >> daySelect;

        if (cin.fail() || (daySelect != 1 && daySelect != 2)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter 1 or 2 only.\n";
        }
        else {
            break;
        }
    }
    return daySelect;
}

// Select payment method (cash/bank in)
void paymentMethod(double totalPrice, Booking custBook, int daySelected) {
    int paymentChoice;
    while (true) {
        cout << "Choose your payment method (1 = Cash, 2 = Bank-in): ";
        cin >> paymentChoice;
        if (cin.fail() || (paymentChoice != 1 && paymentChoice != 2)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter 1 or 2 only.\n";
        }
        else {
            break;
		}
    }
    switch (paymentChoice) {
    case 1:
        cashPayment(totalPrice, custBook, daySelected);
        break;
    case 2:
        bankInPayment(totalPrice, custBook, daySelected);
        break;
    default:
        cout << "Invalid choice.\n";
        break;
    }
}

// Cash payment
void cashPayment(double totalPrice, Booking custBook, int daySelected) {
    double userPaid;
    double change;

    cout << string(30, '-') << endl;
    cout << "Cash Payment" << endl;
    cout << string(30, '-') << endl;

    while (true) {
        cout << "Enter amount: RM ";
        cin >> userPaid;

        if (userPaid < totalPrice) {
            cout << "Insufficient amount! Please enter again.\n";
        }
        else {
            change = userPaid - totalPrice;
            cout << "Change: RM " << fixed << setprecision(2) << change << endl;

            cout << "Payment successful!" << endl;
            break;
        }
    }
    printReceipt(custBook, hallPrice, daySelected, 1, userPaid, change);         // means that the payment choice = 1 (cash)
}

// Bank-in payment
void bankInPayment(double totalPrice, Booking custBook, int daySelected) {
    int bankChoice;

    while (true) {
        cout << "Choose your bank (1 = Affin Bank, 2 = MayBank, 3 = Public Bank): ";
        cin >> bankChoice;

        if (cin.fail() || (bankChoice != 1 && bankChoice != 2 && bankChoice != 3)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter 1, 2, or 3 only.\n";
        }
        else {
            break;
        }
    }

    cout << string(30, '-') << endl;
    switch (bankChoice) {
    case 1: cout << "Affin Bank\n"; break;
    case 2: cout << "MayBank\n"; break;
    case 3: cout << "Public Bank\n"; break;
    }
    cout << string(30, '-') << endl;

    while (true) {
        int confirmation;
        cout << "Total Price: RM " << fixed << setprecision(2) << totalPrice << endl;
		cout << "1 = Confirm Payment, 2 = Cancel Payment: ";
        cin >> confirmation;

        if (cin.fail() || confirmation >2 || confirmation <1) {
            cin.clear();                  // clear error state
            cin.ignore(10000, '\n');      // discard invalid input
            cout << "Invalid input! Please enter a number.\n\n";
            continue;                     // restart loop
        }

        else if (confirmation == 1) {
            cout << "Payment successfully made via bank.\n";
            printReceipt(custBook, hallPrice, daySelected, 2, totalPrice, 0);
            break; 
        }
        else if(confirmation == 2) {
            while (true) {
                cout << "Are you sure you want to cancel the payment? (1 = Yes, 2 = No): ";
                int cancelChoice;
                cin >> cancelChoice;
                if (cin.fail()|| cancelChoice>2 || cancelChoice <1) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input! Please enter again.\n\n";
                    continue; // ask again
                }
                else if (cancelChoice == 1) {
                    cout << "Payment cancelled. Returning to payment method selection.\n";
                    paymentMethod(totalPrice, custBook, daySelected);   // Return to payment method selection
                    return;                                             // Exit the current function to avoid further execution
                }
                else if (cancelChoice == 2) {
                    // return to confirmation prompt
					break; // Exit the inner loop to return to the confirmation prompt
                }
                
            }

		}
    }
    
}

// calculate deposit function
double deposit(double hallPrice) {
    const double DEPOSIT_PERCENTAGE = 0.3;
    return hallPrice * DEPOSIT_PERCENTAGE;
}


// Display booking/payment details only, won't display user details
// to make it reusable (can be use at print receipt)
void Payment_BookingDetailPage(Booking custBook, double hallPrice, int daySelected, double totalPrice) {
    totalPrice = hallPrice + deposit(hallPrice);
    
    cout << left << setw(15) << "Venue ID"
        << setw(30) << "Venue Name"
        << setw(10) << "Pax"
        << setw(15) << "Day Type"
        << setw(15) << "Price (RM)" << endl;
  
    cout << string(100, '=') << endl;

    cout << left << setw(15) << custBook.venue.venueId
        << setw(30) << custBook.venue.venueName
        << setw(10) << custBook.venue.holdableAmount
        << setw(15) << (daySelected == 1 ? "Half Day" : "Full Day")
        << setw(15) << fixed << setprecision(2) << hallPrice << endl;

    cout << string(100, '-') << endl;
    // print deposit
    cout << "Deposit: RM " << deposit(hallPrice) << endl;
    // print total price
    cout << "Total Price: RM " << totalPrice << endl;

    cout << string(100, '=') << endl;

}

// Payment page
void PaymentPage(Booking custBook, double hallPrice, int daySelected) {
    system("cls");

    cout << string(100, '+') << endl;
    cout << setw(46) << " " << "Payment" << endl;
    cout << string(100, '+') << endl;

    // print booking details
    Payment_BookingDetailPage(custBook, hallPrice, daySelected);

    // print customer details
    cout << left << setw(20) << "Customer Name:" << custBook.customerName << endl;
    cout << left << setw(20) << "Phone Number:" << custBook.phoneNo << endl;
    cout << left << setw(20) << "Event Date:" << custBook.date << endl;
    cout << left << setw(20) << "Event Time:" << custBook.time << endl;

    cout << string(100, '=') << endl;

    paymentMethod(hallPrice, custBook, daySelected);
}

// Main payment flow
void Payment(Booking custBook) {
    int daySelected = daySelection();
    double hallPrice = (daySelected == 1) ? custBook.venue.halfDayPrice : custBook.venue.fullDayPrice;
    PaymentPage(custBook, hallPrice, daySelected);
}

// Print receipt
void printReceipt(const Booking& custBook, double hallPrice, int daySelected, int paymentChoice, double userPaid, double change) {
    system("cls");
    cout << string(100, '+') << endl;
    cout << setw(46) << " " << "RECEIPT" << endl;
    cout << string(100, '+') << endl;

    Payment_BookingDetailPage(custBook, hallPrice, daySelected);

   
    cout << "Payment Method: ";
    if (paymentChoice == 1) {
        cout << "Cash\n";
        cout << "Paid: RM " << userPaid << endl;

        cout << "Changes: RM " << change << endl;
    }
    else if (paymentChoice == 2) {
        cout << "Bank In\n";
        cout << "Paid: RM " << hallPrice << endl;
        cout << "Changes: RM 0.00" << endl;
    }
    else {
        cout << "Invalid Input! Please re-enter..." << endl;
    }


    cout << "Thank you for your support!" << endl;
}

