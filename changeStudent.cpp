/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺�޸���Ϣģ��
*/
#include"StudentManagerSystem.h"
using namespace std;

//�޸ĵ���ѧ����Ϣ
void change_student(string id) {
	if (StudentMap.find(id) != StudentMap.end()) {
		cout << "ϵͳ�д��ڸ�ѧ����Ϣ�������޸�:\n";
		cout << "��������Ҫ�޸ĵĿ�Ŀ:\n";
		string name; 
		cin >> name;
		cout << "�������޸ĵķ���:\n";
		double score; 
		cin >> score;
		StudentMap[id].editSubject(name, score);
		cout << "�޸����\n";
	}
	else if (search_id(id)) {
		cout << "���ݿ��д��ڸ�����Ϣ\n";
		mysql_query(&mysql, "set names gbk");
		cout << "��������Ҫ�޸ĵĿ�Ŀ:\n";
		string name; cin >> name;
		cout << "�������޸ĵķ���:\n";
		double score; 
		cin >> score;
		string sql;
		sql = "update subject_study set `"+name+"`='" + to_string(score) + "' where `ѧ��`=" + id;
		int re=mysql_real_query(&mysql, sql.c_str(), sql.length());
		if (re) {
			cout << "�޸�ʧ��\n";
			cout << mysql_errno(&mysql) << mysql_error(&mysql) << "\n";
		}
		else cout << "�޸����\n";
	}
	else {
		cout << "��ѧ��������\n";
	}
}

//�޸���Ϣ
void change_students() {
	char ch = '1';
	while(ch != 27) {
		system("cls");
		cout << "�������޸���Ϣ����\n";
		cout << "������Ҫ�޸ĵ�ѧ��ѧ��:\n";
		string id; 
		cin >> id;
		change_student(id);
		cout << "����esc�˳���ǰ���棬��������������޸�\n";
		ch = _getch();
	}
}