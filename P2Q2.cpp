#include <iostream>
#include <regex>

using namespace std;

int mainP2() {
	string review = "The product is damm useless!";
		
	//string badWord = "damm";

	regex pattern("damm");

	// check if bad word is found
	if (regex_search(review, pattern)) {

		// Replace it 
		string cleanReview = regex_replace(review, pattern, "****");
		cout << cleanReview << endl;
	}
	else {
		cout << review;
	}

	


	return 0;
}