/*


all tests passed

1 feature request pending



#include <iostream>
#include "mastermindGame.h"

int main(int argc, char* argv[])
{
	int widthOfGame = 4;
	int colorsInGame = 6;
	std::vector<int> gameSolution;
	for (int i = 0; i < 4; i++)
	{
		gameSolution.push_back(5 - i);
	}

	mastermind::game testGame(widthOfGame, colorsInGame, gameSolution);

	std::vector<int> testSolutions;
	for (int i = 0; i < 4; i++)
	{
		testSolutions.push_back(4 - i);
	}
	testGame.postSolutionAttempt(testSolutions);
	testSolutions._Pop_back_n(4);

	for (int i = 0; i < 4; i++)
	{
		testSolutions.push_back(i);
	}
	testGame.postSolutionAttempt(testSolutions);
	testSolutions._Pop_back_n(4);

	for (int i = 0; i < 4; i++)
	{
		testSolutions.push_back(i + 1);
	}
	testGame.postSolutionAttempt(testSolutions);



	for (mastermind::rowData r : testGame.boardDataVector)
	{
		std::cout << "Guess:" << std::endl;
		for (int v : r.getSolutionAttempt())
		{
			std::cout << v << " ";
		}
		std::cout << std::endl << "Response: " << std::endl;

		for (int v : r.getIntResponse())
		{
			std::cout << ((v == 1) ? "o" : "x") << " ";
		}

		std::cout << std::endl;
	}



	// BUG 9/11/16 Criticallity level: medium
	// this feature should be fixed eventually, but for now
	// clients must provide their own function for checking for completeness
	// random linker error ????
	// Resolved 9/11/16
	// exposed variable to lower level classes.
	// this should be changed at a later date when the linker
	// errors can be resolved
	std::cout << testGame.mGameIsOver << std::endl;
}


/*
*/