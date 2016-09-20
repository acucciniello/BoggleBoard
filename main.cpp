//main.cpp
#include "board.h"


using namespace std;


int main()
{
	char board[LENGTH][WIDTH] = {{'E','E','C','A'},
           						 {'A','L','E','P'},
           						 {'H','N','B','O'},
           						 {'Q','T','T','Y'}};

    string dict[WIDTH] = {"CENT","QWERTY","BLEEP","FISH"};

    string* outputDict = new string[LENGTH];

	checkBoard(board, dict, outputDict);

	delete [] outputDict;

    return 0;
}

