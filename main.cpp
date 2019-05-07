#include "resources.h"

int main(int argc, char* argv[]) {
	int sz = 0, sp = 0;
	stuffReturn sr;
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
			if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
				std::cout << "Usage:\nThNeedle <options> <file>\n\n" << endl;
				std::cout << "[-h, --help][-c, --cli]\n\n" << endl;
				std::cout << "options:" << endl;
				std::cout << "\t-h, --help       \tDisplay this screen" << endl;
				std::cout << "\t-c, --cli        \tDisplay the CLI(Command Line Interface)" << endl;
				std::cout << "\t-red, --red-check\tDisplay redundancy of phrases used in document" << endl;
				std::cout << "\t-l, --legend     \tDisplay legend to understand color coding for\n\t\
			output" << endl;
				OPT = argv[i];
				sr.pauz();
			}
			if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--cli") == 0)
				TF = true;
			if (strcmp(argv[i], "-red") == 0 || strcmp(argv[i], "--red-check") == 0)
				opti.push_back('r');
			if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--legend") == 0){
				std::cout << "\n\t\t\tLegend\n" << endl;
				std::printf("\e[92m");
				std::cout << "\tGood\n" << endl;
				std::cout << "\tMay need some adjustment, depending on preference\n\n" << endl;
				std::printf("\e[93m");
				std::cout << "\tOkay\n" << endl;
				std::cout << "\tNeeds some adjustment because of multiple uses of\n\tsame words\n\n" << endl;
				std::printf("\e[31m");
				std::cout << "\tBad\n" << endl;
				std::cout << "\tNeeds adjustment, too many instances of this/these\n\tword(s)" << endl;
				std::printf("\e[0m");
			}
		}
		for (int i = 4; i >= 0; i--)
			inpt01[4-i] = argv[argc-1][strlen(argv[argc-1])-i];
		inpt01[4] = '\0';
	}
	//INTAKE:END
	if (TF) {
		sr.clr();
		opti.clear();
		while (true) {
			if(!opti.empty())
				opti.clear();
			sr.clr();
			std::cout << "TTTTTTTT HHHH      NNNN NNNN                      DDDD  LLLL" << endl;
			std::cout << "T::::::T H::H      N:::NN::N EEEEEEEE EEEEEEEE    D::D  L::L EEEEEEEE" << endl;
			std::cout << "TTT::TTT H::HHHHHH N::::N::N E::EE::E E::EE::E    D::D  L::L E::EE::E" << endl;
			std::cout << "  T::T   H:::::::H N::N::::N E:::::E  E:::::E   D::::D  L::L E:::::E" << endl;
			std::cout << "  T::T   H::HHH::H N::NN:::N E:E      E:::E    D::DD:D  L::L E:::E" << endl;
			std::cout << "  T::T   H::H H::H N::N N::N E::::::E E::::::E  D::::D  L::L E::::::E" << endl;
			std::cout << "  TTTT   HHHH HHHH NNNN NNNN EEEEEEE  EEEEEEE    DDDDD  LLLL EEEEEEE" << endl;
			std::cout << "\nBy FlakeyKarma\n\n" << endl;
			std::cout << "[0] Regular Output" << endl;
			std::cout << "[1] Redundancy Check(RedCheck)[BETA]" << endl;
			std::cout << "[2] Legend" << endl;
			std::cout << "[3] About" << endl;
			std::cout << "[4] Help" << endl;
			std::cout << "[x] Exit" << endl;
			std::cout << "\nFK> ";
			cin >> inpt01[0];
			switch (inpt01[0]) {
			//Regular output
			case '0':
				sr.clr();
				while(1){
					std::cout << "FK> Enter directory to file: ";
					cin >> fil;
					if(fil == "ls"){
						system("ls");
					}else{
						break;
					}
				}
				sr.outP(fil, argc, opti);
				sr.pauz();
				break;
			//RedCheck
			case '1':
				sr.clr();
				while(1){
					std::cout << "FK> Enter directory to file: ";
					cin >> fil;
					if(fil == "ls"){
						system("ls");
					}else{
						break;
					}
				}
				opti.push_back('r');
				sr.outP(fil, argc, opti);
				sr.pauz();
				break;
			//Legend
			case '2':
				sr.clr();
				std::cout << "\n\t\t\tLegend\n" << endl;
				std::printf("\e[92m");
				std::cout << "\tGood\n" << endl;
				std::cout << "\tMay need some adjustment, depending on preference\n\n" << endl;
				std::printf("\e[93m");
				std::cout << "\tOkay\n" << endl;
				std::cout << "\tNeeds some adjustment because of multiple uses of\n\tsame words\n\n" << endl;
				std::printf("\e[31m");
				std::cout << "\tBad\n" << endl;
				std::cout << "\tNeeds adjustment, too many instances of this/these\n\tword(s)" << endl;
				std::printf("\e[0m");
				sr.pauz();
				break;
			//About
			case '3':
				sr.clr();
				std::cout << "\n\n\\\\About" << endl;
				std::cout << "\n\\\\I started needing to make this program when I found myself trying\
								\n  finish a ten-page-paper far too late. Albeit, that was a struggle\
								\n  innate of itself, the main problem for me was trying to find out if\
								\n  I needed to change up the wordage used. Different words used show\
								\n  the variance in one\'s vocabulary and that's beneficial to prove a\
								\n  point. Sometimes, you also need a little \"umf\".. ya know?\n\
								\n  There you go\n\
								\n  -FlakeyKarma\n\n" << endl;
				sr.pauz();
				break;
			//Help
			case '4':
				sr.clr();
				std::cout << "Usage:\nThNeedle <options> <file>\n\n" << endl;
				std::cout << "[-h, --help][-c, --cli]\n\n" << endl;
				std::cout << "options:" << endl;
				std::cout << "\t-h, --help       \tDisplay this screen" << endl;
				std::cout << "\t-c, --cli        \tDisplay the CLI(Command Line Interface)" << endl;
				std::cout << "\t-red, --red-check\tDisplay redundancy of phrases used in document" << endl;
				std::cout << "\t-l, --legend     \tDisplay legend to understand color coding for\n\t\
			output" << endl;
				sr.pauz();
				break;
			//Exit
			case 'x':
				sr.clr();
				std::cout << "-=goodbye=-" << endl;
				exit(0);
			}
		}
	}

	if (strcmp(inpt01, ".txt") != 0 && !TF)
		exit(0);
	std::cout << "\nThNeedle" << endl;
	std::cout << "\nBy FlakeyKarma\n\n" << endl;
	sr.outP(argv[argc-1], argc, opti);
	std::cout << "\n\n--=goodbye=--\n\n" << endl;
	return 0;
}