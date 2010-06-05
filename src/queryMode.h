#ifndef __COMMAND_WINDOW_H__
#define __COMMAND_WINDOW_H__

#include <string>
#include <ncurses.h>
#include <sstream>
#include <iostream>
#include <vector>

#include "mysqlConnector.h"
#include "queryInputWindow.h"
#include "queryOutputWindow.h"

using namespace std;

/**
 * User interface for querying a MySQL server.
 */
class QueryMode
{
	private:
		QueryInputWindow *inputWindow;
		QueryOutputWindow *outputWindow;
		IWindow *focusedWindow;

		MySQLConnector *connector;

	public:
		/**
		 * Initialize the query mode UI.
		 *
		 * @param connector an instance of a MySQLConnector object.
		 */
		QueryMode(MySQLConnector *connector);
		~QueryMode();

		/**
		 * Update the UI windows on user input and pass the code of the key to the focused window.
		 *
		 * @return True if the program is quitting, false if we should keep running.
		 */
		bool update();
};

#endif
