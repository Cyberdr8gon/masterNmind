#pragma once

#include <vector>
#include "mmResponseCell.h"
#include "mmSolutionCell.h"

namespace mastermind
{
	class rowData
	{
	public:
		rowData(int boardWidth, int boardColors, std::vector<int> &solutionAttempt, std::vector<int> &solution);

		std::vector<int> getSolutionAttempt();
		std::vector<responseState> getResponse();
	private:
		void assertVectorRightSize(std::vector<int> &vectorToCheck);


		int mWidthOfBoard = 0;
		int mColorsOfBoard = 0;

		std::vector<solutionCell> mSolutionAttemptData;
		std::vector<responseCell> mResponseData;
	};
}