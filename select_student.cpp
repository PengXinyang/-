/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺��ѯѧ����Ϣģ��
*/
#include"StudentManagerSystem.h"
#include "select_student.h"
using namespace std;
//��ѯָ��ѧ����Ϣ
void selectId(string id) {
	if (StudentMap.find(id) != StudentMap.end()) {
		cout << StudentMap[id].toString() << "\n";
		system("pause");
	}
	else {
		bool re = existdata(id);
		if (!re)cout << "���ݿ��ϵͳ�ж�û�и�ѧ����Ϣ������¼��\n";
	}
	
}

void selectMessage()
{
	string id; 
	char ch = '0';
	while (ch != 27) {
		system("cls");
		cout << "���������ѯ��ѧ��ѧ��:\n";
		cin >> id;
		selectId(id);
		cout << "����esc���˳���ѯ���������������������ѯ:\n";
		ch = _getch();
	}
}
