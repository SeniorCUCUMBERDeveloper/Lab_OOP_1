#include "prog.hpp"
#include "lib.hpp"
#include <vector>


/**
 * Функция проверки символа на принадлежность к кириллическим.
 * Аргументы символ (const wchar_t&) 
 * См. определение в файле prog.cpp 
 */


bool Promt(const wchar_t& symbol){
    std::wstring alphabet = L"йЙцЦуУкКеЕнНгГшШщЩзЗхХъЪфФыЫвВаАпПрРоОлЛдДжЖэЭяЯчЧсСмМиИтТьЬбБюЮ";
    return alphabet.find(symbol) != std::wstring::npos; 
}


/**
 * Функция проверки строки; "является ли строка словом".
 * Аргументы  (std::wstring& str) 
 * См. определение в файле prog.cpp 
 */


bool isWord(std::wstring& str){
    std::for_each(str.begin(), str.end(), [](wchar_t& symbol){
        if(!Promt(symbol)){
            throw std::invalid_argument("it's not a word :(");
        }
    });
    return true;
}


/**
 * Функция проверки массива символов; "является ли смассив словом".
 * Аргументы  (wchar_t* const& str) 
 * См. определение в файле prog.cpp 
 */


bool isWord(wchar_t* const& str){
    std::wcout << str[0] << std::endl;
    std::for_each(str, str + wcslen(str), [](wchar_t& symbol){
        if(!Promt(symbol)){
            throw std::invalid_argument("it's not a word :(");
        }
    });
    return true;
}


/**
 * Функция обработки ввода для wchar_t*.
 * Аргументы  (wchar_t* &res) 
 * См. определение в файле prog.cpp 
 */


bool try_read(wchar_t* &res){
    std::wcout << "Input wstring: ";
    std::wcin.getline(res, 37);
    if(std::wcin.eof()){
        throw std::runtime_error("end of file :(");
    }
    if(res == nullptr || res[0] == '\0' || !isWord(res)){
        throw std::invalid_argument("empty :(");
    }
    if(std::wcin.good()){
        return true;
    }
    if(std::wcin.bad()){
        throw std::runtime_error("critical error read ;)");
    }
    return true;
}


/**
 * Оберточная функция-процедура для реализации wchar_t*. Ввод слова в виде массива символов. Обработка слова и вывод результата.
 * Аргументы символ () 
 * См. определение в файле prog.cpp 
 */


void ch(){
    wchar_t* str;
    bool flag = false;
    std::wcin.ignore();
    while(flag == false){
        try{
            str = new wchar_t[37];
            flag = try_read(str);
        }catch(const std::invalid_argument& e){
            delete[] str;
            std::cerr << "Error: " << e.what() << std::endl;
            std::wcout << "try again" << std::endl;
            flag = false;
        }catch(const std::runtime_error& error){
            delete[] str;
            throw;
        }
    }
    wchar_t* out = func(str);
    std::wcout << out << std::endl;
    delete []str;
    delete []out;
}



/**
 * Функция обработки ввода для std::wstring &res. Тип bool, на выходе исключение или true
 * Аргументы  (std::wstring &res) 
 * См. определение в файле prog.cpp 
 */


bool try_read(std::wstring &res){
    std::wcout << "Input wstring: ";
    std::getline(std::wcin, res);
    if(std::wcin.eof()){
        throw std::runtime_error("end of file :(");
    }
    if(res.empty() || res[0] == ' ' || !isWord(res))
    {
        throw std::invalid_argument("empty:(");
    }
    if(std::wcin.good()){
        return true;
    }
    if(std::wcin.bad()){
        throw std::runtime_error("critical error read ;)");
    }
    return true;
}


/**
 * Функция ввода слова в виде std::wstring. На выходе возвращает слово или ошибку.
 * Аргументы ()
 * См. определение в файле prog.cpp 
 */


std::wstring readstr(std::wstring &str){
    std::wstring res;
    bool flag = false;
    std::wcin.ignore();
    while(flag == false){
        try{
            flag = try_read(res);
            }catch(std::invalid_argument& e){
                std::wcout << e.what() << std::endl;
                std::wcout << "try again" << std::endl;
                flag = false;
            }
    }
    return res;
}


/**
 * Оберточная функция-процедура ввода слова в виде std::wstring. Обработки слова и вывода результата.
 * Аргументы ()
 * См. определение в файле prog.cpp 
 */


void wstring(){
    std::wstring str;
    str = readstr(str);
    std::wstring out = func(str);
    std::wcout << out << std::endl;
    return;
}


/**
 * Функция меню / выбора реализации. На выходе int - выбор пункта меню.
 * Аргументы ()
 * См. определение в файле prog.cpp 
 */


int menu(){
    int choiсe;
    std::wcout << "0. using wstring" << std::endl;
    std::wcout << "1. using wchar_t*" << std::endl;
    std::wcout << "2. exit" << std::endl;
    std::wcin >> choiсe;
    if(std::wcin.eof()){
   
        throw std::runtime_error("end of file :(");
    }
    return choiсe;
}


/**
 * Оберточная функция-процедура программы. Реализованная с помощью вектора функций(реализаций);
 * Аргументы ()
 * См. определение в файле prog.cpp 
 */


void prog(){
    int choice;
    std::vector<void (*)()> vec;
    vec.push_back(wstring);
    vec.push_back(ch);
    do{
        choice =  menu();
        if(choice < 2){
            vec[choice]();
        }
    }while(choice != 2);
    return;
}