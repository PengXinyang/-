/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：录入学生信息模块
*/
#pragma once
#include"StudentManagerSystem.h"
#include"student.h"
#include"database.h"
#include"toolkit.h"
using namespace std;

void InputStudent() {
	
	cout << "录入学生信息\n";
	cout << "请输入学生学号:\n";
	string StudentId; 
	cin >> StudentId;

	while (!judgeStudentId(StudentId)) {
		cout << "学号格式有误，请重新输入\n";
		cout << "请输入学生学号:\n";
		cin >> StudentId;
	}

	//处理学生信息
	studentSubject student_subject;
	if (StudentMap.find(StudentId) != StudentMap.end() || existdata(StudentId)) {
		if (StudentMap.find(StudentId) != StudentMap.end()) {
			cout << "该学生已经存在于系统，相关信息如下，请核对是否正确。如有错误请前往修改页面进行修改\n\n";
			student_subject = StudentMap[StudentId];
			cout << student_subject.getStudent().toString() << "\n\n";
		}
		else {
			return;
		}
		cout << "如确认无误，按任意键继续录入成绩，按esc键返回修改页面\n";
		char cc = _getch();
		if (cc == 27)return;
	}
	else {
		cout << "该学生尚未录入，请输入相关信息\n";
		cout << "请输入学生学院:\n";
		string college; 
		cin >> college;
		cout << "请输入学生姓名:\n";
		string name; 
		cin >> name;
		Student student(college, StudentId, name);
		student_subject = studentSubject(student);
		StudentMap.insert({ StudentId,student_subject });
	}

	char ch='1';
	vector<string>str = field_table();
	while (ch!=27) {
		system("cls");
		cout << "录入学生学科成绩，请输入的学科与系统开始建立表格时的学科信息匹配\n";
		cout << "表格学科信息如下：";
		for (int i = 3; i < str.size(); ++i)
			cout << str[i] << " ";
		cout << "\n请输入学科名称:\n";
		string subjectName; 
		cin >> subjectName;
		cout << "请输入学生成绩:\n";
		double score; 
		cin >> score;
		student_subject.addSubject(subjectName, score);
		cout << "请输入esc退出录入，输入其余任意字符继续录入:\n";
		ch = _getch();
	}
	StudentMap[StudentId] = student_subject;
	cout << "学生信息录入成功,请注意前往保存界面进行保存\n";
	system("pause");
}