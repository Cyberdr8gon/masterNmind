/*

all tests passed :D
test removed for production



#include "mmRowData.h"
#include <iostream>

int main(int argc, char* argv[])
{
	int boardWidth = 4;
	int boardColors = 6;
	std::vector<int> testSolutionAttempts;
	std::vector<mastermind::solutionCell> testSolution;
	mastermind::solutionCell temp;
	temp.setColorBound(boardWidth);
	for (int i = 0; i < boardWidth; i++) {
		temp.setColorValue(i);
		testSolution.push_back(temp);
		testSolutionAttempts.push_back(i);
	}

	mastermind::rowData test1(boardWidth, boardColors, testSolutionAttempts, testSolution);
	std::vector<int> returnDataFromSolutionAttempt = test1.getSolutionAttempt();
	for (int solutionAttemptIndex : returnDataFromSolutionAttempt)
	{
		std::cout << solutionAttemptIndex << std::endl;
	}

	std::vector<int> returnDataFromResponse = test1.getIntResponse();
	for (int c: returnDataFromResponse)
	{
		std::cout << c << std::endl;
	}

	std::vector<int> test2SolutionAttempt;
	for (int i = 0; i < boardWidth; i++)
	{
		test2SolutionAttempt.push_back(1);
	}


	mastermind::rowData test2(boardWidth, boardColors, test2SolutionAttempt, testSolution);
	returnDataFromSolutionAttempt = test2.getSolutionAttempt();
	for (int solutionAttemptIndex : returnDataFromSolutionAttempt)
	{
		std::cout << solutionAttemptIndex << std::endl;
	}

	returnDataFromResponse = test2.getIntResponse();
	for (int c: returnDataFromResponse)
	{
		std::cout << c << std::endl;
	}



	// 9/11/16 major error, not responding to o's

	// 9/11/16 error resolved, forgot to change a iterator
	// from i to j

	std::vector<int> test3SolutionAttempt;
	for (int i = boardWidth; i > 0; i--)
	{
		test3SolutionAttempt.push_back(i);
	}

	mastermind::rowData test3(boardWidth, boardColors, test3SolutionAttempt, testSolution);
	returnDataFromSolutionAttempt = test3.getSolutionAttempt();
	for (int solutionAttemptIndex : returnDataFromSolutionAttempt)
	{
		std::cout << solutionAttemptIndex << std::endl;
	}

	returnDataFromResponse = test3.getIntResponse();
	for (int c: returnDataFromResponse)
	{
		std::cout << c << std::endl;
	}



	return 0;
}


/*
*/
