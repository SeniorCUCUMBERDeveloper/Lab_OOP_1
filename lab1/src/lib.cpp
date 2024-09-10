#include "lib.hpp"
#include "prog.hpp"


/**
 * Функция проверки на гласные кириллические символы.
 * Аргументы символ (const char&) 
 * См. определение в файле lib.cpp
 */


bool Vowel(const char& symbol){
    std::string alphabet = "AaOoUuYyeEiI";
    return alphabet.find(symbol) != std::string::npos; 
}


/**
 * Функция проверки символа на специальные кириллические символы.
 * Аргументы символ (const char&) 
 * См. определение в файле lib.cpp
 */


bool Rules(const char& symbol){
    std::string alphabet = "bQq";
    return alphabet.find(symbol) != std::string::npos; 
}


/**
 * Функция обработки слова в виде std::string. На выходе получаем std::string слово с разделением на слоги.
 * Аргументы  (const std::string &str) 
 * См. определение в файле lib.cpp 
 */


std::string func(const std::string &str){
    int first_v = 0;
    for (char symbol : str) {
        if (Vowel(symbol)) {
            break;
        }
        first_v++;
    }
    int cur_pos = 0;
    std::string result;
    for (int i = first_v + 1; i < str.size(); ++i) {
        if (Vowel(str[i])) {
            int vowel_1 = first_v, vowel_2 = i;
            int seporator = vowel_2;
            for(int j = vowel_1 + 1; j < vowel_2; ++j){
                if(Rules(str[j])){
                    seporator = j+1;
                    break;
                }
            }
            if(seporator == vowel_2){
                if (vowel_2 - vowel_1 <= 2) {
                    seporator = vowel_1 + 1;
                } else if (vowel_2 - vowel_1 >= 6) {
                    seporator = vowel_2 - 3;
                } else {
                    seporator = vowel_1 + 2;
                }
            }
            result.append(str, cur_pos, seporator - cur_pos);
            result += "-";
            cur_pos = seporator;
            first_v = i;
        }
    }
    result.append(str, cur_pos, str.size() - cur_pos);
    return result;
}


/**
 * Функция обработки слова в виде char* . На выходе получаем char* слово с разделением на слоги.
 * Аргументы  (char* const& str) 
 * См. определение в файле lib.cpp 
 */


char* func(char* const& str) {
    int first_v = 0;
    int str_len = strlen(str);
    char* result = new char[16];
    for (int i = 0; i < str_len; ++i) {
        if (Vowel((str)[i])) {
            first_v = i;
            break;
        }
    }
    int cur_pos = 0;
    int result_pos = 0;
    for (int i = first_v + 1; i < str_len; ++i) {
        if (Vowel((str)[i])) {
            int vowel_1 = first_v, vowel_2 = i;
            int separator = vowel_2;
            for (int j = vowel_1 + 1; j < vowel_2; ++j) {
                if (Rules((str)[j])) {
                    separator = j + 1;
                    break;
                }
            }
            if (separator == vowel_2) {
                if (vowel_2 - vowel_1 <= 2) {
                    separator = vowel_1 + 1;
                } else if (vowel_2 - vowel_1 >= 6) {
                    separator = vowel_2 - 3;
                } else {
                    separator = vowel_1 + 2;
                }
            }
            strncpy(result + result_pos, str + cur_pos, separator - cur_pos);
            result_pos += separator - cur_pos;
            result[result_pos] = '-';
            result_pos++;
            cur_pos = separator;
            first_v = i;
        }
    }
    strncpy(result + result_pos, str + cur_pos, str_len - cur_pos);
    result[result_pos + str_len - cur_pos] = '\0';
    return result;
}

