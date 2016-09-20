//board.cpp
#include "board.h"

using namespace std;

//Iterates through the letters on the board once for each word in the dictionary 
void checkBoard(char boardLetters[][WIDTH], string* dictWords, string* outputDictWords)
{
	int  j = 0;
	int i = 0;
	int wordsToCheck = 0;
	//Keeps track if a word was used 
	int isUsed[LENGTH][WIDTH] = {0};
	//Knows which letter of the current word in the dictionary we are on
	int letterIndex = 0;
	//keeps track of outout word's index
	int wordIndex = 0;
	//holds the string to be placed in the output array
	string currentString = "";


	for(wordsToCheck = 0; wordsToCheck < LENGTH; wordsToCheck++)
	{
		for(i =0; i< LENGTH; i++)
		{
			for(j = 0; j < WIDTH; j++)
			{
				compare(boardLetters, dictWords, outputDictWords, letterIndex, i, j, isUsed, currentString, wordsToCheck, wordIndex);
				letterIndex = 0;
				isUsed[i][j] = 0;
				currentString = "";

			}
		}
	}
	printCorrectWords(outputDictWords);
}



//Prints the output array with words found in the boggle board
void printCorrectWords(string* outputDictWords)
{
	int  m;
	for(m = 0; m < LENGTH; m++)
	{
		cout << outputDictWords[m] << endl;
	}
}

//Checks the letter in the boggle board with the current letter in the dictionary
//Calls itself if a letter matched once the neighbors are found 
void compare(char boardLetters[][WIDTH], string* dictWords, string* outputDictWords, int letterIndex, int row, int col, int usedLetters[][WIDTH], string currString, int wordsToCheck, int &indexOfWord)
{
	int maxLocations = 16;
	int amount = 0;
	int* neighbors = new int[maxLocations];
	int currentLetIndex = letterIndex;

	if (boardLetters[row][col] == dictWords[wordsToCheck].at(letterIndex))
		{
			//Append the letter that matched to the current string and increase the index by 1
			letterIndex = letterIndex + 1;
			currString = currString + boardLetters[row][col];

			//Show that character at [row][col] is now visited
			usedLetters[row][col] = 1;
			//count the amount of neighboring cells to loop through (2 per locaiton for row and column value)
			amount = getNeightbors(row, col, usedLetters, neighbors);

			for(int k = 0; k < amount; k = k + 2)
			{
				//Check if amount of letters are less than or equal to the length of the current word 
				if(letterIndex < dictWords[wordsToCheck].length())
				{
					//Call compare passing in the new value for a neighbor
					compare(boardLetters, dictWords, outputDictWords, letterIndex, neighbors[k], neighbors[k+1], usedLetters, currString, wordsToCheck, indexOfWord);
					
				}
				
			}
			//Decrement the letterIndex to remove false increments for characters that were though to be used but not anymore
			letterIndex = letterIndex - 1;
		}

	indexOfWord = checkString(currString, dictWords, outputDictWords, wordsToCheck, indexOfWord);
	delete [] neighbors;
}

//Returns an amount of coordinates for letters in the boggle board that are neighbors of the current cell
//The actual locations are stored in int * locations
int getNeightbors(int x, int y, int usedLetters[][WIDTH], int * locations)
{
	int count = 0;
	for(int a = x - 1; a <= x + 1 &&  a < LENGTH; a++)
	{
		for(int b = y - 1; b <= y + 1 &&  b < WIDTH; b++)
		{
			if(a>=0 && b>=0 && usedLetters[a][b] == 0)
			{
				locations[count] = a;
				count++;
				locations[count] = b;
				count++;
			}
		}
	}
	return count;
}

//Compares the currentString with the string in the dictionary to see if the word is completed and can be placed in the output array
int checkString(string currentString, string* dictStrings, string* outputDictWords, int wordsToCheck, int &wordIndex)
{
	if(currentString.compare(dictStrings[wordsToCheck]) == 0 && outputDictWords[wordIndex-1].compare(currentString) != 0)
	{
		outputDictWords[wordIndex] = currentString;
		wordIndex++;
	}
	return wordIndex;
}