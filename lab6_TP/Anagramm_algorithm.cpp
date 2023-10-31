#define _CRT_SECURE_NO_WARNINGS
#include "Anagramm_algorithm.h"
#include <iostream>
void Anagramm::QuickSort(int* arr, int len) {
	int i = 0;
	int j = len - 1;
	int mid = arr[len / 2];
	do {

		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		QuickSort(arr, j + 1);
	}
	if (i < len) {
		QuickSort(&arr[i], len - i);
	}
}
Anagramm::Anagramm() :numOfWords(0), arrOfWords(nullptr), numberEquivalWords(nullptr) {}
int Anagramm::numberLines(FILE* file) {
	int numOfLines = 0;
	char ch;
	while (EOF != (ch = getc(file))) {
		if (ch == '\n')
			++numOfLines;
	}
	rewind(file);
	return numOfLines + 1;
}
int Anagramm::fileInput(char* name) {
	FILE* file = fopen(name, "r");
	if (file == NULL) {
		std::cout << "Error opening file" << std::endl;
		return 0;
	}
	numOfWords = numberLines(file);
	arrOfWords = new char* [numOfWords];
	numberEquivalWords = new int* [numOfWords];
	char ch;
	for (int i = 0; i < numOfWords; i++) {
		int count = 0;
		ch = getc(file);
		while (ch != '\n' && ch != EOF)
		{
			count++;
			ch = getc(file);
		}
		arrOfWords[i] = new char[count + 1];
		numberEquivalWords[i] = new int[count + 1];
	}
	rewind(file);
	for (int i = 0; i < numOfWords; i++) {
		fscanf(file, "%s", arrOfWords[i]);
	}
	fclose(file);
	getNumberEquial();
	return 1;
}
void Anagramm::print() {
	std::cout << "Dictionary:" << std::endl;
	for (int i = 0; i < numOfWords; i++) {
		std::cout << arrOfWords[i] << std::endl;
	}
	std::cout << std::endl;
}
void Anagramm::getNumberEquial() {
	for (int i = 0; i < numOfWords; i++) {
		for (int j = 0; j < strlen(arrOfWords[i]); j++) {
			numberEquivalWords[i][j] = (int)arrOfWords[i][j];
		}
	}
	for (int i = 0; i < numOfWords; i++) {
		QuickSort(numberEquivalWords[i], strlen(arrOfWords[i]));
	}
}
bool Anagramm::equalityOfArrs(int* arr1, int* arr2, int len1, int len2) {
	int min = (len1 > len2) ? len2 : len1;
	int flag = 0;
	if (len1 != len2)
		return false;
	else {
		for (int i = 0; i < min; i++) {
			if (arr1[i] == arr2[i])
				flag++;
		}
		return (flag == min);
	}
}
bool Anagramm::elInArr(int* arr, int elem, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == elem)
			return true;
	}
	return false;
}
void Anagramm::checkAnagramm() {
	print();
	int count = 0;
	int flag;
	int NoAnagram = 0;
	int* arr = new int[numOfWords];
	for (int i = 0; i < numOfWords; i++) {
		flag = 0;
		for (int j = i + 1; j < numOfWords; j++) {
			if (equalityOfArrs(numberEquivalWords[i], numberEquivalWords[j], strlen(arrOfWords[i]), strlen(arrOfWords[j]))) {
				NoAnagram++;
				if (!flag) {
					std::cout << "Anagramms:" << std::endl;
					std::cout << arrOfWords[i] << std::endl;
					flag++;
				}
				if (!elInArr(arr, j, numOfWords))
					std::cout << arrOfWords[j] << std::endl;
				arr[count++] = j;
			}
		}
	}
	if (!NoAnagram)
		std::cout << "No anagramms";
}
int Anagramm::keyboardInput() {
	char q[50];
	int num;
	std::cout << "Input count of words: " << std::endl;
	std::cin >> num;
	while (std::cin.fail()) {
		std::cout << "Not number. Try one more" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> num;
	}
	numOfWords = num;
	arrOfWords = new char* [numOfWords];
	numberEquivalWords = new int* [numOfWords];
	for (int i = 0; i < numOfWords; i++) {
		std::cout << "Input a word:" << std::endl;
		std::cin >> q;
		int size = strlen(q);
		if (!validString(q, size)) {
			std::cout << "Non-valid input" << std::endl;
			return 0;
		}
		arrOfWords[i] = new char[size];
		numberEquivalWords[i] = new int[size];
		strcpy(arrOfWords[i], q);
	}
	getNumberEquial();
	return 1;
}
int Anagramm::validString(char* name, int size) {
	for (int i = 0; i < size; i++) {
		if (!((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122)))
			return 0;
	}
}