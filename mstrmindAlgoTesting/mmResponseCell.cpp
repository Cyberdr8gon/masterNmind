#pragma once
#include "mmResponseCell.h"
#include <cstdlib>

namespace mastermind
{
	void responseCell::setResponseValue(int responseValue)
	{
		if(responseValue != 1 || responseValue != 2)
		{
			// flip out, some how a invalid responseValue got here
			// TODO ERROR HANDLING
			exit(100);
		}

		mResponseValue = static_cast<responseState>(responseValue);
	}

	void responseCell::setResponseValue(responseState responseValue)
	{
		mResponseValue = responseValue;
	}

	responseState responseCell::returnResponseValue() const
	{
		return mResponseValue;
	}


}
