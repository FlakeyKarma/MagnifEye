#include "resources.h"
//Breaks down full string into vector of all words
vector<string> stuffReturn::wordReturn(string inpt) {
	long sz = 0;
	string s = "";
	vector<string> sS;
	vector<char> BLACKLIST = {};
	for (int i = 0; i < 255; i++) {
		progressBar(1.0/255 * 5.0);
		if (i < 32 || i > 123) {
			BLACKLIST.push_back((char)i);
		}
	}
	for (long i = 0; i < inpt.length(); i++) {
		bool CHK = false;
		progressBar(float(1.0/inpt.length())*15.0);
		for (int j = 0; j < BLACKLIST.size(); j++){
			if ((char)inpt[i] == (char)BLACKLIST.at(j)) {
				CHK = true;
				break;
			}
		}
		if (CHK == true)
			continue;
		if ((char)inpt[i] != ' ' && isalpha(inpt[i]) || (char)inpt[i] == '-' || (char)inpt[i] == '.' && isalpha((char)inpt[i+1]) || (char)inpt[i] == '\'') {
			if(isalpha((char)inpt[i])){
				s += tolower(inpt[i]);
			}else{
				s += inpt[i];
			}
		}

		if ((char)inpt[i] == '\\' || (char)inpt[i] == '/'||(char)inpt[i] == ':' && !isalpha((char)inpt[i])||(char)inpt[i] == ' ' && i != 0 && !isalpha((char)inpt[i]) && !s.empty()) {
			sS.push_back(s);
			s = "";
			sz++;
		}
	}
	return sS;
}

//Counts instances of each word
void stuffReturn::nuMake(bool t, vector<string> s) {
	if(t){
		strSz.push_back(s.at(0));
		intSz.push_back(0);
		long SZ = 0;
		for (long i = 0; i < s.size(); i++){
			progressBar(1.0/s.size()*20.0);
			for (long j = 0; j < strSz.size(); j++) {
				if (intSz.size() < strSz.size())
					intSz.push_back(0);
				if (s.at(i) == strSz.at(j)) {
					intSz.at(j)++;
					SZ++;
					break;
				}
				if (s.at(i) != strSz.at(j) && j == strSz.size() - 1) {
					strSz.push_back(s.at(i));
				}
			}
		}
	}
	if(!t){
		intPh.push_back(0);
		for (long i = 0; i < strPh.size(); i++){
			//progressBar(1.0/str.size()*20.0);
			for (long j = 0; j < strPh.size(); j++) {
				if (intPh.size() < strPh.size()){
					intPh.push_back(0);
				}
				if (strPh.at(i) == strPh.at(j)) {
					intPh.at(j)++;
				}
			}
		}
	}
}

