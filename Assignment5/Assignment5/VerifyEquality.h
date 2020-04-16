#pragma once
#include "SizedWord.h"
#include <string>

template<typename WordType> void verifyEquality(const WordType& expected, const WordType& actual, const std::string& error)
{
	if (expected != actual)
	{
		throw std::runtime_error(error);
	}
}

