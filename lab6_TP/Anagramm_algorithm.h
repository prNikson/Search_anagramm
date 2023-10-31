#pragma once
#include <iostream>
class Anagramm {
private:
	int numOfWords;
	char** arrOfWords;
	int** numberEquivalWords;
private:
	void QuickSort(int*, int);
	void getNumberEquial();
	bool elInArr(int*, int, int);
	int numberLines(FILE*);
	bool equalityOfArrs(int*, int*, int, int);
	void print();
public:
	Anagramm();
	void checkAnagramm();
	void fileInput(char*);
	void keyboardInput();
};