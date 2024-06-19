/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺ѧ����ģ��
*/
#pragma once
#include<string>
#include<map>
#include<Windows.h>
using namespace std;
class Student {
private:
	string college = "";//ѧԺ
	string StudentId = "";//ѧ��
	string name = "";//����

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

	//��ӡ�����Ϣ
	string toString();

	//�޸�ѧ��
	void setStudentId(string setStudentId);

	// �޸�ѧԺ
	void setCollege(string college);

	//�޸�����
	void setName(string name);

	//��ѯѧ��
	string getStudentId();
	//��ѯѧԺ
	string getCollege();
	//��ѯ����
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

	//��ȡѧ��
	Student getStudent();

	//��ȡ��ѧ���ɼ���
	map<string, double> getSubject();

	//�޸�ѧ��
	void setStudent(Student student);

	//ֱ���޸�һ�������ѧ���ĳɼ���
	void setSubject(map<string, double>subject);

	//����һ��ѧ�Ƶĳɼ�
	void addSubject(string name, double score);

	//�޸�һ��ѧ�Ƶĳɼ�
	void editSubject(string name, double score);

	//��ӡ�����Ϣ
	string toString();
};