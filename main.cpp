#include "resources.h"

int main(int argc, char* argv[]) {
	try{
		std::ifstream FL;
		int sz = 0, sp = 0;
		Complementary* th = new Complementary, *thNd = new Complementary;
		char inpt01[5], inpt02[1];
		sz = 0;
		std::string fil, ansr;
		bool TF = false, dl = 1, othr = 0, CLI = 0;
		//INTAKE:BEGIN
		if(argc == 1){
			TF = true;
		}
		else{
			for (int i = 1; i < (signed)argc; i++) {
				if (!strcmp(argv[i], "-th") || !strcmp(argv[i], "--thneedle")){
					th->opChc[0] = 1;
				}
				if (!strcmp(argv[i], "-o") || !strcmp(argv[i], "--out-par")){
					th->opChc[4] = 1;
				}
				if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
					std::printf("Usage:\nMagnifEye <options> <file>\n\n\n");
					std::printf("[-h, --help][-c, --cli][-th, --thneedle][-red, --redcheck][-l, --legend][-w ,--WeBI ][-o ,--out-par ]\n\n\n");
					std::printf("options:\n");
					std::printf("\t-h,   --help\t\tDisplay this screen\n");
					std::printf("\t-th,  --thneedle\tDisplay similar words\n");
					std::printf("\t-c,   --cli\t\tDisplay the CLI(Command Line Interface)\n");
					std::printf("\t-red, --redcheck\tDisplay redundancy of phrases used in document\n");
					std::printf("\t-dc,  --doc-com\t\tDisplay similar phrases and words upon two documents\n");
					std::printf("\t-l,   --legend\t\tDisplay legend to understand color coding for\n\toutput\n");
					std::printf("\t-w,   --webi\t\tDisplay information on a web interface\n");
					std::printf("\t-o,   --out-par\t\tOutput info into parsed version\n");
					std::printf("\t-raw, --raw-read:<T|S>\tRead from file raw input\n");
					std::printf("\t\tT (default)\t\"Thorough\" read of the file to compare words/phrases similar in characters, but display raw\n");
					std::printf("\t\tS\t\t\"Skim\" the file to compare words/phrases similar in case and characters\n");
				}
				if (!strcmp(argv[i], "-c") || !strcmp(argv[i], "--cli"))
					TF = true;
				if (!strcmp(argv[i], "-red") || !strcmp(argv[i], "--redcheck"))
					th->opChc[1] = 1;
				if (!strcmp(argv[i], "-l") || !strcmp(argv[i], "--legend")){
					std::printf("\n\t\t\tLegend\n\n");
					std::printf("\t\e[92mGood\n\n");
					std::printf("\tMay need some adjustment, depending on preference\n\n\n");
					std::printf("\t\e[93mOkay\n\n");
					std::printf("\tNeeds some adjustment because of multiple uses of\n\tsame words\n\n\n");
					std::printf("\t\e[31mBad\n\n");
					std::printf("\tNeeds adjustment, too many instances of this/these\n\tword(s)\e[0m\n");
				}
				if (!strcmp(argv[i], "-dc") || !strcmp(argv[i], "--doc-com")){
					th->opChc[2] = 1;
				}
				if (!strcmp(argv[i], "-w") || !strcmp(argv[i], "--webi")){
					th->opChc[4] = 1;
				}
				if (!strcmp(argv[i], "-raw")){
					i++;
					switch(argv[i][0]){
						case 'T':
						case 't':
							th->opChc[5] = 1;
							break;
						case 'S':
						case 's':
							th->opChc[5] = 1;
							th->rawRead = 1;
							break;
					}
				}
				if (!strcmp(argv[i], "--raw-read:T")){
					th->opChc[5] = 1;
				}
				if (!strcmp(argv[i], "--raw-read:S")){
					th->opChc[5] = 1;
					th->rawRead = 1;
				}
			}
			for (int i = 4; i >= 0; i--)
				inpt01[4-i] = argv[argc-1][strlen(argv[argc-1])-i];
			inpt01[4] = '\0';
		}
		//INTAKE:END
		if (TF) {
			th->clr();
			while (true) {
				if(dl){
					thNd = new Complementary;
					dl = 0;
				}
				thNd->CLI = CLI;
				FL.open("downloadTF.txt");
				while(getline(FL, ansr)){
					if(ansr == "NOT-YET" || ansr == "NO" || ansr == "YES"){
						break;
					}
				}
				th->clr();
				std::printf(" __   __                         ___  ____\n");
				std::printf("|  \\ /  |                       / __||  __|\n");
				std::printf("|   `   | _____  ____   ___    _||_  |  _|      _  ____\n");
				std::printf("|  |V|  ||     |/    ||V _ |o |_  _| | |  \\\\   / /|  []|\n");
				std::printf("|  | |  ||[] | ||  []|| / |||\\  ||   | |__ \\\\ / / | \\__|\n");
				std::printf("|__| |__||___|\\| \\_  ||_| |||_| ||   |____| \\` /  |____/\n");
				std::printf("                  _| |                      / /\n");
				std::printf("                 [__/                      / /\n");
				std::printf("                                          /_/\n");
				std::printf("\n%s\n", th->ver().c_str());
				std::printf("By FlakeyKarma\n\n\n");
				std::printf("[0] Regular Output\n");
				std::printf("[1] Redundancy Check \e[91m(RedCheck)\e[0m\n");
				std::printf("[2] Document Comparison \e[96m(DoCo)\e[0m\n");
				std::printf("[3] Web-Based Interface \e[93m(WeBI)\e[0m\n");
				std::printf("[F] Enable Output to temp.txt file?");
				thNd->TFswitch(thNd->CLI);
				std::printf("[O] Other\n");
				std::printf("[X] Exit\n");
				std::printf("\nMEye> ");
				th->libInstl(&ansr);
				std::scanf(" %c", inpt01);
				inpt01[1] = '\0';
				switch (inpt01[0]) {
				//Regular output
				case '0':
					th->clr();
					fil = thNd->filIn();
					thNd->opChc[0] = 1;
					thNd->MagnifEye(fil);
					dl = 1;
					th->pauz();
					inpt01[0] = '\0';
					CLI = thNd->CLI;
					break;
				//RedCheck
				case '1':
					th->clr();
					fil = thNd->filIn();
					thNd->opChc[1] = 1;
					thNd->MagnifEye(fil);
					dl = 1;
					th->pauz();
					inpt01[0] = '\0';
					CLI = thNd->CLI;
					break;
				//DoCo
				case '2':
					th->clr();
					fil = thNd->filIn();
					thNd->opChc[2] = 1;
					thNd->MagnifEye(fil);
					dl = 1;
					th->pauz();
					inpt01[0] = '\0';
					CLI = thNd->CLI;
					break;
				//weBI
				case '3':
					th->clr();
					fil = thNd->filIn();
					if(thNd->GUD(fil)){
						thNd->WeBI();
						thNd->MagnifEye(fil);
					}
					dl = 1;
					th->pauz();
					inpt01[0] = '\0';
					CLI = thNd->CLI;
					break;
				//(De)Select appending info to temp file
				case 'f':
				case 'F':
					thNd->clr();
					inpt01[0] = '\0';
					dl = 1;
					CLI = !thNd->CLI;
					break;
				//Other
				case 'O':
				case 'o':
					while(true){
						th->clr();
						std::printf("\n\n\t\t-<OTHER>-\n\n\n");
						std::printf("=============>[0] Legend\n");
						std::printf("=============>[1] About\n");
						std::printf("=============>[2] Help\n");
						std::printf("=============>[3] Check Files\n");
						std::printf("=============>[4] Install Libraries :: Current setting=%s\n", ansr.c_str());
						std::printf("=============>[x] Exit\n");
						std::printf("\n========>MEye> \n");
						std::scanf(" %c", inpt02);
						inpt01[1] = '\0';
						switch(inpt02[0]){
							//Legend
							case '0':
								th->clr();
								std::printf("\n\t\t\tLegend\n\n");
								std::printf("\t\e[92mGood\n\n");
								std::printf("\tMay need some adjustment, depending on preference\n\n\n");
								std::printf("\t\e[93mOkay\n\n");
								std::printf("\tNeeds some adjustment because of multiple uses of\n\tsame words\n\n\n");
								std::printf("\t\e[31mBad\n\n");
								std::printf("\tNeeds adjustment, too many instances of this/these\n\tword(s)\e[0m\n");
								th->pauz();
								inpt02[0] = '\0';
								break;
							//About
							case '1':
								th->clr();
								std::printf("\n\n\\\\About\n");
								std::printf("\n\\\\I started needing to make this program when I found myself trying\
												\n  finish a ten-page-paper far too late. Albeit, that was a struggle\
												\n  in of itself, the main problem for me was trying to find out if\
												\n  I needed to change up the wordage used. Different words used show\
												\n  the variance in one\'s vocabulary and that's beneficial to prove a\
												\n  point. Sometimes, you also need a little \"umf\".. ya know?\n\
												\n  There you go\n\
												\n  -FlakeyKarma\n\n\n");
								th->pauz();
								inpt02[0] = '\0';
								break;
							//Help
							case '2':
								th->clr();
								th->help();
								th->pauz();
								inpt02[0] = '\0';
								CLI = thNd->CLI;
								break;
							//Check for other files that may be needed for functions
							case '3':
								th->clr();
								th->mkFil();
								th->pauz();
								inpt02[0] = '\0';
								CLI = thNd->CLI;
								break;
							//What to install
							case '4':
								th->clr();
								th->setDownload();
								FL.open("downloadTF.txt");
								while(getline(FL, ansr)){
									if(ansr == "YES"){
										th->Downloadz();
										break;
									}
								}
								FL.close();
								break;
							//Exit
							case 'x':
							case 'X':
								th->clr();
								othr = 1;
								break;
						}
						th->pauz();
						inpt01[0] = '\0';
						if(othr) break;
					}
					break;
				//Exit
				case 'x':
				case 'X':
					th->clr();
					std::printf("--=goodbye=--\n");
					std::exit(0);
				}
				inpt01[0] = '\0';
			}
		}
		if (strcmp(inpt01, ".txt") && !TF)
			std::exit(0);
		std::printf("   \nMagnifEye %s\n", th->ver().c_str());
		std::printf("//          \\\\\n");
		std::printf("  //   _   \\\\\n");
		std::printf("     /` `\\\n");
		std::printf("   <' (O) `>\n");
		std::printf("     \\,_,/\n");
		std::printf("  \\\\       //\n");
		std::printf("\\\\           //\n");
		std::printf("\n\n\n\n\nBy FlakeyKarma\n\n\n");
		if(argc == 2) th->opChc[0] = 1;
		th->MagnifEye(argv[argc-1]);
		std::printf("\n\n--=goodbye=--\n\n\n");
		return 0;
	}catch(int e){
		std::printf("\n\n--=goodbye=--\e[0m\n\n\n");
	}
}
