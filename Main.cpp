#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


int main()
{

	//encrypted message must be in text file named message.txt
	ifstream message;
	message.open("message.txt");
	ofstream file;
	file.open("transpositionDecrypts.txt");


	bool solved = false, outOfOptions = false;
	int method;

	char alphabet[78] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	string encrypted, decrypted,holder;

	while (message)
	{
		getline(message, holder);

		encrypted=encrypted + holder;

	}
	int count = 0;
	while (encrypted[count] != '\0')
	{
		count++;
	}
	

	cout << "please choose decrypting method. (0,1,2,3...etc)" << endl << "Method 1: linear transposition" << "Method 2: random assignment transposition" << "Method 3: ???" << endl << "Method 0: ALL" << endl;
	cin >> method;



	//Method 1: linear forward and backward transposition
	//outputs all 50 possibilities to a text file named transpositionDecrypts.txt with no spaces
	if ( method == 1 || method == 0)
	{
		for (int z = 0; z <= 25; z++)
		{
			for (int i = 0; i <= count; i++)
			{
				for (int j = 26; j <= 51; j++)
				{
					if (encrypted[i] == alphabet[j])
					{
						decrypted[i] = alphabet[j - z];

					}
				}
				file << decrypted;
			}

			file << endl<<endl;
		}


		for (int z = 0; z <= 25; z++)
		{

			for (int i = 0; i <= count; i++)
			{
				for (int j = 26; j <= 51; j++)
				{
					if (encrypted[i] == alphabet[j])
					{

						decrypted[i] = alphabet[j + z];
					}
				}
				file << decrypted;
			}
			file << endl<<endl;
		}

		file.close();
	}
	//end method 1;


		//Method 2: random transposition
	//results in 26! possibilities since each letter can get assigend any letter, including itself.
	//this method requires some kind of parsing by an algorithm to reduce readable outputs
	//solution part 1: look for most used letters and map that letter to 'e' (the most common letter in english communication). this reduces the list of possible transpositions. 
	//solution part 2: look for frequent combinations of letters (could be QU or TH for example  once decoded)
	//(only works for large texts)
	if (method == 2 || method == 0)
	{

		file.open("randomDecryption.txt");

	}












	return 0;
}



//encryption funciton that uses a chosen alphabetical transfer method. 
void randomEncryption(string original, string key)
{
	string key; //fill with new alphabet that is key


	ifstream file;
	file.open("message.txt");
	ofstream code;
	code.open("encrypted.txt");
	string encrypted, message;

	getline(file, message);

	char alphabet[26] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	bool xferd;
	for (int i = 0; i < size(original); i++)
	{
		xferd = false;
		int count = 0;
		while (!xferd)
		{
			if (original[i] == alphabet[count])
			{
				encrypted[i] = key[count];
				xferd = true;
			}
			else
				count++;


		}


	}





}









//function to check for common words and pick out most likely answer. 
//under construction

/*
void wordcheck(char* dcpt, char* word, ifstream file)
{
	int E = 0;

	ifstream file;
	file.open(word[E] + ".txt");
	while (isWord == true)
	{
		for(int i=0; i<)
	}


	file.open(word[E] + ".txt");
	string line;
	char* curWord; 
	bool isWord = true;
	strncat(curWord, &dcpt[E], 1);
	char* holder;
	holder = getline()
	string line;

	while (isWord)
	{
		

		for (int j = 0; j <= Wsize; j++)
		{
			if (line.find(curWord) != string::npos)
			{
				isWord = true;
			}
			else
				isWord = false;
		}
		E++;
	}

	file.close();
}
*/