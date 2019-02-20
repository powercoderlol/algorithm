#include <string>
#include "LongestSubstring.h"

#include "gtest/gtest.h"

TEST(LongestCommonSubstring, Smoke) {
    char str[30] = "qwerty";
    char str1[30] = "tyqwe";
    char str2[30];
    std::string answer;
    findLongestSubstring(str, str1, str2);

    answer = str2;

    EXPECT_EQ("qwe", answer);
}

TEST(LongestCommonSubstring, LongSize) {
    char str[256] =
        "XbaIHUD6IZXabbSEHUpEXbaIHUD6IZXabbSEHUpEXbaIHUD6IZXabbSEHUpEXbaIHUD6IZ"
        "XabbSEHUpEXJB1bmvy9Uom6W0YPBDYRHUD6IZXabbSEHUpEXbaIHUD6IZXabbSEHUpEXba"
        "IHUD6Isdasdda123123HUpEXbaIHUD6IJB1bmvy9Uom6W0YPBDYRXabbSEHUpEXbaIHUD6"
        "IZXabbSEHUpEXbaIHUD6IZXabbSEHUpEXbaIHUD6IZXa";
    char str1[256] =
        "23123JB1bmvy9Uom6W0YPBDYRasdd211231231424124wddwdaQQQQQQQQQQQQQQQQQQQQ"
        "Qdwnjaksdncjdsbu3982034209384902840909uljfo;wijefwojf[0931]"
        "24234oijewfias;ldkq20i-0i12jeijsncansklf[[[[a]"
        "sddklsfjlsdjfoij02394ujflkslsekjjjasdl...z/"
        "xc,992992929923432535234k;alskd;kwqqq";
    char str2[256];
    std::string answer;
    findLongestSubstring(str, str1, str2);

    answer = str2;

    EXPECT_EQ("JB1bmvy9Uom6W0YPBDYR", answer);
}
