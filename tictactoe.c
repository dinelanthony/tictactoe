/* Author: Dinel Anthony
* Date: June 12, 2021
* Purpose: To create tictactoe
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void printInitialBoard(char array[3][3]);
void printBoard(char array[3][3]);
void playerInput(char array[3][3]);
void humanInput(char array[3][3]);
int checkWin(char array[3][3]);
void compInput(char array[3][3]);

int main(void)
{
	char array[3][3];
	int counter = 1;
	int end = 1;
	int choice = 3;

	printInitialBoard(array);
	srand(time(NULL));

	while (choice != 1 || choice != 2)
	{
		printf("Please choose an option below:\n");
		printf("Option 1: Play against computer\n");
		printf("Option 2: Play against another player\n");
		printf("Choice: ");
		scanf("%d", &choice);


		if (choice == 2)
		{
			while (end == 1)
			{
				playerInput(array);
				system("cLs");
				printBoard(array);

				end = checkWin(array);
				if (end == 0)
				{
					return 0;
				}

				humanInput(array);
				system("cLs");
				printBoard(array);

				end = checkWin(array);
				if (end == 0)
				{
					return 0;
				}
			}
		}

		else if (choice == 1)
		{
			while (end == 1)
			{
				playerInput(array);
				system("cLs");
				printBoard(array);

				end = checkWin(array);
				if (end == 0)
				{
					return 0;
				}

				compInput(array);
				system("cLs");
				printBoard(array);

				end = checkWin(array);
				if (end == 0)
				{
					return 0;
				}
			}
		}

		else
		{
			printf("Try again\n\n");
		}
	}
}

void printInitialBoard(char array[3][3])
{
	int rows;
	int cols;

	for (cols = 0;cols < 3;cols++)
	{
		for (rows = 0;rows < 3;rows++)
		{
			array[cols][rows] = (char)176;
			if (rows < 2)
			{
				printf("  %c  |", array[cols][rows]);
			}
			else
			{
				printf("  %c  ", array[cols][rows]);
			}
		}

		if (cols < 2)
		{
			printf("\n-----------------\n");
		}
		else
		{
			printf("\n");
		}
	}
}

void printBoard(char array[3][3])
{
	int rows;
	int cols;

	for (cols = 0;cols < 3;cols++)
	{
		for (rows = 0;rows < 3;rows++)
		{
			if (rows < 2)
			{
				printf("  %c  |", array[cols][rows]);
			}
			else
			{
				printf("  %c  ", array[cols][rows]);
			}
		}

		if (cols < 2)
		{
			printf("\n-------------------\n");
		}
		else
		{
			printf("\n");
		}
	}
}

void playerInput(char array[3][3])
{
	int choice = 10;

	while (choice > 9 || choice < 1)
	{
		printf("\nPlayer 1- Please enter which tile you would like to choose: ");
		scanf("%d", &choice);

		if (choice > 9 || choice < 1)
		{
			printf("Please try again!\n");
		}
	}

	if (choice <= 3)
	{
		if (array[0][choice - 1] == 79 || array[0][choice - 1] == 88)
		{
			printf("Invalid input, please try again: ");
			scanf("%d", &choice);
		}

		array[0][choice - 1] = 88;

	}

	else if (choice > 3 && choice <= 6)
	{
		if (array[1][choice - 4] == 79 || array[1][choice - 4] == 88)
		{
			printf("Invalid input, please try again: ");
			scanf("%d", &choice);
		}

		array[1][choice - 4] = 88;

	}

	else
	{
		if (array[2][choice - 7] == 79 || array[2][choice - 7] == 88)
		{
			printf("Invalid input, please try again: ");
			scanf("%d", &choice);
		}

		array[2][choice - 7] = 88;
	}
}

void humanInput(char array[3][3])
{
	int choice2 = 10;

	while (choice2 > 9 || choice2 < 1)
	{
		printf("\nPlayer 2- Please enter which tile you would like to choose: ");
		scanf("%d", &choice2);

		if (choice2 > 9 || choice2 < 1)
		{
			printf("Please try again!\n");
		}
	}

	if (choice2 <= 3)
	{
		if (array[0][choice2 - 1] == 79 || array[0][choice2 - 1] == 88)
		{
			printf("Invalid input, please try again: ");
			scanf("%d", &choice2);
		}

		array[0][choice2 - 1] = 79;

	}

	else if (choice2 > 3 && choice2 <= 6)
	{
		if (array[1][choice2 - 4] == 79 || array[1][choice2 - 4] == 88)
		{
			printf("Invalid input, please try again: ");
			scanf("%d", &choice2);
		}

		array[1][choice2 - 4] = 79;

	}

	else
	{
		if (array[2][choice2 - 7] == 79 || array[2][choice2 - 7] == 88)
		{
			printf("Invalid input, please try again: ");
			scanf("%d", &choice2);
		}

		array[2][choice2 - 7] = 79;
	}
}

void compInput(char array[3][3])
{
	int choice2;

	choice2 = rand() % 9 + 1;

	if (choice2 <= 3)
	{
		while (array[0][choice2 - 1] == 79 || array[0][choice2 - 1] == 88)
		{
			choice2 = rand() % 9 + 1;
		}

		array[0][choice2 - 1] = 79;

	}

	else if (choice2 > 3 && choice2 <= 6)
	{
		while (array[1][choice2 - 4] == 79 || array[1][choice2 - 4] == 88)
		{
			choice2 = rand() % 9 + 1;
		}

		array[1][choice2 - 4] = 79;

	}

	else
	{
		while (array[2][choice2 - 7] == 79 || array[2][choice2 - 7] == 88)
		{
			choice2 = rand() % 9 + 1;
		}

		array[2][choice2 - 7] = 79;
	}
}

int checkWin(char array[3][3])
{
	int x;
	int y;
	int counter = 0;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (array[x][y] != 0)
			{
				counter++;
			}
		}
	}

	if (counter == 176)
	{
		printf("Draw!");
		return 0;
	}

	else if (array[0][0] == 88 && array[0][1] == 88 && array[0][2] == 88)
	{
		printf("Player 1 Wins!\n");
		return 0;
	}

	else if (array[1][0] == 88 && array[1][1] == 88 && array[1][2] == 88)
	{
		printf("Player 1 Wins!\n");
		return 0;
	}

	else if (array[2][0] == 88 && array[2][1] == 88 && array[2][2] == 88)
	{
		printf("Player 1 Wins!\n");
		return 0;
	}

	else if (array[0][0] == 88 && array[1][0] == 88 && array[2][0] == 88)
	{
		printf("Player 1 Wins!\n");
		return 0;
	}

	else if (array[0][1] == 88 && array[1][1] == 88 && array[2][1] == 88)
	{
		printf("Player 1 Wins!\n");
		return 0;
	}

	else if (array[0][2] == 88 && array[1][2] == 88 && array[2][2] == 88)
	{
		printf("Player 1 Wins!\n");
		return 0;
	}

	else if (array[0][0] == 88 && array[1][1] == 88 && array[2][2] == 88)
	{
		printf("Player 1 Wins!\n");
		return 0;
	}

	else if (array[2][0] == 88 && array[1][1] == 88 && array[0][2] == 88)
	{
		printf("Player 1 Wins!\n");
		return 0;
	}

	else if (array[0][0] == 79 && array[0][1] == 79 && array[0][2] == 79)
	{
		printf("Player 2 Wins!\n");
		return 0;
	}

	else if (array[1][0] == 79 && array[1][1] == 79 && array[1][2] == 79)
	{
		printf("Player 2 Wins!\n");
		return 0;
	}

	else if (array[2][0] == 79 && array[2][1] == 79 && array[2][2] == 79)
	{
		printf("Player 2 Wins!\n");
		return 0;
	}

	else if (array[0][0] == 79 && array[1][0] == 79 && array[2][0] == 79)
	{
		printf("Player 2 Wins!\n");
		return 0;
	}

	else if (array[0][1] == 79 && array[1][1] == 79 && array[2][1] == 79)
	{
		printf("Player 2 Wins!\n");
		return 0;
	}

	else if (array[0][2] == 79 && array[1][2] == 79 && array[2][2] == 79)
	{
		printf("Player 2 Wins!\n");
		return 0;
	}

	else if (array[0][0] == 79 && array[1][1] == 79 && array[2][2] == 79)
	{
		printf("Player 2 Wins!\n");
		return 0;
	}

	else if (array[2][0] == 79 && array[1][1] == 79 && array[0][2] == 79)
	{
		printf("Player 2 Wins!\n");
		return 0;
	}

	else
	{
		counter = 0;
		return 1;
	}
}