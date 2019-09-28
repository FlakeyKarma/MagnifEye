#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

class ThNeedle {
	private:
		std::vector<std::string> *strSz = new std::vector<std::string>(500), *strPh = new std::vector<std::string>(500), *strS2 = new std::vector<std::string>(500),
					  *strDoc = new std::vector<std::string>(500), *spDoc = new std::vector<std::string>(500), *spD2 = new std::vector<std::string>(500);
		std::vector<long> *intSz = new std::vector<long>(500), *intPh = new std::vector<long>(500), *intS2 = new std::vector<long>(500),
					 *intDoc = new std::vector<long>(500), *ipDoc = new std::vector<long>(500), *ipD2 = new std::vector<long>(500);
		std::vector<char> chr;
		float progress = 0;
		int chk = 0, numCheck = 0;
		std::string loadBar, file0, file1;
		const std::string verz = "v1.15.8";
		bool tw = false, th = false, prd = false, libUse;
	public:
		~ThNeedle(){
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
		void setF(std::string s, bool b);
		std::vector<std::string> wordReturn(std::string s);
		void SeNDe(std::string s, bool t);
		void nuMake(int c, std::vector<std::string> *s);
		void outP(std::string file, int ac, std::vector<char> *c);
		void redCheck(std::vector<std::string> *s, bool t);
		bool GT1(std::string s);
		bool GUD(std::string f);
		void doCo(std::vector<char> *c);
		void clr();
		void pauz();
		void progressBar(float x);
		void rO(std::string s);
		std::string ver();
		void data(bool a, bool b, bool c);
		void mkFil();
		void TFswitch(bool t);
		std::vector<char> weBI();
		std::string filIn();
		void help();
		void setDownload();
		void Downloadz();
		void libInstl(std::string* s);
};

class redCheck : public ThNeedle{

};

class doCo : public redCheck {

};