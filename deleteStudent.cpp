/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺ɾ��ѧ����Ϣģ��
*/

#include"StudentManagerSystem.h"
using namespace std;

//ɾ��ѧ����Ϣ
void delete_student() {
	char ch = '1';
	while (ch != 27) {
		system("cls");
		cout << "������ɾ��ѧ����Ϣ�Ľ���\n";
		cout << "������ѧ��ѧ��:\n";
		string id; 
		cin >> id;
		if (StudentMap.find(id) != StudentMap.end()) {
			cout << "ϵͳ�д��ڵ�ǰ��Ϣ������ϵͳ��ɾ��\n";
			StudentMap.erase(id);
		}
		else {
			if (search_id(id)) {
				cout << "��ȷ������ѧ����Ϣ��";
				if (delete_id(id))
					cout << "��ѧ����Ϣɾ���ɹ�\n";
				else cout << "��ѧ����Ϣɾ��ʧ��\n";
			}
			else cout << "�����ڸ�ѧ����Ϣ\n";
		}
		cout << "����esc�˳���ǰ���棬�������������ɾ��\n";
		ch = _getch();
	}
}