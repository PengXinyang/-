#pragma once
/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺����ͳ��ģ��
*/
#include"StudentManagerSystem.h"
using namespace std;
struct media {
	string id = "";
	double score = 0;
	bool operator <(const media& m) {
		return score == m.score ? id < m.id : score < m.score;
	}
};
//ͳ��һ��ѧ�����ܳɼ�
double sum_subject(string id, map<string, studentSubject>& studentMap);

//ͳ��һ��ѧ����ƽ����
double ave_subject(string id, map<string, studentSubject>& studentMap);

//ͳ��һ��ѧ���ļ���
double gpa_subject(string id, map<string, studentSubject>& studentMap);

//ͳ��һ��map����ƽ��������λ��
media medaev_subject(map<string, studentSubject>& studentMap);

//gpa��λ��
media medgpa_subject(map<string, studentSubject>& studentMap);

//ȫ��ƽ����
double averange(map<string, studentSubject>& studentMap);

//ͳ��
void statics_student();
