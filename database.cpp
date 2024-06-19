/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：数据库处理模块
*/
#pragma once
#include"StudentManagerSystem.h"
#include"student.h"
#include"toolkit.h"
#include"database.h"
using namespace std;
MYSQL mysql;
//创建表格，表格名称为subject_study
bool createTable(string sub[],int n) {
	mysql_query(&mysql, "set names gbk");
	string sql = "CREATE TABLE IF NOT EXISTS `subject_study`  ( \
		`学号` int(8) NOT NULL,\
		`姓名` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,\
		`学院` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,\ ";
	for (int i = 0; i < n; ++i) {
		sql = sql + "`" + sub[i] + "` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,\ ";
	}
	sql = sql + "PRIMARY KEY(`学号`)\
		) ";
	int re = mysql_query(&mysql, sql.c_str());//从字符串换成const char*
	if (re != 0)
	{
		cout << "建立表格请求失败！" << mysql_error(&mysql) << endl;
		return false;
	}
	return true;
}

//创建表
bool datatable() {
	system("cls");
	//根据科目进行建表
	char sql[1024]{ 0 };
	sprintf_s(sql, 1024, "select * from subject_study");
	MYSQL_RES* res = nullptr;
	if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql))) {
		res = mysql_store_result(&mysql);
		mysql_free_result(res);
		cout << "数据库中还没有相关表格，建立表格中\n";
		cout << "请输入科目数量:\n";
		int n; 
		cin >> n;//科目数量
		string* subject = new string[n];
		cout << "请输入所需要录入的科目名称:\n";
		for (int i = 0; i < n; ++i) {
			cin >> subject[i];
		}
		if (!createTable(subject, n)) {
			cout << "建立表格请求失败！" << mysql_error(&mysql) << endl;
			delete[]subject;
			system("pause");
			return false;
		}
		delete[]subject;
	}
	cout << "数据库中已有相关表格\n";
	res = mysql_store_result(&mysql);
	mysql_free_result(res);
	system("pause");
	return true;
}

//判断单条学生数据是否存在,true表示存在
bool existdata(string id) {
	MYSQL_RES* res = nullptr;
	MYSQL_ROW row;
	mysql_query(&mysql, "set names gbk");
	string sql = "select * from subject_study WHERE `学号`=" + id +";";
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
		cout << "该学生已经存在于数据库,不能再添加新成绩，相关信息如下，请核对是否正确。如有错误请前往修改页面进行修改\n\n";
		//mysql_query(&mysql, "set names utf8");
		int fields = mysql_num_fields(res);
		for (int i = 0; i < fields; ++i)cout <<row[i] << " ";
		cout << "\n";
		system("pause");
		mysql_free_result(res);
		return true;
	}
}

//保存录入的map数据
bool typeinData(map<string, studentSubject>&studentMap) {
	//筛选科目，由于实际输入时，每个学生所学的科目有所不同，所以用循环将所有科目存在set中，在取出到一个string数组
	set<string>sub;
	for (auto& it : studentMap) {
		map<string, double> subject_map = it.second.getSubject();
		for (auto& iq : subject_map) {
			sub.insert(iq.first);
		}
	}
	int n = sub.size();//科目数量
	string* subject = new string[n];
	int r = 0;
	for (auto it = sub.begin(); it != sub.end(); it++) {
		subject[r] = (*it);
		++r;
	}

	//利用字符串拼接，插入数据
	//写入数据库时设置编码为gbk
	mysql_query(&mysql, "set names gbk");
	int re = 0;
	for (auto& it : studentMap) {
		string ss = "insert `subject_study` (`学号`,`姓名`,`学院`";
		map<string,double> subscore = it.second.getSubject();
		Student stu = it.second.getStudent();
		for (auto& iq : subscore) {
			ss = ss + ",`" + iq.first + "`";//学科
		}
		ss = ss + ") values(";
		ss = ss + it.first + ","+ "\'" + stu.getName() + "\'," + "\'" + stu.getCollege() + "\'";//学号，姓名，学院
		for (auto& iq : subscore) {
			ss = ss + ",\'" + to_string(iq.second) + "\'";//成绩
		}
		ss += ");";
		re = mysql_query(&mysql, ss.c_str());//从字符串换成const char*
		if (re != 0)
		{
			cout << "录入数据请求失败！" << mysql_error(&mysql) << endl;
			delete[]subject;
			system("pause");
			return false;
		}
	}
	cout << "录入数据请求成功！" << endl;
	delete[]subject;
	system("pause");
	return true;
}

