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
#include"database.h"
using namespace std;
MYSQL mysql;
//������񣬱������Ϊsubject_study
bool createTable(string sub[],int n) {
	mysql_query(&mysql, "set names gbk");
	string sql = "CREATE TABLE IF NOT EXISTS `subject_study`  ( \
		`ѧ��` int(8) NOT NULL,\
		`����` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,\
		`ѧԺ` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,\ ";
	for (int i = 0; i < n; ++i) {
		sql = sql + "`" + sub[i] + "` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,\ ";
	}
	sql = sql + "PRIMARY KEY(`ѧ��`)\
		) ";
	int re = mysql_query(&mysql, sql.c_str());//���ַ�������const char*
	if (re != 0)
	{
		cout << "�����������ʧ�ܣ�" << mysql_error(&mysql) << endl;
		return false;
	}
	return true;
}

//������
bool datatable() {
	system("cls");
	//���ݿ�Ŀ���н���
	char sql[1024]{ 0 };
	sprintf_s(sql, 1024, "select * from subject_study");
	MYSQL_RES* res = nullptr;
	if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql))) {
		res = mysql_store_result(&mysql);
		mysql_free_result(res);
		cout << "���ݿ��л�û����ر�񣬽��������\n";
		cout << "�������Ŀ����:\n";
		int n; 
		cin >> n;//��Ŀ����
		string* subject = new string[n];
		cout << "����������Ҫ¼��Ŀ�Ŀ����:\n";
		for (int i = 0; i < n; ++i) {
			cin >> subject[i];
		}
		if (!createTable(subject, n)) {
			cout << "�����������ʧ�ܣ�" << mysql_error(&mysql) << endl;
			delete[]subject;
			system("pause");
			return false;
		}
		delete[]subject;
	}
	cout << "���ݿ���������ر��\n";
	res = mysql_store_result(&mysql);
	mysql_free_result(res);
	system("pause");
	return true;
}

//�жϵ���ѧ�������Ƿ����,true��ʾ����
bool existdata(string id) {
	MYSQL_RES* res = nullptr;
	MYSQL_ROW row;
	mysql_query(&mysql, "set names gbk");
	string sql = "select * from subject_study WHERE `ѧ��`=" + id +";";
	int re = mysql_real_query(&mysql, sql.c_str(), (unsigned int)sql.length());
	res = mysql_store_result(&mysql);
	row = mysql_fetch_row(res);
	if (row==NULL)
	{
		//cout << mysql_errno(&mysql) << mysql_error(&mysql) << "\n";
		
		mysql_free_result(res);
		return false;
	}
	else {
		cout << "��ѧ���Ѿ����������ݿ�,����������³ɼ��������Ϣ���£���˶��Ƿ���ȷ�����д�����ǰ���޸�ҳ������޸�\n\n";
		//mysql_query(&mysql, "set names utf8");
		int fields = mysql_num_fields(res);
		for (int i = 0; i < fields; ++i)cout <<row[i] << " ";
		cout << "\n";
		system("pause");
		mysql_free_result(res);
		return true;
	}
}

