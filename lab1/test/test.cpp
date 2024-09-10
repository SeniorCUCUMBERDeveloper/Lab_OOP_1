#include <gtest/gtest.h>
#include "../src/lib.hpp"


TEST(AdditionTest, TestString){
    std::wstring str = L"калиненков";
    std::wstring answer = L"ка-ли-нен-ков";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
    str = L"карта";
    answer = L"кар-та";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
    str = L"алгоритм";
    answer = L"ал-го-ритм";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
    str = L"мудрствуя";
    answer = L"мудр-ству-я";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
    str = L"верьфи";
    answer = L"верь-фи";
    EXPECT_STREQ(func(str).c_str(), answer.c_str());
}


TEST(AdditionTest, TestChar){
    wchar_t* str = L"калиненков";
    wchar_t* answer = L"ка-ли-нен-ков";
    EXPECT_STREQ(func(str), answer);
    str = L"карта";
    answer = L"кар-та";
    EXPECT_STREQ(func(str), answer);
    str = L"алгоритм";
    answer = L"ал-го-ритм";
    EXPECT_STREQ(func(str), answer);
    str = L"мудрствуя";
    answer = L"мудр-ству-я";
    EXPECT_STREQ(func(str), answer);
    str = L"верьфи";
    answer = L"верь-фи";
    EXPECT_STREQ(func(str), answer);
}


int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}