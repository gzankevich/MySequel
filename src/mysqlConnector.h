#ifndef __MYSQL_CONNECTOR_H__
#define __MYSQL_CONNECTOR_H__

#include <string>
#include <mysql/mysql.h>
#include <vector>
#include <iostream>

using namespace std;

class MySQLConnector
{
	private:
		MYSQL *connection;

	public:
		MySQLConnector();
		~MySQLConnector();

		vector<vector<string> > execute(string command);
};

#endif
