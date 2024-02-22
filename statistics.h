#pragma once
/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：数据统计模块
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
//统计一个学生的总成绩
double sum_subject(string id, map<string, studentSubject>& studentMap);

//统计一个学生的平均分
double ave_subject(string id, map<string, studentSubject>& studentMap);

//统计一个学生的绩点
double gpa_subject(string id, map<string, studentSubject>& studentMap);

//统计一个map里面平均数的中位数
media medaev_subject(map<string, studentSubject>& studentMap);

//gpa中位数
media medgpa_subject(map<string, studentSubject>& studentMap);

//全体平均分
double averange(map<string, studentSubject>& studentMap);

//统计
void statics_student();
