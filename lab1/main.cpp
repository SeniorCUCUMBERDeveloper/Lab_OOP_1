#include <iostream>
#include <locale>
#include "./src/prog.hpp"


/**
 * main функция проекта.
 * Аргументы ()
 * См. определение в файле main.cpp 
 */



int main(){
    setlocale(LC_ALL, "");
    try{
        prog();
   }catch(std::runtime_error& error){
        std::cerr << "Error: " << error.what() << std::endl;
    }
}