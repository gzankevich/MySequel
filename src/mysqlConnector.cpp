#include "mysqlConnector.h"

MySQLConnector::MySQLConnector()
{
	this->connection = mysql_init(NULL);

	if(!mysql_real_connect(this->connection, "localhost", "root", "altec9033", "facebrush", 0, NULL, 0))
		throw mysql_error(this->connection);
}

MySQLConnector::~MySQLConnector()
{
	mysql_close(this->connection);
}

vector<vector<string> > MySQLConnector::execute(string command)
{
	if(mysql_query(this->connection, command.c_str()))
		throw mysql_error(this->connection);

	MYSQL_RES *resource = mysql_use_result(this->connection);
	MYSQL_ROW row;
	vector< vector<string> > results;
	vector<string> resultRow;

	while((row = mysql_fetch_row(resource)) != NULL)
	{
		for(unsigned int i = 0; i < mysql_num_fields(resource); i++)
		{
			// trying to stringify a NULL will cause an exception
			if(row[i] != NULL)
				resultRow.push_back(row[i]);
			else
				resultRow.push_back("");
		}

		results.push_back(resultRow);
		resultRow.clear();
	}

	mysql_free_result(resource);

	return results;
}
