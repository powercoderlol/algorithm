#include "gtest/gtest.h"
#include "../LongestSubstring.h"
#include <string>


TEST(SimpleSmokeTest, Positive)
{
	char str[30] = "qwerty";
	char str1[30] = "tyqwe";
	char str2[30];
	std::string answer;
	findLongestSubstring(str, str1, str2);

	answer = str2;

	EXPECT_EQ("qwe", answer);
}

