#include "mmRowData.h"

namespace mastermind
{
	void responseCell::setResponseValue(int responseValue)
	{
		if (responseValue != 1 && responseValue != 2)
		{
			// flip out, some how a invalid responseValue got here
			// TODO ERROR HANDLING
			exit(100);
		}

		mResponseValue = responseValue;
	}

	int responseCell::returnResponseValue() const
	{
		return mResponseValue;
	}



	void solutionCell::setColorBound(int colorBound)
	{
		mColorBound = colorBound;
	}

	int solutionCell::returnColorBound() const
	{
		return mColorBound;
	}

	void solutionCell::setColorValue(int colorValue)
	{
		mColorValue = colorValue;
		assertIsInBounds();
	}

	int solutionCell::returnColorValue() const
	{
		return mColorValue;
	}

	void solutionCell::assertIsInBounds() const
	{
		if (mColorBound < mColorValue)
		{
			// freak out. somehow bad data got this far
			// TODO implement error handling
			exit(104);
		}
	}

	rowData::rowData(int boardWidth, int boardColors, std::vector<int>& solutionAttempt, std::vector<solutionCell> &solution)
	{
		mWidthOfBoard = boardWidth;
		mColorsOfBoard = boardColors;

		assertVectorRightSize(solutionAttempt);

		solutionCell temp;
		temp.setColorBound(mWidthOfBoard);

		for(int i = 0; i < int(solutionAttempt.size()); i++)
		{
			temp.setColorValue(solutionAttempt[i]);
			mSolutionAttemptData.push_back(temp);
		}

		populateResponse(solution);
	}


	void rowData::assertVectorRightSize(std::vector<int>& vectorToCheck) const
	{
		if (vectorToCheck.size() != mWidthOfBoard)
		{
			// freak out, why is passed vector not equal to width of game
			// input data invalid
			// TODO ERROR HANDLING
			exit(101);
		}
	}

	std::vector<int> rowData::getSolutionAttempt()
	{
		std::vector<int> solutionReturnData;
		for (solutionCell sCell : mSolutionAttemptData)
		{
			solutionReturnData.push_back(sCell.returnColorValue());
		}
		return solutionReturnData;
	}

	// TODO make this not suck
	// for small n values wide this isn't too inefficient but 
	// for larger n values it will slow down runtime considerably
	// its possible this could cause a error from passing object by value :,(

	std::vector<int> rowData::getIntResponse()
	{
		std::vector<int> responseReturnData;
		for (responseCell rCell : mResponseData)
		{
			responseReturnData.push_back(rCell.returnResponseValue());
		}
		return responseReturnData;
	}

	// NOTE 0 means uninitialized, 1 means o and 2 means x
	void rowData::populateResponse(std::vector<solutionCell> &solution)
	{
		solutionRelationship temp;
		temp.relationshipType = 2;
		std::vector<solutionRelationship> relationships;
		for (int i = 0; i < int(mSolutionAttemptData.size()); i++)
		{
			if (mSolutionAttemptData[i].returnColorValue() == solution[i].returnColorValue() )
			{
				temp.solutionIndex = i;
				temp.attemptIndex = i;
				relationships.push_back(temp);
			}
		}
		temp.relationshipType = 1;

		for (int i = 0; i < int(mSolutionAttemptData.size()); i++)
		{
			for (int j = 0; j < mSolutionAttemptData.size(); j++)
			{
				if ((mSolutionAttemptData[i].returnColorValue() == solution[j].returnColorValue()) && assertNotInSet(relationships, i, j))
				{
					temp.solutionIndex = i;
					temp.attemptIndex = j;
					relationships.push_back(temp);
				}
			}
		}
		if(relationships.size() > mSolutionAttemptData.size())
		{
			// Holy **** the relationships are larger then the input
			// actually really really freakout
			// TODO ERROR LOGGING and HANDLING
			exit(200);
		}
		responseCell responseTemp;
		for (solutionRelationship r : relationships)
		{
			responseTemp.setResponseValue(r.relationshipType);
			mResponseData.push_back(responseTemp);
		}
	}

	bool rowData::assertNotInSet(std::vector<solutionRelationship>& relationshipList, int solutionIndex, int attemptIndex)
	{
		
		for(solutionRelationship sRelate : relationshipList)
		{
			if(sRelate.attemptIndex == attemptIndex || sRelate.solutionIndex == solutionIndex)
			{
				return false;
			}
		}

		return true;
	}

	bool rowData::isGameOver()
	{
		bool valuesChecker = true;

		std::vector<int> dataToCheck = getIntResponse();

		if(dataToCheck.size() != mWidthOfBoard)
		{
			return false;
		}
		for (int c : dataToCheck)
		{
			if(c != 2)
			{
				valuesChecker = false;
			}
		}
		return valuesChecker;
	}


}
