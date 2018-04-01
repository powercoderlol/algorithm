#include "LongestSubstring.h"

int main()
{
	char str[30], str1[30],str2[30];
	scanf("%s", str);
	scanf("%s", str1);

	findLongestSubstring(str, str1, str2);
	printf("%s\n", str2);

	return 0;
}

