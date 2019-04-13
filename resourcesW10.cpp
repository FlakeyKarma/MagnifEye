#include <vector>
#include <iostream>
#include <string>
#include "resources.h"
using namespace std;

vector<string> stuffReturn::wordReturn(string inpt) {
	long sz = 0;
	string s = "";
	vector<string> sS;
	cout << "stuffReturn: " << inpt << endl;
	vector<char> BLACKLIST = {};
	for (int i = 0; i < 255; i++) {
		if (i < 32 || i > 123) {
			BLACKLIST.push_back((char)i);
		}
	}
	for (long i = 0; i < inpt.length(); i++) {
		bool CHK = false;
		for (int j = 0; j < BLACKLIST.size(); j++)
			if ((char)inpt[i] == (char)BLACKLIST.at(j)) {
				CHK = true;
				break;
			}
		if (CHK == true)
			continue;
		if ((char)inpt[i] != ' ' && isalpha(inpt[i]) || (char)inpt[i] == '-') {
			s += tolower(inpt[i]);
		}

		if ((char)inpt[i] == '\\' || (char)inpt[i] == '/'||(char)inpt[i] == ':' && !isalpha((char)inpt[i])||(char)inpt[i] == ' ' && i != 0 && !isalpha((char)inpt[i]) && !s.empty()) {
			sS.push_back(s);
			s = "";
			sz++;
		}
	}
	return sS;
}

void stuffReturn::nuMake(vector<string> s) {
	vector<string> strList;
	strList.push_back(s.at(0));
	vector<long> intList;
	intList.push_back(0);
	long SZ = 0;
	for (long i = 0; i < s.size(); i++){
		for (long j = 0; j < strList.size(); j++) {
			if (intList.size() < strList.size())
				intList.push_back(0);
			if (s.at(i) == strList.at(j)) {
				intList.at(j)++;
				SZ++;
				break;
			}
			if (s.at(i) != strList.at(j) && j == strList.size() - 1) {
				strList.push_back(s.at(i));
			}

		}
	}
	intSz = intList;
	strSz = strList;
}

vector<long> stuffReturn::numzReturn() {
	return intSz;
}

vector<string> stuffReturn::strReturn() {
	return strSz;
}