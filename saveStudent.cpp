/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺����¼����Ϣģ��
*/
#pragma once
#include"saveStudent.h"
void SaveStudent() {
	if (StudentMap.empty()) {
		cout << "ϵͳ��û��������ݣ����Ƚ��й���Ϣ¼��\n";
		system("pause");
		return;
	}
	typeinData(StudentMap);
	StudentMap.clear();
}