/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：欢迎界面模块
*/
#pragma once
#include"StudentManagerSystem.h"
using namespace std;
//欢迎界面
void Welcome() {
    cout << "----------------------------------------\n";
    cout << "*         欢迎使用成绩管理系统         *\n";
    cout << "----------------------------------------\n";
    cout << "*         请选择所需的功能列表         *\n";
    cout << "----------------------------------------\n";
    cout << "*           1、录入学生信息            *\n";
    cout << "*           2、保存学生信息            *\n";
    cout << "*           3、删除学生信息            *\n";
    cout << "*           4、修改学生信息            *\n";
    cout << "*           5、查询学生信息            *\n";
    cout << "*           6、打印学生信息            *\n";
    cout << "*           7、统计成绩信息            *\n";
    cout << "*           esc、退出系统              *\n";
    cout << "----------------------------------------\n";
}
