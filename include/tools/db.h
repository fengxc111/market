#ifndef _DB_H_
#define _DB_H_
#include <mysql.h>
#include <iostream>

void connectdb(MYSQL* mysql,const char* host, const char* user, const char* pass, const char* db);    //���ӵ�¼���ݿ�
void conn_timeout(MYSQL* mysql, int to);    //��ʱ��⣬to��ʱʱ��
void reconn(MYSQL* mysql, int recon);    //�Զ�����,recon�Զ��������
void runsql(MYSQL* mysql, const char* sql);			//ִ�д����sql���
#endif