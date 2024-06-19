// StudentManagerSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 项目名称：成绩管理系统
*/
#include<bits/stdc++.h>
#include"StudentManagerSystem.h"
#include "welcome.h"
#include"inputStudent.h"
#include"saveStudent.h"
#include"deleteStudent.h"
#include"changeStudent.h"
#include"select_student.h"
#include"printMessage.h"
#include"statistics.h"
#include"database.h"
using namespace std;
map<string, studentSubject>StudentMap;
static void start();
int main(){
    
    if (!databaseStart()||!datatable()) {
        cout << "数据库出现问题，即将退出页面\n";
        cout << "按任意键返回\n";
        char cc = _getch();
        return 0;
    }
    else system("cls");
    start();
    databaseEnd();
    system("pause");;
    return 0;
}
static void start() {
    
    while (1) {
        Welcome();
        char c = _getch();
        system("cls");
        switch (c) {
        case '1':
            InputStudent();
            break;
        case '2':
            SaveStudent();
            break;
        case '3':
            delete_student();
            break;
        case '4':
            change_students();
            break;
        case '5':
            selectMessage();
            break;
        case '6':
            printmessage();
            break;
        case '7':
            statics_student();
            break;
        default:
            break;
        }
        system("cls");
        if (c == 27)
            break;
    }
    system("cls");
    cout << "*         感谢您的使用         *\n";
    cout << "*如果您是不小心退出系统，输入9回到原系统。输入其他任意字符退出系统*\n";
    char ch = _getch();
    if (ch == '9') {
        system("cls");
        start();
    }
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
