#include <iostream>
#include <sstream>
#include <string>			// for getline 

using namespace std;

int mainT2() {
	// convert string -> floating pt
	string data = "45.67,23,12.5,10,78.9";
	
	stringstream ss(data);
	string numString;			// temporaly store the number as string
	double sum = 0.0;
	
	// getline(input_stream, variable_to_store, delimiter);

	while (getline(ss, numString, ',')) {
		
		// convert to double : stod
		double convertedNum = stod(numString);
		cout << convertedNum << "\t";
		sum += convertedNum;
	}

	cout << "\nSum = " << sum << endl;

	return 0;
}

