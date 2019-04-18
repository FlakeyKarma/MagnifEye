#include <iostream>
#include <string>
#include <vector>
using namespace std;

class stuffReturn {
	private:
		vector<string> strSz;
		vector<long> intSz;
	public:
		vector<string> wordReturn(string s);
		void nuMake(vector<string> s);
		vector<long> numzReturn();
		vector<string> strReturn();
		void outP(string file, int ac);
		void clr();
		void pauz();
};

