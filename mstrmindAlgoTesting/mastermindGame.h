#pragma once
#include "mmRowData.h"

namespace mastermind
{
	class game
	{
	public:
		// currently not checking if each value is in bounds
		// except at cell level. Probably should change that
		// and remove checks at cell level
		game(int widthOfGame,
			 int colorsInGame,
			 std::vector<int>& gameSolution);

		void postSolutionAttempt(std::vector<int>& solutionAttempt);
		inline int getNumberOfTurns() const;

		// slightly dangerous to leave these out in the open without
		// a private protecting the data, however, I feel for performance reasons
		// it is worth the risk. If we run into issues we can always private them again
		std::vector<rowData> boardDataVector;
		std::vector<solutionCell> solutionVector;

		const int mWidthOfBoard;
		const int mColorsOfBoard;

		// feature request
		// this needs to be encapsulated in a getter or setter
		bool mGameIsOver = false;

	private:
		inline void endGame();
		inline void incrementNumberOfTurns();

		int mNumberOfTurns = 0;

	};
}