#ifndef WHATEVER_HPP
#define WHATEVER_HPP

namespace Utility
{
	template <typename T>
	void swap(T& firstValue, T& secondValue)
	{
		T temp;

		temp = firstValue;
		firstValue = secondValue;
		secondValue = temp;
	}

	template <typename T>
	T min(T firstValue, T secondValue)
	{
		if (firstValue < secondValue)
		{
			return firstValue;
		}
		else 
		{
			return secondValue;
		}
	}

	template <typename T>
	T max(T firstValue, T secondValue)
	{
		if (firstValue > secondValue)
		{
			return firstValue;
		}
		else
		{
			return secondValue;
		}
	}
}
#endif