#include <iostream>
#include <list>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

char wheel[26 + 10 + 4] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '?', '.'};
	
char board[6][22]{' '};

int search(char input)
{
	if (islower(input))
	{
		input = (int)input - 32;
	}

	for (int i = 0; i < sizeof(wheel); i++)
	{
		if (input == wheel[i])
		{
			return i;
		}
	}

	return -1;
}

void print()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

int main()
{
	char input;
	int i = 0, j = 0;
	fstream file;
	file.open("tiktokbs.txt");

	if (file.is_open())
	{
		while (file.get(input))
		{
			if (search(input) != -1)
			{
				board[i][j] = wheel[search(input)];
				j++;

				if (j == 22)
				{
					j = 0;
					i++;
				}
			}
		}
		

		print();
	}

	else
	{
		cout << "You fucked up";
	}

	file.close();
	return 0;
}