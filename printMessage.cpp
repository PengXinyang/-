/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺��ӡ��Ϣģ��
*/

#include"StudentManagerSystem.h"
using namespace std;
void printmessage() {
	if (!StudentMap.empty()) {
		cout << "������ϵͳ�����������Ϣ:\n";
		for (auto& it : StudentMap) {
			cout << it.second.toString() << "\n";
		}
	}
	map<string, studentSubject> studentMap;
	databaseLoad(studentMap);
	if (!studentMap.empty()) {
		cout << "���������ݿ������������Ϣ:\n";
		for (auto& it : studentMap) {
			cout << it.second.toString() << "\n";
		}
	}
	system("pause");
}