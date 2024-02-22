/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺ѧ����ģ��
*/
#pragma once
#include"student.h"
#include<iostream>
#include<Windows.h>
using namespace std;

//ѧ����
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

//ѧ����Ŀ��

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
		cout << "����ѧ���Ѿ����ڣ���ǰ���޸���Ϣҳ���޸ĳɼ�\n";
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
		std::cout << "��������Ӧѧ�ƣ���ǰ��¼��ɼ�ҳ��¼���ѧ���ĳɼ�\n";
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


