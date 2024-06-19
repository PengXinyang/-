/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：杂项功能模块
*/
#pragma once
#include"StudentManagerSystem.h"
using namespace std;
bool judgeStudentId(string id);
bool isNumber(const string& s);
char* wchar_to_char(wchar_t* wChar);
string wchar_to_string(wchar_t* wChar);
//读取时将utf8转为unicode
wchar_t* Utf8_2_Unicode(char* row_i);