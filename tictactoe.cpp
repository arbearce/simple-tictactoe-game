/*
 * tictactoe.cpp
 *
 *  Created on: Jun 27, 2018
 *      Author: 1282716573C
 */
#include "tictactoe.h"

using namespace std;

void tictactoeGame :: initBoard()
{
	winner = 0;
	movesPlayed = 0;
	numPlayers = 0;

	for (int i = 0; i < 9; i++)
	{
		board[i] = (i + 48);
		boardMarked[i] = 0;
	}
}
void tictactoeGame :: checkWin()
{
	/*
	* Function to see if we have a winner
	*This will go through the possible combinations
	*if the square and adjacent squares are equal then we have a winner
	* |0|1|2|
	* |3|4|5|
	* |6|7|8|
	* Possible win combinations
	* Horizontal: (0,1,2) (3,4,5) (6,7,8)
	* Vertical:   (0,3,6) (1,4,7) (2,5,8)
	* Cross:      (0,4,8) (2,4,8)/
	*/

	/*
	* Check Horizontal: (0,1,2) (3,4,5) (6,7,8)
	*/

	if(board[0] == board[1] && board[1] == board[2])
	{
		/*
		* Check to see which player won
		*/
		if (board[0] == 'X')
			winner = PLAYER1;
		else
			winner = PLAYER2;
	}
	else if (board[3] == board[4] && board[4] == board[5])
	{
		/*
		* Check to see which player won
		*/
		if (board[3] == 'X')
			winner = PLAYER1;
		else
			winner = PLAYER2;
	}
	else if (board[6] == board[7] && board[7] == board[8])
	{
		/*
		* Check to see which player won
		*/
		if (board[6] == 'X')
			winner = PLAYER1;
		else
			winner = PLAYER2;
	}
	/*
	* Vertical: (0,3,6) (1,4,7) (2,5,8)
	*/
	else if(board[0] == board[3] && board[3] == board[6])
	{
		/*
		* Check to see which player won
		*/
		if (board[0] == 'X')
			winner = PLAYER1;
		else
			winner = PLAYER2;
	}
	else if (board[1] == board[4] && board[4] == board[7])
	{
		/*
		* Check to see which player won
		*/
		if (board[1] == 'X')
			winner = PLAYER1;
		else
			winner = PLAYER2;
	}
	else if (board[2] == board[5] && board[5] == board[8])
	{
		/*
		* Check to see which player won
		*/
		if (board[2] == 'X')
			winner = PLAYER1;
		else
			winner = PLAYER2;
	}
	/*
	* Cross: (0,4,8) (2,4,6)
	*/
	else if(board[0] == board[4] && board[4] == board[8])
	{
		/*
		* Check to see which player won
		*/
		if (board[0] == 'X')
			winner = PLAYER1;
		else
			winner = PLAYER2;
	}
	else if (board[2] == board[4] && board[4] == board[6])
	{
		/*
		* Check to see which player won
		*/
		if (board[2] == 'X')
			winner = PLAYER1;
		else
			winner = PLAYER2;
	}
}

void tictactoeGame :: markBoard(int player, int selection)
{
	/*
	* When a player makes a selection:
	* Check to see if the position has been marked
	* Mark position as played
	* Insert the players character into the spot
	* Otherwise state that the move is illegal
	*/
	cout << "\nYou wish to place you mark on : " << selection;
	if (!boardMarked[selection])
	{
		boardMarked[selection] = 1;
		if (player == 1)
		{
			board[selection] = 'X';

		}
		else
			board[selection] = 'Y';

		cout <<"\nThe players move is valid and a " << board[selection]<< " will be placed in section " << selection <<"\n";
	}
	else
		cout << "\nThat move is not allowed! You can not place again this round!\n";

}

int tictactoeGame :: generateMove()
{
	/*
	 * Generate the computers move based on a simple die roll
	 * It will continue to roll the die until a valid move is found
	 */
	int compMove = 0;
	int max = 8;
	bool isValidMove = 0;

	srand(time(NULL));

	/*
	 * While there isn't a valid move try to generate a valid move
	 */
	while(!isValidMove)
	{
		compMove = 1 + (rand() % max) -1;
		/*
		 * If there board space hasn't been taken then allow the computer to make it's move
		 */
		if (!boardMarked[compMove])
		{
			/*
			 * The move is valid
			 */
				isValidMove = 1;
		}
	}

	return compMove;
}

