#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "resources.h"
using namespace std;

vector<string> stuffReturn::wordReturn(string inpt) {
	long sz = 0;
	string s = "";
	vector<string> sS;
	vector<char> BLACKLIST = {};
	for (int i = 0; i < 255; i++) {
		if (i % 100 == 0)
			cout << "BL.";
		if (i < 32 || i > 123) {
			BLACKLIST.push_back((char)i);
		}
	}
	cout << endl;
	for (long i = 0; i < inpt.length(); i++) {
		if (i % 100 == 0)
			cout << "wR.";
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
	cout << endl;
	return sS;
}

void stuffReturn::nuMake(vector<string> s) {
	vector<string> strList;
	strList.push_back(s.at(0));
	vector<long> intList;
	intList.push_back(0);
	long SZ = 0;
	for (long i = 0; i < s.size(); i++){
		if (i % 100 == 0)
			cout << "nM.";
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
	cout << endl;
	intSz = intList;
	strSz = strList;
}

vector<long> stuffReturn::numzReturn() {
	return intSz;
}

vector<string> stuffReturn::strReturn() {
	return strSz;
}

void stuffReturn::outP(string file, int ac) {
	string inpt, inpt0, txtF = file;
	ifstream fil;
	fil.open(txtF);
	while (!fil.eof()) {
		getline(fil, inpt0);
		inpt += inpt0 + " \n";
	}
	stuffReturn sR;
	vector<string> a = sR.wordReturn(inpt);
	sR.nuMake(a);
	a = sR.strReturn();
	vector<long> a0 = sR.numzReturn();
	long COUNT = 0;
	while (COUNT < a.size()) {
		for (long i = 0; i < a.size(); i++) {
			if (i < a.size()) {
				if ((i + 1) >= a0.size())
					break;
				if (a0.at(i) > a0.at(i + 1)) {
					iter_swap(a.begin() + i, a.begin() + i + 1);
					iter_swap(a0.begin() + i, a0.begin() + i + 1);
				}
			}
		}
		COUNT++;
	}
	int w0 = 0, w1 = 0;
	while (a.size() - 1 > w0) {
		w1 = w0;
		while (w1 < a.size()) {
			if (a.at(w0) == a.at(w1)) {
				a.erase(a.begin() + w1);
				a0.erase(a0.begin() + w1);
			}
			w1++;
		}
		w0++;
	}
	cout << "---------" << endl;
	int SET, numS;
	long LENg = 0, i = 0;
	string SP = "        ";
	while (true) {
		SET = a0.at(i);
		cout << "OUTPUT " << "=| " << a0.at(i) << " | :" << endl;
		while (SET == a0.at(i)) {
			SP = "        ";
			numS = a0.at(i) / 10;
			for (int i = 0; i < a0.at(i); i++) {
				SP += " ";
			}
			cout << SP << a.at(i) << endl;
			i++;
			if (a0.size() <= i)
				break;
		}
		LENg++;
		if (LENg == a.size() || i >= a0.size())
			break;
	}
}

void stuffReturn::clr(){
	#ifdef _WIN32
	system("CLS");
	#else
	system("clear");
	#endif
}

void stuffReturn::pauz(){
	char a[0];
	#ifdef _WIN32
	system("pause");
	#else
	cout << "PressAnyKey\\" << endl;
	cin.ignore();
	cin.get();
	#endif
}