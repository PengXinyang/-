/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺¼��ѧ����Ϣģ��
*/
#pragma once
#include"StudentManagerSystem.h"
#include"student.h"
#include"database.h"
#include"toolkit.h"
using namespace std;

void InputStudent() {
	
	cout << "¼��ѧ����Ϣ\n";
	cout << "������ѧ��ѧ��:\n";
	string StudentId; 
	cin >> StudentId;

	while (!judgeStudentId(StudentId)) {
		cout << "ѧ�Ÿ�ʽ��������������\n";
		cout << "������ѧ��ѧ��:\n";
		cin >> StudentId;
	}

	//����ѧ����Ϣ
	studentSubject student_subject;
	if (StudentMap.find(StudentId) != StudentMap.end() || existdata(StudentId)) {
		if (StudentMap.find(StudentId) != StudentMap.end()) {
			cout << "��ѧ���Ѿ�������ϵͳ�������Ϣ���£���˶��Ƿ���ȷ�����д�����ǰ���޸�ҳ������޸�\n\n";
			student_subject = StudentMap[StudentId];
			cout << student_subject.getStudent().toString() << "\n\n";
		}
		else {
			return;
		}
		cout << "��ȷ�����󣬰����������¼��ɼ�����esc�������޸�ҳ��\n";
		char cc = _getch();
		if (cc == 27)return;
	}
	else {
		cout << "��ѧ����δ¼�룬�����������Ϣ\n";
		cout << "������ѧ��ѧԺ:\n";
		string college; 
		cin >> college;
		cout << "������ѧ������:\n";
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
		cout << "¼��ѧ��ѧ�Ƴɼ����������ѧ����ϵͳ��ʼ�������ʱ��ѧ����Ϣƥ��\n";
		cout << "���ѧ����Ϣ���£�";
		for (int i = 3; i < str.size(); ++i)
			cout << str[i] << " ";
		cout << "\n������ѧ������:\n";
		string subjectName; 
		cin >> subjectName;
		cout << "������ѧ���ɼ�:\n";
		double score; 
		cin >> score;
		student_subject.addSubject(subjectName, score);
		cout << "������esc�˳�¼�룬�������������ַ�����¼��:\n";
		ch = _getch();
	}
	StudentMap[StudentId] = student_subject;
	cout << "ѧ����Ϣ¼��ɹ�,��ע��ǰ�����������б���\n";
	system("pause");
}