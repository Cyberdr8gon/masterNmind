#pragma once

#include "mmSolutionCell.h"
#include <cstdlib>

namespace mastermind {
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
		if(mColorBound < mColorValue)
		{
			// freak out. somehow bad data got this far
			// TODO implement error handling
			exit(100);
		}
	}


}
