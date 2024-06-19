/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：删除学生信息模块
*/

#include"StudentManagerSystem.h"
using namespace std;

//删除学生信息
void delete_student() {
	char ch = '1';
	while (ch != 27) {
		system("cls");
		cout << "以下是删除学生信息的界面\n";
		cout << "请输入学生学号:\n";
		string id; 
		cin >> id;
		if (StudentMap.find(id) != StudentMap.end()) {
			cout << "系统中存在当前信息，将从系统中删除\n";
			StudentMap.erase(id);
		}
		else {
			if (search_id(id)) {
				cout << "请确认以上学生信息？";
				if (delete_id(id))
					cout << "该学生信息删除成功\n";
				else cout << "该学生信息删除失败\n";
			}
			else cout << "不存在该学生信息\n";
		}
		cout << "输入esc退出当前界面，输入其余键继续删除\n";
		ch = _getch();
	}
}