#include "resources.h"

int main(int argc, char* argv[]) {
	int sz = 0, sp = 0;
	stuffReturn sr;
	char inpt01[5];
	sz = 0;
	string OPT, fil;

	bool TF = false;
	//INTAKE:BEGIN
	if(argc == 1){
		TF = true;
	}
	else{
		for (int i = 1; i < (signed)argc; i++) {
			if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
				std::cout << "Usage:\nThNeedle <options> <file>\n\n" << endl;
				std::cout << "[-h, --help][-g, --gui]\n\n" << endl;
				std::cout << "options:" << endl;
				std::cout << "\t-h, --help\tDisplay this screen" << endl;
				std::cout << "\t-g, --gui \tDisplay the GUI(Generated User Interface)" << endl;
				OPT = argv[i];
				sr.pauz();
			}
			if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "--gui") == 0)
				TF = true;
		}
		for (int i = 4; i >= 0; i--)
			inpt01[4-i] = argv[argc-1][strlen(argv[argc-1])-i];
		inpt01[4] = '\0';
	}
	//INTAKE:END
	if (TF) {
		sr.clr();
		while (true) {
			sr.clr();
			std::cout << "TTTTTTTT HHHH      NNNN NNNN                      DDDD  LLLL" << endl;
			std::cout << "TT::::TT H::H      N:::NN::N EEEEEEEE EEEEEEEE    D::D  L::L EEEEEEEE" << endl;
			std::cout << "TTT::TTT H::HHHHHH N::::N::N E::EE::E E::EE::E    D::D  L::L E::EE::E" << endl;
			std::cout << "  T::T   H:::::::H N::N::::N E:::::E  E:::::E   D::::D  L::L E:::::E" << endl;
			std::cout << "  T::T   H::HHH::H N::NN:::N E:E      E:::E    D::DD:D  L::L E:::E" << endl;
			std::cout << "  T::T   H::H H::H N::N N::N E::::::E E::::::E  D::::D  L::L E::::::E" << endl;
			std::cout << "  TTTT   HHHH HHHH NNNN NNNN EEEEEEE  EEEEEEE    DDDDD  LLLL EEEEEEE" << endl;
			std::cout << "\nBy FlakeyKarma\n\n" << endl;
			std::cout << "[0] Regular Output" << endl;
			std::cout << "[1] Redundancy Check" << endl;
			std::cout << "[2] About" << endl;
			std::cout << "[3] Help" << endl;
			std::cout << "[x] Exit" << endl;
			std::cout << "\nFK> ";
			cin >> inpt01[0];
			switch (inpt01[0]) {
			case '0':
				std::cout << "FK> Enter directory to file: ";
				cin >> fil;
				sr.outP(fil, argc);
				sr.pauz();
				break;
			case '1':
				sr.clr();
				std::cout << "\\\\UNDER CONSTRUCTION\\\\" << endl;
				std::cout << "\\\\SORRY TO SAY\\\\" << endl;
				sr.pauz();
				break;
			case '2':
				sr.clr();
				std::cout << "\\\\UNDER CONSTRUCTION\\\\" << endl;
				std::cout << "\\\\SORRY TO SAY\\\\" << endl;
				sr.pauz();
				break;
			case '3':
				sr.clr();
				std::cout << "Usage:\nThNeedle <options> <file>\n\n" << endl;
				std::cout << "[-h, --help][-g, --gui]\n\n" << endl;
				std::cout << "options:" << endl;
				std::cout << "\t-h, --help\tDisplay this screen" << endl;
				std::cout << "\t-g, --gui \tDisplay the GUI(Generated User Interface)" << endl;
				sr.pauz();
				break;
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
	sr.outP(argv[argc-1], argc);
	std::cout << "\n\n--=goodbye=--\n\n" << endl;
	return 0;
}