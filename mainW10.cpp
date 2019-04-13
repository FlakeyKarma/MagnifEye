#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "resources.h"
using namespace std;

int main(int argc, char* argv[]) {
	int sz = 0, sp = 0;
	char inpt01[100];
	sz = 0;
	for (int i = 1; i < (signed)argc; i++)
		for (int j = 0; j < strlen(argv[i]); j++) {
			inpt01[sz] = argv[i][j];
			sz++;
		}
	inpt01[sz] = '\0';
	//INTAKE:END
	string inpt, inpt0, txtF = inpt01;
	ifstream fil;
	fil.open(inpt01);
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
	int w0=0, w1=0;
	while(a.size() - 1 > w0) {
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
	return 0;
}