//数据库初始化函数
bool databaseStart() {
	cout << "连接数据库中……\n";
	
	//初始化
	mysql_init(&mysql);

	///< 连接的数据库（句柄、主机名、用户名、密码、数据库名、端口号、socket指针、标记）
	cout << "请输入主机名，若为本机则为'localhost':\n";
	string hostname; 
	cin >> hostname;
	cout << "请输入用户名，默认为'root':\n";
	string username; 
	cin >> username;
	cout << "请输入密码:\n";
	string password; 
	cin >> password;
	cout << "请输入数据库的名称:\n";
	string database_name; 
	cin >> database_name;
	cout << "请输入端口号，默认为3306:\n";
	unsigned int port; 
	cin >> port;
	if (!mysql_real_connect(&mysql, hostname.c_str(), username.c_str(), password.c_str(), database_name.c_str(), port, nullptr, 0))
	{
		cout << "数据库连接失败" << mysql_errno(&mysql) << endl;
		return false;
	}

	cout << "数据库连接成功" << endl << endl;
	system("pause");
	return true;
}

//数据库关闭函数
void databaseEnd() {

	///< 关闭数据库连接
	mysql_close(&mysql);
	cout << "数据库关闭成功\n";
}

//将数据库内容装入studentMap中（读取数据）
bool databaseLoad(map<string, studentSubject>&studentMap) {
	//读取数据库时设置编码为utf8
	mysql_query(&mysql, "set names utf8");
	///< 创建数据库回应结构体
	MYSQL_RES* res = nullptr;
	///< 创建存放结果的结构体
	MYSQL_ROW row;
	///< 创建存放字段列数组
	MYSQL_FIELD* field = nullptr;

	char sql[1024]{ 0 };
	sprintf_s(sql, 1024, "select * from subject_study");

	///< 调用查询接口
	if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	{
		cout << "查询失败，可能原因是没有这个表，请直接进行录入信息" << ": " << mysql_errno(&mysql) << endl;
		mysql_free_result(res);
		system("pause");
		return false;
	}
	else
	{
		cout << "查询成功" << endl << endl;

		///< 装载结果集
		res = mysql_store_result(&mysql);

		if (nullptr == res)
		{
			cout << "装载数据失败" << ": " << mysql_errno(&mysql) << endl;
			mysql_free_result(res);
			system("pause");
			return false;
		}
		else
		{
			///< 取出结果集中内容,按照 学号 姓名 学院 学科依次排列
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

	///< 释放结果集
	mysql_free_result(res);
	return true;
}

//获取字段列表头数据
vector<string> field_table() {

	vector<string>str;

	//设置UTF8
	mysql_query(&mysql, "set names utf8");
	///< 创建数据库回应结构体
	MYSQL_RES* res = nullptr;
	///< 创建存放字段列数组
	MYSQL_FIELD* field = nullptr;

	char sql[1024]{ 0 };
	sprintf_s(sql, 1024, "select * from subject_study");
	///< 调用查询接口
	if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	{
		cout << "表头数据获取失败" << ": " << mysql_error(&mysql) << mysql_errno(&mysql) << endl;
		mysql_free_result(res);
		system("pause");
		return str;
	}
	else {
		///< 装载结果集
		res = mysql_store_result(&mysql);

		if (nullptr == res)
		{
			cout << "装载数据失败" << ": " << mysql_errno(&mysql) << endl;
			mysql_free_result(res);
			system("pause");
			return str;
		}
		else {
			///< 取出结果集中内容,按照 学号 姓名 学院 学科依次排列
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

//删除指定学号的信息
bool delete_id(string id) {
	mysql_query(&mysql, "set names gbk");
	string sql = "delete from subject_study WHERE `学号`=" + id + " limit 1;";
	int re = mysql_real_query(&mysql, sql.c_str(), (unsigned int)sql.length());
	if (re) {
		cout << "删除失败\n";
		cout << mysql_errno(&mysql) << " " << mysql_error(&mysql);
		system("pause");
		return false;
	}
	return true;
}

//查找单个学号的信息
bool search_id(string id) {
	MYSQL_RES* res = nullptr;
	MYSQL_ROW row;
	mysql_query(&mysql, "set names gbk");
	string sql = "select * from subject_study WHERE `学号`=" + id + ";";
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