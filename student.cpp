/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：学生类模块
*/
#pragma once
#include"student.h"
#include<iostream>
#include<Windows.h>
using namespace std;

//学生类
string Student::toString() {
	return college + " " + StudentId + " " + name + " " ;
}

void Student::setCollege(string college) {
	this->college = college;
}

void Student::setStudentId(string StudentId) {
	this->StudentId = StudentId;
}

void Student::setName(string name) {
	this->name = name;
}

string Student::getStudentId()
{
	return StudentId;
}

string Student::getCollege()
{
	return college;
}

string Student::getName()
{
	return name;
}

//学生科目类

Student studentSubject::getStudent()
{
	return student;
}

map<string, double> studentSubject::getSubject()
{
	return subject;
}

void studentSubject::setStudent(Student student)
{
	this->student = student;
}

void studentSubject::setSubject(map<string, double> subject)
{
	this->subject = subject;
}

void studentSubject::addSubject(string name, double score)
{
	if (subject.find(name) != subject.end()) {
		cout << "这门学科已经存在，请前往修改信息页面修改成绩\n";
	}
	else {
		subject.insert({ name,score });
	}
}

void studentSubject::editSubject(string name, double score)
{
	if (subject.find(name) != subject.end()) {
		subject[name] = score;
	}
	else {
		std::cout << "不存在相应学科，请前往录入成绩页面录入该学生的成绩\n";
	}
}

string studentSubject::toString()
{
	string str = student.toString();
	for (auto& it : subject) {
		str += (it.first + " " + to_string(it.second) + " ");
	}
	return str;
}


