/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：打印信息模块
*/

#include"StudentManagerSystem.h"
using namespace std;
void printmessage() {
	if (!StudentMap.empty()) {
		cout << "下面是系统中所储存的信息:\n";
		for (auto& it : StudentMap) {
			cout << it.second.toString() << "\n";
		}
	}
	map<string, studentSubject> studentMap;
	databaseLoad(studentMap);
	if (!studentMap.empty()) {
		cout << "下面是数据库中所储存的信息:\n";
		for (auto& it : studentMap) {
			cout << it.second.toString() << "\n";
		}
	}
	system("pause");
}