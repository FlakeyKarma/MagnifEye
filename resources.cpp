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
	std::cout << endl;
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
		if ((char)inpt[i] != ' ' && isalpha(inpt[i]) || (char)inpt[i] == '-' || (char)inpt[i] == '.' && isalpha((char)inpt[i+1])) {
			s += tolower(inpt[i]);
		}

		if ((char)inpt[i] == '\\' || (char)inpt[i] == '/'||(char)inpt[i] == ':' && !isalpha((char)inpt[i])||(char)inpt[i] == ' ' && i != 0 && !isalpha((char)inpt[i]) && !s.empty()) {
			sS.push_back(s);
			s = "";
			sz++;
		}
	}
	std::cout << endl;
	return sS;
}

//Counts instances of each word
void stuffReturn::nuMake(vector<string> s) {
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

void stuffReturn::outP(string file, int ac) {
	string inpt, inpt0, txtF = file;
	ifstream fil;
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
		sR.nuMake(a);
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
		std::cout << "---------" << endl;
		long SET, numS;
		long LENg = 0, i = 0;
		string SP = "        ";
		while (true) {
			SET = a0.at(i);
			std::cout << "OUTPUT " << "=| " << a0.at(i) << " | :" << endl;
			while (SET == a0.at(i)) {
				SP = "        ";
				for (int i = 0; i < a0.size(); i++) {
					SP += " ";
				}
				std::cout << SP << a.at(i) << endl;
				i++;
				if (a0.size() <= i)
					break;
			}
			LENg++;
			if (LENg == a.size() || i >= a0.size())
				break;
		}
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
	std::cout << "PressAnyKey\\" << endl;
	cin.ignore();
	cin.get();
	#endif
}

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
	printf("%c[A", 27);
	printf("%c[2K", 27);
}