/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：保存录入信息模块
*/
#pragma once
#include"saveStudent.h"
void SaveStudent() {
	if (StudentMap.empty()) {
		cout << "系统中没有相关数据，请先将有关信息录入\n";
		system("pause");
		return;
	}
	typeinData(StudentMap);
	StudentMap.clear();
}