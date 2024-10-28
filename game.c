#include <stdio.h>
#include <stdbool.h>

struct TicTacToe
{
	char board[3][3];
	bool xTurn;
	bool isOver;

	int size;

};
typedef struct TicTacToe TicTacToe;

void initialize(TicTacToe *game)
{
 	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			game->board[i][j] = ' '; 	
		}
	}


	game->isOver = false;	
	game->xTurn = true;
}


void printBoard(TicTacToe *game)
{
	 printf(" \n \n ");
	 printf("   0   1   2 \n");

	 for (int i = 0; i < 3; i++)
	 {
		 printf("%d ", i);

		 for (int j = 0; j < 3; j++)
		 {
			printf(" %c ", game->board[i][j]);
		       	if (j != 2)
				printf("|");	
		 }
		 if (i != 2)
			 printf("\n  ---|---|---\n");
	 }
	 printf("\n \n");
}
	
bool move(char player, TicTacToe *game)
{
	int row, col;
	printf("Player %c Where do you want to put your mark? [Row] [Column]\n", player);
			scanf("%d %d", &row, &col); 
			
			if (game->board[row][col] == ' ')	
			{
				game->board[row][col] = player;
				game->size += 1;
				return false;	
			}
			else if (game->board[row][col] == 'X' || game->board[row][col] == 'O')
			      	puts("\nPosition already taken, enter new position: ");
			else	
			       	puts("\nInvalid input, row and column number must be less than 3, try again: ");
			return true;
}

bool checkRows(char player, TicTacToe *game)
{
	for (int i = 0; i < 3; i++)
	{
		int count = 1;
		char cur = game->board[i][0];
		
		if (cur == player)
		{
			for (int j = 1; j < 3; j++)
			{
				if (game->board[i][j] == cur)
					count++;
			}
		}

		if (count >= 3)
		{

			printf("\n Player %c wins!", player);
			return true;
		}
	}
	return false;
}

bool checkCols(char player, TicTacToe *game)
{
	for (int j = 0; j < 3; j++)
	{
		int count = 1;
		char cur = game->board[0][j];
		
		if (cur == player)
		{
			for (int i = 1; i < 3; i++)
			{
				if (game->board[i][j] == cur)
					count++;
			}
		}

		if (count >= 3)
		{
			printf("\n Player %c wins!", player);
			return true;
		}
			
	}
	return false;
}

bool checkDiagonals(char player, TicTacToe *game)
{
	if (game->board[1][1] == player)
	{
		if ( (game->board[0][0] == player && game->board[2][2] == player) || (game->board[0][2] == player && game->board[2][0] == player))
		{
			printf("\n Player %c wins!", player);
			return true;
		}
	}
	return false;
}

int main()
{
	TicTacToe game;
	initialize(&game);
		
	while (!game.isOver)
	{
		printBoard(&game);
	
		if (game.xTurn)
		{
			game.xTurn = move('X', &game);	
		}
		else 
		{
			game.xTurn = !(move('O', &game));
		}

		if ( checkRows('X', &game) || checkCols('X', &game) || checkDiagonals('X', &game))
		{
			printBoard(&game);
			game.isOver = true;
		}
		else if (checkRows('O', &game) || checkCols('O', &game) || checkDiagonals('O', &game))
		{
			printBoard(&game);
			game.isOver = true;
		}
		else if (game.size >= 9)
		{
			printBoard(&game);
			puts("\n It's a tie! You can restart program to play again");
			game.isOver = true;
		}
	}
}
		
