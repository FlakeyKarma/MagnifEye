#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class stuffReturn {
	private:
		vector<string> strSz;
		vector<string> strPh;
		vector<long> intSz;
		vector<long> intPh;
		float progress = 0;
		int chk = 0;
		int numCheck = 0;
		string loadBar;
	public:
		vector<string> wordReturn(string s);
		void nuMake(bool tf, vector<string> s);
		void outP(string file, int ac, vector<char> c);
		void redCheck(vector<string> s);
		bool GT1(string s);
		void clr();
		void pauz();
		void progressBar(float x);
};

