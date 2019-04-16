#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <windows.h>
#include "resources.h"

int main(int argc, char* argv[]) {
	int sz = 0, sp = 0;
	stuffReturn sr;
	char inpt01[5];
	sz = 0;
	string OPT, fil;

	bool TF = false;
	//INTAKE:BEGIN
	for (int i = 1; i < (signed)argc; i++) {
		if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
			cout << "Usage:\nThNeedle <options> <file>\n\n" << endl;
			cout << "[-h, --help][-g, --gui]\n\n" << endl;
			cout << "options:" << endl;
			cout << "\t-h, --help\tDisplay this screen" << endl;
			cout << "\t-g, --gui \tDisplay the GUI(Generated User Interface)" << endl;
			OPT = argv[i];
		}
		if (strcmp(argv[i], "-g") == 0)
			TF = true;
	}
	for (int i = 4; i >= 0; i--)
		inpt01[4-i] = argv[argc-1][strlen(argv[argc-1])-i];
	inpt01[4] = '\0';
	//INTAKE:END
	if (TF) {
#ifdef _WIN32
		system("CLS");
#else
		system("clear");
#endif
		while (true) {
			cout << "TTTTTTTT HHHH      NNNN NNNN                      DDDD  LLLL" << endl;
			cout << "TT::::TT H::H      N:::NN::N EEEEEEEE EEEEEEEE    D::D  L::L EEEEEEEE" << endl;
			cout << "TTT::TTT H::HHHHHH N::::N::N E::EE::E E::EE::E    D::D  L::L E::EE::E" << endl;
			cout << "  T::T   H:::::::H N::N::::N E:::::E  E:::::E   D::::D  L::L E:::::E" << endl;
			cout << "  T::T   H::HHH::H N::NN:::N E:E      E:::E    D::DD:D  L::L E:::E" << endl;
			cout << "  T::T   H::H H::H N::N N::N E::::::E E::::::E  D::::D  L::L E::::::E" << endl;
			cout << "  TTTT   HHHH HHHH NNNN NNNN EEEEEEE  EEEEEEE    DDDDD  LLLL EEEEEEE" << endl;
			cout << "\nBy FlakeyKarma\n\n" << endl;
			cout << "[0] Regular Output" << endl;
			cout << "[1] Redundancy Check" << endl;
			cout << "[2] Exit" << endl;
			cout << "\nFK> ";
			cin >> inpt01[0];
			switch (inpt01[0]) {
			case '0':
				cout << "FK> Enter directory to file: ";
				cin >> fil;
				sr.outP(fil, argc);
				system("pause");
				system("CLS");
				break;
			case '1':
				cout << "\\\\UNDER CONSTRUCTION\\\\" << endl;
				cout << "\\\\SORRY TO SAY\\\\" << endl;
				break;
			case '2':
				system("CLS");
				cout << "goodbye";
				exit(0);
			}
		}
	}

	if (strcmp(inpt01, ".txt") != 0 && !TF)
		exit(0);
	cout << "\nThNeedle" << endl;
	cout << "\nBy FlakeyKarma\n\n" << endl;
	sr.outP(argv[argc-1], argc);
	cout << "goodbye";
	return 0;
}