#include "resources.h"

int main(int argc, char* argv[]) {
	try{
		int sz = 0, sp = 0;
		stuffReturn* sr = new stuffReturn;
		char inpt01[5];
		sz = 0;
		string OPT, fil;
		vector<char> opti;
		bool TF = false;
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
					std::cout << "Usage:\nThNeedle <options> <file>\n\n" << std::endl;
					std::cout << "[-h, --help][-c, --cli][-red, --red-check][-l, --legend]\n\n" << std::endl;
					std::cout << "options:" << std::endl;
					std::cout << "\t-h,   --help        \tDisplay this screen" << std::endl;
					std::cout << "\t-c,   --cli         \tDisplay the CLI(Command Line Interface)" << std::endl;
					std::cout << "\t-red, --red-check \tDisplay redundancy of phrases used in document" << std::endl;
					std::cout << "\t-dc,  --doc-com\tDisplay similar words" << std::endl;
					std::cout << "\t-l,   --legend     \tDisplay legend to understand color coding for\n\toutput" << std::endl;
					std::cout << "\t-w,   --webInt        \tDisplay information on a web interface" << std::endl;
					std::cout << "\t-p,   --path          \tSet path to HTML and JavaScript files" << std::endl;
					OPT = argv[i];
					sr->pauz();
				}
				if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--path") == 0)
					opti.push_back('P');
				if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--cli") == 0)
					TF = true;
				if (strcmp(argv[i], "-red") == 0 || strcmp(argv[i], "--red-check") == 0)
					opti.push_back('r');
				if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--legend") == 0){
					std::cout << "\n\t\t\tLegend\n" << std::endl;
					std::printf("\e[92m");
					std::cout << "\tGood\n" << std::endl;
					std::cout << "\tMay need some adjustment, depending on preference\n\n" << std::endl;
					std::printf("\e[93m");
					std::cout << "\tOkay\n" << std::endl;
					std::cout << "\tNeeds some adjustment because of multiple uses of\n\tsame words\n\n" << std::endl;
					std::printf("\e[31m");
					std::cout << "\tBad\n" << std::endl;
					std::cout << "\tNeeds adjustment, too many instances of this/these\n\tword(s)" << std::endl;
					std::printf("\e[0m");
				}
				if (strcmp(argv[i], "-dc") == 0 || strcmp(argv[i], "--doc-com") == 0){
					opti.push_back('r');
					opti.push_back('d');
				}
				if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--webInt") == 0){
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
				sr->clr();

				std::cout << "_________" << std::endl;
				std::cout << " ===:===" << std::endl;
				std::cout << "   _|_   __        __   __                        ,,   ====" << std::endl;
				std::cout << "  |::_| |  |      |   \\|  |  ,====,   ,====,     |  |   ||   ,====," << std::endl;
				std::cout << "  |::_| |  l___   |       | | {}   | | {}   |   _|  |  |: | | {}   |" << std::endl;
				std::cout << "  |::_| |       | |       | |    _/  |    _/   /    |  |: | |    _/" << std::endl;
				std::cout << "  |::_| |   _   | |  |\\   | |  \\__   |  \\__    |  ()|  |: | |  \\__" << std::endl;
				std::cout << "   ===  |  | |  | |  | \\  | |      | |      |  \\    |  |: | |      |" << std::endl;
				std::cout << "    |    **   **   **   **   *====*   *====*    *==*    `|   *====*" << std::endl;
				std::cout << "\n" << sr->ver() << std::endl;
				std::cout << "By FlakeyKarma\n\n" << std::endl;
				std::cout << "[0] Regular Output" << std::endl;
				std::cout << "[1] Redundancy Check ";
				std::printf("\e[91m");
				std::cout << "(RedCheck)" << std::endl;
				std::printf("\e[0m");
				std::cout << "[2] Document Comparison ";
				std::printf("\e[96m");
				std::cout << "(DoCo)" << std::endl;
				std::printf("\e[0m");
				std::cout << "[3] Legend" << std::endl;
				std::cout << "[4] About" << std::endl;
				std::cout << "[5] Help" << std::endl;
				std::cout << "[x] Exit" << std::endl;
				std::cout << "\nFK> ";
				std::cin >> inpt01[0];
				switch (inpt01[0]) {
				//Regular output
				case '0':
					sr->clr();
					while(1){
						std::cout << "FK> Enter directory to file: ";
						std::cin >> fil;
						if(fil == "ls"){
							system("ls");
						}else{
							break;
						}
					delete sr;
					}
					opti.push_back('A');
					sr->outP(fil, argc, opti);
					sr->pauz();
				if(!opti.empty())
					opti.clear();
					break;
				//RedCheck
				case '1':
					sr->clr();
					while(1){
						std::cout << "FK> Enter directory to file: ";
						std::cin >> fil;
						if(fil == "ls"){
							system("ls");
						}else{
							break;
						}
					}
					opti.push_back('r');
					opti.push_back('A');
					sr->outP(fil, argc, opti);
					sr->pauz();
					break;
				//DoCo
				case '2':
					sr->clr();
					while(1){
						std::cout << "FK> Enter directory to file: ";
						std::cin >> fil;
						if(fil == "ls"){
							system("ls");
						}else{
							break;
						}
					}
					opti.push_back('M');
					opti.push_back('A');
					opti.push_back('d');
					opti.push_back('r');
					sr->outP(fil, argc, opti);
					sr->pauz();
					break;
				//Legend
				case '3':
					sr->clr();
					std::cout << "\n\t\t\tLegend\n" << std::endl;
					std::printf("\e[92m");
					std::cout << "\tGood\n" << std::endl;
					std::cout << "\tMay need some adjustment, depending on preference\n\n" << std::endl;
					std::printf("\e[93m");
					std::cout << "\tOkay\n" << std::endl;
					std::cout << "\tNeeds some adjustment because of multiple uses of\n\tsame words\n\n" << std::endl;
					std::printf("\e[31m");
					std::cout << "\tBad\n" << std::endl;
					std::cout << "\tNeeds adjustment, too many instances of this/these\n\tword(s)" << std::endl;
					std::printf("\e[0m");
					sr->pauz();
					break;
				//About
				case '4':
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
				case '5':
					sr->clr();
					std::cout << "Usage:\nThNeedle <options> <file>\n\n" << std::endl;
					std::cout << "[-h, --help][-c, --cli][-red, --red-check][-l, --legend]\n\n" << std::endl;
					std::cout << "options:" << std::endl;
					std::cout << "\t-h,   --help        \tDisplay this screen" << std::endl;
					std::cout << "\t-c,   --cli         \tDisplay the CLI(Command Line Interface)" << std::endl;
					std::cout << "\t-red, --red-check \tDisplay redundancy of phrases used in document" << std::endl;
					std::cout << "\t-dc,  --doc-com\tDisplay similar words" << std::endl;
					std::cout << "\t-l,   --legend     \tDisplay legend to understand color coding for\n\toutput" << std::endl;
					std::cout << "\t-w,   --webInt        \tDisplay information on a web interface" << std::endl;
					std::cout << "\t-p,   --path          \tSet path to HTML and JavaScript files" << std::endl;
					sr->pauz();
					break;
				//Exit
				case 'x':
					sr->clr();
					std::cout << "-=goodbye=-" << std::endl;
					std::exit(0);
				}
			}
		}

		if (strcmp(inpt01, ".txt") != 0 && !TF)
			std::exit(0);
		std::cout << "|  [========\\" << std::endl;
		std::cout << "|={:|;;|;;|;;}==---o" << std::endl;
		std::cout << "|  [========/       D" << std::endl;
		std::cout << "\nThNeedle " << sr->ver() << std::endl;
		std::cout << "\nBy FlakeyKarma\n\n" << std::endl;
		opti.push_back('A');
		sr->outP(argv[argc-1], argc, opti);
		std::cout << "\n\n--=goodbye=--\n\n" << std::endl;
		return 0;
	}catch(int e){
		std::cout << "\n\n--=goodbye=--\n\n" << std::endl;
		std::printf("\e[0m");
	}
}