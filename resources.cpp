#include "resources.h"

//Information output
void stuffReturn::outP(string file, int ac, vector<char> chr) {
	ifstream fil;
	bool def = false, rC = false, co = false, M = false;
	for(int i = 0; i < chr.size(); i++){
		switch(chr.at(i)){
			case 'A':
				def = true;
				break;
			case 'r':
				rC = true;
				break;
			case 'd':
				co = true;
				chr.erase(chr.begin() + i);
				i--;
				break;
			case 'M':
				M = true;
				break;
		}
	}
	fil.open(file);
	bool isGud = true;
	isGud = GUD(file);
	fil.close();
	if(isGud){
		stuffReturn sR;
		sR.chr = chr;
		sR.setF(file, 1);
		//sR.rO("AA::outP::A::");
		sR.SeNDe(file, 0);
		if(rC){
			sR.SeNDe(file, 1);
		}
		//sR.rO("BB::outP::B::");
		vector<string> a = sR.strSz;
		vector<long> a0 = sR.intSz;
		std::cout << "---------" << std::endl;
		/*
		if(rC){
			sR.strPh.clear();
			sR.intPh.clear();
		}
		*/
		if(co){
			sR.chr.push_back('d');
			sR.doCo(sR.chr);
		}
		long SET, numS;
		long LENg = 0, i = 0;
		string SP = " |--->  ";
		//sR.rO("CC::outP::C::");
		if(!M && def){
			while (true) {
				SET = a0.at(i);
				std::cout << "OUTPUT " << "=| " << a0.at(i) << " | :" << std::endl;
				while (SET == a0.at(i)) {
					if(i % 20 == 0 && i > 0)
						sR.pauz();
					if(a0.at(i) <= 5){
						std::printf("\e[92m");
						std::cout << SP << a.at(i) << "\n" << " " << std::endl;
						std::printf("\e[0m");
					}
					if(a0.at(i) > 5 && a0.at(i) <= 10){
						std::printf("\e[93m");
						std::cout << SP << a.at(i) << "\n" << " " << std::endl;
						std::printf("\e[0m");
					}
					if(a0.at(i) > 10){
						std::printf("\e[31m");
						std::cout << SP << a.at(i) << "\n" << " " << std::endl;
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
		}
		if(rC){
			bool rCT = 0;
			if(!M)
				if(def)
					sR.pauz();
			a = sR.strPh;
			a0 = sR.intPh;
			std::cout << "\n---------\n" << std::endl;
			LENg = 0, i = 0;
			std::printf("\e[91m");
			std::printf("\e[4m");
			std::cout << "BEGIN::(RedCheck)" << std::endl;
			std::printf("\e[0m");
			std::printf("\e[91m");
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				if(a0.at(i) > 1){
					rCT = 1;
					std::cout << "OUTPUT " << "=| " << a0.at(i) - 1 << " | :" << std::endl;
					while (SET == a0.at(i)) {
						if(i % 20 == 0 && i > 0)
							sR.pauz();
						std::cout << SP << a.at(i) << "\n" << " " << std::endl;
						i++;
						if (a0.size() <= i)
							break;
					}
					LENg++;
					if (LENg == a.size() || i >= a0.size())
						break;
				}
				i++;
				if(!rCT && i >= a.size()){
					std::printf("\e[4m");
					std::cout << "\nTerminal>";
					std::printf("\e[0m");
					std::printf("\e[91m");
					std::printf("\e[5m");
					std::cout << "\tNo phrases to return" << std::endl;
					std::printf("\e[0m");
					std::printf("\e[91m");
				}
			}
			std::printf("\e[4m");
			std::cout << "\nEND::(RedCheck)" << std::endl;
			std::printf("\e[0m");
		}
		if(co){
			vector<string> nLW, nL0, pr0, pr1;
			if(!M)
				if(def || rC)
					sR.pauz();
			//sR.rO("EE::outP::D::");
			int ln0 = 0, ln1 = 0, sWrd = 0, s0 = 0, s1 = 0, lng0, lng1, lng2 = 0;
			string spWrd = "", sp0 = "", outpt = " +===> OUTPUT", lne = "-{", prc = "%  ", prcW;
			long chk0, chk1;
			//Set sWrd as length of longest word in strSz 
			for(long i = 0; i < sR.strSz.size(); i++){
				if(i > 0){
					if(to_string(sR.intSz.at(i)).length() > to_string(sR.intSz.at(i-1)).length()){
						sWrd = sR.strSz.at(i).length();
					}
				}
			}
			//Add presence of percentages from first document to list of prO
			for(long i = 0; i < sR.intSz.size(); i++){
				if(sR.intSz.at(i)/sR.intSz.size() > 0)
					prcW = to_string(sR.intSz.at(i)/sR.intSz.size());
				else
					prcW = "<0";
				
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr0.push_back(prcW);
			}
			//Add presence of percentages from second document to list of pr1
			for(long i = 0; i < sR.intS2.size(); i++){
				if(sR.intS2.at(i)/sR.intS2.size() > 0)
					prcW = to_string(sR.intS2.at(i)/sR.intS2.size());
				else
					prcW = "<0";
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr1.push_back(prcW);
			}
			//Make length of each number to equal that of the size of the longest number, plus two spaces
			for(long i = 0; i < sR.intSz.size(); i++){
				spWrd = to_string(sR.intSz.at(i));
				while(spWrd.length() < sWrd + 2){
					spWrd += " ";
				}
				nLW.push_back(spWrd);
			}
			for(long i = 0; i < sR.strS2.size(); i++){
				if(i > 0){
					if(to_string(sR.intS2.at(i)).length() > to_string(sR.intS2.at(i-1)).length()){
						sWrd = sR.strS2.at(i).length();
					}
				}
			}
			for(long i = 0; i < sR.intS2.size(); i++){
				if(i > 0){
					if(sR.strS2.at(i).length() > sR.strS2.at(i-1).length()){
						s0 = sR.strS2.at(i).length();
					}
				}
			}
			for(long i = 0; i < sR.strS2.size(); i++){
				sp0 = to_string(sR.intS2.at(i));
				while(sp0.length() < sWrd + 3){
					sp0 += " ";
				}
				nL0.push_back(sp0);
			}
			if(s0 + 2 > sR.file0.length() + 1) lng0 = s0+2; else lng0 = sR.file0.length() + 1;
			sR.file0 += " ";
			for(long i = 0; i < sR.strDoc.size(); i++){
				if(i > 0){
					if(sR.strDoc.at(i).length() > sR.strDoc.at(i-1).length()){
						s1 = sR.strDoc.at(i).length();
					}
				}
			}
			sR.file1 += ' ';
			a = sR.strDoc;
			for(int i = 0; i < a.size(); i++){
				if(i > 0){
					if(a.at(i).length() >= lng2){
						lng2 = a.at(i).length();
					}
				}
			}
			for(long i = 0; i < a.size(); i++){
				while(a.at(i).length() < lng2 + 3){
					a.at(i) += " ";
				}
			}
			while(outpt.length() < lng2 + 11){
				outpt += " ";
			}
			while(lne.length() < lng2 + lng0 + lng0 + sWrd){
				lne += "=";
			}
			lne += "}-";
			a0 = sR.intDoc;
			std::cout << "\n---------\n" << std::endl;
			LENg = 0, i = 0;
			std::printf("\e[96m");
			std::printf("\e[4m");
			std::cout << "BEGIN::(DoCo)" << std::endl;
			std::printf("\e[0m");
			std::printf("\e[96m");
			//sR.rO("FIN::B:");
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				bool rCT = 0;
				rCT = 1;
				std::cout << outpt << sR.file0 << prc << sR.file1 << prc << std::endl;
				std::cout << lne << std::endl;
				while (SET == a0.at(i)) {
					if(i % 30 == 0 && i > 0)
						sR.pauz();
					for(int j = 0; j < sR.strSz.size(); j++){
						if(sR.strSz.at(j) == sR.strDoc.at(i)){
							chk0 = j;
							break;
						}
					}
					for(int j = 0; j < sR.strS2.size(); j++){
						if(sR.strS2.at(j) == sR.strDoc.at(i)){
							chk1 = j;
							break;
						}
					}
					std::cout << SP << a.at(i) << nLW.at(chk0) << pr0.at(chk0) << nL0.at(chk1) << pr1.at(chk1) << '\n'<< std::endl;
					i++;
					if (a0.size() <= i)
						break;
				}
				LENg++;
				if (LENg == a.size() || i >= a0.size())
					break;
				i++;
				if(!rCT && i >= a.size()){
					std::printf("\e[4m");
					std::cout << "\nTerminal>";
					std::printf("\e[0m");
					std::printf("\e[91m");
					std::printf("\e[5m");
					std::cout << "\tNo phrases to return" << std::endl;
					std::printf("\e[0m");
					std::printf("\e[96m");
				}
			}
			std::printf("\e[4m");
			std::cout << "\nEND::(DoCo)" << std::endl;
			std::printf("\e[0m");
		}
	}
}

/*
FUNCTIONS FOR outP
*/

//SearchNDestroy
void stuffReturn::SeNDe(string file, bool rC){
	cout << "\n\n\tSeNDe\n\n" << endl;
	bool c = false, t = false, def = false, dc = false;
	for(int i = 0; i < chr.size(); i++){
		switch(chr.at(i)){
			case 'd':
				c = true;
				break;
			case 't':
				t = true;
				break;
			case 'A':
				def = true;
				break;
			case 'O':
				dc = true;
				break;
		}
	}
	if(rC)
		def = false;
	//rO("FF::SeNDe::A::");
	ifstream fil;
	string inpt, inpt0;
	fil.open(file);
	while (!fil.eof()) {
		getline(fil, inpt0);
		inpt += inpt0 + " \n";
	}
	fil.close();
	vector<string> a = wordReturn(inpt);
	vector<long> a0;
	inpt = "";
	inpt0 = "";
	if(def && !c)
		nuMake(0, a);
	if(rC && !c && !dc){
		redCheck(a, 0);
	}
	if(dc)
		redCheck(a, 1);
	if(c && !dc)
		nuMake(2, a);
	a = strSz;
	progressBar(20.0);
	a0 = intSz;
	progressBar(20.0);
	if(rC){
		a = strPh;
		if(dc)
			a = spDoc;
		if(!dc)
			nuMake(1, a);
		if(dc)
			nuMake(4, a);
		a0 = intPh;
		if(dc){
			a0 = ipDoc;
		}
	}
	if(def && !dc){
		a = strSz;
		a0 = intSz;
	}
	if(c && !dc){
		a = strS2;
		a0 = intS2;
	}
	long COUNT = 0;
	while (COUNT < a.size()) {
		progressBar(float(1.0/a.size()*20.0));
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
	//rO("GG::SeNDe::B::");
	COUNT = 0;
	int w0 = 0, w1 = 0;
	while (a.size() - 1 > w0) {
		w1 = w0 + 1;
		while (w1 < a.size()) {
			if (a.at(w0) == a.at(w1)) {
				a.erase(a.begin() + w1);
				a0.erase(a0.begin() + w1);
				w1--;
			}
			w1++;
		}
		w0++;
	}
	//rO("HH::SeNDe::C::");
	if(c && !dc){
		strS2 = a;
		intS2 = a0;
	}
	if (def && !c){
		strSz = a;
		intSz = a0;
	}
	if (rC && !dc){
		for(int i = 0; i < chr.size(); i++){
			if(chr.at(i) == 'r'){
				chr.erase(chr.begin() + i);
				break;
			}
		}
		strPh = a;
		intPh = a0;
	}
	if(dc){
		spDoc = a;
		ipDoc = a0;
	}
	std::cout << "\n\n\t\\SeNDe\n\n" << std::endl;
}

//Breaks down full string into vector of all words
vector<string> stuffReturn::wordReturn(string inpt) {
	cout  << "\n\n\twordReturn\n\n" << endl;
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
	//rO("II::wordReturn::A::");
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
	//rO("JJ::wordReturn::B::");
	cout << "\n\n\t\\wordReturn\n\n" << endl;
	return sS;
}

//Counts instances of each word
void stuffReturn::nuMake(char t, vector<string> s) {
	cout << "\n\n\tnuMake\n\n" << endl;
	if(t == 0){
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
	else if(t >= 1){
		vector<string> a, strV;
		vector<long> a0;
		switch(t){
			case 1:
				strV = strPh;
				a = strPh;
				break;
			default:
				strV = s;
				a = s;
				break;
		}
		a0.push_back(0);
		for (long i = 0; i < a.size(); i++){
			//progressBar(1.0/str.size()*20.0);
			for (long j = 0; j < strV.size(); j++) {
				if (a0.size() < a.size()){
					a0.push_back(0);
				}
				if (a.at(i) == strV.at(j)) {
					a0.at(j)++;
				}
			}
		}
		switch(t){
			case 1:
				intPh = a0;
				break;
			case 2:
				strS2 = a;
				intS2 = a0;
				break;
			case 3:
				intDoc = a0;
				break;
			case 4:
				ipDoc = a0;
				break;
			case 5:
				ipD2 = a0;
				break;
		}
		if(!a0.empty())
			a0.clear();
		if(!a.empty())
			a.clear();
	}
	cout  << "\n\n\t\\nuMake\n\n" << endl;
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
	std::cout << "PressAnyKey\\" << std::endl;
	cin.ignore();
	cin.get();
	#endif
}

//Returns Version
string stuffReturn::ver(){
	return verz;
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
	
	std::cout << loadBar << bar[numCheck] << int(progress) << "\%" << std::endl;
	std::printf("%c[A", 27);
	std::printf("%c[2K", 27);
}

//Check for redundant phrases used
void stuffReturn::redCheck(vector<string> s, bool d){
	cout  << "\n\n\tredCheck\n\n" << endl;
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
							if(d)
								spDoc.push_back(nxt);
							else
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
	cout  << "\n\n\t\\redCheck\n\n" << endl;
}

//Compare documents for similarities in vocabulary and word patterns
void stuffReturn::doCo(vector<char> c){
	cout  << "\n\n\tdoCo\n\n" << endl;
	string file;
	while(1){
		std::cout << "FK> Enter second file: ";
		cin >> file;
		if(file == "ls"){
			system("ls");
			file = "";
		}
		else if (GUD(file)){
			break;
		}
	}
	setF(file, 0);
	SeNDe(file, 0);
	for(int i = 0; i < strSz.size(); i++){
		for(int j = 0; j < strS2.size(); j++){
			if(strSz.at(i) == strS2.at(j)){
				strDoc.push_back(strSz.at(j));
			}
		}
	}
	nuMake(3, strDoc);
	chr.push_back('O');
	SeNDe(file, 1);
	chr.pop_back();
	for(int i = 0; i < strPh.size(); i++){
		for(int j = 0; j < spDoc.size(); j++){
			if(strPh.at(i) == spDoc.at(j)){
				spD2.push_back(strPh.at(i));
			}
		}
	}
	nuMake(5, spD2);
	//rO("DoCo::C");
	pauz();
	cout  << "\n\n\t\\doCo\n\n" << endl;
}

//Check if the string has more than one word
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

//Check if file is good
bool stuffReturn::GUD(string fil){
	bool tf = 0;
	ifstream f;
	f.open(fil);
	if(!f.good()){
			std::cout << "-+=FileNotFound=+-" << std::endl;
	} else {
		tf = 1;
	}
	f.close();
	return tf;
}

//Setting file names
void stuffReturn::setF(string fil, bool b){
	string f = "";
	for(int i = 0; i < f.length() - 4; i++){
		f += fil[i];
	}
	if(b)
		file0 = f;
	else
		file1 = f;
		
}

void stuffReturn::rO(string s){
	cout << "--LISTS--" << endl;
	cout << s << "::::::::::::::>Doc 1 words<< " << strSz.size() << " " << intSz.size() << endl;
	for(int i = 0; i < strSz.size(); i++){
		cout << strSz.at(i) << " :: " << intSz.at(i) << endl;
	}
	cout << s << "::::::::::::::>\\Doc 1 words<< " << strSz.size() << " " << intSz.size() << endl;
	pauz();
	cout << s << "::::::::::::::>Doc 1 red<< " << strPh.size() << " " << intPh.size() << endl;
	for(int i = 0; i < strPh.size(); i++){
		cout << strPh.at(i) << " :: " << intPh.at(i) << endl;
	}
	cout << s << "::::::::::::::>\\Doc 1 red<< " << strPh.size() << " " << intPh.size() << endl;
	pauz();
	cout << s << "::::::::::::::>Doc 2 words<< " << strS2.size() << " " << intS2.size() << endl;
	for(int i = 0; i < strS2.size(); i++){
		cout << strS2.at(i) << " :: " << intS2.at(i) << endl;
	}
	cout << s << "::::::::::::::>\\Doc 2 words<< " << strS2.size() << " " << intS2.size() << endl;
	pauz();
	cout << s << "::::::::::::::>doCo:Words<< " << strDoc.size() << " " << intDoc.size() << endl;
	for(int i = 0; i < strDoc.size(); i++){
		cout << strDoc.at(i) << " :: " << intDoc.at(i) << endl;
	}
	cout << s << "::::::::::::::>\\doCo:Words<< " << strDoc.size() << " " << intDoc.size() << endl;
	pauz();
	cout << s << "::::::::::::::>Doc 2 red<< " << spDoc.size() << " " << ipDoc.size() << endl;
	for(int i = 0; i < spDoc.size(); i++){
		cout << spDoc.at(i) << " :: " << ipDoc.at(i) << endl;
	}
	cout << s << "::::::::::::::>\\Doc 2 red<< " << spDoc.size() << " " << ipDoc.size() << endl;
	pauz();
	cout << s << "::::::::::::::>doCo:Red<< " << spD2.size() << " " << ipD2.size() << endl;
	for(int i = 0; i < spD2.size(); i++){
		cout << spD2.at(i) << " :: " << ipD2.at(i) << endl;
	}
	cout << s << "::::::::::::::>\\doCo:Red<< " << endl;
	pauz();
}