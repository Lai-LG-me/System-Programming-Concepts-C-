#include <iostream>

using namespace std;

int mainT3() {
	string text = "Two dimensional array";

	int firstVowel = text.find_first_of("aeiou");
	int lastVowel = text.find_last_of("aeiou");

	cout << "First vowel index: " << firstVowel << endl;
	cout << "Last vowel index : " << lastVowel << endl;

	return 0;
}