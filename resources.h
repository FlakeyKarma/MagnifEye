#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <variant>
#define CHC_SIZE 5

class Complementary {
	private:
		struct set0{
			std::vector<std::string> str;
			std::vector<long> lng;
		};
		std::vector<set0> tempSort;
		std::vector<std::string> *strThNeedle = new std::vector<std::string>(500), *strRedCheck = new std::vector<std::string>(500), *strComparison0 = new std::vector<std::string>(500),
						*strComparison1 = new std::vector<std::string>(0), *strDoc0 = new std::vector<std::string>(500), *strDoc1 = new std::vector<std::string>(0);
		std::vector<long> *intThNeedle = new std::vector<long>(500), *intRedCheck = new std::vector<long>(500), *intComparison0 = new std::vector<long>(500),
					 *intComparison1 = new std::vector<long>(0), *intDoc0 = new std::vector<long>(500), *intDoc1 = new std::vector<long>(0);

		float progress = 0;
		int chk = 0, numCheck = 0, prg = 0;
		std::string loadBar, file0="", file1="", inptMain;
		const std::string verz = "v2.15.8";
		bool tw = false, th = false, prd = false, libUse;
		~Complementary(){
			if(!strThNeedle->empty())
				delete strThNeedle;
			if(!strRedCheck->empty())
				delete strRedCheck;
			if(!strComparison1->empty())
				delete strComparison1;
			if(!strComparison0->empty())
				delete strComparison0;
			if(!strDoc0->empty())
				delete strDoc0;
			if(!strDoc1->empty())
				delete strDoc1;
			if(!intThNeedle->empty())
				delete intThNeedle;
			if(!intRedCheck->empty())
				delete intRedCheck;
			if(!intComparison1->empty())
				delete intComparison1;
			if(!intComparison0->empty())
				delete intComparison0;
			if(!intDoc0->empty())
				delete intDoc0;
			if(!intDoc1->empty())
				delete intDoc1;
		}
	public:
		//Main functions

			//ThNeedle function
			std::vector<set0> ThNeedle(bool b);

			//RedCheck function
				std::vector<set0> RedCheck(bool b);

			//DoCo function
				void DoCo();

			//WeBI function
				void WeBI();

			//MagnifEye function
				void MagnifEye(std::string f);

			//Output
				void outP();

			//Return functions
				std::vector<std::string> wordReturn(std::string s);
				std::vector<set0> SeNDe(std::vector<set0>);
				std::vector<set0> nuMake(bool t, std::vector<std::string> s);
				char * filIn();
				bool GT1(std::string s);
				bool GUD(std::string f);
				std::string ver();

			//Set functions
				void setF(std::string s, bool b);
				void TFswitch(bool t);
				void setDownload();

			//Helper functions
				void clr();
				void progressBar(float x);
				void rO(std::string s);
				void data(bool a, bool b, bool c);
				void mkFil();
				void help();
				void Downloadz();
				void libInstl(std::string* s);

			//Var setF
				//ThNeedle, RedCheck, DoCo0, Doco1, WeBI, ParseData
				bool opChc[CHC_SIZE] = {0};
};
