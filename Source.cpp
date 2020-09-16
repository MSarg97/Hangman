#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//rot13

/*string decrypt(string str, int key)
{
	string str1 = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
			str1 += static_cast<char>((str[i] + 26 - key - 'A') % 26 + 'A');
		else if (islower(str[i]))
			str1 += static_cast<char>((str[i] + 26 - key - 'a') % 26 + 'a');
		else
			str1 += " ";
	}
	return str1;
}

string encrypt(string str, int key)
{
	string str1 = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
			str1 += static_cast<char>((str[i] + key - 'A') % 26 + 'A');
		else if (islower(str[i]))
			str1 += static_cast<char>((str[i] + key - 'a') % 26 + 'a');
		else
			str1 +=  " ";
	}
	return str1;
}

int main()
{
	string str = "Hello World";

	cout << "Initial message: " << str << endl;
	cout << "Encrypted message: " << encrypt(str, 13) << endl;
	cout << "Decrypted message: " << decrypt(encrypt(str, 13), 13) << endl;
	return 0;
}*/

//Words Ending in “r” or “ay"

/*int main()
{
	string str[6] = { "Hello", "World", "character", "array array", "Jay", "Dayer" };
	int location1, location2;
	for (int i = 0; i < 6; i++)
	{
		location1 = str[i].find("ay");
		location2 = str[i].find("r");
		if (location1 != -1 || location2 != -1)
			cout << str[i] << endl;
	}
	return 0;
}
*/

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
	//ifstream inFile("HangmanWords.txt", ios::in);
	string hangmanWords[12] = { "story", "driver", "penguin", "quarantine", "wedding", "dog", "sunflower",
								"watermelon", "love", "happiness", "pepper", "hangman" };

	string currentWord("");
	string originalWord("");

	char hangman[12] = { ' ', 'O', ' ', '/', '|', '\\', ' ', '|', ' ', '/', ' ', '\\' };
	int guessNumber[7] = { 2, 4, 5, 6, 8, 10, 12 };
	int wordCount = 0;
	int guessCount = 0;
	int location;
	char character;
	int option = 0;
		
	//while (inFile >> hangmanWords[wordCount])
	//	wordCount++;

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

//Printing string backward
/* main()
{
	string str = "Hello, World!";

	for (int i = str.size() - 1; i >= 0; i--)
		cout << str[i];
	cout << endl;
	string::reverse_iterator it;

	for (it = str.rbegin(); it != str.rend(); it++)
		cout << *it;

	return 0;
}*/

//Counting palindromes and tokenizing strings

/*
bool isPalindrome(string st)
{
	string originalString;
	string reverseString;
	originalString.assign(st);
	reverseString.assign(st);

	int sz = reverseString.size();
	for (int i = 0; i < sz / 2; i++)
		swap(reverseString[i], reverseString[sz - i - 1]);

	if (!originalString.compare(reverseString))
		return true;
	else
		return false;
}

int main()
{
	char str[] = "ono omomo ond";
	char delim[] = " ";
	int countNotPalindrome = 0;
	int countPalindrome = 0;
	char* token = strtok(str, delim);

	while (token)
	{
		if (isPalindrome(token))
			countPalindrome++;
		else
			countNotPalindrome++;
		token = strtok(NULL, delim);
	}

	cout << "Number of palindromes in string: " << countPalindrome << endl;
	cout << "Number of words that are not palindromes in string: " << countNotPalindrome << endl;

	return 0;
}
*/

//Counting number of each vowel and printing total number of vowels in sentence
/*
int main()
{
	char str[] = "can't help falling in love with you";
	int aCount = 0;
	int oCount = 0;
	int eCount = 0;
	int uCount = 0;
	int iCount = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a' || str[i] == 'o' || str[i] == 'e' || str[i] == 'u' || str[i] == 'i' ||
			str[i] == 'A' || str[i] == 'O' || str[i] == 'E' || str[i] == 'U' || str[i] == 'I')
		{
			switch (str[i])
			{
			case 'a':
			case 'A':
				aCount++;
				break;
			case 'o':
			case 'O':
				oCount++;
				break;
			case 'e':
			case 'E':
				eCount++;
				break;
			case 'u':
			case 'U':
				uCount++;
				break;
			case 'i':
			case 'I':
				iCount++;
				break;
			}
		}
	}

	cout << "The sentence is: ";
	for (int i = 0; str[i] != '\0'; i++)
		cout << str[i];
	cout << endl << endl;

	cout << "Number of vowel a in sentence is: " << aCount << endl;
	cout << "Number of vowel o in sentence is: " << oCount << endl;
	cout << "Number of vowel e in sentence is: " << eCount << endl;
	cout << "Number of vowel u in sentence is: " << uCount << endl;
	cout << "Number of vowel i in sentence is: " << iCount << endl;
	cout << "Total number of vowels in sentence is: " << aCount + oCount + eCount + uCount + iCount << endl;

	return 0;
}
*/

