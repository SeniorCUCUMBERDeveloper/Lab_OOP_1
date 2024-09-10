#include "prog.hpp"
#include "lib.hpp"
#include <vector>


/**
 * Функция проверки символа на принадлежность к кириллическим.
 * Аргументы символ (const char&) 
 * См. определение в файле prog.cpp 
 */


bool Promt(const char& symbol){
    std::string alphabet = "qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM";
    return alphabet.find(symbol) != std::string::npos; 
}


/**
 * Функция проверки строки; "является ли строка словом".
 * Аргументы  (std::string& str) 
 * См. определение в файле prog.cpp 
 */


bool isWord(std::string& str){
    std::for_each(str.begin(), str.end(), [](char& symbol){
        if(!Promt(symbol)){
            throw std::invalid_argument("it's not a word :(");
        }
    });
    return true;
}


/**
 * Функция проверки массива символов; "является ли смассив словом".
 * Аргументы  (char* const& str) 
 * См. определение в файле prog.cpp 
 */


bool isWord(char* const& str){
    std::for_each(str, str + strlen(str), [](char& symbol){
        if(!Promt(symbol)){
            throw std::invalid_argument("it's not a word :(");
        }
    });
    return true;
}


/**
 * Функция обработки ввода для char*.
 * Аргументы  (char* &res) 
 * См. определение в файле prog.cpp 
 */


bool try_read(char* &res){
    std::cout << "Input string: ";
    std::cin.getline(res, 37);
    if(std::cin.eof()){
        throw std::runtime_error("end of file :(");
    }
    if(res == nullptr || res[0] == '\0' || !isWord(res)){
        throw std::invalid_argument("empty :(");
    }
    if(std::cin.good()){
        return true;
    }
    if(std::cin.bad()){
        throw std::runtime_error("critical error read ;)");
    }
    return true;
}


/**
 * Оберточная функция-процедура для реализации char*. Ввод слова в виде массива символов. Обработка слова и вывод результата.
 * Аргументы символ () 
 * См. определение в файле prog.cpp 
 */


void ch(){
    char* str;
    bool flag = false;
    std::cin.ignore();
    while(flag == false){
        try{
            str = new char[37];
            flag = try_read(str);
        }catch(const std::invalid_argument& e){
            delete[] str;
            std::cerr << "Error: " << e.what() << std::endl;
            std::cout << "try again" << std::endl;
            flag = false;
        }catch(const std::runtime_error& error){
            delete[] str;
            throw;
        }
    }
    char* out = func(str);
    std::cout << out << std::endl;
    delete []str;
    delete []out;
}



/**
 * Функция обработки ввода для std::string &res. Тип bool, на выходе исключение или true
 * Аргументы  (std::string &res) 
 * См. определение в файле prog.cpp 
 */


bool try_read(std::string &res){
    std::cout << "Input string: ";
    std::getline(std::cin, res);
    if(std::cin.eof()){
        throw std::runtime_error("end of file :(");
    }
    if(res.empty() || res[0] == ' ' || !isWord(res))
    {
        throw std::invalid_argument("empty:(");
    }
    if(std::cin.good()){
        return true;
    }
    if(std::cin.bad()){
        throw std::runtime_error("critical error read ;)");
    }
    return true;
}


/**
 * Функция ввода слова в виде std::string. На выходе возвращает слово или ошибку.
 * Аргументы ()
 * См. определение в файле prog.cpp 
 */


std::string readstr(std::string &str){
    std::string res;
    bool flag = false;
    std::cin.ignore();
    while(flag == false){
        try{
            flag = try_read(res);
            }catch(std::invalid_argument& e){
                std::cout << e.what() << std::endl;
                std::cout << "try again" << std::endl;
                flag = false;
            }
    }
    return res;
}


/**
 * Оберточная функция-процедура ввода слова в виде std::string. Обработки слова и вывода результата.
 * Аргументы ()
 * См. определение в файле prog.cpp 
 */


void string(){
    std::string str;
    str = readstr(str);
    std::string out = func(str);
    std::cout << out << std::endl;
    return;
}


/**
 * Функция меню / выбора реализации. На выходе int - выбор пункта меню.
 * Аргументы ()
 * См. определение в файле prog.cpp 
 */


int menu(){
    int choiсe;
    std::cout << "0. using string" << std::endl;
    std::cout << "1. using char*" << std::endl;
    std::cout << "2. exit" << std::endl;
    std::cin >> choiсe;
    if(std::cin.eof()){
   
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
    vec.push_back(string);
    vec.push_back(ch);
    do{
        choice =  menu();
        if(choice < 2){
            vec[choice]();
        }
    }while(choice != 2);
    return;
}