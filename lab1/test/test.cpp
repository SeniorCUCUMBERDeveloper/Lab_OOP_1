#include <gtest/gtest.h>
#include "../src/lib.hpp"


TEST(AdditionTest, TestString){
    std::string str = "kalinenkov";
    std::string answer = "ka-li-nen-kov";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
    str = "qwerty";
    answer = "qwer-ty";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
    str = "algorithm";
    answer = "al-go-rithm";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
    str = "mydrstvya";
    answer = "mydr-stvy-a";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
    str = "verbfe";
    answer = "verb-fe";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
}


TEST(AdditionTest, TestChar){
    char* str = "kalinenkov";
    char* answer = "ka-li-nen-kov";
    EXPECT_STREQ(func(str), answer);
    str = "qwerty";
    answer = "qwer-ty";
    EXPECT_STREQ(func(str), answer);
    str = "algorithm";
    answer = "al-go-rithm";
    EXPECT_STREQ(func(str), answer);
    str = "mydrstvya";
    answer = "mydr-stvy-a";
    EXPECT_STREQ(func(str), answer);
    str = "verbfe";
    answer = "verb-fe";
    EXPECT_STREQ(func(str), answer);
}


int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}