#include <iostream>
#include "Anagramm_algorithm.h"
int main() {
	char q[1];
	char* name = new char[30];
	Anagramm ana;
	while (true) {
		std::cout << "Select a operating mode: f - file input, k - keyboard input, q - exit from program" << std::endl;
		std::cin >> q;
		switch (q[0]) {
		case 'q':
			std::cout << "Exit";
			break;
		case 'f':
			std::cout << "Type a name of file:" << std::endl;
			std::cin >> name;
			if(ana.fileInput(name))
				ana.checkAnagramm();
			break;
		case 'k':
			if(ana.keyboardInput())
				ana.checkAnagramm();
			break;
		default:
			std::cout << "Incorrect input. Try one more" << std::endl;
			break;
		}
	}
	return 0;
}