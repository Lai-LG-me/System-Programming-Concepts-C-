#include <iostream>
#include <string>
#include <format>		// use .format need to include this

using namespace std;

int mainP5() {
	string itemName;
	

	while(true){
		cout << "Enter Item name or 999 to stop: ";
		getline(cin, itemName);

		if (itemName == "999") {
			break;
		}

		double price;
		cout << "Enter Price (RM): ";
		cin >> price;

		int quantity;
		cout << "Enter quantity: ";
		cin >> quantity;
		cout << "\n";

		cin.ignore();
		double totalPrice;
		totalPrice = price * quantity;

		string output = format("{} x {} @ RM{:.2f} = RM{:.2f}", itemName, quantity, price, totalPrice);		
		cout << output << endl;
	} 
	

	return 0;
}