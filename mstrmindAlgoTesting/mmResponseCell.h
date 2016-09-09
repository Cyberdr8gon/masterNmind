#pragma once

namespace mastermind
{
	enum responseState
	{
		o = 1, 
		x
	};

	class responseCell
	{
	public:
		inline void setResponseValue(int responseValue);
		inline void setResponseValue(responseState responseValue);
		inline responseState returnResponseValue() const;

	private:
		responseState mResponseValue = o;
	};
}