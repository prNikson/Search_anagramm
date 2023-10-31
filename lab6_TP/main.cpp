#include <iostream>
#include "Anagramm_algorithm.h"
int main() {
	Anagramm ana;
	//ana.fileInput(const_cast<char*>("1.txt"));
	ana.keyboardInput();
	ana.checkAnagramm();
	return 0;
}