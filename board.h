//board.h
#include <iostream>
#include <stdlib.h>
#include <cstring>

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#define WIDTH 4
#define LENGTH 4

using namespace std;

	void printCorrectWords(string* outputDictWords);
	void checkBoard(char boardLetters[LENGTH][WIDTH], string* dictWords, string* outputDictWords);
	void compare(char boardLetters[][WIDTH], string* dictWords, string* outputDictWords, int letterIndex, int row, int col, int usedLetters[][WIDTH], string currString, int wordsToCheck, int& indexOfWord);
	int getNeightbors(int x, int y, int usedLetters[][WIDTH], int * locations);
	int checkString(string currentString, string* dictStrings, string* outputDictWords, int wordsToCheck, int &wordIndex);

	

#endif // BOARD_INCLUDED
