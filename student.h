/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：学生类模块
*/
#pragma once
#include<string>
#include<map>
#include<Windows.h>
using namespace std;
class Student {
private:
	string college = "";//学院
	string StudentId = "";//学号
	string name = "";//姓名

public:

	Student() = default;

	Student(const string& college, const string& StudentId, const string& name)
		: college(college), StudentId(StudentId), name(name)
	{
	}
	Student(const Student& s) {
		college = s.college;
		StudentId = s.StudentId;
		name = s.name;
	}
	bool operator==(const Student& other) const
	{
		return college == other.college && StudentId == other.StudentId && name == other.name;
	}

	//打印相关信息
	string toString();

	//修改学号
	void setStudentId(string setStudentId);

	// 修改学院
	void setCollege(string college);

	//修改姓名
	void setName(string name);

	//查询学号
	string getStudentId();
	//查询学院
	string getCollege();
	//查询姓名
	string getName();
};

class studentSubject {
	Student student;
	map<string,double> subject;

public:

	studentSubject() = default;

	studentSubject(const Student& student)
		: student(student), subject()
	{
	}

	studentSubject(const Student& student, const map<string, double>& subject)
		: student(student), subject(subject)
	{
	}

	//获取学生
	Student getStudent();

	//获取该学生成绩表
	map<string, double> getSubject();

	//修改学生
	void setStudent(Student student);

	//直接修改一整张这个学生的成绩表
	void setSubject(map<string, double>subject);

	//增加一门学科的成绩
	void addSubject(string name, double score);

	//修改一门学科的成绩
	void editSubject(string name, double score);

	//打印相关信息
	string toString();
};