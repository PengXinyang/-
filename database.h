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
using namespace std;
//创建数据库句柄
extern MYSQL mysql;

//创建表格，表格名称为subject_study
bool createTable(string sub[], int n);

//创建表
bool datatable();

//判断单条学生数据是否存在,true表示存在
bool existdata(string id);

//保存录入的map数据
bool typeinData(map<string, studentSubject>&studentMap);

//数据库初始化函数
bool databaseStart();

//数据库关闭函数
void databaseEnd();

//将数据库内容装入studentMap中（读取数据）
bool databaseLoad(map<string, studentSubject>&studentMap);

//获取字段列表头数据
vector<string> field_table();

//删除指定学号的信息
bool delete_id(string id);

//查找单个学号的信息
bool search_id(string id);