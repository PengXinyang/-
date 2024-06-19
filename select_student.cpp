/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：查询学生信息模块
*/
#include"StudentManagerSystem.h"
#include "select_student.h"
using namespace std;
//查询指定学号信息
void selectId(string id) {
	if (StudentMap.find(id) != StudentMap.end()) {
		cout << StudentMap[id].toString() << "\n";
		system("pause");
	}
	else {
		bool re = existdata(id);
		if (!re)cout << "数据库和系统中都没有该学生信息，请先录入\n";
	}
	
}

void selectMessage()
{
	string id; 
	char ch = '0';
	while (ch != 27) {
		system("cls");
		cout << "请输入待查询的学生学号:\n";
		cin >> id;
		selectId(id);
		cout << "输入esc键退出查询，输入其余任意键继续查询:\n";
		ch = _getch();
	}
}
