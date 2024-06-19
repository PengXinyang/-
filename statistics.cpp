/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：数据统计模块
*/
#include"StudentManagerSystem.h"
#include"statistics.h"
using namespace std;

//统计一个学生的总成绩
double sum_subject(string id, map<string, studentSubject>& studentMap) {
	if (studentMap.find(id) == studentMap.end()) {
		cout << "没有找到学号为" + id + "的学生。\n";
		return -1;
	}
	map<string, double> subject = studentMap[id].getSubject();
	double ans = 0;
	for (auto& it : subject) {
		ans += it.second;
	}
	return ans;
}

//统计一个学生的平均分
double ave_subject(string id, map<string, studentSubject>& studentMap) {
	double sum = sum_subject(id, studentMap);
	if (sum < 0) { 
		cout << "不存在该生成绩\n"; 
		return -1; 
	}
	return sum / (studentMap[id].getSubject().size());
}

//统计一个学生的绩点
double gpa_subject(string id, map<string, studentSubject>& studentMap) {
	if (studentMap.find(id) == studentMap.end()) {
		cout << "没有找到学号为" + id + "的学生。\n";
		return -1;
	}
	double ans = 0;
	map<string, double> subject = studentMap[id].getSubject();
	for (auto& it : subject) {
		double gpa = 4 - 3 * (pow(100 - it.second, 2) / 1600);
		ans += gpa;
	}
	ans /= subject.size();
	return ans;
}

//统计一个map里面平均数的中位数
media medaev_subject(map<string, studentSubject>& studentMap) {
	int n = studentMap.size();
	if (n == 0) {
		cout << "没有学生数据\n";
		system("pause");
		media m;
		m.id = "";
		m.score = -1;
		return m;
	}
	media* median = new media[n];
	int p = 0;
	for (auto& it : studentMap) {
		double ans = ave_subject(it.first, studentMap);
		median[p].id = it.first;
		median[p].score = ans;
		++p;
	}
	sort(median, median + n);
	if (n % 2) {
		media m=median[(n - 1) / 2];
		delete[]median;
		return m;
	}
	else {
		media m = median[n / 2 - 1];;
		delete[]median;
		return m; 
	}
}

//gpa中位数
media medgpa_subject(map<string, studentSubject>& studentMap) {
	int n = studentMap.size();
	if (n == 0) {
		cout << "没有学生数据\n";
		system("pause");
		media m;
		m.id = "";
		m.score = -1;
		return m;
	}
	media* median = new media[n];
	int p = 0;
	for (auto& it : studentMap) {
		double ans = gpa_subject(it.first, studentMap);
		median[p].id = it.first;
		median[p].score = ans;
		++p;
	}
	sort(median, median + n);
	if (n % 2) {
		media m = median[(n - 1) / 2];
		delete[]median;
		return m;
	}
	else {
		media m = median[n / 2 - 1];;
		delete[]median;
		return m;
	}
}

//全体平均分
double averange(map<string, studentSubject>& studentMap) {
	double ans = 0;
	for (auto& it : studentMap) {
		double score = ave_subject(it.first, studentMap);
		ans += score;
	}
	ans /= (studentMap.size());
	return ans;
}

//统计
void statics_student() {
	system("cls");
	cout << "以下是统计页面\n\n";
	char ch = '1';
	map<string, studentSubject> studentMap = StudentMap;
	databaseLoad(studentMap);
	while (ch != 27) {
		cout << "请输入待统计学生的学号:\n";
		string id; 
		cin >> id;
		cout << "该生的总成绩为:" << sum_subject(id, studentMap)<<"\n";
		cout << "该生的平均分为:" << ave_subject(id, studentMap)<<"\n";
		cout << "该生的绩点为:" << gpa_subject(id, studentMap)<<"\n\n";
		cout << "请输入esc退出当前界面，按其余任意键继续统计\n\n";
		ch = _getch();
	}
	if (!studentMap.empty()) {
		cout << "所有学生中位数为:\n";
		cout << "平均分:" << medaev_subject(studentMap).score << "\n";
		cout << "gpa:" << medgpa_subject(studentMap).score << "\n";
		cout << "所有学生平均分数为:\n";
		cout << averange(studentMap)<<"\n";
		system("pause");
	}
}