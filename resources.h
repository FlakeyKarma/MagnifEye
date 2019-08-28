#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

class Starter {
	protected:
		vector<string> *strSz = new vector<string>(500), *strPh = new vector<string>(500), *strS2 = new vector<string>(500),
					  *strDoc = new vector<string>(500), *spDoc = new vector<string>(500), *spD2 = new vector<string>(500);
		vector<long> *intSz = new vector<long>(500), *intPh = new vector<long>(500), *intS2 = new vector<long>(500),
					 *intDoc = new vector<long>(500), *ipDoc = new vector<long>(500), *ipD2 = new vector<long>(500);
		vector<char> chr;
		float progress = 0;
		int chk = 0, numCheck = 0;
		string loadBar, file0, file1;
		const string verz = "v1.13.8";
		bool tw = false, th = false, prd = false, libUse;
	public:
		~Starter(){
			if(!strSz->empty())
				delete strSz;
			if(!strPh->empty())
				delete strPh;
			if(!strS2->empty())
				delete strS2;
			if(!strDoc->empty())
				delete strDoc;
			if(!spDoc->empty())
				delete spDoc;
			if(!spD2->empty())
				delete spD2;
			if(!intSz->empty())
				delete intSz;
			if(!intPh->empty())
				delete intPh;
			if(!intS2->empty())
				delete intS2;
			if(!intDoc->empty())
				delete intDoc;
			if(!ipDoc->empty())
				delete ipDoc;
			if(!ipD2->empty())
				delete ipD2;

		}
		void setF(string s, bool b);
		bool GT1(string s);
		bool GUD(string f);
		void clr();
		void pauz();
		void progressBar(float x);
		void rO(string s);
		string ver();
		void data(bool a, bool b, bool c);
		void mkFil();
		void TFswitch(bool t);
		string filIn();
		void help();
		void setDownload();
		void Downloadz();
		void libInstl(string* s);
};

class ThNeedle : public Starter{
	public:
		vector<string> wordReturn(string s);
		void SeNDe(string s, bool t);
		void nuMake(int c, vector<string> *s);
};

class redCheck : public ThNeedle{
	public:
		void main(vector<string> *s, bool t);

};

class doCo : public redCheck {
	public:
		void main(vector<char> *c);
};

class weBI : public doCo {
	public:
		vector<char> main();
};

class MagnifEye : public weBI {
	public:
		void outP(string file, int ac, vector<char> *c);

};