void tictactoeGame :: showBoard()
{
	/*
	* Display the game board
	* Loop though board[] and cout each element insert a new line every 3
	*/
	for (int i = 0; i < 9; i++)
	{
		cout << board[i] << "\t";
		if (i == 2 || i == 5 || i == 8)
			cout << "\n";
	}
}

void tictactoeGame :: getNumPlayers()
{
	/*
	 * Find out how many human players there will be
	 */
	while(!numPlayers)
	{
		cout <<"\nHow many players will there be? enter 1 or 2 : ";

		/*
		 * This will check to see if the user inputs an int
		 */
		while (!(cin >> numPlayers))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(), '\n');
			cout << "\nYou did not enter a correct number of players. Please try again.\n";
			cout <<"\nHow many players will there be? enter 1 or 2 : ";
		}



		switch (numPlayers)
		{
		/*
		 * Switch on numPlayers
		 * 1 - a human vs computer
		 * 2 - human vs human
		 * default set to human vs computer
		 */
			case 1:
				cout << "\nThere will be one human player and on computer player";
				cout << "\nThe human player will be represented by X and the computer player by O\n";
				break;

			case 2:
				cout << "\nThere will be two human players";
				cout << "\nPlayer 1 will be represented by X and player 2 by O\n";
				break;

			default:
				cout << "\nYou did not enter a correct number of players. Please try again.\n";
				numPlayers = 0;
				break;
		}

	}

}
void tictactoeGame :: startNewGame()
{
	/*
		 * This main function will declare variables needed to play the game that
		 */
		int selection = 0;

		/*
		 * Initialize the game board
		 */
		initBoard();

		cout << "\nShall we play a game?\n";

		getNumPlayers();

		while (!winner)
		{
			/*
			 * While there is no winner then play the game
			 */

			/*
			* Display the game board
			*/
			showBoard();

			/*
			* Asked player to make a selection
			*/
			cout << "\nPlayer " << PLAYER1 << " select a box to play: ";

			/*
			* capture the players selection and make sure it is an int
			*/
			while (!(cin >> selection))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize> :: max(), '\n');
					cout << "\nYou did not enter a correct board space.\n";
					cout << "\nPlayer " << PLAYER1 << " select a box to play: ";
				}
;

			/*
			 * Get the computers move
			 */
			markBoard(PLAYER1, selection);

			/*
			 *Increment move count
			 */
			movesPlayed++;

			/*
			* Check to see if we have a winner
			*/
			checkWin();

			/*
			*if player 1 wins then break out of the loop
			*/
			if (winner)
				break;

			/*
			* Display the game board
			*/
			showBoard();
			cout << "\n";

			/*
			 * Simple control logic for if there is a second player or a computer player
			 */
			if (numPlayers == 1)
			{
				/*
				 * We have a computer player
				 */

				/*
				 * Get the computers move
				 */
				selection = generateMove();
			}
			else
			{
				/*
				 * We have a second human player
				 */
				/*
				 * Asked player to make a selection
				 */
				cout << "\nPlayer " << PLAYER2 << " select a box to play: ";

				/*
				 * capture the players selection and make sure it is an int
				 */
				while (!(cin >> selection))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize> :: max(), '\n');
						cout << "\nYou did not enter a correct board space.\n";
						cout << "\nPlayer " << PLAYER2 << " select a box to play: ";
					}
			}
			/*
			 *Mark the players selection on to update the game board
			 */
			markBoard(PLAYER2, selection);

			/*
			 * Check to see if we have a winner
			*/
			checkWin();

			/*
			 *Increment move count
			 */
			movesPlayed++;

			/*
			 * If we have reached the maximum amount of moves without a winner then the game is a draw
			 */
			if (movesPlayed > 8)
				break;

		}


		if (winner == PLAYER1)
		{
			cout << "\nPlayer 1 has won the game!\n";
		}
		else if (winner == PLAYER2)
		{
			cout << "\nPlayer 2 has won the game!\n";
		}
		else
			cout << "\nThe game is a draw!\n The only way to win is to not play the game";

		cout << "\n";

		showBoard();

}


