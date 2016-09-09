#pragma once

namespace mastermind
{
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
}