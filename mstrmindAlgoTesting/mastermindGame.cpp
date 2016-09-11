#pragma once
#include "mastermindGame.h"

namespace mastermind
{
	game::game(int widthOfGame,
			   int colorsInGame,
			   std::vector<int>& gameSolution
			) 
			: mWidthOfBoard(widthOfGame), 
			  mColorsOfBoard(colorsInGame)
	{

		if (gameSolution.size() != widthOfGame)
		{
			// bad input, maybe don't freak out as bad
			// TODO ERROR HANDLING
			exit(300);

		}

		solutionCell temp;
		temp.setColorBound(mColorsOfBoard);
		for(int i = 0; i < mWidthOfBoard; i++)
		{
			temp.setColorValue(gameSolution[i]);
			solutionVector.push_back(temp);
		}
	}


	void game::postSolutionAttempt(std::vector<int>& solutionAttempt)
	{
		incrementNumberOfTurns();
		rowData temp(mWidthOfBoard, mColorsOfBoard, solutionAttempt, solutionVector);
		if (temp.isGameOver())
		{
			mGameIsOver = true;
		}
		boardDataVector.push_back(temp);
	}

	void game::endGame()
	{
		mGameIsOver = true;
	}

	void game::incrementNumberOfTurns()
	{
		mNumberOfTurns++;
	}


	int game::getNumberOfTurns() const
	{
		return mNumberOfTurns;
	}

}