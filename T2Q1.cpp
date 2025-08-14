#include <iostream>
#include <string>

using namespace std;

int mainT1() {
	// 1(a) int to string
	int64_t phoneNum = 60123456789;
	string phoneStr = to_string(phoneNum);

	// 1(b) display +60 12-3456789
	string countryCode = "+60 ";
	string telPrefix = phoneStr.substr(2, 2);		// substr(start_index, length)
	string telNum = phoneStr.substr(4);

	cout << countryCode << telPrefix << "-" << telNum;

	return 0;
}