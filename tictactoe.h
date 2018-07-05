/*
 * tictactoe.h
 *
 *  Created on: Jun 27, 2018
 *      Author: 1282716573C
 */

#ifndef SRC_TICTACTOE_H_
#define SRC_TICTACTOE_H_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <limits>

#define PLAYER1 1
#define PLAYER2 2

class tictactoeGame
{
private:

	/*
	 * Character representation for the game board
	 * X: Player 1 game piece
	 * Y: Player 2 game piece
	 */
	char board[9];

	/*
	 * array for marking a section of the game board as played
	 */
	bool boardMarked[9];

	/*
	 * Indicator to stating if a player has won
	 * 0: no winner
	 * 1: Player 1 is the winner
	 * 2: Player 2 is the winner
	 */
	int winner;
	/*
	 * Keeps track of the amount of moves that have been played.
	 */
	int movesPlayed;
	int numPlayers;


	void initBoard();
	void checkWin();
	void markBoard(int, int);
	int generateMove();
	void showBoard();
	void getNumPlayers();

public:

	void startNewGame();

};

#endif /* SRC_TICTACTOE_H_ */
