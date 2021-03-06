#include "resources.h"
/*
  MAIN FUNCTIONS
*/

//Whole MagnifEye program through this main function
void Complementary::MagnifEye(std::string file){
  std::ifstream fil;
  bool pass = 0;

  this->setPath((char *)"/");

  if(!this->custom_path) this->mkPath();

	if(GUD(file)){
    fil.close();
    this->setF(file, 0);

    if(this->opChc[2]){
      this->DoCo();
    }
    if(!pass && this->opChc[1]){
      pass = 1;
      this->tempSort = this->RedCheck(0);
      *this->strRedCheck = this->tempSort[0].str;
      *this->intRedCheck = this->tempSort[0].lng;
    }
    if(!pass && this->opChc[0]){
      pass = 1;
      this->tempSort = this->ThNeedle(0);
      *this->strThNeedle = this->tempSort[0].str;
      *this->intThNeedle = this->tempSort[0].lng;
    }
    if(this->opChc[3]){
      this->WeBI();
    }
    this->outP();
  }
  fil.close();
}

//ThNeedle  function

std::vector<Complementary::set0> Complementary::ThNeedle(bool b){
  std::ifstream fil;
  std::string inptTemp;
	fil.open((b ? this->file1 : this->file0));


  this->inptMain = "";
	while (!fil.eof()) {
		getline(fil, inptTemp);
		this->inptMain += inptTemp + " \n";
	}
  fil.close();
  return this->SeNDe(this->nuMake(0, wordReturn(this->inptMain)));
}

//RedCheck  function

std::vector<Complementary::set0> Complementary::RedCheck(bool d){
  //std::printf("\n\n\tredCheck\n\n");
  std::vector<Complementary::set0> sort = this->ThNeedle(d);
  (d ? *this->strComparison0 : *this->strThNeedle) = sort[0].str;
  (d ? *this->intComparison0 : *this->intThNeedle) = sort[0].lng;
	std::vector<std::string> phrase, phraseFull, *s = new std::vector<std::string>(0);
  *s = this->wordReturn(this->inptMain);
	std::string nxt = "";
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
              phraseFull.push_back(nxt);
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
  //std::printf("\n\n\t/redCheck\n\n");
  return this->SeNDe(this->nuMake(1, phraseFull));
}

//DoCo      function
void Complementary::DoCo(){
  //std::printf("\n\n\tDoCo\n\n");
	char *file = new(std::nothrow) char[15];
  //Set NewMetric and ReSize
	long NM = 0, RS;

	while(1){
		std::printf("MEye> Enter second file: ");
		std::scanf("%s\n", file);
		if(file == "ls"){
			std::system("ls");
			file = (char*)"";
		}
		else if (GUD(file)){
			break;
		}
	}

  this->tempSort = this->RedCheck(0);
  *this->strDoc0 = this->tempSort[0].str;
  *this->intDoc0 = this->tempSort[0].lng;


  this->setF(file, 1);

  this->tempSort = this->RedCheck(1);
  *this->strDoc1 = this->tempSort[0].str;
  *this->intDoc1 = this->tempSort[0].lng;

  //Compare strings between both
	for(int i = 0; i < strThNeedle->size(); i++){
		for(int j = 0; j < strComparison0->size(); j++){
      //Dynamically resize strComparison1
      if(this->strComparison1->size() == NM) this->strComparison1->resize(NM+1);
			if(this->strThNeedle->at(i) == this->strComparison0->at(j)){
				this->strComparison1->at(NM) = this->strThNeedle->at(j);
				if(this->strComparison1->at(NM) != "")
					RS = NM;
				NM++;
				break;
			}
		}
	}

	//Adjust size of strComparison1 based on RS
	this->strComparison1->resize(RS + 1);
	this->strComparison1->shrink_to_fit();

	//Get numbers for strComparison1
	this->tempSort = this->SeNDe(this->nuMake(3, *this->strComparison1));
  *this->strComparison1 = this->tempSort[0].str;
  *this->intComparison1 = this->tempSort[0].lng;

  //Reset NewMetric
  NM = 0;

  //Compare phrases between both
	for(int i = 0; i < this->strRedCheck->size(); i++){
		for(int j = 0; j < this->strDoc0->size(); j++){
      //Dynamically resize strDoc1
      if(this->strDoc1->size() == NM) this->strDoc1->resize(NM+1);
			if(this->strRedCheck->at(i) == this->strDoc0->at(j)){
				this->strDoc1->at(NM) = this->strRedCheck->at(j);
				if(this->strDoc1->at(NM) != "")
					RS = NM;
				NM++;
				break;
			}
		}
	}

	//Resize strDoc1 based on RS
	this->strDoc1->resize(RS + 1);
	this->strDoc1->shrink_to_fit();
	//Get numbers on strDoc1
	this->tempSort = this->SeNDe(this->nuMake(5, *this->strDoc1));
  *this->strDoc1 = this->tempSort[0].str;
  *this->intDoc1 = this->tempSort[0].lng;
  //std::printf("\n\n\t/DoCo\n\n");
}

//WeBI      function

void Complementary::WeBI(){
  //std::printf("\n\n\tweBI\n\n");
	char ch, inpt;
	bool rg = 0, rC = 0, dC = 0, brk = 0, x = 0;
	std::string rgS = "[ ", rCS = "[ ", dCS = "[ ";
	std::vector<std::string> stAr = {rgS, rCS, dCS};
	std::vector<bool> boAr = {rg, rC, dC};
  this->mkFil();
	while(1){
		clr();
		for(int i = 0; i < stAr.size(); i++){
			stAr.at(i) += std::to_string(boAr.at(i)) + " ]";
		}
		std::printf("Select the options to be displayed:\n");
		std::printf("[0] Regular Output               ");
		TFswitch(boAr.at(0));
		std::printf("[1] Redundancy Check ");
		std::printf("\e[91m(RedCheck)\e[0m  ");
		TFswitch(boAr.at(1));
		std::printf("[2] Document Comparison ");
		std::printf("\e[96m(DoCo)\e[0m   ");
		TFswitch(boAr.at(2));
		std::printf("[D] Done\n");
		std::printf("[R] Reset selections\n");
		std::printf("[C] Cancel\n");
		std::printf("MEye> ");
		std::scanf("%c", &ch);
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
				opChc[0] = 1;
				break;
			case '1':
				if(boAr.at(1)){
					boAr.at(1) = 0;
				} else {
					boAr.at(1) = 1;
				}
				opChc[1] = 1;
				break;
			case '2':
				if(boAr.at(2)){
					boAr.at(2) = 0;
				} else {
					boAr.at(2) = 1;
				}
				opChc[2] = 1;
				break;
			case 'r':
			case 'R':
				for(int i = 0; i < 5; i++){
					opChc[i] = 0;
				}
				for(int i = 0; i < boAr.size(); i++)
					boAr.at(i) = 0;
				break;
			case 'c':
			case 'C':
				std::printf("Are you sure?\n");
        std::scanf(" %c", &inpt);
				switch(inpt){
					case 'y':
					case 'Y':
						x = 1;
						break;
					case 'n':
					case 'N':
						break;
					default:
						std::printf("Please choose either:\n\'Y\' for yes\nor\n\'N\' for no\n");
				}
				break;
			default:
				std::printf("Enter a valid choice\n");
		}
		if(x)
			break;
		ch = 0;
		if(brk){
			opChc[3] = 1;
		}
	}
	if(x)
		std::printf("Returning...\n");
    //std::printf("\n\n\t/weBI\n\n");
}

/*
  HELPER FUNCTIONS
*/

//Set file name variables
void Complementary::setF(std::string s, bool b){
  //std::printf("\n\n\tsetF\n\n");
    for(int i = 0; i < s.length(); i++){
      (!b ? this->file0 += s[i] : this->file1 += s[i]);
    }
  //std::printf("\n\n\t/setF\n\n");
}

//Set new path
void Complementary::setPath(char *ary){
  char *NAME = (char *)malloc(16);
  getlogin_r(NAME, 16);
  if(this->custom_path){
      strcpy(this->etc_path, (char *)"./");
  } else {
    std::sprintf(this->etc_path, _HDN_PATH_, NAME);
    for(char i = 0; i < strlen(ary); i++) this->etc_path[strlen(this->etc_path)] = ary[i];
  }
}

