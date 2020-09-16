#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

//Hangman game

void printHangman(const char hangmanArray[], int currentSize)
{
	for (int i = 0; i < currentSize; i++)
	{
		if (i % 3 == 2)
			cout << hangmanArray[i] << endl;
		else
			cout << hangmanArray[i];
	}
	cout << endl;
}

int main()
{
	string hangmanWords[12] = { "story", "driver", "penguin", "quarantine", "wedding", "dog", "sunflower",
					"watermelon", "love", "happiness", "pepper", "hangman" };

	string currentWord;
	string originalWord;

	char hangman[12] = { ' ', 'O', ' ', '/', '|', '\\', ' ', '|', ' ', '/', ' ', '\\' };
	int guessNumber[7] = { 2, 4, 5, 6, 8, 10, 12 };
	int wordCount = 0;
	int guessCount = 0;
	int location;
	char character;
	int option = 0;
		
	while (!option)
	{
		vector<char> guesses;
		srand(time(nullptr));

		int randIndex = rand() % 11;		
		guessCount = 0;

		currentWord.assign(hangmanWords[randIndex]);
		originalWord.assign(hangmanWords[randIndex]);

		for (int i = 0; i < hangmanWords[randIndex].size(); i++)
			currentWord[i] = 'X';

		cout << "Guess the word: " << currentWord << endl;

		while (originalWord.compare(currentWord))
		{
			if (guessCount == 7)
				break;

			cout << endl << "Enter a letter: ";
			cin >> character;
			guesses.push_back(character);			

			cout << endl;

			for (int i = 0; i < guesses.size(); i++)
				cout << "Guess " << i + 1 << ": " << guesses[i] << endl;

			location = hangmanWords[randIndex].find(character);
			
			for (int i = 0; i < hangmanWords[randIndex].size(); i++)
			{
				if (i == location)
				{
					currentWord[location] = character;
					hangmanWords[randIndex][location] = 'X';
				}
			}

			cout << endl << currentWord << endl;

			if (location == -1)
			{
				cout << endl << "Wrong answer! Now hangman looks like this!" << endl;
				printHangman(hangman, guessNumber[guessCount]);
				guessCount++;
			}
		}

		if (guessCount == 7)
			cout << endl << "You lost! The right word was '" << originalWord <<
			"'!" << endl << "Play again? If yes enter 0, if no enter 1!" << endl;
		else
			cout << endl << "Congratulations! You guessed the word! Play again? If yes enter 0, if no enter 1!" << endl;
		cin >> option;
	}

	return 0;
}
