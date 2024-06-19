/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺����ͳ��ģ��
*/
#include"StudentManagerSystem.h"
#include"statistics.h"
using namespace std;

//ͳ��һ��ѧ�����ܳɼ�
double sum_subject(string id, map<string, studentSubject>& studentMap) {
	if (studentMap.find(id) == studentMap.end()) {
		cout << "û���ҵ�ѧ��Ϊ" + id + "��ѧ����\n";
		return -1;
	}
	map<string, double> subject = studentMap[id].getSubject();
	double ans = 0;
	for (auto& it : subject) {
		ans += it.second;
	}
	return ans;
}

//ͳ��һ��ѧ����ƽ����
double ave_subject(string id, map<string, studentSubject>& studentMap) {
	double sum = sum_subject(id, studentMap);
	if (sum < 0) { 
		cout << "�����ڸ����ɼ�\n"; 
		return -1; 
	}
	return sum / (studentMap[id].getSubject().size());
}

//ͳ��һ��ѧ���ļ���
double gpa_subject(string id, map<string, studentSubject>& studentMap) {
	if (studentMap.find(id) == studentMap.end()) {
		cout << "û���ҵ�ѧ��Ϊ" + id + "��ѧ����\n";
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

//ͳ��һ��map����ƽ��������λ��
media medaev_subject(map<string, studentSubject>& studentMap) {
	int n = studentMap.size();
	if (n == 0) {
		cout << "û��ѧ������\n";
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

//gpa��λ��
media medgpa_subject(map<string, studentSubject>& studentMap) {
	int n = studentMap.size();
	if (n == 0) {
		cout << "û��ѧ������\n";
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

//ȫ��ƽ����
double averange(map<string, studentSubject>& studentMap) {
	double ans = 0;
	for (auto& it : studentMap) {
		double score = ave_subject(it.first, studentMap);
		ans += score;
	}
	ans /= (studentMap.size());
	return ans;
}

//ͳ��
void statics_student() {
	system("cls");
	cout << "������ͳ��ҳ��\n\n";
	char ch = '1';
	map<string, studentSubject> studentMap = StudentMap;
	databaseLoad(studentMap);
	while (ch != 27) {
		cout << "�������ͳ��ѧ����ѧ��:\n";
		string id; 
		cin >> id;
		cout << "�������ܳɼ�Ϊ:" << sum_subject(id, studentMap)<<"\n";
		cout << "������ƽ����Ϊ:" << ave_subject(id, studentMap)<<"\n";
		cout << "�����ļ���Ϊ:" << gpa_subject(id, studentMap)<<"\n\n";
		cout << "������esc�˳���ǰ���棬���������������ͳ��\n\n";
		ch = _getch();
	}
	if (!studentMap.empty()) {
		cout << "����ѧ����λ��Ϊ:\n";
		cout << "ƽ����:" << medaev_subject(studentMap).score << "\n";
		cout << "gpa:" << medgpa_subject(studentMap).score << "\n";
		cout << "����ѧ��ƽ������Ϊ:\n";
		cout << averange(studentMap)<<"\n";
		system("pause");
	}
}