//Get new path
char *Complementary::getPath(char *ary){
  char *temp_file = (char *)malloc(strlen(this->etc_path) + strlen(ary));
  strcpy(temp_file, this->etc_path);
  strcat(temp_file, ary);
  temp_file[strlen(temp_file)] = '\0';
  return temp_file;
}

//Create new hidden dir
void Complementary::mkPath(){
  char *root_path_cmd = (char *)malloc(255),\
        *magz_path_cmd = (char *)malloc(255),\
        *temp_path = (char *)malloc(_HDN_LENG_ + _HDN_LENG_EXT_);
  //First, check if the first-layer directory exists in user's home directory
  this->setPath((char *)"/");
  std::system("echo '#!/bin/bash' > mkPath.sh");
  std::system("chmod a+x mkPath.sh");
  std::sprintf(root_path_cmd, "echo 'mkdir \"%s.HIDDEN/\" 2>/dev/null' >> mkPath.sh", this->etc_path);
  if(!this->checkPath(root_path_cmd)) std::system(root_path_cmd);
  //Next, check if data-dir exists for user
  std::sprintf(temp_path, "echo 'mkdir \"%s.HIDDEN/%s\" 2>/dev/null' >> mkPath.sh", this->etc_path, _DIR_NAME_);
  std::sprintf(magz_path_cmd, "%s\0", temp_path);
  if(!this->checkPath(magz_path_cmd)) std::system(magz_path_cmd);
  //Execute script
  //std::system("echo 'Running script...'");
  std::system("./mkPath.sh");
  std::system("rm mkPath.sh");
  //std::system("echo 'Done running script...'");
  //Finally, just set base dir to the combination of both the root dir for hidden data and for MagnifEye configz
  std::sprintf(this->etc_path, "%s.HIDDEN/%s/", this->etc_path, _DIR_NAME_);
}

//Props to Ingo Leonhardt on Stack Overflow (https://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c)
bool Complementary::checkPath(char *path){
  struct stat dir_info;
  //No access (or no present dir)
  if(stat(path, &dir_info)) return 0;
  //Present dir
  //else if(dir_info.st_mode & S_IFDIR) return 1;
  return 1;
  //No present dir
  //else return 0;
}

//Counts instances of each word
std::vector<Complementary::set0> Complementary::nuMake(bool t, std::vector<std::string> s){
  //std::printf("\n\n\tnuMake\n\n");
  std::vector<Complementary::set0> retSet;
  std::vector<std::string> a, strV;
  std::vector<long> a0;
  if(!tw && !th)
		prg = 20.0;
	if(tw)
		prg = 10.0;
	if(th)
		prg = 3.33;
  if(!t){
		a.push_back(s.at(0));
		a0.push_back(0);
		long SZ = 0;
		for (long i = 0; i < s.size(); i++){
			progressBar(1.0/s.size()*prg);
			for (long j = 0; j < a.size(); j++) {
				if (a0.size() < a.size())
					a0.push_back(0);
				switch(this->rawRead){
          //If the text being read must be verified by case and match
          case 1:
            if (s.at(i) == a.at(j)) {
              a0.at(j)++;
              SZ++;
            }
            if (s.at(i) != a.at(j) && j == a.size() - 1) {
              a.push_back(s.at(i));
            }
            break;
          //If the text is just verified by match
          case 0:
            if (this->lower(s.at(i)) == this->lower(a.at(j))) {
              a0.at(j)++;
              SZ++;
            }
            if (this->lower(s.at(i)) != this->lower(a.at(j)) && j == a.size() - 1) {
              a.push_back(s.at(i));
            }
            break;
        }
			}
		}
	} else {

    strV = s;
    a = s;

		a0.push_back(0);
		for (long i = 0; i < a.size(); i++){
			progressBar(1.0/a.size()*prg);
			for (long j = 0; j < a.size(); j++) {
				if (a0.size() < a.size()){
					a0.push_back(0);
				}
				if (a.at(i) == a.at(j)) {
					a0.at(j)++;
				}
			}
		}
  }
  retSet.push_back({a, a0});
  //std::printf("\n\n\t/nuMake\n\n");
  return retSet;
}

//Breaks down full std::string into std::vector of all words
std::vector<std::string> Complementary::wordReturn(std::string inpt){
  //std::printf("\n\n\twordReturn\n\n");
  //Set progress bar percentage
	if(!tw && !th)
		prg = 5.0;
	if(tw)
		prg = 2.5;
	if(th)
		prg = 0.75;
	std::string s = "";
	std::vector<std::string> sS;
  bool excluded = 0, included = 0;
  //Check if char is safe to use
  for(long i = 0; i < inpt.length(); i++){
    progressBar(float(1.0/inpt.length())*(prg*3));
    //Construction of the word itself
    if(!this->removal_set && !this->delimeter_set){
      this->removal[0] = '.';
      if ((char)inpt[i] != ' ' && isalpha(inpt[i]) || (char)inpt[i] == '-' || (char)inpt[i] == '.' && isalpha((char)inpt[i+1]) || (char)inpt[i] == '\'' || (int)inpt[i] >= 48 && (int)inpt[i] <= 57) {
        s += inpt[i];
      }
    }
    if(this->delimeter_set){
      for(char j = 0; j < strlen(this->delimeterz); j++){
        if((char)inpt[i] == this->delimeterz[j]){
          break;
        }
        if(j == strlen(this->delimeterz)-1){

          s += inpt[i];
        }
      }
    }
    if(this->removal_set){
      for(char j = 0; j < strlen(this->removal); j++){
        if((char)inpt[i] == this->removal[j]){
          if(this->delimeter_set) s.erase(s.begin() + (s.length()-1));
          break;
        }
        if(j == strlen(this->removal)-1 && !this->delimeter_set){
            s += inpt[i];
        }
      }
    }

    for(char j = 0; j < strlen(this->removal); j++)
      if((char)inpt[i] == this->removal[j] && !isalpha((char)inpt[i+1])){
        sS.push_back("\\\\+==PERIOD==+//");
        prd = true;
      }
  	if(s != "" && s != " "){
      if(this->delimeter_set){
        for(char j = 0; j < strlen(this->delimeterz); j++){
          if(inpt[i] == this->delimeterz[j] || !isalpha((char)inpt[i+1])){
            if(sS.size() > 0 && sS.at(sS.size()-1) == "\\\\+==PERIOD==+//"){
              sS.pop_back();
            }
            sS.push_back(s);
            s = "";
            break;
          }
        }
      }else{
        //Where the fully constructed word is appended to vector
        if ((char)inpt[i] == '\\' || (char)inpt[i] == '/'||(char)inpt[i] == ':' && !isalpha((char)inpt[i])||(char)inpt[i] == ' ' && i != 0 && !isalpha((char)inpt[i]) && !inpt.empty()|| (char)inpt[i] == '\t') {
          if(!this->include_set && !this->exclude_set && sS.size() > 0 && sS.at(sS.size()-1) == "\\\\+==PERIOD==+//"){
            sS.pop_back();
            sS.push_back(s);
            sS.push_back("\\\\+==PERIOD==+//");
          }
          else if(this->exclude_set){
            for(unsigned char j = 0; j < this->exclusionz->size(); j++){
              if(!strcmp((this->rawRead?this->lower(s):s).c_str(), this->exclusionz->at(j))){
                s = "";
                excluded = 1;
                break;
              }
            }
            if(excluded){
              excluded = 0;
              continue;
            }
          }
          else if(this->include_set){
            for(char inc = 0; inc < this->inclusionz->size(); inc++){
              if(!strcmp((this->rawRead?this->lower(this->inclusionz->at(inc)).c_str():this->inclusionz->at(inc)), (this->rawRead?this->lower(s):s).c_str())){
                sS.push_back((this->rawRead?this->lower(s):s));
                s = "";
                included = 1;
                break;
              }
            }
            if(included){
              included = 0;
              continue;
            }
          } else {
            sS.push_back(s);
          }
          s = "";
        }
      }
    }
  }
  //std::printf("\n\n\t/wordReturn\n\n");
  return sS;
}

