#include "resources.h"

//Information output
void stuffReturn::outP(string file, int ac, vector<char> *chr0) {
	ifstream fil;
	bool def = false, rC = false, co = false, M = false, tw = false, th = false, toFil = false, w = false, pth = false;
	for(int i = 0; i < chr0->size(); i++){
		switch(chr0->at(i)){
			case 'A':
				def = true;
				break;
			case 'r':
				rC = true;
				tw = true;
				break;
			case 'd':
				co = true;
				th = true;
				chr0->erase(chr0->begin() + i);
				i--;
				break;
			case 'M':
				M = true;
				break;
			case 'w':
				w = true;
				toFil = true;
				break;
			case 'F':
				toFil = true;
				break;
			case 'P':
				pth = true;
				break;
		}
	}
	//No RedCheck
	if(!rC){
		if(!this->strPh->empty())
			delete this->strPh;	
		if(!this->intPh->empty())
			delete this->intPh;
	}
	//No second file
	if(!co){
			if(!this->strS2->empty())
				delete this->strS2;
			if(!this->strDoc->empty())
				delete this->strDoc;
			if(!this->spDoc->empty())
				delete this->spDoc;
			if(!this->spD2->empty())
				delete this->spD2;
			if(!this->intS2->empty())
				delete this->intS2;
			if(!this->intDoc->empty())
				delete this->intDoc;
			if(!this->ipDoc->empty())
				delete this->ipDoc;
			if(!this->ipD2->empty())
				delete this->ipD2;
	}
	fil.open(file);
	bool isGud = true;
	isGud = GUD(file);
	fil.close();
	if(isGud){
		ofstream W;
		W.open("temp.txt");
		string temp = "";
		this->mkFil();
		this->tw = tw;
		this->th = th;
		chr = *chr0;
		this->setF(file, 1);
		//cout << "A" << endl;
		this->SeNDe(file, 0);
		////this->rO("AA::outP::A::");
		if(rC){
			this->SeNDe(file, 1);
		}
		//this->rO("BB::outP::B::");
		//cout << "B" << endl;
		vector<string> a = *this->strSz;
		vector<long> a0 = *this->intSz;
		if(!w)
			std::cout << "---------" << std::endl;
		if(co){
			chr.push_back('d');
			this->doCo(&chr);
		}

		//No RedCheck
		if(rC){
			this->strPh->erase(this->strPh->end()-1);
			this->intPh->erase(this->intPh->end()-1);
		}
		//No second file
		if(co){
			this->strS2->erase(this->strS2->end()-1);
			this->strDoc->erase(this->strDoc->end()-1);
			this->spDoc->erase(this->spDoc->end()-1);
			this->spD2->erase(this->spD2->end()-1);
			this->intS2->erase(this->intS2->end()-1);
			this->intDoc->erase(this->intDoc->end()-1);
			this->ipDoc->erase(this->ipDoc->end()-1);
			this->ipD2->erase(this->ipD2->end()-1);
		}

		long SET, numS;
		long LENg = 0, i = 0;
		string SP = " |--->  ";
		//this->rO("CC::outP::C::");
		//cout << "C" << endl;
		if(!M && def){
			if(w){
				for(int i = 0; i < this->strSz->size(); i++){
					W << "STRSZ= " << this->strSz->at(i) <<" " << this->intSz->at(i) << endl;
				}
			}
			while (true) {
				SET = a0.at(i);
				if(!w)
					std::cout << "OUTPUT " << "=| " << a0.at(i) << " | :" << std::endl;
				while (SET == a0.at(i)) {
					if(!toFil)
						if(i % 20 == 0 && i > 0)
							this->pauz();
					if(a0.at(i) <= 5 && !w){
						std::cout << "\e[92m" << SP << a.at(i) << "\n" << " \e[0m" << std::endl;
					}
					if(a0.at(i) > 5 && a0.at(i) <= 10 && !w){
						std::cout << "\e[93m" << SP << a.at(i) << "\n" << " \e[0m" << std::endl;
					}
					if(a0.at(i) > 10 && !w){
						std::cout << "\e[31m" << SP << a.at(i) << "\n" << " \e[0m" << std::endl;
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
			if(w){
				for(int i = 0; i < this->strPh->size(); i++){
					if(this->intPh->at(i) > 1)
						W << "STRPH= " << this->strPh->at(i) <<" " << this->intPh->at(i) << std::endl;
				}
			}
			if(!M)
				if(!toFil)
					if(def)
						this->pauz();
			a = *this->strPh;
			a0 = *this->intPh;
			if(!w)
				std::cout << "\n---------\n" << std::endl;
			LENg = 0, i = 0;
			if(!w){
				std::cout << "\e[91m\e[4mBEGIN::(RedCheck)\e[0m\e[91m" << std::endl;
			}
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				if(a0.at(i) > 1){
					rCT = 1;
					if(!w){						
						std::cout << "OUTPUT " << "=| \e[97m";
						std::cout << a0.at(i) - 1;
						std::cout << "\e[91m | :" << std::endl;
					}
					while (SET == a0.at(i)) {
						if(!toFil)
							if(i % 20 == 0 && i > 0)
								this->pauz();
						if(!w)
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
					if(!w){
						std::cout << "\n\e[4mTerminal>\e[0m\e[91m\e[5m";
						std::cout << "\tNo phrases to return\e[0m\e[91m" << std::endl;
					} else {
						W << "NONE" << std::endl;
					}
				}
			}
			if(!w){
				std::cout << "\n\e[4mEND::(RedCheck)\e[0m" << std::endl;
			}
		}
		if(co){
			vector<string> nLW, nL0, pr0, pr1;
			if(w){
				W << "FILE 1: " << this->file0 << std::endl;
				W << "FILE 2: " << this->file1 << std::endl;
				for(int i = 0; i < this->strS2->size(); i++){
					W << "STRS2= " << this->strS2->at(i) <<" " << this->intS2->at(i) << std::endl;
				}
				for(int i = 0; i < this->strDoc->size(); i++){
					W << "STRDOC= " << this->strDoc->at(i) <<" " << this->intDoc->at(i) << std::endl;
				}
				for(int i = 0; i < this->spDoc->size(); i++){
					W << "SPDOC= " << this->spDoc->at(i) <<" " << this->ipDoc->at(i) << std::endl;
				}
				for(int i = 0; i < this->spD2->size(); i++){
					W << "SPD2= " << this->spD2->at(i) <<" " << this->ipD2->at(i) << std::endl;
				}
			}
			if(!M)
				if(!toFil)
					if(def || rC)
						this->pauz();
			//this->rO("EE::outP::D::");
			int ln0 = 0, sWrd = 0, s0 = 0, s1 = 0, lng0, lng1, lng2 = 0;
			string spWrd = "", sp0 = "", outpt = " +===> OUTPUT", lne = "-{", prc = "%  ", prcW;
			long chk0, chk1;
			//Set sWrd as length of longest word in strSz 
			for(long i = 0; i < this->strSz->size(); i++){
				if(i > 0){
					if(to_string(this->intSz->at(i)).length() > to_string(this->intSz->at(i-1)).length()){
						sWrd = this->strSz->at(i).length();
					}
				}
			}
			//Add presence of percentages from first document to list of prO
			for(long i = 0; i < this->intSz->size(); i++){
				if(this->intSz->at(i)/this->intSz->size() > 0)
					prcW = to_string(this->intSz->at(i)/this->intSz->size());
				else
					prcW = "<0";
				
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr0.push_back(prcW);
			}
			//Add presence of percentages from second document to list of pr1
			for(long i = 0; i < this->intS2->size(); i++){
				if(this->intS2->at(i)/this->intS2->size() > 0)
					prcW = to_string(this->intS2->at(i)/this->intS2->size());
				else
					prcW = "<0";
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr1.push_back(prcW);
			}
			//Make length of each number to equal that of the size of the longest number, plus two spaces
			for(long i = 0; i < this->intSz->size(); i++){
				spWrd = to_string(this->intSz->at(i));
				while(spWrd.length() < sWrd + 2){
					spWrd += " ";
				}
				nLW.push_back(spWrd);
			}
			for(long i = 0; i < this->strS2->size(); i++){
				if(i > 0){
					if(to_string(this->intS2->at(i)).length() > to_string(this->intS2->at(i-1)).length()){
						sWrd = this->strS2->at(i).length();
					}
				}
			}
			for(long i = 0; i < this->intS2->size(); i++){
				if(i > 0){
					if(this->strS2->at(i).length() > this->strS2->at(i-1).length()){
						s0 = this->strS2->at(i).length();
					}
				}
			}
			for(long i = 0; i < this->strS2->size(); i++){
				sp0 = to_string(this->intS2->at(i));
				while(sp0.length() < sWrd + 3){
					sp0 += " ";
				}
				nL0.push_back(sp0);
			}
			if(s0 + 2 > this->file0.length() + 1) lng0 = s0+2; else lng0 = this->file0.length() + 1;
			this->file0 += " ";
			for(long i = 0; i < this->strDoc->size(); i++){
				if(i > 0){
					if(this->strDoc->at(i).length() > this->strDoc->at(i-1).length()){
						s1 = this->strDoc->at(i).length();
					}
				}
			}
			this->file1 += ' ';
			a = *this->strDoc;
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
			a0 = *this->intDoc;
			if(!w)
				std::cout << "\n---------\n" << std::endl;
			LENg = 0, i = 0;
			if(!w){
				std::cout << "\e[96m\e[4mBEGIN::(DoCo)\e[0m\e[96m" << std::endl;
			}			
			//this->rO("FIN::B:");
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				bool rCT = 0;
				rCT = 1;
				if(!w){
					std::cout << outpt << this->file0 << prc << this->file1 << prc << std::endl;
					std::cout << lne << std::endl;
				}
				while (SET == a0.at(i)) {
					if(!toFil)
						if(i % 30 == 0 && i > 0)
							this->pauz();
					for(int j = 0; j < this->strSz->size(); j++){
						if(this->strSz->at(j) == this->strDoc->at(i)){
							chk0 = j;
							break;
						}
					}
					for(int j = 0; j < this->strS2->size(); j++){
						if(this->strS2->at(j) == this->strDoc->at(i)){
							chk1 = j;
							break;
						}
					}
					if(!w)
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
					if(!w){
						std::cout << "\n\e[4mTerminal>\e[0m\e[91m\e[5m";
						std::cout << "\tNo phrases to return\e[0m\e[96m" << std::endl;
					} else {
						W << "NONE" << std::endl;
					}
				}
			}

			if(!toFil)
				pauz();
			
			
			vector<vector<string>> chekk = {nLW, nL0, pr0, pr1};
			for(int i = 0; i < chekk.size(); i++){
				if(!chekk.at(i).empty())
					chekk.at(i).clear();
			}
			if(!M)
				if(!toFil)
					if(def || rC)
						this->pauz();
			//this->rO("EE::outP::D::");
			ln0 = 0, sWrd = 0, s0 = 0, s1 = 0, lng0, lng2 = 0;
			spWrd = "", sp0 = "", outpt = " +===> OUTPUT", lne = "-{", prc = "%  ", prcW;
			chk0, chk1;
			//Set sWrd as length of longest word in strPh 
			for(long i = 0; i < this->strPh->size(); i++){
				if(i > 0){
					if(to_string(this->intPh->at(i)).length() > to_string(this->intPh->at(i-1)).length()){
						sWrd = to_string(this->intPh->at(i)).length();
					}
				}
			}
			//Add presence of percentages from first document to list of prO
			for(long i = 0; i < this->intPh->size(); i++){
				if(this->intPh->at(i)/this->intPh->size() > 0)
					prcW = to_string(this->intPh->at(i)/this->intPh->size());
				else
					prcW = "<0";
				
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr0.push_back(prcW);
			}
			//Add presence of percentages from second document to list of pr1
			for(long i = 0; i < this->ipDoc->size(); i++){
				if(this->ipDoc->at(i)/this->ipDoc->size() > 0)
					prcW = to_string(this->ipDoc->at(i)/this->ipDoc->size());
				else
					prcW = "<0";
				while(prcW.length() < prc.length()){
					prcW += ' ';
				}
				pr1.push_back(prcW);
			}
			//Make length of each number to equal that of the size of the longest number, plus two spaces
			for(long i = 0; i < this->intPh->size(); i++){
				spWrd = to_string(this->intPh->at(i));
				while(spWrd.length() < sWrd + 3){
					spWrd += " ";
				}
				nLW.push_back(spWrd);
			}
			for(long i = 0; i < this->spDoc->size(); i++){
				if(i > 0){
					if(to_string(this->ipDoc->at(i)).length() > to_string(this->ipDoc->at(i-1)).length()){
						sWrd = to_string(this->ipDoc->at(i)).length();
					}
				}
			}
			for(long i = 0; i < this->ipDoc->size(); i++){
				if(i > 0){
					if(this->spDoc->at(i).length() > this->spDoc->at(i-1).length()){
						s0 = this->spDoc->at(i).length();
					}
				}
			}
			for(long i = 0; i < this->spDoc->size(); i++){
				sp0 = to_string(this->ipDoc->at(i));
				while(sp0.length() < sWrd + 3){
					sp0 += " ";
				}
				nL0.push_back(sp0);
			}
			if(s0 + 2 > this->file0.length() + 1) lng0 = s0+2; else lng0 = this->file0.length() + 1;
			this->file0 += " ";
			for(long i = 0; i < this->spD2->size(); i++){
				if(i > 0){
					if(this->spD2->at(i).length() > this->spD2->at(i-1).length()){
						s1 = this->spD2->at(i).length();
					}
				}
			}
			this->file1 += ' ';
			a = *this->spD2;
			for(int i = 0; i < a.size(); i++){
				if(i > 0){
					if(a.at(i).length() >= lng2){
						lng2 = a.at(i).length();
					}
				}
			}
			for(long i = 0; i < a.size(); i++){
				while(a.at(i).length() < lng2 + 3){
					a.at(i) += "-";
				}
			}
			while(outpt.length() < lng2 + 11){
				outpt += " ";
			}
			while(lne.length() < lng2 + lng0 + lng0 + sWrd){
				lne += "=";
			}
			lne += "}-";
			a0 = *this->ipD2;
			if(!w)
				std::cout << "\n---------\n" << std::endl;
			LENg = 0, i = 0;
			if(!w){
				std::cout << "\e[96m\e[4mBEGIN::(DoCo)\e[0m\e[96m" << std::endl;
			}
			//this->rO("FIN::B:");
			while (true) {
				if(i >= a.size()){
					break;
				}
				SET = a0.at(i);
				bool rCT = 0;
				rCT = 1;
				if(!w){
					std::cout << outpt << this->file0 << prc << this->file1 << prc << std::endl;
					std::cout << lne << std::endl;
				}
				while (SET == a0.at(i)) {
					if(w)
						W << a.at(i) <<" " << a0.at(i) << endl;
					if(!toFil)
						if(i % 30 == 0 && i > 0)
							this->pauz();
					for(int j = 0; j < this->strPh->size(); j++){
						if(this->strPh->at(j) == this->spD2->at(i)){
							chk0 = j;
							break;
						}
					}
					for(int j = 0; j < this->spDoc->size(); j++){
						if(this->spDoc->at(j) == this->spD2->at(i)){
							chk1 = j;
							break;
						}
					}
					if(!w)
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
					if(!w){
						std::cout << "\n\e[4mTerminal>\e[0m\e[91m\e[5m";
						std::cout << "\tNo phrases to return\e[0m\e[96m" << std::endl;
					} else {
						W << "NONE" << std::endl;
					}
				}
			}


			///
			if(!w){
				std::cout << "\n\e[4mEND::(DoCo)\e[0m" << std::endl;
			}

		}
		W.close();
		if(w){
			this->data();
		}
	}
}

/*
FUNCTIONS FOR outP
*/

//Search-N-Destroy
void stuffReturn::SeNDe(string file, bool rC){
	//cout << "\n\n\tSeNDe\n\n" << endl;
	bool c = false, def = false, dc = false;
	int prg;
	for(int i = 0; i < chr.size(); i++){
		switch(chr.at(i)){
			case 'A':
				def = true;
				break;
			case 'd':
				c = true;
				break;
			case 'O':
				dc = true;
				break;
		}
	}
	if(!tw && !th)
		prg = 20.0;
	if(tw)
		prg = 10.0;
	if(th)
		prg = 6.67;
	if(rC)
		def = false;
	//rO"FF::SeNDe::A::");
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
		nuMake(0, &a);
	if(rC && !c && !dc){
		redCheck(&a, 0);
	}
	if(dc)
		redCheck(&a, 1);
	if(c && !dc)
		nuMake(2, &a);
	a = *strSz;
	progressBar(prg);
	a0 = *intSz;
	progressBar(prg);
	if(rC){
		a = *strPh;
		if(dc){
			a = *spDoc;
		}
		if(!dc){
			nuMake(1, &a);
		}
		if(dc){
			nuMake(4, &a);
		}
		a0 = *intPh;
		if(dc){
			a0 = *ipDoc;
		}
	}
	if(def && !dc){
		a = *strSz;
		a0 = *intSz;
	}
	if(c && !dc){
		a = *strS2;
		a0 = *intS2;
	}
	long COUNT = 0;
	while (COUNT < a.size()) {
		progressBar(float(1.0/a.size()*prg));
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
	//rO"GG::SeNDe::B::");
	COUNT = 0;
	int w0 = 0, w1 = 0;
	while (a.size() - 1 > w0) {
		w1 = w0 + 1;
		while (w1 < a.size()) {
			if (a.at(w0) == a.at(w1) || a.at(w1) == "\\\\+==PERIOD==+//" || a0.at(w1) == 0) {
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
		*strS2 = a;
		*intS2 = a0;
	}
	if (def && !c){
		*strSz = a;
		*intSz = a0;
	}
	if (rC && !dc){
		for(int i = 0; i < chr.size(); i++){
			if(chr.at(i) == 'r'){
				chr.erase(chr.begin() + i);
				break;
			}
		}
		*strPh = a;
		*intPh = a0;
	}
	if(dc){
		*spDoc = a;
		*ipDoc = a0;
	}
	//std::cout << "\n\n\t\\SeNDe\n\n" << std::endl;
}

//Breaks down full string into vector of all words
vector<string> stuffReturn::wordReturn(string inpt) {
	//cout  << "\n\n\twordReturn\n\n" << endl;
	int prg;
	if(!tw && !th)
		prg = 5.0;
	if(tw)
		prg = 2.5;
	if(th)
		prg = 0.75;
	long sz = 0;
	string s = "";
	vector<string> sS;
	vector<char> BLACKLIST = {};
	for (int i = 0; i < 255; i++) {
		progressBar(1.0/255 * prg);
		if (i < 32 || i > 123) {
			BLACKLIST.push_back((char)i);
		}
	}
	//rO"II::wordReturn::A::");
	for (long i = 0; i < inpt.length(); i++) {
		bool CHK = false;
		progressBar(float(1.0/inpt.length())* (prg * 3));
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
			}
			else{
				s += inpt[i];
			}
		}
		if((char)inpt[i] == '.' && !isalpha((char)inpt[i+1])){
			sS.push_back("\\\\+==PERIOD==+//");
			prd = true;
		}
		if(s != "" && s != " ")
			if ((char)inpt[i] == '\\' || (char)inpt[i] == '/'||(char)inpt[i] == ':' && !isalpha((char)inpt[i])||(char)inpt[i] == ' ' && i != 0 && !isalpha((char)inpt[i]) && !s.empty()|| (char)inpt[i] == '\t') {
				if(sS.size() > 0 && sS.at(sS.size()-1) == "\\\\+==PERIOD==+//"){
					sS.pop_back();
					sS.push_back(s);
					sS.push_back("\\\\+==PERIOD==+//");
				} else {
					sS.push_back(s);
				}
				s = "";
				sz++;
			}
	}
	//rO"JJ::wordReturn::B::");
	//cout << "\n\n\t\\wordReturn\n\n" << endl;
	return sS;
}

//Counts instances of each word
void stuffReturn::nuMake(char t, vector<string> *s) {
	//cout << "\n\n\tnuMake\n\n" << endl;
	int prg;
	if(!tw && !th)
		prg = 20.0;
	if(tw)
		prg = 10.0;
	if(th)
		prg = 3.33;
	if(t == 0){
		strSz->push_back(s->at(0));
		intSz->push_back(0);
		long SZ = 0;
		for (long i = 0; i < s->size(); i++){
			progressBar(1.0/s->size()*prg);
			for (long j = 0; j < strSz->size(); j++) {
				if (intSz->size() < strSz->size())
					intSz->push_back(0);
				if (s->at(i) == strSz->at(j)) {
					intSz->at(j)++;
					SZ++;
					break;
				}
				if (s->at(i) != strSz->at(j) && j == strSz->size() - 1) {
					strSz->push_back(s->at(i));
				}
			}
		}
	}
	else if(t >= 1){
		vector<string> a, strV;
		vector<long> a0;
		switch(t){
			case 1:
				strV = *strPh;
				a = *strPh;
				break;
			default:
				strV = *s;
				a = *s;
				break;
		}
		a0.push_back(0);
		for (long i = 0; i < a.size(); i++){
			progressBar(1.0/a.size()*prg);
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
				*intPh = a0;
				break;
			case 2:
				*strS2 = a;
				*intS2 = a0;
				break;
			case 3:
				*intDoc = a0;
				break;
			case 4:
				*ipDoc = a0;
				break;
			case 5:
				*ipD2 = a0;
				break;
		}
		if(!a0.empty())
			a0.clear();
		if(!a.empty())
			a.clear();
	}
	//cout  << "\n\n\t\\nuMake\n\n" << endl;
}

//Clears Screen
void stuffReturn::clr(){
	#ifdef _WIN32
	system("CLS");
	#else
	std::system("clear");
	#endif
}

//Pauses screen for user
void stuffReturn::pauz(){
	char a[0];
	#ifdef _WIN32
	system("pause");
	#else
	std::cout << "PressEnter\\" << std::endl;
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

//Check for redundant phrases us.
void stuffReturn::redCheck(vector<string> *s, bool d){
	//cout  << "\n\n\tredCheck\n\n" << endl;
	vector<string> phrase;
	string nxt = "";
	long leng = 0, l = 0;
	for(int i = 0; i < s->size(); i++){
		if(prd){
			while(s->at(leng + i) != "\\\\+==PERIOD==+//"){
				phrase.push_back(s->at(leng + i));
				leng++;
				if(leng + i == s->size()){
					break;
				}
			}
		} else {
			while(leng < 10){
				phrase.push_back(s->at(leng + i));
				leng++;
				if(leng + i == s->size()){
					break;
				}
			}
		}
		leng = 0;
		for(int j = i; j < s->size(); j++){
			while(l < phrase.size()){
				if(l > 0){
					phrase.erase(phrase.begin());
					l--;
				}
				if(s->at(j) == phrase.at(l)){
					nxt += s->at(j) + " ";
					if(l == 0){
						if(nxt != "" && nxt != " " && GT1(nxt)){
							if(d)
								spDoc->push_back(nxt);
							else
								strPh->push_back(nxt);
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
				if(s->at(j) != phrase.at(l)){
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
	//cout  << "\n\n\t\\redCheck\n\n" << endl;
}

//Compare documents for similarities in vocabulary and word patterns
void stuffReturn::doCo(vector<char> *c){
	//cout  << "\n\n\tdoCo\n\n" << endl;
	string file;
	while(1){
		std::cout << "FK> Enter second file: ";
		cin >> file;
		if(file == "ls"){
			std::system("ls");
			file = "";
		}
		else if (GUD(file)){
			break;
		}
	}
	setF(file, 0);
	SeNDe(file, 0);
	for(int i = 0; i < strSz->size(); i++){
		for(int j = 0; j < strS2->size(); j++){
			if(strSz->at(i) == strS2->at(j)){
				strDoc->push_back(strSz->at(j));
				break;
			}
		}
	}
	nuMake(3, strDoc);
	chr.push_back('O');
	SeNDe(file, 1);
	chr.pop_back();
	for(int i = 0; i < strPh->size(); i++){
		for(int j = 0; j < spDoc->size(); j++){
			if(strPh->at(i) == spDoc->at(j)){
				spD2->push_back(strPh->at(i));
				break;
			}
		}
	}
	nuMake(5, spD2);
	//rO"DoCo::C");
	//cout  << "\n\n\t\\doCo\n\n" << endl;
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
			std::cout << fil << std::endl;
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

//Data to display on web-page
void stuffReturn::data(){
	ofstream f0;
	f0.open("graphicOut.js");
	string fil, inpt = "", Wfl = "start ", Lfl = "firefox ", bse,
	sSz = " ", iSz = " ",
	sPh = " ", iPh = " ",
	sS2 = " ", iS2 = " ",
	sDc = " ", iDc = " ",
	sD2 = " ", iD2 = " ",
	jsFil = "function mkBar(doc, xPos, yPos, w, h, id){\n\
    var c = doc.getElementById(id);\n\
    c.width = w;\n\
    c.height = h;\n\
    var ctx = c.getContext(\"2d\");\n\
    ctx.rect(xPos, yPos, w, h);\n\
	ctx.fillStyle = \"lightgrey\";\n\
    ctx.fill();\n\
    ctx.stroke();\n\
}\n\
\n\
function mkRct(doc, xPos, yPos, w, h, id, max, id0){\n\
    var c = doc.getElementById(id);\n\
    c.width = w;\n\
    c.height = h;\n\
    var ctx = c.getContext(\"2d\");\n\
    ctx.rect(xPos, yPos, w, h);\n\
    if(w/max <= 0.25){\n\
        ctx.fillStyle = \"green\";\n\
    }\n\
    if(w/max > 0.25 && w/max <= 0.50){\n\
        ctx.fillStyle = \"yellow\";\n\
    }\n\
    if(w/max > 0.50 && w/max <=0.75){\n\
        ctx.fillStyle = \"orange\";\n\
    }\n\
    if(w/max > 0.75){\n\
        ctx.fillStyle = \"red\";\n\
    }\n\
    ctx.fill();\n\
    ctx.stroke();\n\
    mkBar(doc, xPos, yPos, max, h, id0);\n\
}\n\
\n\
\n\
function outP(x) { \n\
    var ";
	vector<vector<string>> allS = {*strSz, *strPh, *strS2, *strDoc, *spD2};
	vector<vector<long>> allL = {*intSz, *intPh, *intS2, *intDoc, *ipD2};
	vector<string> stz = {sSz, sPh, sS2, sDc, sD2}, lnz = {iSz, iPh, iS2, iDc, iD2};
	string strFil = "";
	for(int i = 0; i < allS.size(); i++){
		for(int j = i; j < allS.at(i).size(); j++){
			if(i > 0 && allL.at(i).at(j) <= 1)
				continue;
			strFil = allS.at(i).at(j);
			stz.at(i) += "\"" + strFil + "\"";
			lnz.at(i) += to_string(allL.at(i).at(j));
			if(j < allS.at(i).size() - 1){
				stz.at(i) += ", ";
				lnz.at(i) += ", ";
			}
		}
	}
	for(int i = 0; i < stz.size(); i++){
		if(i > 0)
			jsFil += ", ";
		switch(i){
			case 0:
				jsFil += "sSz = [" + stz.at(i) + "], iSz = [" + lnz.at(i) + "] ";
				break;
			case 1:
				jsFil += "sPh = [" + stz.at(i) + "], iPh = [" + lnz.at(i) + "] ";
				break;
			case 2:
				jsFil += "sS2 = [" + stz.at(i) + "], iS2 = [" + lnz.at(i) + "] ";
				break;				
			case 3:
				jsFil += "sDc = [" + stz.at(i) + "], iDc = [" + lnz.at(i) + "] ";
				break;
			case 4:
				jsFil += "sD2 = [" + stz.at(i) + "], iD2 = [" + lnz.at(i) + "] ";
				break;
		}
	}
	f0 << jsFil + " ,\n\
    Slst = [sSz, sPh, sS2, sDc, sD2],\n\
    Ilst = [iSz, iPh, iS2, iDc, iD2],\n\
    sP = [], sP0 = [],\n\
    iP = [], iP0 = [],\n\
    lt0 = [],\n\
    lt1 = [],\n\
    lt2 = [],\n\
    lt = [lt0, lt1, lt2],\n\
    ul0 = [],\n\
    canv = [],\n\
    canv0 = [];\n\
\n\
    for(var i = 0; i < Slst.length; i++){\n\
        Slst[i].reverse();\n\
        Ilst[i].reverse();\n\
    }\n\
\n\
    for(var i = Slst.length - 1; i >= 0; i--){\n\
        for(var j = Slst[i].length - 1; j >= 0; j--){\n\
            canv[j + i * Slst.length] = \"\";\n\
            canv[j + i * Slst.length] = document.createElement(\"canvas\");\n\
            canv[j + i * Slst.length].id = \"canv\" + j + i;\n\
\n\
            canv0[j + i * Slst.length] = \"\";\n\
            canv0[j + i * Slst.length] = document.createElement(\"canvas\");\n\
            canv0[j + i * Slst.length].id = \"canv0\" + j + i;\n\
            \n\
            if(x){                \n\
                iP[j + i * Slst.length] = \"\";\n\
                iP0[j + i * Slst.length] = \"\";\n\
                sP[j + i * Slst.length] = \"\";\n\
                sP0[j + i * Slst.length] = \"\";\n\
                lt0[j + i * Slst.length] = \"\";\n\
                lt1[j + i * Slst.length] = \"\";\n\
\n\
                sP[j + i * Slst.length] = document.createElement(\"p\");\n\
                sP0[j + i * Slst.length] = document.createTextNode(Slst[i][j]);\n\
                sP[j + i * Slst.length].appendChild(sP0[j + i * Slst.length]);\n\
                lt0[j + i * Slst.length] = document.createElement(\"li\");\n\
                lt0[j + i * Slst.length].appendChild(sP[j + i * Slst.length]);\n\
\n\
                iP[j + i * Slst.length] = document.createElement(\"p\");\n\
                iP0[j + i * Slst.length] = document.createTextNode(Ilst[i][j]);\n\
                iP[j + i * Slst.length].appendChild(iP0[j + i * Slst.length]);\n\
                lt1[j + i * Slst.length] = document.createElement(\"li\");\n\
                lt1[j + i * Slst.length].appendChild(iP[j + i * Slst.length]);\n\
            }            \n\
            lt2[j + i * Slst.length] = document.createElement(\"li\");\n\
            lt2[j + i * Slst.length].appendChild(canv[j + i * Slst.length]);\n\
            lt2[j + i * Slst.length].appendChild(canv0[j + i * Slst.length]);\n\
        }\n\
    }\n\
\n\
    if(x){\n\
        for(var i = 0; i < lt.length; i++){\n\
            ul0[i] = \"\";\n\
            ul0[i] = document.createElement(\"ol\");\n\
            for(var j = 0; j < lt[i].length; j++){\n\
                ul0[i].appendChild(lt[i][j]);\n\
\n\
                if(i == 0){\n\
                    ul0[i].setAttribute(\"padding-top\", \"20px\");\n\
                    document.getElementById(\"hW\").appendChild(ul0[i]);\n\
                }\n\
                if(i == 1){\n\
                    ul0[i].setAttribute(\"padding-top\", \"20px\");\n\
                    document.getElementById(\"hW0\").appendChild(ul0[i]);\n\
                }\n\
                if(i == 2){\n\
                    ul0[i].setAttribute(\"style\", \"list-style:none; margin:0;\");\n\
                    document.getElementById(\"hW1\").appendChild(ul0[i]);\n\
                }   \n\
            }\n\
        }\n\
    }\n\
    \n\
    for(var i = 0; i < Slst.length; i++){\n\
        for(var j = 0; j < Slst[i].length; j++){\n\
            /* doc, xPos, yPos, w, h, id*/\n\
            mkRct(document, 0, 0, (Ilst[i][j]/Ilst[i][0]) * (window.innerWidth * 0.20), 10, canv[j + i * Slst.length].id, (window.innerWidth * 0.20), canv0[j + i * Slst.length].id);\n\
        }\n\
    }\n\
}";
	f0.close();
	Lfl += "index.html";
	#if WIN_32
		std::system(Wlf.c_str());
	#else
		std::system(Lfl.c_str());
	#endif
}

//Constructs all files not present
void stuffReturn::mkFil(){
	ofstream f;
	f.open("index.html");
	f << "<!DOCTYPE html>\n\
<html lang=\"en\">\n\
    <head>\n\
        <meta charset=\"UTF-8\">\n\
        <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/foundation-sites@6.5.3/dist/css/foundation-float.min.css\" integrity=\"sha256-sP0p6J7SbJGiJ2gkdY1nkVsLgdwiFN2kI370lU+zacQ= sha384-yZLxxcD8nfiSt1qfKJWwHwtkL58WZDTlkBnZN60qr3ZS35+LDsmUF2JHLxdyZ+KU sha512-Z3WbpfWFSsK2dBvoSYZnMvPmxSJUa5cxj3TYlmyj6cq8IXy7iB2nlUk+jjms8gnz4HmpQk/yhRSlRzW7keoSlg==\" crossorigin=\"anonymous\">\n\
        <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/foundation-sites@6.5.3/dist/css/foundation-prototype.min.css\" integrity=\"sha256-ksLmXa0k3ACbX6azB9g6l7XlmSKFBkuH0DXKNwULXtE= sha384-RGTvu65DAT+yLQsTj5tnITDrMfrS5mbajNAYILSg4hHr9vRr/3Y9q0WAdChqLKfx sha512-KMJ7XYrv5UcwEvJFaYnLSdN5O3fT7aQvjed//LQPB3AsN4VPA/wXG9j4x4vKZkjNmU/U8aZC9Ac3FYxs9lPXcw==\" crossorigin=\"anonymous\">\n\
        <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/foundation-sites@6.5.3/dist/css/foundation-rtl.min.css\" integrity=\"sha256-jvk46bzgetf2fy3FF19toDOoy9CG3aFqZfd229doSyo= sha384-w6E9ynA6OV6MFswc7C8nr8QoBiRtqqOKF/5M9ZVyVDDyrUPLI75xizNuXgRZxWK5 sha512-7MZk47L+5Mj6Y0dP3NuB2aqlNdDgzTlCf8m50nvgnCHUbxZ9KabCy8VUzQAl/DqDKwR7E6JsCf1MUjkfCiVzJw==\" crossorigin=\"anonymous\">\n\
        <link rel=\"stylesheet\" href=\"style.css\">\n\
		<link href=\"https://fonts.googleapis.com/css?family=Kumar+One+Outline&display=swap\" rel=\"stylesheet\">\n\
		<script thisc=\"https://requirejs.org/docs/release/2.3.6/minified/require.js\"></script>\n\
        <script type=\"text/javascript\" thisc=\"graphicOut.js\"></script>\n\
    </head>\n\
    <body onresize=\"outP(0)\">\n\
        <div class=\"row\">\n\
            <div class=\"columns large-3 large-pull-3 medium-4 medium-push-1\">\n\
                <img thisc=\"imgs/MagnifEyeLogo.png\">\n\
            </div>\n\
            <div class=\"columns large-9 large-pull-4 medium-8\">\n\
                <h1>MagnifEye</h1>\n\
            </div>\n\
        </div>\n\
        <div class=\"row\">\n\
            <div class=\"columns large-12 large-pull-3 medium-9 medium-push-1\">\n\
                    <h4>" + verz + "</h4>\n\
            </div>\n\
            <div class=\"columns large-12 large-pull-3 medium-10 medium-pull-1\">\n\
                <h5>By FlakeyKarma</h5>\n\
            </div>\n\
        </div>\n\
        <div class=\"row\">\n\
                <div class=\"columns large-6 large-pull-3 medium-4 medium-push-1\">\n\
                    <p><strong>Words discovered</strong></p>\n\
                </div>\n\
                <div class=\"columns large-4 large-pull-3 medium-4\">\n\
                    <p><strong>Number of instances</strong></p>\n\
                </div>\n\
                <div class=\"columns large-2 large-pull-2 medium-4 medium-pull-1\">\n\
                    <p><strong>Proportion Level</strong></p>\n\
                </div>\n\
            </div>\n\
        <div class=\"row\">\n\
            <div class=\"columns large-12\">\n\
                <ul id=\"barz\"></ul>\n\
            </div>\n\
        </div>\n\
        <div class=\"row\">\n\
            <div class=\"columns large-6 large-pull-2 medium-5 medium-push-2\" id=\"hW\"></div>\n\
            <div class=\"columns large-4 large-pull-2 medium-5\" id=\"hW0\"></div>\n\
            <div class=\"columns large-2 large-pull-3 medium-2 medium-pull-3\" id=\"hW1\"></div>\n\
        </div>\n\
        <div id=\"div1\"></div>\n\
        <script type=\"text/javascript\">\n\
            outP(1);\n\
        </script>\n\
    </body>\n\
</html>";
	f.close();
	f.open("style.css");
	f << "/*SOURCE OF ARROW*/\n\
/*https://www.w3schools.com/howto/howto_css_arrows.asp*/\n\
i {\n\
    border: solid black;\n\
    border-width: 0 3px 3px 0;\n\
    display: inline-block;\n\
    padding: 3px;\n\
  }\n\
  \n\
  .right {\n\
    transform: rotate(-45deg);\n\
    -webkit-transform: rotate(-45deg);\n\
  }\n\
  \n\
  .left {\n\
    transform: rotate(135deg);\n\
    -webkit-transform: rotate(135deg);\n\
  }\n\
  \n\
  .up {\n\
    transform: rotate(-135deg);\n\
    -webkit-transform: rotate(-135deg);\n\
  }\n\
  \n\
  .down {\n\
    transform: rotate(45deg);\n\
    -webkit-transform: rotate(45deg);\n\
  }\n\
li {\n\
    font-size: 20px;\n\
}\n\
div#hW1 li {\n\
    font-size: 10px;\n\
}\n\
h4, h1 {\n\
    color: limegreen;\n\
}\n\
h1 {\n\
    padding-top: 1em;\n\
	font-family: 'Kumar One Outline', cursive;\n\
}\n\
h5 {\n\
    color: red;\n\
}\n\
p {\n\
    margin: 0;\n\
    padding: 0;\n\
    color: limegreen;\n\
    font-family: 'Courier New', Courier, monospace;\n\
}\n\
body {\n\
    background: #333;\n\
}\n\
img {\n\
    width: 50%;\n\
    height: 50%;\n\
}\n\
li {\n\
  color: red;\n\
}";
	f.close();
}

//Returns file requested to have read
string stuffReturn::filIn(){
	string fil;
	while(1){
		std::cout << "FK> Enter directory to file: ";
		std::cin >> fil;
		cout << fil << endl;
		if(fil == "ls"){
			system("ls");
		}else{
			return fil;
		}
	}
}

//Returns chars required to run full weBI
vector<char> stuffReturn::weBI(){
	char ch, inpt;
	vector<char> opti;
	bool rg = 0, rC = 0, dC = 0, brk = 0, x = 0;
	string rgS = "[ ", rCS = "[ ", dCS = "[ ";
	vector<string> stAr = {rgS, rCS, dCS};
	vector<bool> boAr = {rg, rC, dC};
	while(1){
		clr();
		for(int i = 0; i < stAr.size(); i++){
			stAr.at(i) += to_string(boAr.at(i)) + " ]";
		}
		std::cout << "Select the options to be displayed:" << std::endl;
		std::cout << "[0] Regular Output               ";
		TFswitch(boAr.at(0));
		std::cout << std::endl;
		std::cout << "[1] Redundancy Check ";
		std::cout << "\e[91m(RedCheck)\e[0m  ";
		TFswitch(boAr.at(1));
		std::cout << std::endl;
		std::cout << "[2] Document Comparison ";
		std::cout << "\e[96m(DoCo)\e[0m   ";
		TFswitch(boAr.at(2));
		std::cout << std::endl;
		std::cout << "[D] Done" << std::endl;
		std::cout << "[R] Reset selections" << std::endl;
		std::cout << "[C] Cancel" << std::endl;
		std::cout << "FK> ";
		std::cin >> ch;
		for(int i = 0; i < stAr.size(); i++){
			stAr.at(i) = "[ ";
		}
		switch(ch){
			case 'd':
			case 'D':
				brk = 1;
				break;
			case '0':
				if(boAr.at(0)){
					boAr.at(0) = 0;
				} else {
					boAr.at(0) = 1;
				}
				opti.push_back('A');
				break;
			case '1':
				if(boAr.at(1)){
					boAr.at(1) = 0;
				} else {
					boAr.at(1) = 1;
				}
				opti.push_back('r');
				break;
			case '2':
				if(boAr.at(2)){
					boAr.at(2) = 0;
				} else {
					boAr.at(2) = 1;
				}
				opti.push_back('d');
				break;
			case 'r':
			case 'R':
				for(int i = 0; i < opti.size(); i++){
					opti.erase(opti.begin());
				}
				for(int i = 0; i < boAr.size(); i++)
					boAr.at(i) = 0;
				break;
			case 'c':
			case 'C':
				std::cout << "Are you sure?" << std::endl;
				std::cin >> inpt;
				switch(inpt){
					case 'y':
					case 'Y':
						x = 1;
						break;
					case 'n':
					case 'N':
						break;
					default:
						std::cout << "Please choose either:\n\'Y\' for yes\nor\n\'N\' for no" << std::endl;
				}
				break;
			default:
				std::cout << "Enter a valid choice" << std::endl;
				pauz();
		}
		if(x)
			break;
		ch = 0;
		if(brk){
			opti.push_back('w');
			return opti;
		}
	}
	if(x)
		std::cout << "Returning..." << std::endl;
}

//Switch to display true or false
void stuffReturn::TFswitch(bool t){
	const char oArr[4] = "\xE2\x96\x91", iArr[4] = "\xE2\x96\x93", btn[4] = "\xE2\x96\x88";
	string fll = "";
	if(t){
		fll += iArr;
		fll += iArr;
		fll += btn;
		std::printf("%s", fll.c_str());
	}else{
		fll += btn;
		fll += oArr;
		fll += oArr;
		std::printf("%s", fll.c_str());
	}
	
}

//Output help for each function
void stuffReturn::help(){
	std::cout << "Help [-h, --help]\n\
	\t\tDisplay" << std::endl;
	std::cout << "Command Line Interface(CLI) [-c, --cli]\n\
	\t\tDisplay" << std::endl;
	std::cout << "Redundancy Check\e[91m(RedCheck)\e[0m\n\
	\t\tDisplay" << std::endl;
	std::cout << "Document Comparison\e[96m(DoCo)\e[0m\n\
	\t\tDisplay" << std::endl;
	std::cout << "Web-Based-Interface \e[93m(WeBI)\e[0m\n\
	\t\tDisplay" << std::endl;
}

//Dev debug variable tool
void stuffReturn::rO(string s){
	int J = 0;
	std::cout << "--LISTS--" << endl;
	std::cout << s;
	std::cout << "::::::::::::::>Doc 1 words<< ";
	std::cout << strSz->size();
	std::cout << " " << intSz->size() << endl;
	for(int i = 0; i < strSz->size(); i++){
		J++;
		if(J % 30 == 0)
			pauz();
		if(intSz->at(i) != 0)
			std::cout << strSz->at(i) << " :: " << intSz->at(i) << endl;
		else
			J--;
		
	}
	std::cout << s;
	std::cout << "::::::::::::::>\\Doc 1 words<< ";
	std::cout << strSz->size();
	std::cout << " " << intSz->size() << endl;
	pauz();
	std::cout << s;
	std::cout << "::::::::::::::>Doc 1 red<< ";
	std::cout << strPh->size();
	std::cout << " " << intPh->size() << endl;
	for(int i = 0; i < strPh->size(); i++){
		J++;
		if(J % 30 == 0)
			pauz();
		if(intPh->at(i) != 0)
			std::cout << strPh->at(i) << " :: " << intPh->at(i) << endl;
		else
			J--;
		
	}
	std::cout << s;
	std::cout << "::::::::::::::>\\Doc 1 red<< ";
	std::cout << strPh->size();
	std::cout << " " << intPh->size() << endl;
	pauz();
	std::cout << s;
	std::cout << "::::::::::::::>Doc 2 words<< ";
	std::cout << strS2->size();
	std::cout << " " << intS2->size() << endl;
	for(int i = 0; i < strS2->size(); i++){
		J++;
		if(J % 30 == 0)
			pauz();
		if(intS2->at(i) != 0)
			std::cout << strS2->at(i) << " :: " << intS2->at(i) << endl;
		else
			J--;
		
	}
	std::cout << s;
	std::cout << "::::::::::::::>\\Doc 2 words<< ";
	std::cout << strS2->size();
	std::cout << " " << intS2->size() << endl;
	pauz();
	std::cout << s;
	std::cout << "::::::::::::::>doCo:Words<< ";
	std::cout << strDoc->size();
	std::cout << " " << intDoc->size() << endl;
	for(int i = 0; i < strDoc->size(); i++){
		J++;
		if(J % 30 == 0)
			pauz();	
		if(intDoc->at(i) != 0)
			std::cout << strDoc->at(i) << " :: " << intDoc->at(i) << endl;
		else
			J--;
		
	}
	std::cout << s;
	std::cout << "::::::::::::::>\\doCo:Words<< ";
	std::cout << strDoc->size();
	std::cout << " " << intDoc->size() << endl;
	pauz();
	std::cout << s;
	std::cout << "::::::::::::::>Doc 2 red<< ";
	std::cout << spDoc->size();
	std::cout << " " << ipDoc->size() << endl;
	for(int i = 0; i < spDoc->size(); i++){
		J++;
		if(J % 30 == 0)
			pauz();
		if(ipDoc->at(i) != 0)
			std::cout << spDoc->at(i) << " :: " << ipDoc->at(i) << endl;
		else
			J--;
		
	}
	std::cout << s;
	std::cout << "::::::::::::::>\\Doc 2 red<< ";
	std::cout << spDoc->size();
	std::cout << " " << ipDoc->size() << endl;
	pauz();
	std::cout << s;
	std::cout << "::::::::::::::>doCo:Red<< ";
	std::cout << spD2->size();
	std::cout << " " << ipD2->size() << endl;
	for(int i = 0; i < spD2->size(); i++){
		J++;
		if(J % 30 == 0)
			pauz();
		if(ipD2->at(i) != 0)
			std::cout << spD2->at(i) << " :: " << ipD2->at(i) << endl;
		else
			J--;
		
	}
	std::cout << s;
	std::cout << "::::::::::::::>\\doCo:Red<< ";
	std::cout << spD2->size();
	std::cout << " " << ipD2->size() << endl;
	pauz();
}