/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 13

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAVE_SIZE 13
#pragma warning(disable : 4996)

void InitialiseStory(char* paragraph)
{

	char temp[2000] = ("Whilst exploring the caves, searching for ancient artifacts,\nan earthquake caused the ceiling to become uneasy, resulting\nin damages to the cave. Find the treasure, block the holes\nusing the scattered boulders and make sure not to fall in!\nYour safety is in your own hands.\n");
	strcpy(paragraph, temp);
}

void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char* layout)
{
	char temp[CAVE_SIZE][CAVE_SIZE];

	int k = 0;

	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (layout[k] == 49)
			{
				temp[i][j] = 1;
			}
			else if (layout[k] == 48)
			{
				temp[i][j] = 0;
			}
			else if (layout[k] == 69)
			{
				temp[i][j] = 2;
			}
			k++;
			cave[i][j] = temp[i][j];
		}
	}
}

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	char temp[CAVE_SIZE][CAVE_SIZE];

	for (int i = 0; i < CAVE_SIZE; i++)
	{

		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 1)
			{
				temp[i][j] = '#';
			}
			else if (cave[i][j] == 0)
			{
				temp[i][j] = ' ';
			}
			else if (cave[i][j] == 2)
			{
				temp[i][j] = ' ';
			}
			else if (cave[i][j] == 79)
			{
				temp[i][j] = 'O';
			}
			else if (cave[i][j] == 88)
			{
				temp[i][j] = 'X';
			}
			else if (cave[i][j] == 42)
			{
				temp[i][j] = '*';
			}
			else if (cave[i][j] == 43)
			{
				temp[i][j] = '+';
			}

			printf("%c", temp[i][j]);

		}
		printf("\n");
	}
}

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i;
	int j;
	int exit_counter = 0;
	int wall_counter = 0;
	int counter = 0;

	for (i = 0; i < CAVE_SIZE; i++)
	{
		if (cave[i][0] == 1)
		{
			wall_counter++;
		}
		if (cave[i][0] == 2)
		{
			exit_counter++;
		}
		if (cave[i][CAVE_SIZE - 1] == 1)
		{
			wall_counter++;
		}
		if (cave[i][CAVE_SIZE - 1] == 2)
		{
			exit_counter++;
		}
	}
	for (j = 0; j < CAVE_SIZE; j++)
	{
		if (cave[0][j] == 1)
		{
			wall_counter++;
		}
		if (cave[0][j] == 2)
		{
			exit_counter++;
		}
		if (cave[9][j] == 1)
		{
			wall_counter++;
		}
		if (cave[9][j] == 2)
		{
			exit_counter++;
		}
	}

	if (cave[0][0] == 1)
	{
		counter++;
	}
	if (cave[0][0] == 2)
	{
		counter++;
	}
	if (cave[0][9] == 1)
	{
		counter++;
	}
	if (cave[0][9] == 2)
	{
		counter++;
	}
	if (cave[9][0] == 1)
	{
		counter++;
	}
	if (cave[9][0] == 2)
	{
		counter++;
	}
	if (cave[9][9] == 1)
	{
		counter++;
	}
	if (cave[9][9] == 2)
	{
		counter++;
	}

	int total = wall_counter + exit_counter - counter;


	if (total >= 36)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{

	int exit_counter = 0;

	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{

			if (cave[i][j] == 2)
			{
				exit_counter++;
			}
		}
	}

	if (exit_counter == 1)
	{
		return 1;
	}
	else if (exit_counter != 1)
	{
		return 0;
	}
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int k;
	int l;
	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 2)
			{
				k = i;
				l = j;
			}
		}
	}

	if ((k == 9) & (l == 9))
	{
		return 0;
	}
	else if ((k == 0) & (l == 0))
	{
		return 0;
	}
	else if ((k == 0) & (l == 9))
	{
		return 0;
	}
	else if ((k == 9) & (l == 0))
	{
		return 0;
	}
	return 1;
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char* element)
{
	int temp;


	if (element == "player")
	{
		temp = 10;
	}
	if (element == "boulder")
	{
		temp = 11;
	}
	if (element == "hole")
	{
		temp = 12;
	}
	if (element == "treasure")
	{
		temp = 13;
	}
	int counter = 0;
	if (row > 9)
	{
		return;
	}
	if (col > 9)
	{
		return;
	}
	if (cave[row][col] == 1)
	{
		return;
	}


	if (temp == 10)
	{
		for (int i = 0; i < CAVE_SIZE; i++)
		{
			for (int j = 0; j < CAVE_SIZE; j++)
			{
				if (cave[i][j] == 88)
				{
					counter++;
				}
			}
		}
		if (counter > 0)
		{
			return;
		}
		cave[row][col] = 88;
	}

	if (cave[row][col] == 0)
	{
		if ((temp == 11))
		{
			cave[row][col] = 79;
		}

		if ((temp == 12))
		{
			cave[row][col] = 42;
		}
		if ((temp == 13))
		{
			cave[row][col] = 43;
		}
	}

}

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int temp[CAVE_SIZE][CAVE_SIZE];

	for (int i = 0; i < CAVE_SIZE / 2; i++)
	{
		for (int j = i; j < CAVE_SIZE - i - 1; j++)
		{
			temp[i][j] = cave[i][j];
			cave[i][j] = cave[CAVE_SIZE - 1 - j][i];
			cave[CAVE_SIZE - 1 - j][i] = cave[CAVE_SIZE - 1 - i][CAVE_SIZE - 1 - j];
			cave[CAVE_SIZE - 1 - i][CAVE_SIZE - 1 - j] = cave[j][CAVE_SIZE - 1 - i];
			cave[j][CAVE_SIZE - 1 - i] = temp[i][j];
		}
	}
}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	int x;
	int y;
	int k = 0;

	for (int i = 0; i < CAVE_SIZE; i++)
	{
		for (int j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 88)
			{
				x = i;
				y = j;
			}
		}
	}



	if (move == 'd')
	{
		if (cave[x][y + 1] == 2)
		{
			cave[x][y] = 0;
			cave[x][y + 1] = 88;
			return 2;
		}
		else if (cave[x][y + 1] == 42)
		{
			cave[x][y] = 0;
			cave[x][y + 1] = 42;
			return 1;
		}
		else if (cave[x][y + 1] == 0)
		{
			cave[x][y] = 0;
			cave[x][y + 1] = 88;
			return 0;
		}
		else if (cave[x][y + 1] == 43)
		{
			cave[x][y] = 0;
			cave[x][y + 1] = 88;
			return 0;
		}
		else if (cave[x][y + 1] == 1)
		{
			cave[x][y] = 88;
			return 0;
		}
		else if (cave[x][y + 1] == 79)
		{
			cave[x][y] = 88;

			while (cave[x][y + 2] == 0)
			{
				cave[x][y + 1] = 0;
				cave[x][y + 2] = 79;
				y++;

			}
			if (cave[x][y + 2] == 42)
			{
				cave[x][y + 1] = 0;
				cave[x][y + 2] = 0;
			}
			if (cave[x][y + 2] == 2)
			{
				cave[x][y + 1] = 0;
			}
			return 0;
		}
	}
	if (move == 'w')
	{
		if (cave[x - 1][y] == 2)
		{
			cave[x][y] = 0;
			cave[x - 1][y] = 88;
			return 2;
		}
		else if (cave[x - 1][y] == 42)
		{
			cave[x][y] = 0;
			cave[x - 1][y] = 42;
			return 1;
		}
		else if (cave[x - 1][y] == 0)
		{
			cave[x][y] = 0;
			cave[x - 1][y] = 88;
			return 0;
		}
		else if (cave[x - 1][y] == 43)
		{
			cave[x][y] = 0;
			cave[x - 1][y] = 88;
			return 0;
		}
		else if (cave[x - 1][y] == 1)
		{
			cave[x][y] = 88;
			return 0;
		}
		else if (cave[x - 1][y] == 79)
		{
			cave[x][y] = 88;

			while (cave[x - 2][y] == 0)
			{
					cave[x - 1][y] = 0;
					cave[x - 2][y] = 79;
					x--;

			}
			if (cave[x - 2][y] == 42)
			{
				cave[x - 1][y] = 0;
				cave[x - 2][y] = 0;
			}
			if (cave[x-2][y] == 2)
			{
				cave[x-1][y] = 0;
			}
			return 0;
		}
	}
	if (move == 's')
	{
		if (cave[x + 1][y] == 2)
		{
			cave[x][y] = 0;
			cave[x + 1][y] = 88;
			return 2;
		}
		else if (cave[x + 1][y] == 42)
		{
			cave[x][y] = 0;
			cave[x + 1][y] = 42;
			return 1;
		}
		else if (cave[x + 1][y] == 0)
		{
			cave[x][y] = 0;
			cave[x + 1][y] = 88;
			return 0;
		}
		else if (cave[x + 1][y] == 43)
		{
			cave[x][y] = 0;
			cave[x + 1][y] = 88;
			return 0;
		}
		else if (cave[x + 1][y] == 1)
		{
			cave[x][y] = 88;
			return 0;
		}
		else if (cave[x + 1][y] == 79)
		{
			cave[x][y] = 88;

			while (cave[x + 2][y] == 0)
			{
				cave[x + 1][y] = 0;
				cave[x + 2][y] = 79;
				x++;

			}
			if (cave[x+2][y] == 42)
			{
				cave[x+1][y] = 0;
				cave[x+2][y] = 0;
			}
			if (cave[x+2][y] == 2)
			{
				cave[x+1][y] = 0;
			}
			return 0;
		}
	}
	if (move == 'a')
	{
		if (cave[x][y - 1] == 2)
		{
			cave[x][y] = 0;
			cave[x][y - +1] = 88;
			return 2;
		}
		else if (cave[x][y - 1] == 42)
		{
			cave[x][y] = 0;
			cave[x][y - 1] = 42;
			return 1;
		}
		else if (cave[x][y - 1] == 0)
		{
			cave[x][y] = 0;
			cave[x][y - 1] = 88;
			return 0;
		}
		else if (cave[x][y - 1] == 43)
		{
			cave[x][y] = 0;
			cave[x][y - 1] = 88;
			return 0;
		}
		else if (cave[x][y - 1] == 1)
		{
			cave[x][y] = 88;
			return 0;
		}
		else if (cave[x][y - 1] == 79)
		{
			cave[x][y] = 88;

			while (cave[x][y - 2] == 0)
			{
				cave[x][y - 1] = 0;
				cave[x][y - 2] = 79;
				y--;

			}
			if (cave[x][y - 2] == 42)
			{
				cave[x][y - 1] = 0;
				cave[x][y - 2] = 0;
			}
			if (cave[x][y - 2] == 2)
			{
				cave[x][y - 1] = 0;
			}
			return 0;
		}
	}
	return 0;
}

/* GetMove() returns the entered character. Invalid characters ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	char story[2000];
	char layout[200] = "11111111111111000001110001100000110000110000010000011000000000001100000000000111110000000011110000000001100000000000110000000111111000000000001E0000000000011111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE];
	int gameOver = 0;

	InitialiseStory(story);
	InitialiseCave(cave, layout);

	AddItem(cave, 3, 6, "player");
	AddItem(cave, 2, 8, "player");
	AddItem(cave, 8, 4, "boulder");
	AddItem(cave, 6, 3, "boulder");
	AddItem(cave, 5, 9, "boulder");
	AddItem(cave, 2, 2, "boulder");
	AddItem(cave, 11, 1, "hole");
	AddItem(cave, 9, 9, "treasure");
	AddItem(cave, 8, 9, "treasure");
	AddItem(cave, 8, 8, "hole");

	printf("ENGGEN131 - C Project 2022\n");
	printf("                          ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n");

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}