//Information output
void Complementary::outP(){
  std::ofstream W;
  if(this->opChc[4])(this->CLI ? W.open(this->getPath((char *)"temp.txt"), std::ios_base::app) : W.open(this->getPath((char *)"temp.txt"), std::ios_base::app));
  //this->opChc[4] = this->CLI;
  std::string temp = "";
  this->tw = this->opChc[1];
  this->th = this->opChc[2];
  std::vector<std::string> a = *this->strThNeedle;
  std::vector<long> a0 = *this->intThNeedle;

  long SET, numS;
  long LENg = 0, i = 0;
  std::string SP = " |--->  ";
  //this->rO("CC::outP::C::");
  if(this->opChc[0]){
    if(this->opChc[4]){
      for(int i = 0; i < this->strThNeedle->size(); i++){
        W << "ThNeedle=" << this->lower(this->strThNeedle->at(i)) << ">" << this->intThNeedle->at(i) << "\n";
      }
    }
    while (true) {
      SET = a0.at(i);

      //if(a.at(i) != ""){
        if(!this->opChc[4])
        std::printf("OUTPUT =| %ld | :\n", a0.at(i));
        while (SET == a0.at(i)) {
          if(a0.at(i) <= this->metricz[0] && !this->opChc[4]){
            std::printf("\e[92m%s%s\n \e[0m\n", SP.c_str(), a.at(i).c_str());
          }
          if(a0.at(i) > this->metricz[0] && a0.at(i) <= 10 && !this->opChc[4]){
            std::printf("\e[93m%s%s\n \e[0m\n", SP.c_str(), a.at(i).c_str());
          }
          if(a0.at(i) > this->metricz[1] && !this->opChc[4]){
            std::printf("\e[31m%s%s\n \e[0m\n", SP.c_str(), a.at(i).c_str());
          }
          i++;
          if (a0.size() <= i)
          break;
        }
      //}
      LENg++;
      if (LENg == a.size() || i >= a0.size())
        break;
    }
  }
  //std::printf("E\n");
  if(this->opChc[1]){
    bool rCT = 0;
    if(this->opChc[4]){
      for(int i = 0; i < this->strRedCheck->size(); i++){
        if(this->intRedCheck->at(i) > 1)
          W << "RedCheck=" << this->lower(this->strRedCheck->at(i)) << ">" << this->intRedCheck->at(i) << std::endl;
      }
    }
    a = *this->strRedCheck;
    a0 = *this->intRedCheck;
    if(!this->opChc[4])
      std::printf("\n---------\n\n");
    LENg = 0, i = 0;
    if(!this->opChc[4]){
      std::printf("\e[91m\e[4mBEGIN::(RedCheck)\e[0m\e[91m\n");
    }
    while (true) {
      if(i >= a.size()){
        break;
      }
      SET = a0.at(i);
      if(a0.at(i) > 1){
        rCT = 1;
        if(!this->opChc[4]){
          std::printf("OUTPUT =| \e[97m");
          std::printf("%ld", a0.at(i) - 1);
          std::printf("\e[91m | :\n");
        }
        while (SET == a0.at(i)) {
          if(!this->opChc[4])
            std::printf("%s%s\n \n", SP.c_str(), a.at(i).c_str());
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
        if(!this->opChc[4]){
          std::printf("\n\e[4mTerminal>\e[0m\e[91m\e[5m");
          std::printf("\tNo phrases to return\e[0m\e[91m\n");
        } else {
          W << "NONE\n\n";
        }
      }
    }
    if(!this->opChc[4]){
      std::printf("\n\e[4mEND::(RedCheck)\e[0m\n");
    }
  }
  //std::printf("E\n");
  if(this->opChc[2]){
    std::vector<std::string> nLW, nL0, pr0, pr1;
    if(this->opChc[4]){
      W << "FILE1=" << this->lower(this->file0) << std::endl;
      W << "FILE2=" << this->lower(this->file1) << std::endl;
      for(int i = 0; i < this->strComparison0->size(); i++){
        W << "Comparison0=" << this->lower(this->strComparison0->at(i)) << ">" << this->intComparison0->at(i) << std::endl;
      }
      for(int i = 0; i < this->strComparison1->size(); i++){
        W << "Comparison1=" << this->lower(this->strComparison1->at(i)) << ">" << this->intComparison1->at(i) << std::endl;
      }
      for(int i = 0; i < this->strDoc0->size(); i++){
        W << "Doc0=" << this->lower(this->strDoc0->at(i)) << ">" << this->intDoc0->at(i) << std::endl;
      }
      for(int i = 0; i < this->strDoc1->size(); i++){
        W << "Doc1=" << this->lower(this->strDoc1->at(i)) << ">" << this->intDoc1->at(i) << std::endl;
      }
    }
    //this->rO("EE::outP::D::");
    int ln0 = 0, sWrd = 0, s0 = 0, s1 = 0, lng0, lng1, lng2 = 0;
    std::string spWrd = "", sp0 = "", outpt = " +===> OUTPUT", lne = "-{", prc = "%  ", prcW;
    long chk0, chk1;
    //Set sWrd as length of longest word in strThNeedle
    for(long i = 0; i < this->strThNeedle->size(); i++){
      if(i > 0){
        if(std::to_string(this->intThNeedle->at(i)).length() > std::to_string(this->intThNeedle->at(i-1)).length()){
          sWrd = this->strThNeedle->at(i).length();
        }
      }
    }
    //Add presence of percentages from first document to list of prO
    for(long i = 0; i < this->intThNeedle->size(); i++){
      if(this->intThNeedle->at(i)/this->intThNeedle->size() > 0)
        prcW = std::to_string(this->intThNeedle->at(i)/this->intThNeedle->size());
      else
        prcW = "<0";

      while(prcW.length() < prc.length()){
        prcW += ' ';
      }
      pr0.push_back(prcW);
    }
    //Add presence of percentages from second document to list of pr1
    for(long i = 0; i < this->intComparison0->size(); i++){
      if(this->intComparison0->at(i)/this->intComparison0->size() > 0)
        prcW = std::to_string(this->intComparison0->at(i)/this->intComparison0->size());
      else
        prcW = "<0";
      while(prcW.length() < prc.length()){
        prcW += ' ';
      }
      pr1.push_back(prcW);
    }
    //Make length of each number to equal that of the size of the longest number, plus two spaces
    for(long i = 0; i < this->intThNeedle->size(); i++){
      spWrd = std::to_string(this->intThNeedle->at(i));
      while(spWrd.length() < sWrd + 2){
        spWrd += " ";
      }
      nLW.push_back(spWrd);
    }
    for(long i = 0; i < this->strComparison0->size(); i++){
      if(i > 0){
        if(std::to_string(this->intComparison0->at(i)).length() > std::to_string(this->intComparison0->at(i-1)).length()){
          sWrd = this->strComparison0->at(i).length();
        }
      }
    }
    for(long i = 0; i < this->intComparison0->size(); i++){
      if(i > 0){
        if(this->strComparison0->at(i).length() > this->strComparison0->at(i-1).length()){
          s0 = this->strComparison0->at(i).length();
        }
      }
    }
    for(long i = 0; i < this->strComparison0->size(); i++){
      sp0 = std::to_string(this->intComparison0->at(i));
      while(sp0.length() < sWrd + 3){
        sp0 += " ";
      }
      nL0.push_back(sp0);
    }
    if(s0 + 2 > this->file0.length() + 1) lng0 = s0+2; else lng0 = this->file0.length() + 1;
    this->file0 += " ";
    for(long i = 0; i < this->strComparison1->size(); i++){
      if(i > 0){
        if(this->strComparison1->at(i).length() > this->strComparison1->at(i-1).length()){
          s1 = this->strComparison1->at(i).length();
        }
      }
    }
    this->file1 += ' ';
    a = *this->strComparison1;
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
    a0 = *this->intComparison1;
    if(!this->opChc[4])
      std::printf("\n---------\n\n");
    LENg = 0, i = 0;
    if(!this->opChc[4]){
      std::printf("\e[96m\e[4mBEGIN::(DoCo)\e[0m\e[96m\n");
    }
    //this->rO("FIN::B:");
    while (true) {
      if(i >= a.size()){
        break;
      }
      SET = a0.at(i);
      bool rCT = 0;
      rCT = 1;
      if(!this->opChc[4]){
        std::printf("%s%s%s%s%s\n",outpt.c_str(), this->file0.c_str(), prc.c_str(), this->file1.c_str(), prc.c_str());
        std::printf("%s\n", lne.c_str());
      }
      while (SET == a0.at(i)) {
        for(int j = 0; j < this->strThNeedle->size(); j++){
          if(this->strThNeedle->at(j) == this->strComparison1->at(i)){
            chk0 = j;
            break;
          }
        }
        for(int j = 0; j < this->strComparison0->size(); j++){
          if(this->strComparison0->at(j) == this->strComparison1->at(i)){
            chk1 = j;
            break;
          }
        }
        if(!this->opChc[4])
          std::printf("%s%s%s%s%s%s\n\n",SP.c_str(), a.at(i).c_str(), nLW.at(chk0).c_str(), pr0.at(chk0).c_str(), nL0.at(chk1).c_str(), pr1.at(chk1).c_str());
        i++;
        if (a0.size() <= i)
          break;
      }
      LENg++;
      if (LENg == a.size() || i >= a0.size())
        break;
      i++;
      if(!rCT && i >= a.size()){
        if(!this->opChc[4]){
          std::printf("\n\e[4mTerminal>\e[0m\e[91m\e[5m");
          std::printf("\tNo phrases to return\e[0m\e[96m\n");
        } else {
          W << "NONE\n";
        }
      }
    }

    std::vector<std::vector<std::string>> chekk = {nLW, nL0, pr0, pr1};
    for(int i = 0; i < chekk.size(); i++){
      if(!chekk.at(i).empty())
        chekk.at(i).clear();
    }
    //this->rO("EE::outP::D::");
    ln0 = 0, sWrd = 0, s0 = 0, s1 = 0, lng0, lng2 = 0;
    spWrd = "", sp0 = "", outpt = " +===> OUTPUT", lne = "-{", prc = "%  ", prcW;
    chk0, chk1;
    //Set sWrd as length of longest word in strRedCheck
    for(long i = 0; i < this->strRedCheck->size(); i++){
      if(i > 0){
        if(std::to_string(this->intRedCheck->at(i)).length() > std::to_string(this->intRedCheck->at(i-1)).length()){
          sWrd = std::to_string(this->intRedCheck->at(i)).length();
        }
      }
    }
    //Add presence of percentages from first document to list of prO
    for(long i = 0; i < this->intRedCheck->size(); i++){
      if(this->intRedCheck->at(i)/this->intRedCheck->size() > 0)
        prcW = std::to_string(this->intRedCheck->at(i)/this->intRedCheck->size());
      else
        prcW = "<0";

      while(prcW.length() < prc.length()){
        prcW += ' ';
      }
      pr0.push_back(prcW);
    }
    //Add presence of percentages from second document to list of pr1
    for(long i = 0; i < this->intDoc0->size(); i++){
      if(this->intDoc0->at(i)/this->intDoc0->size() > 0)
        prcW = std::to_string(this->intDoc0->at(i)/this->intDoc0->size());
      else
        prcW = "<0";
      while(prcW.length() < prc.length()){
        prcW += ' ';
      }
      pr1.push_back(prcW);
    }
    //Make length of each number to equal that of the size of the longest number, plus two spaces
    for(long i = 0; i < this->intRedCheck->size(); i++){
      spWrd = std::to_string(this->intRedCheck->at(i));
      while(spWrd.length() < sWrd + 3){
        spWrd += " ";
      }
      nLW.push_back(spWrd);
    }
    for(long i = 0; i < this->strDoc0->size(); i++){
      if(i > 0){
        if(std::to_string(this->intDoc0->at(i)).length() > std::to_string(this->intDoc0->at(i-1)).length()){
          sWrd = std::to_string(this->intDoc0->at(i)).length();
        }
      }
    }
    for(long i = 0; i < this->intDoc0->size(); i++){
      if(i > 0){
        if(this->strDoc0->at(i).length() > this->strDoc0->at(i-1).length()){
          s0 = this->strDoc0->at(i).length();
        }
      }
    }
    for(long i = 0; i < this->strDoc0->size(); i++){
      sp0 = std::to_string(this->intDoc0->at(i));
      while(sp0.length() < sWrd + 3){
        sp0 += " ";
      }
      nL0.push_back(sp0);
    }
    if(s0 + 2 > this->file0.length() + 1) lng0 = s0+2; else lng0 = this->file0.length() + 1;
    this->file0 += " ";
    for(long i = 0; i < this->strDoc1->size(); i++){
      if(i > 0){
        if(this->strDoc1->at(i).length() > this->strDoc1->at(i-1).length()){
          s1 = this->strDoc1->at(i).length();
        }
      }
    }
    this->file1 += ' ';
    a = *this->strDoc1;
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
    a0 = *this->intDoc1;
    if(!this->opChc[4])
      std::printf("\n---------\n\n");
    LENg = 0, i = 0;
    if(!this->opChc[4]){
      std::printf("\e[96m\e[4mBEGIN::(DoCo)\e[0m\e[96m\n");
    }
    //this->rO("FIN::B:");
    while (true) {
      if(i >= a.size()){
        break;
      }
      SET = a0.at(i);
      bool rCT = 0;
      rCT = 1;
      if(!this->opChc[4]){
        std::printf("%s%s%s%s%s\n", outpt.c_str(), this->file0.c_str(), prc.c_str(), this->file1.c_str(), prc.c_str());
        std::printf("%s\n",lne.c_str());
      }
      while (SET == a0.at(i)) {
        if(this->opChc[4])
          W << this->lower(a.at(i)) << ">" << a0.at(i) << std::endl;
        for(int j = 0; j < this->strRedCheck->size(); j++){
          if(this->strRedCheck->at(j) == this->strDoc1->at(i)){
            chk0 = j;
            break;
          }
        }
        for(int j = 0; j < this->strDoc0->size(); j++){
          if(this->strDoc0->at(j) == this->strDoc1->at(i)){
            chk1 = j;
            break;
          }
        }
        if(!this->opChc[4])
          std::printf("%s%s%s%s%s%s\n\n", SP.c_str(), a.at(i).c_str(), nLW.at(chk0).c_str(), pr0.at(chk0).c_str(), nL0.at(chk1).c_str(), pr1.at(chk1).c_str());
        i++;
        if (a0.size() <= i)
          break;
      }
      LENg++;
      if (LENg == a.size() || i >= a0.size())
        break;
      i++;
      if(!rCT && i >= a.size()){
        if(!this->opChc[4]){
          std::printf("\n\e[4mTerminal>\e[0m\e[91m\e[5m");
          std::printf("\tNo phrases to return\e[0m\e[96m\n");
        } else {
          W << "NONE\n";
        }
      }
    }


    ///
    if(!this->opChc[4]){
      std::printf("\n\e[4mEND::(DoCo)\e[0m\n");
    }

  }
  if(this->opChc[3]){
    this->data(&this->opChc[0], &this->opChc[1], &this->opChc[2]);
  }
  W.close();
  std::printf("Output written to %s", this->getPath((char *)"temp.txt"));
  //std::printf("\n\nTh %ld -- %ld", this->strThNeedle->size(), this->intThNeedle->size());
  //std::printf("\n\nRC %ld -- %ld\n", this->strRedCheck->size(), this->intRedCheck->size());
  //std::printf("\n\nC0 %ld -- %ld\n", this->strComparison0->size(), this->intComparison0->size());
  //std::printf("\n\nC1 %ld -- %ld\n", this->strComparison1->size(), this->intComparison1->size());
  //std::printf("\n\nD0 %ld -- %ld\n", this->strDoc0->size(), this->intDoc0->size());
  //std::printf("\n\nD1 %ld -- %ld\n", this->strDoc1->size(), this->intDoc1->size());
  }


//Percentage bar to present percentage
void Complementary::progressBar(float x){

}

//Check if file is good, rather, if it exists
bool Complementary::GUD(std::string FILE){
  //std::printf("\n\n\tGUD\n\n");
	bool tf = 0;
	std::ifstream f;
	f.open(FILE);
	if(!f.good()){
			std::printf("-+=FileNotFound=+-\n");
	} else {
		tf = 1;
	}
	f.close();
  //std::printf("\n\n\t/GUD\n\n");
	return tf;
}


//Data to display on web-page
void Complementary::data(bool a, bool b, bool c){
  //std::printf("\n\n\tdata\n\n");
	std::ofstream f0;
	std::string fil, inpt = "", Wfl = "start ", Lfl = "firefox ", LFilr = "filr.sh", WFilr = "filr.bat", bse, jsFil;
	if(libUse){
		f0.open(this->getPath((char *)"wrdz.json"));
		Wfl += "10.0.0.185:8000";
		Lfl += "10.0.0.185:8000";
		jsFil += "{";
	} else {
		//Javascript for displaying information on WeBI, but as a bar-generator
		f0.open(this->getPath((char *)"graphicOut.js"));
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
function opn(document, ID){\n\
    var elm = document.querySelectorAll('#' + ID), X, y = document.getElementById(ID + \"B\"), t = false, LETAry = ['Reg', 'Red', 'Doc'];\n\
    \n\
    for(var i = 0; i < LETAry.length; i++){\n\
        if(LETAry[i] == ID){\n\
            t = true;\n\
        }\n\
    }\n\
\n\
    for (var i = 0; i < elm.length; i++) {\n\
        X = elm[i];\n\
        if(X.style.display == \"none\"){\n\
            X.style.display = \"block\";\n\
            if(t){\n\
                y.style.backgroundColor = \"green\";\n\
            }\n\
        } else {\n\
            X.style.display = \"none\";\n\
            if(t){\n\
                y.style.backgroundColor = \"red\";\n\
            }\n\
        }\n\
    }\n\
}\n\
\n\
function Clicke(x, document) {\n\
    var LETAry, i;\n\
    \n\
    LETAry = ['Reg', 'Red', 'Doc'];\n\
    for (i = 0; i < LETAry.length; i += 1) {\n\
        if (x == LETAry[i]) {\n\
            opn(document, x);\n\
            continue;\n\
        } else {\n\
            opn(document, x);\n\
        }\n\
    }\n\
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
function outP(x) { \n\
    var ";
	}
	std::vector<std::vector<std::string>> *allS = new(std::nothrow) std::vector<std::vector<std::string>>(5);
	std::vector<std::vector<long>> *allL = new(std::nothrow) std::vector<std::vector<long>>(5);
	//Append string vector if specified option is true
	if(a){
		allS->at(0) = *strThNeedle;
		allL->at(0) = *intThNeedle;
	}
	if(b){
		allS->at(1) = *strRedCheck;
		allL->at(1) = *intRedCheck;
	}
	if(c){
		allS->at(2) = *strComparison0;
		allL->at(2) = *intComparison0;
		allS->at(3) = *strComparison1;
		allL->at(3) = *intComparison1;
		allS->at(4) = *strDoc1;
		allL->at(4) = *intDoc1;
	}

	std::vector<std::string> *stz = new(std::nothrow) std::vector<std::string>(5), *lnz = new(std::nothrow) std::vector<std::string>(5);
	std::string strFil = "";
	for(int i = 0; i < allS->size(); i++){
		for(int j = i; j < allS->at(i).size(); j++){
			if(i > 0 && allL->at(i).at(j) <= 1)
				continue;
			strFil = allS->at(i).at(j);
			stz->at(i) += "\"" + strFil + "\"";
			lnz->at(i) += std::to_string(allL->at(i).at(j));
			if(j < allS->at(i).size() - 1){
				stz->at(i) += ", ";
				lnz->at(i) += ", ";
			}
		}
	}
	for(int i = 0; i < stz->size(); i++){
		if(i > 0)
			jsFil += ", ";
		//Append applicable strings
		switch(i){
			case 0:
				jsFil += "\"sSz\" : [" + stz->at(i) + "], \"iSz\" : [" + lnz->at(i) + "] ";
				break;
			case 1:
				jsFil += "\"sPh\" : [" + stz->at(i) + "], \"iPh\" : [" + lnz->at(i) + "] ";
				break;
			case 2:
				jsFil += "\"sS2\" : [" + stz->at(i) + "], \"iS2\" : [" + lnz->at(i) + "] ";
				break;
			case 3:
				jsFil += "\"sDc\" : [" + stz->at(i) + "], \"iDc\" : [" + lnz->at(i) + "] ";
				break;
			case 4:
				jsFil += "\"sD2\" : [" + stz->at(i) + "], \"iD2\" : [" + lnz->at(i) + "] ";
				break;
		}
	}
	if(libUse){
		jsFil += "}";
	} else {
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
    canv0 = [],\n\
    lnl = 0;\n\
\n\
    document.getElementById(\"dropdown\").style.display = \"none\";\n\
    \n\
    document.getElementById(\"RegB\").style.backgroundColor = \"green\";\n\
    document.getElementById(\"RedB\").style.backgroundColor = \"red\";\n\
    document.getElementById(\"DocB\").style.backgroundColor = \"red\";\n\
\n\
    for(var i = 0; i < Slst.length; i++){\n\
        Slst[i].reverse();\n\
        Ilst[i].reverse();\n\
    }\n\
\n\
    for(var i = 0; i < Slst.length; i++){\n\
        for(var j = 0; j < Slst[i].length; j++){\n\
            canv[lnl] = \"\";\n\
            canv[lnl] = document.createElement(\"canvas\");\n\
            canv[lnl].id = \"canv\" + j + i;\n\
            \n\
            canv0[lnl] = \"\";\n\
            canv0[lnl] = document.createElement(\"canvas\");\n\
            canv0[lnl].id = \"canv0\" + j + i;\n\
            \n\
            if(x){                \n\
                iP[lnl] = \"\";\n\
                iP0[lnl] = \"\";\n\
                sP[lnl] = \"\";\n\
                sP0[lnl] = \"\";\n\
                lt0[lnl] = \"\";\n\
                lt1[lnl] = \"\";\n\
                \n\
                sP[lnl] = document.createElement(\"p\");\n\
                sP0[lnl] = document.createTextNode(Slst[i][j]);\n\
                sP[lnl].appendChild(sP0[lnl]);\n\
                lt0[lnl] = document.createElement(\"li\");\n\
                lt0[lnl].appendChild(sP[lnl]);\n\
                \n\
                iP[lnl] = document.createElement(\"p\");\n\
                iP0[lnl] = document.createTextNode(Ilst[i][j]);\n\
                iP[lnl].appendChild(iP0[lnl]);\n\
                lt1[lnl] = document.createElement(\"li\");\n\
                lt1[lnl].appendChild(iP[lnl]);\n\
            }            \n\
            lt2[lnl] = document.createElement(\"li\");\n\
            lt2[lnl].appendChild(canv[lnl]);\n\
            lt2[lnl].appendChild(canv0[lnl]);\n\
            lnl++;\n\
            if(lnl - 1 < sSz.length){\n\
                lt0[lnl - 1].id = \"Reg\";\n\
                lt1[lnl - 1].id = \"Reg\";\n\
                lt2[lnl - 1].id = \"Reg\";\n\
                lt0[lnl - 1].style.display = \"block\";\n\
                lt1[lnl - 1].style.display = \"block\";\n\
                lt2[lnl - 1].style.display = \"block\";\n\
                continue;\n\
            }\n\
            if(lnl - 1 < sSz.length + sPh.length){\n\
                lt0[lnl - 1].id = \"Red\";\n\
                lt1[lnl - 1].id = \"Red\";\n\
                lt2[lnl - 1].id = \"Red\";\n\
                lt0[lnl - 1].style.display = \"none\";\n\
                lt1[lnl - 1].style.display = \"none\";\n\
                lt2[lnl - 1].style.display = \"none\";\n\
                continue;\n\
            } else {\n\
                lt0[lnl - 1].id = \"Doc\";\n\
                lt1[lnl - 1].id = \"Doc\";\n\
                lt2[lnl - 1].id = \"Doc\";\n\
                lt0[lnl - 1].style.display = \"none\";\n\
                lt1[lnl - 1].style.display = \"none\";\n\
                lt2[lnl - 1].style.display = \"none\";\n\
            }\n\
        }\n\
    }\n\
\n\
    for(var i = 0; i < lt.length; i++){\n\
        for(var j = 0; j < lt[i].length; j++){\n\
            console.log(lt[i][j]);\n\
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
    lnl = 0;\n\
\n\
    for(var i = 0; i < Slst.length; i++){\n\
        for(var j = 0; j < Slst[i].length; j++){\n\
            /* doc, xPos, yPos, w, h, id*/\n\
            mkRct(document, 0, 0, (Ilst[i][j]/Ilst[i][0]) * (window.innerWidth * 0.20), 10, canv[lnl].id, (window.innerWidth * 0.20), canv0[lnl].id);\n\
            lnl++;\n\
        }\n\
    }\n\
}";
	}
	f0 << jsFil;
	f0.close();
	if(libUse){
		#if WIN_32
			std::system(WFilr.c_str());
			std::system(Wlf.c_str());
		#else
			std::system(LFilr.c_str());
			std::system(Lfl.c_str());
		#endif
	}
  //std::printf("\n\n\t/data\n\n");
}

//Constructs all files not present
void Complementary::mkFil(){
  //std::printf("\n\n\tmkFil\n\n");
	std::ofstream f;
	//HTML for page's structure
	f.open(this->getPath((char *)"index.html"));
	f << "<!DOCTYPE html>\n\
<html lang=\"en\">\n\
    <head>\n\
        <meta charset=\"UTF-8\">\n\
        <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/foundation-sites@6.5.3/dist/css/foundation-float.min.css\" integrity=\"sha256-sP0p6J7SbJGiJ2gkdY1nkVsLgdwiFN2kI370lU+zacQ= sha384-yZLxxcD8nfiSt1qfKJWwHwtkL58WZDTlkBnZN60qr3ZS35+LDsmUF2JHLxdyZ+KU sha512-Z3WbpfWFSsK2dBvoSYZnMvPmxSJUa5cxj3TYlmyj6cq8IXy7iB2nlUk+jjms8gnz4HmpQk/yhRSlRzW7keoSlg==\" crossorigin=\"anonymous\">\n\
        <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/foundation-sites@6.5.3/dist/css/foundation-prototype.min.css\" integrity=\"sha256-ksLmXa0k3ACbX6azB9g6l7XlmSKFBkuH0DXKNwULXtE= sha384-RGTvu65DAT+yLQsTj5tnITDrMfrS5mbajNAYILSg4hHr9vRr/3Y9q0WAdChqLKfx sha512-KMJ7XYrv5UcwEvJFaYnLSdN5O3fT7aQvjed//LQPB3AsN4VPA/wXG9j4x4vKZkjNmU/U8aZC9Ac3FYxs9lPXcw==\" crossorigin=\"anonymous\">\n\
        <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/foundation-sites@6.5.3/dist/css/foundation-rtl.min.css\" integrity=\"sha256-jvk46bzgetf2fy3FF19toDOoy9CG3aFqZfd229doSyo= sha384-w6E9ynA6OV6MFswc7C8nr8QoBiRtqqOKF/5M9ZVyVDDyrUPLI75xizNuXgRZxWK5 sha512-7MZk47L+5Mj6Y0dP3NuB2aqlNdDgzTlCf8m50nvgnCHUbxZ9KabCy8VUzQAl/DqDKwR7E6JsCf1MUjkfCiVzJw==\" crossorigin=\"anonymous\">\n\
        <link rel=\"stylesheet\" href=\"style.css\">\n\
        <link rel=\"icon\" type=\"image/png\" href=\"favicon.ico\">\n\
		<link href=\"https://fonts.googleapis.com/css?family=Kumar+One+Outline&display=swap\" rel=\"stylesheet\">\n\
        <script type=\"text/javascript\" src=\"graphicOut.js\"></script>\n\
    </head>\n\
    <body onresize=\"outP(0)\">\n\
        <div class=\"row\">\n\
            <div class=\"columns large-3 large-pull-3 medium-4 medium-push-1\">\n\
                <img src=\"imgs/MagnifEyeLogo.png\">\n\
            </div>\n\
            <div class=\"columns large-9 large-pull-4 medium-8\">\n\
                <h1>MagnifEye</h1>\n\
            </div>\n\
        </div>\n\
        <div class=\"row\">\n\
            <div class=\"columns large-12 large-pull-3 medium-9 medium-push-1\">\n\
                    <h4>v1.8.8</h4>\n\
            </div>\n\
            <div class=\"columns large-9 large-pull-3 medium-10 medium-push-1\">\n\
                <h5>By FlakeyKarma</h5>\n\
            </div>\n\
            <div class=\"columns large-3 medium-2 medium-pull-1\">\n\
                <button onclick=\"opn(document, 'dropdown', 'true')\" class=\"btn\" id=\"btn\"><p>Options</p></button>\n\
                <div id=\"dropdown\">\n\
                    <div class=\"rows\">\n\
                        <ul>\n\
                            <div class=\"columns large-12 large-push-1\">\n\
                                <li id=\"RegB\">\n\
                                    <button onclick=\"Clicke('Reg', document)\"><p>Regular Output</p></button>\n\
                                </li>\n\
                            </div>\n\
                            <div class=\"columns large-12 large-push-1\">\n\
                                <li id=\"RedB\">\n\
                                    <button onclick=\"Clicke('Red', document)\"><p>Redundancy Check</p></button>\n\
                                </li>\n\
                            </div>\n\
                            <div class=\"columns large-12 large-push-1\">\n\
                                <li id=\"DocB\">\n\
                                    <button onclick=\"Clicke('Doc', document)\"><p>Document Comparison</p></button>\n\
                                </li>\n\
                            </div>\n\
                        </ul>\n\
                    </div>\n\
                </div>\n\
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
	//Styles for page
	f.open(this->getPath((char *)"style.css"));
	f << "#dropdown {\n\
  display: none;\n\
  background: lightgrey;\n\
  position: absolute;\n\
  z-index: 5;\n\
  padding-left: 5px;\n\
  padding-bottom: 20px;\n\
  border-radius: 10px;\n\
}\n\
.btn {\n\
  background: grey;\n\
  border-radius: 5px;\n\
  padding: 2px;\n\
}\n\
.btn p, #dropdown p {\n\
  font-size: 15px;\n\
  color: black;\n\
}\n\
#dropdown li {\n\
  list-style: none;\n\
  width: 80%;\n\
  padding-left: 5px;\n\
  border-radius: 5px;\n\
  margin-bottom: 2px;\n\
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
	if(libUse){
		//Javascript for use with library dependencies
		f.open(this->getPath((char *)"graphicOut.js"));
		f << "function mkBar(doc, xPos, yPos, w, h, id){\n\
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
	function opn(document, ID){\n\
		var elm = document.querySelectorAll('#' + ID), X, y = document.getElementById(ID + \"B\"), t = false, LETAry = ['Reg', 'Red', 'Doc'];\n\
		\n\
		for(var i = 0; i < LETAry.length; i++){\n\
			if(LETAry[i] == ID){\n\
				t = true;\n\
			}\n\
		}\n\
	\n\
		for (var i = 0; i < elm.length; i++) {\n\
			X = elm[i];\n\
			if(X.style.display == \"none\"){\n\
				X.style.display = \"block\";\n\
				if(t){\n\
					y.style.backgroundColor = \"green\";\n\
				}\n\
			} else {\n\
				X.style.display = \"none\";\n\
				if(t){\n\
					y.style.backgroundColor = \"red\";\n\
				}\n\
			}\n\
		}\n\
	}\n\
	\n\
	function Clicke(x, document) {\n\
		var LETAry, i;\n\
		\n\
		LETAry = ['Reg', 'Red', 'Doc'];\n\
		for (i = 0; i < LETAry.length; i += 1) {\n\
			if (x == LETAry[i]) {\n\
				opn(document, x);\n\
				continue;\n\
			} else {\n\
				opn(document, x);\n\
			}\n\
		}\n\
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
	function outP(x) {\n\
		var X = new XMLHttpRequest(), path = \"wrdz.json\";\n\
		X.open(\'GET\', path, true);\n\
		X.responseType = \'blob\';\n\
		X.onload = function(window) {\n\
			if(this.status == 200){\n\
				var F = new File([this.response], \'temp\');\n\
				var FReader = new FileReader();\n\
				FReader.addEventListener(\'load\', function(window){\n\
					var JSs = JSON.parse(FReader.result);\n\
					var sSz = JSs.sSz,\n\
					iSz = JSs.iSz,\n\
					sPh = JSs.sPh,\n\
					iPh = JSs.iPh,\n\
					sS2 = JSs.sS2,\n\
					iS2 = JSs.iS2,\n\
					sDc = JSs.sDc,\n\
					iDc = JSs.iDc,\n\
					sD2 = JSs.sD2,\n\
					iD2 = JSs.iD2,\n\
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
					canv0 = [],\n\
					lnl = 0;\n\
				\n\
					document.getElementById(\"dropdown\").style.display = \"none\";\n\
					\n\
					document.getElementById(\"RegB\").style.backgroundColor = \"green\";\n\
					document.getElementById(\"RedB\").style.backgroundColor = \"red\";\n\
					document.getElementById(\"DocB\").style.backgroundColor = \"red\";\n\
				\n\
					for(var i = 0; i < Slst.length; i++){\n\
						Slst[i].reverse();\n\
						Ilst[i].reverse();\n\
					}\n\
				\n\
					for(var i = 0; i < Slst.length; i++){\n\
						for(var j = 0; j < Slst[i].length; j++){\n\
							canv[lnl] = \"\";\n\
							canv[lnl] = document.createElement(\"canvas\");\n\
							canv[lnl].id = \"canv\" + j + i;\n\
							\n\
							canv0[lnl] = \"\";\n\
							canv0[lnl] = document.createElement(\"canvas\");\n\
							canv0[lnl].id = \"canv0\" + j + i;\n\
							\n\
							//Just in case\n\
							//if(x){                \n\
							iP[lnl] = \"\";\n\
							iP0[lnl] = \"\";\n\
							sP[lnl] = \"\";\n\
							sP0[lnl] = \"\";\n\
							lt0[lnl] = \"\";\n\
							lt1[lnl] = \"\";\n\
							\n\
							sP[lnl] = document.createElement(\"p\");\n\
							sP0[lnl] = document.createTextNode(Slst[i][j]);\n\
							sP[lnl].appendChild(sP0[lnl]);\n\
							lt0[lnl] = document.createElement(\"li\");\n\
							lt0[lnl].appendChild(sP[lnl]);\n\
							\n\
							iP[lnl] = document.createElement(\"p\");\n\
							iP0[lnl] = document.createTextNode(Ilst[i][j]);\n\
							iP[lnl].appendChild(iP0[lnl]);\n\
							lt1[lnl] = document.createElement(\"li\");\n\
							lt1[lnl].appendChild(iP[lnl]);\n\
							//Just in case\n\
							//}            \n\
							lt2[lnl] = document.createElement(\"li\");\n\
							lt2[lnl].appendChild(canv[lnl]);\n\
							lt2[lnl].appendChild(canv0[lnl]);\n\
							lnl++;\n\
							if(lnl - 1 < sSz.length){\n\
								lt0[lnl - 1].id = \"Reg\";\n\
								lt1[lnl - 1].id = \"Reg\";\n\
								lt2[lnl - 1].id = \"Reg\";\n\
								lt0[lnl - 1].style.display = \"block\";\n\
								lt1[lnl - 1].style.display = \"block\";\n\
								lt2[lnl - 1].style.display = \"block\";\n\
								continue;\n\
							}\n\
							if(lnl - 1 < sSz.length + sPh.length){\n\
								lt0[lnl - 1].id = \"Red\";\n\
								lt1[lnl - 1].id = \"Red\";\n\
								lt2[lnl - 1].id = \"Red\";\n\
								lt0[lnl - 1].style.display = \"none\";\n\
								lt1[lnl - 1].style.display = \"none\";\n\
								lt2[lnl - 1].style.display = \"none\";\n\
								continue;\n\
							} else {\n\
								lt0[lnl - 1].id = \"Doc\";\n\
								lt1[lnl - 1].id = \"Doc\";\n\
								lt2[lnl - 1].id = \"Doc\";\n\
								lt0[lnl - 1].style.display = \"none\";\n\
								lt1[lnl - 1].style.display = \"none\";\n\
								lt2[lnl - 1].style.display = \"none\";\n\
							}\n\
						}\n\
					}\n\
				\n\
					for(var i = 0; i < lt.length; i++){\n\
						for(var j = 0; j < lt[i].length; j++){\n\
							console.log(lt[i][j]);\n\
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
					lnl = 0;\n\
				\n\
					for(var i = 0; i < Slst.length; i++){\n\
						for(var j = 0; j < Slst[i].length; j++){\n\
							/* doc, xPos, yPos, w, h, id*/\n\
							mkRct(document, 0, 0, (Ilst[i][j]/Ilst[i][0]) * (innerWidth * 0.20), 10, canv[lnl].id, (innerWidth * 0.20), canv0[lnl].id);\n\
							lnl++;\n\
						}\n\
					}\n\
				});\n\
				FReader.readAsText(F);\n\
			}\n\
		}\n\
		X.send();\n\
	}";
	f.close();
	}
  //std::printf("\n\n\t/mkFil\n\n");
}

//Switch to display true or false in cli menu
void Complementary::TFswitch(bool t){
	const char oArr[4] = "\xE2\x96\x91", iArr[4] = "\xE2\x96\x93", btn[4] = "\xE2\x96\x88";
	std::string fll = "";
	if(t){
    fll += iArr;
    fll += iArr;
		fll += btn;
		std::printf("%s\n", fll.c_str());
	}else{
		fll += btn;
    fll += oArr;
    fll += oArr;
		std::printf("%s\n", fll.c_str());
	}
}

void Complementary::excludeSET(char *ary){
  if(this->include_set){
    std::printf("Error: Include all ready set.\n");
    exit(-1);
  }
  this->param_bool[0] = 1;
  this->param_bool[1] = 1;
  this->exclude_set = 1;
  this->strGrab(ary);
}

void Complementary::excludeCLI(){

}

void Complementary::includeSET(char *ary){
  if(this->exclude_set){
    std::printf("Error: Exclude all ready set.\n");
    exit(-1);
  }
  this->param_bool[0] = 1;
  this->param_bool[1] = 1;
  this->include_set = 1;
  this->strGrab(ary);
}

void Complementary::removalSET(char *ary){
  this->param_bool[0] = 0;
  this->param_bool[1] = 0;
  this->paramGetter(ary);
  //exit(0);
}

//If there is a desired removal char set desired, then display TRUE and the character and it's ASCII value, in case it isn't human readable
void Complementary::removalCLI(){

}

void Complementary::delimeterSET(char *ary){
  this->param_bool[0] = 1;
  this->param_bool[1] = 0;
  this->delimeter_set = 1;
  this->paramGetter(ary);
  //exit(0);
}

//If there is a desired removal char set desired, then display TRUE and the character and it's ASCII value, in case it isn't human readable
void Complementary::delimeterCLI(){

}

//Set the new metrics based on entered measurements
void Complementary::metricSET(char *ary){
  //std::printf("MET\n\n");
  this->param_bool[0] = 0;
  this->param_bool[1] = 1;
  this->paramGetter(ary);
  //std::printf("METZ %d %d\n", this->metricz[0], this->metricz[1]);
}

//Clear screen
void Complementary::clr(){
	#ifdef _WIN32
	system("CLS");
	#else
	std::system("clear");
	#endif
}

//Pause output
void Complementary::pauz(){
  #ifdef _WIN32
  system("PAUSE");
  #else
  std::printf("PressAnyKey...\n");
  std::cin.ignore();
  std::cin.get();
  #endif
}

//Returns file requested to have read
char * Complementary::filIn(){
  //std::printf("\n\n\tfilIn\n\n");
	char *fil;
	while(1){
		std::printf("MEye> Enter directory to file: ");
    std::scanf(" %s", fil);
    fil[strlen(fil)] = '\0';
		if(!strcmp(fil, "ls")){
			system("ls");
      fil = new char;
		}else{
			return fil;
		}
	}
  //std::printf("\n\n\t/filIn\n\n");
}

//Output help for each function
void Complementary::help(){
	std::printf("- Help [-h, --help]\n\
	\n-- Display this screen in console view, but otherwise shows\n\
   the command and a shorter version of this screen.\n");
	std::printf("\n\n- Regular Output\n\
	\n-- Display each word used in the document with the amount\n\
   next at the top of the group of words that share the same\n\
   amount.\n");
	std::printf("\n\n- Command Line Interface (CLI) [-c, --cli]\n\
	\n-- Initialize the console version of MagnifEye.\n");
	std::printf("\n\n- Redundancy Check\e[91m (RedCheck)\e[0m  [-red, --redcheck]\n\
	\n-- Similar to \'Regular Output\' but it displays both the\n\
   words and phrases that have been repeated in the document.\n");
	std::printf("\n\n- Document Comparison\e[96m (DoCo)\e[0m   [-dc, --doc-com]\n\
	\n-- Display comparison between two documents both as \'Regular Output\'\n\
   and \'Redundancy Check\' in a similar format, with percentage of\n\
   similarity at the end.\n");
	std::printf("\n\n- Web-Based-Interface \e[93m(WeBI)\e[0m   [-w, --WeBI]\n\
	\n-- Display the output in a FireFox browser window.\n");
	std::printf("\n\n- Output-Parsed [-o, --out-par]\n\
	\n-- Output the results into a parsed version intended for usage by other programs.\n");
}

//Set as to whether to download the files needed or not
void Complementary::setDownload(){
  //std::printf("\n\n\tsetDownload\n\n");
	char answer, FIN = 0;
	std::ofstream fil;
	fil.open(this->getPath((char *)"downloadTF.txt"));
	std::printf("Would you like to download Node.JS, NPM, and http-server? [y/n]\n");
	#ifdef _WIN32
		std::printf("I will automatically add this to your path as well.\n");
	#endif
  std::scanf(" %c", &answer);
	while(true){
		if(FIN)
			break;
		switch(answer){
			case 1:
			case 'y':
			case 'Y':
				fil << "YES";
				FIN = 1;
				break;
			case 0:
			case 'n':
			case 'N':
				fil << "NO";
				FIN = 1;
				break;
			default:
				std::printf("Please enter \'y\' or \'n\'.\n");
		}
	}
	fil.close();
  //std::printf("\n\n\t/setDownload\n\n");
}

//Download libraries needed
void Complementary::Downloadz(){
	#ifdef _WIN32
		//Download files w/ batch files
	#else
		//Download w/ sh files
	#endif
}

//Set value of bool libUse depending on whether or not the "libraries" are in "use"
void Complementary::libInstl(std::string *s){
  //std::printf("\n\n\tlibInstl\n\n");
	if(*s == "YES"){
		libUse = 1;
	} else {
		libUse = 0;
	}
  //std::printf("\n\n\t/libInstl\n\n");
}

//Returns verison
std::string Complementary::ver(){
    return verz;
}

std::vector<Complementary::set0> Complementary::SeNDe(std::vector<Complementary::set0> T){

  //std::printf("\n\n\tSeNDe\n\n");
  if(!tw && !th)
    prg = 20.0;
  if(tw)
    prg = 10.0;
  if(th)
    prg = 6.67;

	std::vector<std::string> a = T[0].str;
	std::vector<long> a0 = T[0].lng;

  //Erasure of excess strings/period place-holders && corresponding longs
	int w0 = 0, w1;
	while (a.size() - 1 > w0) {
		w1 = w0 + 1;
		while (w1 < a.size()) {
      if (a.at(w1) == "\\\\+==PERIOD==+//"){
        a.erase(a.begin() + w1);
        a0.erase(a0.begin() + w1);
        continue;
      }
			if ((this->rawRead ? a.at(w0) == a.at(w1) : this->lower(a.at(w0)) == this->lower(a.at(w1))) || a0.at(w1) == 0 || a.at(w1) == " ") {
        if(a0.at(w1) > a0.at(w0)){
          iter_swap(a.begin() + w0, a.begin() + w1);
  				iter_swap(a0.begin() + w0, a0.begin() + w1);
        }
				a.erase(a.begin() + w1);
				a0.erase(a0.begin() + w1);
				w1--;
			}
			w1++;
		}
		w0++;
	}

  //Bubble-Sort, largest long to rightmost position along with corresponding string
  if(!this->reverse)
    for (long i = 0; i < a.size()-1; i++) {
      progressBar(float(1.0/a.size()*prg));
      for (long j = i+1; j < a.size(); j++){
        if (a0.at(i) > a0.at(j)) {
          iter_swap(a.begin() + i, a.begin() + j);
          iter_swap(a0.begin() + i, a0.begin() + j);
        }
      }
    }
  T[0].str = a;
  T[0].lng = a0;
  //std::printf("\n\n\t/SeNDe\n\n");
  return T;
}

//Check if the std::string has more than one word
bool Complementary::GT1(std::string s){
  //std::printf("\n\n\tGT1\n\n");
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
  //std::printf("\n\n\t/GT1D\n\n");
	return 0;
}

//
std::string Complementary::lower(std::string s){
  for(int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
  return s;
}

//Get strings from char array
void Complementary::strGrab(char *ary){
  //Comma is used to get the number of words to prep for
  //word_length is used to select index for latest exclusionz word current char
  //word_array_index is used to select index for latest exclusionz word
  unsigned char comma = 1, word_length = 0, word_array_index = 0;
  //Increment for number of commas
  for(unsigned int i = 0; i < strlen(ary); i++) if(ary[i] == ',') comma++;
  //Create vector with number of words delimited by commas
  if(this->exclude_set) this->exclusionz = new std::vector<char *>(comma);
  if(this->include_set) this->inclusionz = new std::vector<char *>(comma);
  //Increment through each character in given array
  for(unsigned int i = 0; i < strlen(ary); i++)
    //Skip character if it is a space
    if(ary[i] != ' '){
      //If either this is the start of the loop or a comma is the current character
      if(!i || ary[i] == ','){
        //Initialize new char array of 64 in length
        if(this->exclude_set) this->exclusionz->at(word_array_index++) = (char *)calloc('\0', 64);
        else this->inclusionz->at(word_array_index++) = (char *)calloc('\0', 64);
        //Set word length back to 0 for sake of char array indexing
        word_length = 0;
      }
      //If char is not a comma then change newest char in scope selected by word_length as index to the current char
      if(ary[i] != ','){
        if(this->exclude_set) this->exclusionz->at(word_array_index-1)[word_length++] = ary[i];
        else this->inclusionz->at(word_array_index-1)[word_length++] = ary[i];
      }
    }
}

//Gets data as delimeters, characters to be removed, or metrics, parses it, then assigns the correct var
//  with the correct data.
void Complementary::paramGetter(char *ary){
  bool MET_SET = 0;
  char *word;
  word = (char *)calloc(strlen(ary), '\0');
  if(!this->param_bool[0] && !this->param_bool[1]){
    this->removal_set = 1;
    this->removal = (char *)calloc(strlen(ary), '\0');
  }
  for(char i = 0; i < strlen(ary); i++){

    word[strlen(word)] = ary[i];

    if(word[strlen(word)-1] == ',' || strlen(ary)-1 == i){
      if(word[strlen(word)-1] == ',') word[strlen(word)-1] = '\0';
      if(this->checkIfNum(word)){
        switch(this->param_bool[0]){
          case 0:
            switch(this->param_bool[1]){
              case 0:
                this->removal[strlen(this->removal)] = atoi(word);
                break;
              case 1:
                this->metricz[MET_SET] = atoi(word);
                break;
            }
            break;
          case 1:
            switch(this->param_bool[1]){
              case 0:
                this->delimeterz[strlen(this->delimeterz)] = atoi(word);
                break;
              case 1:
                break;
            }
            break;
        }
        MET_SET = !MET_SET;
        word = (char *)calloc(strlen(ary), '\0');
        continue;
      } if(strlen(word) > 1 && !this->param_bool[0] && !this->param_bool[1]){
        exit(1);
      }
      switch(this->param_bool[0]){
        case 0:
          switch(this->param_bool[1]){
            case 0:
              this->removal[strlen(this->removal)] = word[strlen(word)-1];
              break;
            case 1:
              break;
          }
          break;
        case 1:
          switch(this->param_bool[1]){
            case 0:
              this->delimeterz[strlen(this->delimeterz)] = word[strlen(word)-1];
              break;
            case 1:
              break;
          }
          break;
      }
      word = (char *)calloc(strlen(ary), '\0');
    }
  }

  if(MET_SET && !this->param_bool[0] && this->param_bool[1]){
    std::printf("Invalid option [Not Enough Numbers Set For metrics]\n");
    exit(1);
  }
  if(this->metricz[0] >= this->metricz[1] && !this->param_bool[0] && this->param_bool[1]){
    std::printf("Invalid option [First Number Greater Than or Equal To Second]: %d >= %d\n", this->metricz[0], this->metricz[1]);
    exit(1);
  }
  if(!this->param_bool) this->removal[strlen(this->removal)] = '\0';
}

//If the collection is of digits, then return true, else return false
bool Complementary::checkIfNum(char *num){
  for(char i = 0; i < strlen(num); i++)
    if(num[i] <= 47 || num[i] >= 58) return 0;
  return 1;
}
