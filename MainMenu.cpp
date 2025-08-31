#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> 
#include <cctype>
#include "Structures.h"
#include "Func.h"
using namespace std;
//Definitely need header files so we code first 
bool YesNo(string YN) {
	int i = 0;
	for (int i = 0; i < YN.length();i++) {
		YN[i] = toupper(YN[i]);
	}
	if (YN == "YES") {
		return true;
	}
	return false;
}

void main() {
	cout <<"\t\t\t\t   " << string(50, '+') << endl;
	cout <<"\t\t\t\t   " << setw(11) << " " << "Wedding Venue Booking System" << endl;
	cout << "\t\t\t\t   " << string(50, '+') << endl;
	string YN;
	cout << "Do you want to book a venue? (yes/no): ";
	cin >> YN;
	if (YesNo(YN)) {
		system("cls"); //this is a clear screen command btw
		//what system() does is basically access the terminal with code
		//move to booking page
		booking();
	}
	else {
		exit;
	}
}
