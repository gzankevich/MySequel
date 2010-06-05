#include <iostream>
#include <ncurses.h>

#include "queryMode.h"
#include "mysqlConnector.h"

using namespace std;

int main()
{
	initscr();
	start_color();
	noecho();
	cbreak();

	MySQLConnector *connector = new MySQLConnector();
	

	QueryMode *queryMode = new QueryMode(connector);

	bool done = false;
	while(!done)
	{
		done = queryMode->update();
	}

	delete queryMode;
	queryMode = NULL;


	delete connector;
	connector = NULL;


/*	WINDOW *win = newwin(4, COLS, LINES - 4, 0);
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	wbkgd(win, COLOR_PAIR(1));
	wrefresh(win); */

	endwin();

	return 0;
}

