/*
* ���ߣ�������
* ѧԺ�����ѧԺ
* ѧ�ţ�21375049
* ģ�飺���ݿ⴦��ģ��
*/
#pragma once
#include"StudentManagerSystem.h"
#include"student.h"
#include"toolkit.h"
using namespace std;
//�������ݿ���
extern MYSQL mysql;

//������񣬱������Ϊsubject_study
bool createTable(string sub[], int n);

//������
bool datatable();

//�жϵ���ѧ�������Ƿ����,true��ʾ����
bool existdata(string id);

//����¼���map����
bool typeinData(map<string, studentSubject>&studentMap);

//���ݿ��ʼ������
bool databaseStart();

//���ݿ�رպ���
void databaseEnd();

//�����ݿ�����װ��studentMap�У���ȡ���ݣ�
bool databaseLoad(map<string, studentSubject>&studentMap);

//��ȡ�ֶ��б�ͷ����
vector<string> field_table();

//ɾ��ָ��ѧ�ŵ���Ϣ
bool delete_id(string id);

//���ҵ���ѧ�ŵ���Ϣ
bool search_id(string id);