//Inserting '******' characters in the exact middle of a string
/*
int main()
{
	string str = "Hello World";
	string addString = "******";
	int middle = str.size() / 2;
	cout << "String before adding '******' characters: " << str << endl;

	str.insert(str.size() / 2, addString);

	cout << "String after adding '******' characters: " << str << endl;


	str.erase(middle, addString.size());

	cout << "String after erasing '******' characters: " << str << endl;
	return 0;
}
*/
//Erasing "by" and "BY" sequences from a string
/*int main()
{
	char str[] = "lullaby aliby stonky wonky nearby chonky";
	char delim[] = " ";
	string stringErased = "";
	char* token = strtok(str, delim);
	string currentString;
	int location;
	int sz = sizeof(str) / sizeof(str[0]);

	currentString = str;
	cout << "String before erasing 'by': ";

	for (int i = 0; i < sz; i++)
		cout << str[i];
	cout << endl;

	while (token)
	{
		currentString = token;
		location = currentString.find("by");

		if (location != -1)
		{
			currentString.erase(location, 2);
			sz -= 2;
		}

		stringErased = stringErased + currentString + " ";
		token = strtok(NULL, delim);
	}

	strcpy(str, stringErased.c_str());
	cout << "String after erasing 'by': " << str << endl;

	return 0;
}*/

//Reversing a string recursively
/*
string reverseString(string str)
{
	static int i;
	if (i < str.size() / 2)
	{
		swap(str[i], str[str.size() - i - 1]);
		i++;
		cout << str << endl;
		str = reverseString(str);
	}
	return str;
}

int main()
{
	string str = "Hello World";
	cout << "String before calling reverseString() function: " << str << endl;
	str = reverseString(str);
	cout << "String after calling reverseString() function: " << str << endl;
}*/

//Calling string's erase function with iterator arguments
/*
int main()
{
	char str[] = "Hello my World";
	string str1 = "";
	int location;
	int end;
	str1 = str;

	cout << "String before erasing 'my' string: " << str1 << endl;

	location = str1.find("my");

	if (location != -1)
	{
		end = str1.size() - location - 2;
		str1.erase(str1.begin() + location, str1.end() - end);
	}

	cout << "String after erasing 'my' string: " << str1 << endl;
	return 0;
}*/

//Generating triangle form from the string "abcdefghijklmnopqrstuvwxyz{"

/*int main()
{
	string str = "abcdefghijklmnopqrstuvwxyz{";
	int curIndex, endIndex, numIndex = 0;

	for (int i = 0; i <= str.size() / 2; i++)
	{
		for (int space = str.size() / 2; space > i; space--)
			cout << "  ";

		curIndex = numIndex - i;

		while (curIndex <= numIndex)
		{
			cout << str[curIndex] << " ";
			curIndex++;
		}

		curIndex = numIndex - 1;
		endIndex = curIndex - i;

		while (curIndex > endIndex)
		{
			cout << str[curIndex] << " ";
			curIndex--;
		}

		numIndex += 2;
		cout << endl;
	}
	return 0;
}*/

//Sorting string using selection sort
/*
int main()
{
	string str[8] = { "Hello", "hello", "chonk", "mail", "hall", "Kitten", "open", "letter" };
	string currentStr;
	int minIndex;
	int j;

	for (int i = 0; i < 8; i++)
		cout << str[i] << endl;

	for (int i = 0; i < 8; i++)
	{
		minIndex = i;
		for (j = i + 1; j < 8; j++)
		{
			if (str[j].compare(str[minIndex]) < 0)
				minIndex = j;
		}

		currentStr.assign(str[minIndex]);
		str[minIndex].assign(str[i]);
		str[i].assign(currentStr);
	}

	cout << endl << "String after selection sorting" << endl << endl;

	for (int i = 0; i < 8; i++)
		cout << str[i] << endl;

	return 0;
}
*/

//Converting C-style strings to int and counting their total
/*
int main()
{
	char a[] = "16";
	char b[] = "160";
	char c[] = "1";
	char d[] = "1600";

	cout << "Total is: " << atoi(a) + atoi(b) + atoi(c) + atoi(d);
	return 0;
}
*/

//Counting the total number of occurences of each letter of the alphabet in the string 
/*int main()
{
	char str[] = "I ponder of something great, My lungs will fill and then deflate, Enhale the fire, exhale desire, I know it's dire my time today, I have this thoughts so often I ough, To replace a slot with things once I bought, Cause somebody stole my CAR RADIO, And now I just sit here in silence";
	int size = sizeof(str) / sizeof(str[0]);

	for (char character = 'a'; character <= 'z'; character++)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (str[i] == character)
				count++;
		}
		cout << "The number of uppercase and lowercase " << character << "-s is: " << count << endl;
	}

	return 0;
}
*/

//Displaying characters for given ASCII codes

/*void printBinary(int);

int main()
{
	cout << setw(15) << right << "Decimal"
		<< setw(15) << right << "Character"
		<< setw(15) << right << "Octal"
		<< setw(16) << right << "Hexadecimal"
		<< setw(16) << right << "Binary\n";

	for (int i = 0; i <= 255; i++)
	{
		cout << setw(15) << right << dec << i << setw(15) << right << 0 << \
			//static_cast<char>(i) <<
			setw(15) << right << oct << i << setw(15) << right << hex << i;
		printBinary(i);
	}
}

void printBinary(int number)
{
	const int size = 8;
	int arr[size] = { 0 };
	int i = 1;

	while (number != 0)
	{
		arr[size - i] = number % 2;
		number /= 2;
		i++;
	}

	cout<< setw(9) << right;
	for (int i = 0; i < 8; i++)
		cout << arr[i];
	cout << endl;
}
*/
