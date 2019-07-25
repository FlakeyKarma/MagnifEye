#include "resources.h"

int main(int argc, char* argv[]) {
	try{
		std::ifstream FL;
		int sz = 0, sp = 0;
		stuffReturn* sr = new stuffReturn, *stRt;
		char inpt01[5];
		sz = 0;
		string OPT, fil, ansr;
		vector<char> opti;
		bool TF = false, dl = 1;
		//INTAKE:BEGIN
		if(argc == 1){
			TF = true;
		}
		else{
			for (int i = 1; i < (signed)argc; i++) {
				if (strcmp(argv[i], ">") == 0 || strcmp(argv[i], ">>") == 0){
					opti.push_back('F');
				}
				if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
					std::cout << "Usage:\nMagnifEye <options> <file>\n\n" << std::endl;
					std::cout << "[-h, --help][-c, --cli][-red, --red-check][-l, --legend]\n\n" << std::endl;
					std::cout << "options:" << std::endl;
					std::cout << "\t-h,   --help        \tDisplay this screen" << std::endl;
					std::cout << "\t-c,   --cli         \tDisplay the CLI(Command Line Interface)" << std::endl;
					std::cout << "\t-red, --red-check   \tDisplay redundancy of phrases used in document" << std::endl;
					std::cout << "\t-dc,  --doc-com     \tDisplay similar words" << std::endl;
					std::cout << "\t-l,   --legend      \tDisplay legend to understand color coding for\n\toutput" << std::endl;
					std::cout << "\t-w,   --WeBI        \tDisplay information on a web interface" << std::endl;
					OPT = argv[i];
					sr->pauz();
				}
				if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--cli") == 0)
					TF = true;
				if (strcmp(argv[i], "-red") == 0 || strcmp(argv[i], "--red-check") == 0)
					opti.push_back('r');
				if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--legend") == 0){
					std::cout << "\n\t\t\tLegend\n" << std::endl;
					std::cout << "\t\e[92mGood\n" << std::endl;
					std::cout << "\tMay need some adjustment, depending on preference\n\n" << std::endl;
					std::cout << "\t\e[93mOkay\n" << std::endl;
					std::cout << "\tNeeds some adjustment because of multiple uses of\n\tsame words\n\n" << std::endl;
					std::cout << "\t\e[31mBad\n" << std::endl;
					std::cout << "\tNeeds adjustment, too many instances of this/these\n\tword(s)\e[0m" << std::endl;
				}
				if (strcmp(argv[i], "-dc") == 0 || strcmp(argv[i], "--doc-com") == 0){
					opti.push_back('r');
					opti.push_back('d');
				}
				if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--WeBI") == 0){
					opti.push_back('w');
				}
			}
			for (int i = 4; i >= 0; i--)
				inpt01[4-i] = argv[argc-1][strlen(argv[argc-1])-i];
			inpt01[4] = '\0';
		}
		//INTAKE:END
		if (TF) {
			sr->clr();
			opti.clear();
			while (true) {
				if(dl){
					stRt = new stuffReturn;
					dl = 0;
				}
				FL.open("downloadTF.txt");
				while(getline(FL, ansr)){
					if(ansr == "NOT-YET" || ansr == "NO" || ansr == "YES"){
						break;
					}
				}
				sr->clr();

				std::cout << " __   __                         ___  ____" << std::endl;
				std::cout << "|  \\ /  |                       / __||  __|" << std::endl;
				std::cout << "|   `   | _____  ____   ___    _||_  |  _|      _  ____" << std::endl;
				std::cout << "|  |V|  ||     |/    ||V _ |o |_  _| | |  \\\\   / /|  []|" << std::endl;
				std::cout << "|  | |  ||[] | ||  []|| / |||\\  ||   | |__ \\\\ / / | \\__|" << std::endl;
				std::cout << "|__| |__||___|\\| \\_  ||_| |||_| ||   |____| \\` /  |____/" << std::endl;
				std::cout << "                  _| |                      / /" << std::endl;
				std::cout << "                 [__/                      / /" << std::endl;
				std::cout << "                                          /_/" << std::endl;
				std::cout << "\n" << sr->ver() << std::endl;
				std::cout << "By FlakeyKarma\n\n" << std::endl;
				std::cout << "[0] Regular Output" << std::endl;
				std::cout << "[1] Redundancy Check \e[91m(RedCheck)\e[0m" << std::endl;
				std::cout << "[2] Document Comparison \e[96m(DoCo)\e[0m" << std::endl;
				std::cout << "[3] Web-Based Interface \e[93m(WeBI)\e[0m" << std::endl;
				std::cout << "[4] Legend" << std::endl;
				std::cout << "[5] About" << std::endl;
				std::cout << "[6] Help" << std::endl;
				std::cout << "[i] Install :: Current setting=" << ansr << std::endl;
				std::cout << "[x] Exit" << std::endl;
				std::cout << "\nMEye> ";
				std::cin >> inpt01[0];
				switch (inpt01[0]) {
				//Regular output
				case '0':
					sr->clr();
					fil = stRt->filIn();
					opti.push_back('A');
					stRt->outP(fil, argc, &opti);
					dl = 1;
					sr->pauz();
					if(!opti.empty())
						opti.clear();
					break;
				//RedCheck
				case '1':
					sr->clr();
					fil = stRt->filIn();
					opti.push_back('r');
					opti.push_back('A');
					stRt->outP(fil, argc, &opti);
					dl = 1;
					sr->pauz();
					break;
				//DoCo
				case '2':
					sr->clr();
					fil = stRt->filIn();
					opti.push_back('M');
					opti.push_back('A');
					opti.push_back('d');
					opti.push_back('r');
					stRt->outP(fil, argc, &opti);
					dl = 1;
					sr->pauz();
					break;
				//weBI
				case '3':
					sr->clr();
					fil = stRt->filIn();
					opti = stRt->weBI();
					if(!opti.empty())
						stRt->outP(fil, argc, &opti);
					dl = 1;
					sr->pauz();
					break;
				//Legend
				case '4':
					sr->clr();
					std::cout << "\n\t\t\tLegend\n" << std::endl;
					std::cout << "\t\e[92mGood\n" << std::endl;
					std::cout << "\tMay need some adjustment, depending on preference\n\n" << std::endl;
					std::cout << "\t\e[93mOkay\n" << std::endl;
					std::cout << "\tNeeds some adjustment because of multiple uses of\n\tsame words\n\n" << std::endl;
					std::cout << "\t\e[31mBad\n" << std::endl;
					std::cout << "\tNeeds adjustment, too many instances of this/these\n\tword(s)\e[0m" << std::endl;
					sr->pauz();
					break;
				//About
				case '5':
					sr->clr();
					std::cout << "\n\n\\\\About" << std::endl;
					std::cout << "\n\\\\I started needing to make this program when I found myself trying\
									\n  finish a ten-page-paper far too late. Albeit, that was a struggle\
									\n  innate of itself, the main problem for me was trying to find out if\
									\n  I needed to change up the wordage used. Different words used show\
									\n  the variance in one\'s vocabulary and that's beneficial to prove a\
									\n  point. Sometimes, you also need a little \"umf\".. ya know?\n\
									\n  There you go\n\
									\n  -FlakeyKarma\n\n" << std::endl;
					sr->pauz();
					break;
				//Help
				case '6':
					sr->clr();
					sr->help();
					sr->pauz();
					break;
				//What to install
				case 'i':
				case 'I':
					sr->clr();
					sr->setDownload();
					FL.open("downloadTF.txt");
					while(getline(FL, ansr)){
						if(ansr == "YES"){
							sr->Downloadz();
							break;
						}
					}
					FL.close();
					sr->pauz();
					break;
				//Exit
				case 'x':
				case 'X':
					sr->clr();
					std::cout << "--=goodbye=--" << std::endl;
					std::exit(0);
				}
			}
		}

		if (strcmp(inpt01, ".txt") && !TF)
			std::exit(0);
		std::cout << "   \nMagnifEye " << sr->ver() << std::endl;
		std::cout << "//          \\\\" << std::endl;
		std::cout << "  //   _   \\\\" << std::endl;
		std::cout << "     /` `\\" << std::endl;
		std::cout << "   <' (O) `>" << std::endl;
		std::cout << "     \\,_,/" << std::endl;
		std::cout << "  \\\\       //" << std::endl;
		std::cout << "\\\\           //" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "\nBy FlakeyKarma\n\n" << std::endl;
		opti.push_back('A');
		sr->outP(argv[argc-1], argc, &opti);
		std::cout << "\n\n--=goodbye=--\n\n" << std::endl;
		return 0;
	}catch(int e){
		std::cout << "\n\n--=goodbye=--\e[0m\n\n" << std::endl;
	}
}