#pragma once
#include "mastermindGame.h"
#include <mutex>


namespace mastermind
{
	struct dataProtectionCapsule
	{
		std::mutex dataLock;
		game* gameInstance = NULL;
		bool inUse = false;
	};

	class database
	{
	public:
		// returns index of game
		int createGameInstance(int widthOfGame, int colorsInGames, std::vector<int>& gameSolution);

		// Getters and Setters
		// this should probably just talk to each game
		// method to avoid race conditions
		// game& returnGameInstance(int gameIndex);


		// TODO impliment pass through methods here
		bool endGame(int gameIndex);

		bool postSolutionAttempt(int gameIndex, std::vector<int>& solutionAttempt);
		int getNumberOfTurns(int gameIndex);
		int getWidthOfBoard(int gameIndex);
		int getColorsOfBoard(int gameIndex);
		bool isGameOver(int gameIndex);

		int getNumberOfGamesRunning();


		// must lock data protection capsule before using function!!! 
		std::vector<rowData>& getReferenceToBoard(int gameIndex);

	private:
		void deleteGameInstance(int index);

		std::vector<dataProtectionCapsule> data;

		std::mutex mNumGamesRunningMutex;
		int mNumberOfGamesRunning = 0;

		std::mutex mLowestFreeIndexMutex;
		int refreshLowestFreeInstance();
		int mLowestFreeIndex = 0;
		
	};
}