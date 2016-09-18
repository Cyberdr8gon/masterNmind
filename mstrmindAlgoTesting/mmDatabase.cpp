#include "mmDatabase.h"
#include <iostream>

namespace mastermind
{
	int database::createGameInstance(int widthOfGame, int colorsInGames, std::vector<int>& gameSolution)
	{
		mLowestFreeIndexMutex.lock();
		int index = mLowestFreeIndex;
		refreshLowestFreeInstance();
		mLowestFreeIndexMutex.unlock();

		data[index].dataLock.lock();
		if(data[index].inUse)
		{
			// FREAK OUT EVERYTHING BAD ABOUT
			// MULTITHREADING JUST HAPPENED AT ONCE
			std::cout << "Error: currently overwriting game data" << std::endl;
		}
		data[index].inUse = true;
		if(data[index].gameInstance != NULL)
		{
			free((data[index].gameInstance));
		}
		data[index].gameInstance = new game(widthOfGame, colorsInGames, gameSolution);
		data[index].dataLock.unlock();

		mNumGamesRunningMutex.lock();
		mNumberOfGamesRunning++;
		mNumGamesRunningMutex.unlock();

		return index;
	}

	void database::deleteGameInstance(int index)
	{
		data[index].dataLock.lock();
		if(!data[index].inUse)
		{
			// game cell is malformed
			std::cout << "error: cell malformed, correcting" << std::endl;
		}
		free(data[index].gameInstance);
		data[index].gameInstance = NULL;
		data[index].inUse = false;

		mLowestFreeIndexMutex.lock();
		if(mLowestFreeIndex > index)
		{
			mLowestFreeIndex = index;
		}
		mLowestFreeIndexMutex.unlock();
		data[index].dataLock.unlock();
	}

	int database::refreshLowestFreeInstance()
	{
		mLowestFreeIndexMutex.lock();
		bool isFound = false;
		int j = data.size() + 1;
		for (int i = 0; i < data.size(); i++)
		{
			if(data[i].dataLock.try_lock())
			{
				if (!(data[i].inUse) && i < j)
				{
					j = i;
				}
				data[i].dataLock.unlock();
			}
		}

		mLowestFreeIndex = j;
		mLowestFreeIndexMutex.unlock();
		return j;
	}

	int database::getNumberOfGamesRunning()
	{
		mNumGamesRunningMutex.lock();
		int temp = mNumberOfGamesRunning;
		mNumGamesRunningMutex.unlock();
		return temp;
	}

	bool database::isGameOver(int gameIndex)
	{
		data[gameIndex].dataLock.lock();
		if (!data[gameIndex].inUse)
		{
			data[gameIndex].dataLock.unlock();
			return true;
		}

		std::vector<rowData> temp = getReferenceToBoard(gameIndex);
		if(temp[temp.size()].isGameOver())
		{
			data[gameIndex].dataLock.unlock();
			deleteGameInstance(gameIndex);
			return true;
		}

		auto intResponse = temp[temp.size()].getIntResponse();
		for (int ir : intResponse)
		{
			if(ir != 2)
			{
				data[gameIndex].dataLock.unlock();
				return false;
			}
		}

		data[gameIndex].dataLock.unlock();
		deleteGameInstance(gameIndex);
		return true;
	}

	bool database::endGame(int gameIndex)
	{
		deleteGameInstance(gameIndex);
		return true;
	}

	bool database::postSolutionAttempt(int gameIndex, std::vector<int>& solutionAttempt)
	{
		data[gameIndex].dataLock.lock();
		data[gameIndex].gameInstance->postSolutionAttempt(solutionAttempt);
		data[gameIndex].dataLock.unlock();
		return true;
	}

	int database::getNumberOfTurns(int gameIndex)
	{
		data[gameIndex].dataLock.lock();
		int numOfTurns = data[gameIndex].gameInstance->getNumberOfTurns();
		data[gameIndex].dataLock.unlock();
		return numOfTurns;
	}

	int database::getWidthOfBoard(int gameIndex)
	{
		data[gameIndex].dataLock.lock();
		int widthOfBoard = data[gameIndex].gameInstance->mWidthOfBoard;
		data[gameIndex].dataLock.unlock();
		return widthOfBoard;
	}

	int database::getColorsOfBoard(int gameIndex)
	{
		data[gameIndex].dataLock.lock();
		int colorsOfBoard = data[gameIndex].gameInstance->mColorsOfBoard;
		data[gameIndex].dataLock.unlock();
		return colorsOfBoard;
	}

	std::vector<rowData>& database::getReferenceToBoard(int gameIndex)
	{
		return data[gameIndex].gameInstance->boardDataVector;
	}

}
