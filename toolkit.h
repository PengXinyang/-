/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺�����ģ��
*/
#pragma once
#include"StudentManagerSystem.h"
using namespace std;
bool judgeStudentId(string id);
bool isNumber(const string& s);
char* wchar_to_char(wchar_t* wChar);
string wchar_to_string(wchar_t* wChar);
//��ȡʱ��utf8תΪunicode
wchar_t* Utf8_2_Unicode(char* row_i);