//����¼���map����
bool typeinData(map<string, studentSubject>&studentMap) {
	//ɸѡ��Ŀ������ʵ������ʱ��ÿ��ѧ����ѧ�Ŀ�Ŀ������ͬ��������ѭ�������п�Ŀ����set�У���ȡ����һ��string����
	set<string>sub;
	for (auto& it : studentMap) {
		map<string, double> subject_map = it.second.getSubject();
		for (auto& iq : subject_map) {
			sub.insert(iq.first);
		}
	}
	int n = sub.size();//��Ŀ����
	string* subject = new string[n];
	int r = 0;
	for (auto it = sub.begin(); it != sub.end(); it++) {
		subject[r] = (*it);
		++r;
	}

	//�����ַ���ƴ�ӣ���������
	//д�����ݿ�ʱ���ñ���Ϊgbk
	mysql_query(&mysql, "set names gbk");
	int re = 0;
	for (auto& it : studentMap) {
		string ss = "insert `subject_study` (`ѧ��`,`����`,`ѧԺ`";
		map<string,double> subscore = it.second.getSubject();
		Student stu = it.second.getStudent();
		for (auto& iq : subscore) {
			ss = ss + ",`" + iq.first + "`";//ѧ��
		}
		ss = ss + ") values(";
		ss = ss + it.first + ","+ "\'" + stu.getName() + "\'," + "\'" + stu.getCollege() + "\'";//ѧ�ţ�������ѧԺ
		for (auto& iq : subscore) {
			ss = ss + ",\'" + to_string(iq.second) + "\'";//�ɼ�
		}
		ss += ");";
		re = mysql_query(&mysql, ss.c_str());//���ַ�������const char*
		if (re != 0)
		{
			cout << "¼����������ʧ�ܣ�" << mysql_error(&mysql) << endl;
			delete[]subject;
			system("pause");
			return false;
		}
	}
	cout << "¼����������ɹ���" << endl;
	delete[]subject;
	system("pause");
	return true;
}

//���ݿ��ʼ������
bool databaseStart() {
	cout << "�������ݿ��С���\n";
	
	//��ʼ��
	mysql_init(&mysql);

	///< ���ӵ����ݿ⣨��������������û��������롢���ݿ������˿ںš�socketָ�롢��ǣ�
	cout << "����������������Ϊ������Ϊ'localhost':\n";
	string hostname; 
	cin >> hostname;
	cout << "�������û�����Ĭ��Ϊ'root':\n";
	string username; 
	cin >> username;
	cout << "����������:\n";
	string password; 
	cin >> password;
	cout << "���������ݿ������:\n";
	string database_name; 
	cin >> database_name;
	cout << "������˿ںţ�Ĭ��Ϊ3306:\n";
	unsigned int port; 
	cin >> port;
	if (!mysql_real_connect(&mysql, hostname.c_str(), username.c_str(), password.c_str(), database_name.c_str(), port, nullptr, 0))
	{
		cout << "���ݿ�����ʧ��" << mysql_errno(&mysql) << endl;
		return false;
	}

	cout << "���ݿ����ӳɹ�" << endl << endl;
	system("pause");
	return true;
}

//���ݿ�رպ���
void databaseEnd() {

	///< �ر����ݿ�����
	mysql_close(&mysql);
	cout << "���ݿ�رճɹ�\n";
}

//�����ݿ�����װ��studentMap�У���ȡ���ݣ�
bool databaseLoad(map<string, studentSubject>&studentMap) {
	//��ȡ���ݿ�ʱ���ñ���Ϊutf8
	mysql_query(&mysql, "set names utf8");
	///< �������ݿ��Ӧ�ṹ��
	MYSQL_RES* res = nullptr;
	///< ������Ž���Ľṹ��
	MYSQL_ROW row;
	///< ��������ֶ�������
	MYSQL_FIELD* field = nullptr;

	char sql[1024]{ 0 };
	sprintf_s(sql, 1024, "select * from subject_study");

	///< ���ò�ѯ�ӿ�
	if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	{
		cout << "��ѯʧ�ܣ�����ԭ����û���������ֱ�ӽ���¼����Ϣ" << ": " << mysql_errno(&mysql) << endl;
		mysql_free_result(res);
		system("pause");
		return false;
	}
	else
	{
		cout << "��ѯ�ɹ�" << endl << endl;

		///< װ�ؽ����
		res = mysql_store_result(&mysql);

		if (nullptr == res)
		{
			cout << "װ������ʧ��" << ": " << mysql_errno(&mysql) << endl;
			mysql_free_result(res);
			system("pause");
			return false;
		}
		else
		{
			///< ȡ�������������,���� ѧ�� ���� ѧԺ ѧ����������
			field = mysql_fetch_field(res);
			int fields = mysql_num_fields(res);
			string* subname = new string[fields];
			for (int i = 0; i < fields; ++i) {
				subname[i] = wchar_to_string(Utf8_2_Unicode(field[i].name));
			}
			while (row = mysql_fetch_row(res))
			{
				//cout << row[0] << "  " << row[1] << endl;
				for (int i = 0; i < fields; ++i) {
					row[i] = wchar_to_char(Utf8_2_Unicode(row[i]));
				}
				string id = row[0];
				if (studentMap.find(id) != studentMap.end()) continue;
				else {
					Student student(row[2], id, row[1]);
					studentSubject stusub(student);
					char** p = row + 3;
					int k = 3;
					while (k < fields) {
						stusub.addSubject(subname[k], atof(*p));
						++p;
						++k;
					}
					studentMap[id] = stusub;
				}
			}
		}
	}

	///< �ͷŽ����
	mysql_free_result(res);
	return true;
}

