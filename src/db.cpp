#include "tools/db.h"


void connectdb(MYSQL* mysql,const char* host, const char* user, const char* pass, const char* db)
{
    if (!mysql_real_connect(mysql, host, user, pass, db, 3306, 0, 0))
    {
        std::cout << "mysql connect failed! " << mysql_error(mysql) << std::endl;
    }
    else
    {
        std::cout << "mysql connect " << host << " success" << std::endl;
    }

    return ;
}

void conn_timeout(MYSQL* mysql, int to)
{
    int re = mysql_options(mysql, MYSQL_OPT_CONNECT_TIMEOUT, &to);
    if (re != 0)
    {
        std::cout << "mysql_options failed " << mysql_error(mysql) << std::endl;
    }
}

void reconn(MYSQL* mysql, int recon)
{
    int re = mysql_options(mysql, MYSQL_OPT_RECONNECT, &recon);
    if (re != 0)
    {
        std::cout << "mysql_options failed " << mysql_error(mysql) << std::endl;
    }
}

void runsql(MYSQL* mysql, const char* sql)
{
    //1.ִ��sql���
    //mysql_real_query:  sql����п��԰�������������
    //mysql_query:  sql���ֻ�����ַ���
    //0���ر�ʾ�ɹ�
    int re = mysql_real_query(mysql, sql, strlen(sql));
    //re = mysql_query(mysql, sql);
    if (re != 0)
    {
        std::cout << "mysql_real_query failed!\n" <<  sql << ":   \n" << mysql_error(mysql) << std::endl;
    }
    else
    {
        std::cout << "mysql_real_query success! " << sql << ":   \n" << std::endl;
    }

    //2.��ȡ�����
    //mysql_use_result:  ��ʵ�ʶ�ȡ����
    //mysql_store_result:  ��ȡ�������ݣ�ע�⻺���С
    //MYSQL_RES* result = mysql_use_result(mysql);
    MYSQL_RES* result = mysql_store_result(mysql);
    if (!result)
    {
        std::cout << "mysql_use_result failed!\n" << mysql_error(mysql) << std::endl;
    }

    //3.���������
    MYSQL_ROW row;
    while (row = mysql_fetch_row(result))
    {
        unsigned long* lens = mysql_fetch_lengths(result);
        std::cout << lens[0] << "[" << row[0] << ", " << row[1] << "]" << std::endl;
    }

    //4.��������
    mysql_free_result(result);
}