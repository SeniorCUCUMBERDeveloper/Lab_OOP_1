#ifndef PROG_HPP
#define PROG_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>

int menu();
void prog();
bool Promt(const char& symbol);
bool isWord(std::string& str);
bool isWord(char* const& str);
bool try_read(char* &res);
void ch();
bool try_read(std::string &res);
std::string  readstr(std::string &res);
void string();


#endif