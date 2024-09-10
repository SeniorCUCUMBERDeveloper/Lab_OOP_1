#include "lib.hpp"
#include "prog.hpp"


/**
 * Функция проверки на гласные кириллические символы.
 * Аргументы символ (const wchar_t&) 
 * См. определение в файле lib.cpp
 */


bool Vowel(const wchar_t& symbol){
    std::wstring alphabet = L"аАеЕёЁиИоОуУыЫэЭюЮяЯ";
    return alphabet.find(symbol) != std::wstring::npos; 
}


/**
 * Функция проверки символа на специальные кириллические символы.
 * Аргументы символ (const wchar_t&) 
 * См. определение в файле lib.cpp
 */


bool Rules(const wchar_t& symbol){
    std::wstring alphabet = L"йЙьЬъЪ";
    return alphabet.find(symbol) != std::wstring::npos; 
}


/**
 * Функция обработки слова в виде std::wstring. На выходе получаем std::wstring слово с разделением на слоги.
 * Аргументы  (const std::wstring &str) 
 * См. определение в файле lib.cpp 
 */


std::wstring func(const std::wstring &str){
    int first_v = 0;
    for (wchar_t symbol : str) {
        if (Vowel(symbol)) {
            break;
        }
        first_v++;
    }
    int cur_pos = 0;
    std::wstring result;
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
            result += L"-";
            cur_pos = seporator;
            first_v = i;
        }
    }
    result.append(str, cur_pos, str.size() - cur_pos);
    return result;
}


/**
 * Функция обработки слова в виде wchar_t* . На выходе получаем wchar_t* слово с разделением на слоги.
 * Аргументы  (wchar_t* const& str) 
 * См. определение в файле lib.cpp 
 */


wchar_t* func(wchar_t* const& str) {
    int first_v = 0;
    int str_len = wcslen(str);
    wchar_t* result = new wchar_t[16];
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
            wcsncpy(result + result_pos, str + cur_pos, separator - cur_pos);
            result_pos += separator - cur_pos;
            result[result_pos] = '-';
            result_pos++;
            cur_pos = separator;
            first_v = i;
        }
    }
    wcsncpy(result + result_pos, str + cur_pos, str_len - cur_pos);
    result[result_pos + str_len - cur_pos] = '\0';
    return result;
}

