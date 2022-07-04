#ifndef _DB_H_
#define _DB_H_
#include <mysql.h>
#include <iostream>

void connectdb(MYSQL* mysql,const char* host, const char* user, const char* pass, const char* db);    //连接登录数据库
void conn_timeout(MYSQL* mysql, int to);    //超时检测，to超时时间
void reconn(MYSQL* mysql, int recon);    //自动重连,recon自动重连间隔
void runsql(MYSQL* mysql, const char* sql);			//执行传入的sql语句
#endif