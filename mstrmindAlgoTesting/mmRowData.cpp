#pragma once
#include "mmRowData.h"

namespace mastermind
{
	rowData::rowData(int boardWidth, int boardColors, std::vector<int>& solutionAttempt, std::vector<int>& solution)
	{
		mWidthOfBoard = boardWidth;
		mColorsOfBoard = boardColors;

		assertVectorRightSize(solutionAttempt);

		solutionCell temp;
		temp.setColorBound(mWidthOfBoard);
		for(int i = 0; i < solutionAttempt.size(); i++)
		{
			temp.setColorValue(solutionAttempt[i]);
			mSolutionAttemptData.push_back(temp);
		}
	}

}