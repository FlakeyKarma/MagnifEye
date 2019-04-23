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
		vector<long> intSz;
		float progress = 0;
		int chk = 0;
		int numCheck = 0;
		string loadBar;
	public:
		vector<string> wordReturn(string s);
		void nuMake(vector<string> s);
		vector<long> numzReturn();
		vector<string> strReturn();
		void outP(string file, int ac);
		void clr();
		void pauz();
		void progressBar(float x);
};

