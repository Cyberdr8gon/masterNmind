#pragma once

#include <vector>


namespace mastermind
{

	class responseCell
	{
	public:

		inline void setResponseValue(int responseValue);
		inline int returnResponseValue() const;

	private:
		int mResponseValue = 0;
	};

	class solutionCell
	{
	public:
		inline void setColorValue(int colorValue);
		inline int returnColorValue() const;

		inline void setColorBound(int colorBound);
		inline int returnColorBound() const;

	private:

		inline void assertIsInBounds() const;

		int mColorValue = 0;
		int mColorBound = 0;
	};

	struct solutionRelationship
	{
		int solutionIndex;
		int attemptIndex;
		int relationshipType;
	};



	class rowData
	{
	public:
		rowData(int boardWidth, int boardColors, std::vector<int>& solutionAttempt, std::vector<solutionCell> &solution);

		std::vector<int> getSolutionAttempt();
		std::vector<int> getIntResponse();


	private:
		inline void assertVectorRightSize(std::vector<int> &vectorToCheck) const;
		void populateResponse(std::vector<solutionCell> &solution);
		bool assertNotInSet(std::vector<solutionRelationship>& relationshipList, int solutionIndex, int attemptIndex);


		int mWidthOfBoard = 0;
		int mColorsOfBoard = 0;

		std::vector<solutionCell> mSolutionAttemptData;
		std::vector<responseCell> mResponseData;
	};
}