#include <iostream>
#include "./src/prog.hpp"


/**
 * main функция проекта.
 * Аргументы ()
 * См. определение в файле main.cpp 
 */



int main(){
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    try{
        prog();
   }catch(std::runtime_error& error){
        std::cerr << "Error: " << error.what() << std::endl;
    }
}