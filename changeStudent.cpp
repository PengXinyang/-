/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：修改信息模块
*/
#include"StudentManagerSystem.h"
using namespace std;

//修改单个学生信息
void change_student(string id) {
	if (StudentMap.find(id) != StudentMap.end()) {
		cout << "系统中存在该学生信息，进行修改:\n";
		cout << "请输入需要修改的科目:\n";
		string name; 
		cin >> name;
		cout << "请输入修改的分数:\n";
		double score; 
		cin >> score;
		StudentMap[id].editSubject(name, score);
		cout << "修改完成\n";
	}
	else if (search_id(id)) {
		cout << "数据库中存在该生信息\n";
		mysql_query(&mysql, "set names gbk");
		cout << "请输入需要修改的科目:\n";
		string name; cin >> name;
		cout << "请输入修改的分数:\n";
		double score; 
		cin >> score;
		string sql;
		sql = "update subject_study set `"+name+"`='" + to_string(score) + "' where `学号`=" + id;
		int re=mysql_real_query(&mysql, sql.c_str(), sql.length());
		if (re) {
			cout << "修改失败\n";
			cout << mysql_errno(&mysql) << mysql_error(&mysql) << "\n";
		}
		else cout << "修改完成\n";
	}
	else {
		cout << "该学生不存在\n";
	}
}

//修改信息
void change_students() {
	char ch = '1';
	while(ch != 27) {
		system("cls");
		cout << "以下是修改信息界面\n";
		cout << "请输入要修改的学生学号:\n";
		string id; 
		cin >> id;
		change_student(id);
		cout << "输入esc退出当前界面，输入其余键继续修改\n";
		ch = _getch();
	}
}