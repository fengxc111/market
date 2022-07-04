//#include <stdio.h>

#include <iostream>
#include <thread>
using namespace std;
#include "tools/db.h"
//#include "hint.h"
//#include "color.h"
const char* hello = "Hello, WinterCode!";
const char* host = "127.0.0.1";
//const char* host = "192.168.56.101";
const char* user = "root";
const char* pass = "123456";
const char* db = "mysql";
const char* sql;
int main() {
    //welcomeMessage();
    //invalidMessage();

    //connectdb();

    //初始化mysql上下文
    MYSQL* mysql = new MYSQL();
    mysql_init(mysql);
    //conn_timeout(mysql, 3);
    //reconn(mysql, 1);
    connectdb(mysql, host, user, pass, db);

    sql = "select user,host,plugin from user";
    runsql(mysql, sql);
    //测试mysql_ping
    /*for (int i = 0; i < 1000; i++)
    {
        int re = mysql_ping(mysql);
        if (re == 0)
        {
            cout << host << ":mysql ping success!" << endl;
        }
        else
        {
            cout << "mysql ping failed! " << mysql_error(mysql) << endl;
        }
        this_thread::sleep_for(1s);
    }*/

    //printf("Hello world!");
    //printf("%s%s%s\n", TWINKLING, hello, RESET);
    mysql_close(mysql);
    mysql_library_end();
    system("pause");
    return 0;
}