//��ȡ�ֶ��б�ͷ����
vector<string> field_table() {

	vector<string>str;

	//����UTF8
	mysql_query(&mysql, "set names utf8");
	///< �������ݿ��Ӧ�ṹ��
	MYSQL_RES* res = nullptr;
	///< ��������ֶ�������
	MYSQL_FIELD* field = nullptr;

	char sql[1024]{ 0 };
	sprintf_s(sql, 1024, "select * from subject_study");
	///< ���ò�ѯ�ӿ�
	if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	{
		cout << "��ͷ���ݻ�ȡʧ��" << ": " << mysql_error(&mysql) << mysql_errno(&mysql) << endl;
		mysql_free_result(res);
		system("pause");
		return str;
	}
	else {
		///< װ�ؽ����
		res = mysql_store_result(&mysql);

		if (nullptr == res)
		{
			cout << "װ������ʧ��" << ": " << mysql_errno(&mysql) << endl;
			mysql_free_result(res);
			system("pause");
			return str;
		}
		else {
			///< ȡ�������������,���� ѧ�� ���� ѧԺ ѧ����������
			field = mysql_fetch_field(res);
			int fields = mysql_num_fields(res);
			for (int i = 0; i < fields; ++i) {
				str.push_back(wchar_to_string(Utf8_2_Unicode(field[i].name)));
			}
		}
	}
	mysql_free_result(res);
	return str;
}

//ɾ��ָ��ѧ�ŵ���Ϣ
bool delete_id(string id) {
	mysql_query(&mysql, "set names gbk");
	string sql = "delete from subject_study WHERE `ѧ��`=" + id + " limit 1;";
	int re = mysql_real_query(&mysql, sql.c_str(), (unsigned int)sql.length());
	if (re) {
		cout << "ɾ��ʧ��\n";
		cout << mysql_errno(&mysql) << " " << mysql_error(&mysql);
		system("pause");
		return false;
	}
	return true;
}

//���ҵ���ѧ�ŵ���Ϣ
bool search_id(string id) {
	MYSQL_RES* res = nullptr;
	MYSQL_ROW row;
	mysql_query(&mysql, "set names gbk");
	string sql = "select * from subject_study WHERE `ѧ��`=" + id + ";";
	int re = mysql_real_query(&mysql, sql.c_str(), (unsigned int)sql.length());
	res = mysql_store_result(&mysql);
	row = mysql_fetch_row(res);
	if (row == NULL)
	{
		//cout << mysql_errno(&mysql) << mysql_error(&mysql) << "\n";

		mysql_free_result(res);
		return false;
	}
	else {
		//mysql_query(&mysql, "set names utf8");
		int fields = mysql_num_fields(res);
		for (int i = 0; i < fields; ++i)
			cout << row[i] << " ";
		cout << "\n";
		mysql_free_result(res);
		return true;
	}
}