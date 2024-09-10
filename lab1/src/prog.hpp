#ifndef PROG_HPP
#define PROG_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>

int menu();
void prog();
bool Promt(const wchar_t& symbol);
bool isWord(std::wstring& str);
bool isWord(wchar_t* const& str);
bool try_read(wchar_t* &res);
void ch();
bool try_read(std::wstring &res);
std::wstring  readstr(std::wstring &res);
void wstring();


#endif