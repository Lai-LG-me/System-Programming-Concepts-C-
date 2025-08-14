#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string message;
	cout << "Enter product name and price: ";
	getline(cin, message);

	int RM_position = message.find("RM");	

	stringstream ss(message);
	// substr(start_index, length)			-> T2Q1
	string name = message.substr(0, RM_position - 1);

	// Convert string -> double
	string priceString = message.substr(RM_position + 2);			// +2 to skip RM
	double price = stod(priceString);
	
	ss >> name >> price;

	cout << name << price;

	return 0;
}