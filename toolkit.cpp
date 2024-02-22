/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺�����ģ��
*/
#pragma once
#include"StudentManagerSystem.h"
using namespace std;

//�ж��ַ����Ƿ�Ϊ����
bool isNumber(const string& s) {
	return std::ranges::all_of(s.begin(), s.end(),[](char c) { return isdigit(c) != 0; });
}

//�ж�ѧ���Ƿ�Ϸ�,�Ա�����Ϊ��������Ҫ���Ծ����޸�
bool judgeStudentId(string id) {
	return id.length() == 8 && isNumber(id);
}

//wchar_t*תchar*
char* wchar_to_char(wchar_t* wChar) {
	int bufSize = WideCharToMultiByte(CP_ACP, NULL, wChar, -1, NULL, 0, NULL, FALSE);
	char* ch = new char[bufSize];
	WideCharToMultiByte(CP_ACP, NULL, wChar, -1, ch, bufSize, NULL, FALSE);
	return ch;
}

//wchar_t*תstring
string wchar_to_string(wchar_t* wChar) {
	int bufSize = WideCharToMultiByte(CP_ACP, NULL, wChar, -1, NULL, 0, NULL, FALSE);
	char* ch = new char[bufSize];
	WideCharToMultiByte(CP_ACP, NULL, wChar, -1, ch, bufSize, NULL, FALSE);
	string str = string(ch, bufSize);
	delete[] ch;
	ch = nullptr;
	return str;
}

//��ȡʱ��utf8תΪunicode
wchar_t* Utf8_2_Unicode(char* row_i) {
	int len = MultiByteToWideChar(CP_UTF8, 0, row_i, strlen(row_i), NULL, 0);
	wchar_t* wszStr = new wchar_t[len + 1];
	MultiByteToWideChar(CP_UTF8, 0, row_i, strlen(row_i), wszStr, len);
	wszStr[len] = '\0';
	return wszStr;
}