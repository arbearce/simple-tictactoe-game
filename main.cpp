//Tic Tac Toe game

#include "tictactoe.h"

using namespace std;
/*
 * Character representation for the game board
 * X: Player 1 game piece
 * Y: Player 2 game piece
 */
char board[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };

/*
 * array for marking a section of the game board as played
 */
bool boardMarked[9] = { 0, 0, 0, 0, 0 ,0, 0, 0, 0 };

/*
 * Indicator to stating if a player has won
 * 0: no winner
 * 1: Player 1 is the winner
 * 2: Player 2 is the winner
 */
int winner = 0;


void checkWin()
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
			winner = 1;
		else
			winner = 2;
	}
	else if (board[3] == board[4] && board[4] == board[5])
	{
		/*
		* Check to see which player won
		*/
		if (board[3] == 'X')
			winner = 1;
		else
			winner = 2;
	}
	else if (board[6] == board[7] && board[7] == board[8])
	{
		/*
		* Check to see which player won
		*/
		if (board[6] == 'X')
			winner = 1;
		else
			winner = 2;
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
			winner = 1;
		else
			winner = 2;
	}
	else if (board[1] == board[4] && board[4] == board[7])
	{
		/*
		* Check to see which player won
		*/
		if (board[1] == 'X')
			winner = 1;
		else
			winner = 2;
	}
	else if (board[2] == board[5] && board[5] == board[8])
	{
		/*
		* Check to see which player won
		*/
		if (board[2] == 'X')
			winner = 1;
		else
			winner = 2;
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
			winner = 1;
		else
			winner = 2;
	}
	else if (board[2] == board[4] && board[4] == board[6])
	{
		/*
		* Check to see which player won
		*/
		if (board[2] == 'X')
			winner = 1;
		else
			winner = 2;
	}
}

void markBoard(int player, int selection)
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

int generateMove()
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

void showBoard()
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

void startNewGame(bool newGameFlag)
{
	/*
		 * This main function will declare variables needed to play the game that
		 */
		int numPlayers = 0, player1 = 1, player2 = 2;
		int selection = 0, moves = 0;

		/*
		 * Is this not the first game?
		 */
		if(newGameFlag)
		{
			/*
			 * Reset to the game board
			 */
			for (moves = 0; moves < 9; moves++)
			{
				board[moves] = (moves + 48);
				boardMarked[moves] = 0;
			}

			winner = 0;
			moves = 0;
		}


		cout << "\nShall we play a game?\n";

		/*
		 * Find out how many human players there will be
		 */
		cout <<"\nHow many players will there be? enter 1 or 2 :";

		cin >>	numPlayers;

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
		    	cout << "\nYou did not enter a correct number of players. Setting number of players 1.\n";
		    	numPlayers = 1;
		    	break;
		}


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
			cout << "\nPlayer " << player1 << " select a box to play: ";

			/*
			* capture the players selection
			*/
			cin >> selection;

			/*
			 * Get the computers move
			 */
			markBoard(player1, selection);

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
				cout << "\nPlayer " << player2 << " select a box to play: ";

				/*
				 * capture the players selection
				 */
				cin >> selection;
			}
			/*
			 *Mark the players selection on to update the game board
			 */
			markBoard(player2, selection);

			/*
			 * Check to see if we have a winner
			*/
			checkWin();

			/*
			 *Increment move count
			 */
			moves++;

			/*
			 * If we have reached the maximum amount of moves without a winner then the game is a draw
			 */
			if (moves > 8)
			{
				cout << "\nMoves = " << moves;
				break;
			}
			}


		if (winner == 1)
		{
			cout << "\nPlayer 1 has won the game!\n";
		}
		else if (winner == 2)
		{
			cout << "\nPlayer 2 has won the game!\n";
		}
		else
			cout << "\nThe game is a draw!\n The only way to win is to not play the game";

		cout << "\n";

		showBoard();

}

int main()
{
	bool exitGame = 0;
	char userAnswer;
	tictactoeGame newGame;


	while(!exitGame)
	{
		newGame.startNewGame();

		cout << "\nWould you like to play again? Y or N : ";
		cin >> userAnswer;

		if (userAnswer == 'N' || userAnswer == 'n')
		{
			exitGame = 1;
			cout << "\nGood Bye ";
		}
		else
		{
			cout << "\nYou have decided to play again. You have chosen ... wisely.";
		}

	}
	return 0;
}