//Information output
void stuffReturn::outP(string file, int ac, vector<char> chr) {
	string inpt, inpt0, txtF = file;
	ifstream fil;
	bool rC = false;
	for(int i = 0; i < chr.size(); i++){
		switch(chr.at(i)){
			case 'r':
				rC = true;
				break;
		}
	}
	fil.open(txtF);
	bool isGud = true;
	if(!fil.good()){
			std::cout << "-+=FileNotFound=+-" << endl;
			isGud = false;
		}
	if(isGud){
		while (!fil.eof()) {
			getline(fil, inpt0);
			inpt += inpt0 + " \n";
		}
		stuffReturn sR;
		vector<string> a = sR.wordReturn(inpt);
		sR.nuMake(1, a);
		if(rC)
			sR.redCheck(a);
		a = sR.strSz;
		sR.progressBar(20.0);
		vector<long> a0 = sR.intSz;
		sR.progressBar(20.0);
		long COUNT = 0;
		while (COUNT < a.size()) {
			sR.progressBar(float(1.0/a.size()*20.0));
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
		if(rC){
			sR.nuMake(0, a);
			COUNT = 0;
			while (COUNT < sR.strPh.size()) {
				sR.progressBar(float(1.0/sR.strPh.size()*20.0));
				for (long i = 0; i < sR.strPh.size(); i++) {
					if (i < sR.strPh.size()) {
						if ((i + 1) >= sR.intPh.size())
							break;
						if (sR.intPh.at(i) > sR.intPh.at(i + 1)) {
							iter_swap(sR.strPh.begin() + i, sR.strPh.begin() + i + 1);
							iter_swap(sR.intPh.begin() + i, sR.intPh.begin() + i + 1);
						}
					}
				}
				COUNT++;
			}
		}
		int w0 = 0, w1 = 0;
		while (a.size() - 1 > w0) {
			w1 = w0 + 1;
			while (w1 < a.size()) {
				if (a.at(w0) == a.at(w1)) {
					a.erase(a.begin() + w1);
					a0.erase(a0.begin() + w1);
				}
				w1++;
			}
			w0++;
		}
		if(rC){
			w0 = 0, w1 = 0;
			while (sR.strPh.size() > w0) {
				w1 = w0 + 1;
				while (w1 < sR.strPh.size()) {
					if (sR.strPh.at(w0) == sR.strPh.at(w1)) {
						sR.strPh.erase(sR.strPh.begin() + w1);
						sR.intPh.erase(sR.intPh.begin() + w1);
					}
					if (w1 == sR.strPh.size()-1){
						break;
					}
					w1++;
				}
				w0++;
			}
		}
		std::cout << "---------" << endl;
		long SET, numS;
		long LENg = 0, i = 0;
		string SP = " |--->  ";
		while (true) {
			SET = a0.at(i);
			std::cout << "OUTPUT " << "=| " << a0.at(i) << " | :" << endl;
			while (SET == a0.at(i)) {
				if(a0.at(i) <= 5){
					std::printf("\e[92m");
					std::cout << SP << a.at(i) << "\n" << " " << endl;
					std::printf("\e[0m");
				}
				if(a0.at(i) > 5 && a0.at(i) <= 10){
					std::printf("\e[93m");
					std::cout << SP << a.at(i) << "\n" << " " << endl;
					std::printf("\e[0m");
				}
				if(a0.at(i) > 10){
					std::printf("\e[31m");
					std::cout << SP << a.at(i) << "\n" << " " << endl;
					std::printf("\e[0m");
				}
				i++;
				if (a0.size() <= i)
					break;
			}
			LENg++;
			if (LENg == a.size() || i >= a0.size())
				break;
		}

		if(rC){
			sR.pauz();
			a = sR.strPh;
			a0 = sR.intPh;
			std::cout << "\n---------\n" << endl;
			SET, numS;
			LENg = 0, i = 0;
			std::printf("\e[91m");
			std::printf("\e[4m");
			std::cout << "BEGIN::(RedCheck)" << endl;
			std::printf("\e[0m");
			std::printf("\e[91m");
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				bool rCT = 0;
				if(a0.at(i) > 1){
					rCT = 1;
					std::cout << "OUTPUT " << "=| " << a0.at(i) - 1 << " | :" << endl;
					while (SET == a0.at(i)) {
						std::cout << SP << a.at(i) << "\n" << " " << endl;
						i++;
						if (a0.size() <= i)
							break;
					}
					LENg++;
					if (LENg == a.size() || i >= a0.size())
						break;
				}
				i++;
				if(!rCT && i >=a.size()){
					std::printf("\e[4m");
					std::cout << "\nTerminal>";
					std::printf("\e[0m");
					std::printf("\e[91m");
					std::printf("\e[5m");
					std::cout << "\tNo phrases to return" << endl;
					std::printf("\e[0m");
					std::printf("\e[91m");
				}
			}
			std::printf("\e[4m");
			std::cout << "\nEND::(RedCheck)" << endl;
			std::printf("\e[0m");
		}
	}
}

//Clears Screen
void stuffReturn::clr(){
	#ifdef _WIN32
	system("CLS");
	#else
	system("clear");
	#endif
}

//Pauses screen for user
void stuffReturn::pauz(){
	char a[0];
	#ifdef _WIN32
	system("pause");
	#else
	std::cout << "PressAnyKey\\" << endl;
	cin.ignore();
	cin.get();
	#endif
}

//Progress bar for...Progress
void stuffReturn::progressBar(float x){
	progress += x;
	char bar[] = {'\\', '|', '/', '-'};
	loadBar = "[";
	int frst = int(progress/10), second = 10-frst;
	for(int i = 0; i < frst; i++){
		loadBar += ":=:";
	}
	for(int i = 0; i < second; i++){
		loadBar += "   ";
	}
	loadBar += "]";
	if(chk % 2 == 0){
		numCheck++;
	}
	if(numCheck == 4){
		numCheck = 0;
	}
	chk++;
	
	std::cout << loadBar << bar[numCheck] << int(progress) << "\%" << endl;
	std::printf("%c[A", 27);
	std::printf("%c[2K", 27);
}

//Check for redundant phrases used
void stuffReturn::redCheck(vector<string> s){
	vector<string> phrase;
	string nxt = "";
	long leng = 0, l = 0;
	for(int i = 0; i < s.size(); i++){
		while(leng < 5){
			phrase.push_back(s.at(leng + i));
			leng++;
			if(leng + i == s.size() || leng + i == s.size()){
				break;
			}
		}
		leng = 0;
		for(int j = i; j < s.size(); j++){
			while(l < phrase.size()){
				if(l > 0){
					phrase.erase(phrase.begin());
					l--;
				}
				if(s.at(j) == phrase.at(l)){
					nxt += s.at(j) + " ";
					if(l == 0){
						if(nxt != "" && nxt != " " && GT1(nxt)){
							strPh.push_back(nxt);
						}
					}
					j++;
					l++;
					if(l >= phrase.size()){
						nxt = "";
						break;
					}
					continue;
				}
				if(s.at(j) != phrase.at(l)){
					nxt = "";
					break;
				}
				l++;
				j--;
			}
			l = 0;
		}
		if(!phrase.empty())
			phrase.clear();
	}
}

bool stuffReturn::GT1(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == ' '){
			if(i != s.length() - 1){
				if(s[i + 1] != ' '){
					return 1;
				}
			}
			if(i == s.length() - 1){
				return 0;
			}
		}
		if(i == s.length() - 1){
			return 0;
		}
	}
}