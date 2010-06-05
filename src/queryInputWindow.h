#ifndef __QUERY_INPUT_WINDOW_H__
#define __QUERY_INPUT_WINDOW_H__

#include <string>
#include <sstream>

#include "windowInterface.h"
#include "colourScheme.h"
#include "mysqlConnector.h"
#include "queryOutputWindow.h"

/**
 * Input window for QueryMode.
 *
 * Sends user input to the QueryOutputWindow.
 * \todo Keeps track of input history.
 * \todo Tab completion for SQL commands.
 */
class QueryInputWindow : public IWindow
{
	private:
		// Keeps track of where the cursor is
		int cursorOffset;

		std::string buffer;
		MySQLConnector *connector;
		QueryOutputWindow *outputWindow;

		bool processInput();

	public:
		/**
		 * Initialize the input window.
		 *
		 * @param connector an instance of a MySQLConnector object.
		 * @param queryOutputWindow an instance of a QueryOutputWindow object.
		 */
		QueryInputWindow(MySQLConnector *connector, QueryOutputWindow *queryOutputWindow);
		~QueryInputWindow();

		/**
		 * Handle user input.
		 *
		 * @param key ASCII keycode of the key pressed.
		 */
		bool keyDown(int key);

		/**
		 * Resize the window to new dimensions.
		 *
		 * @param width New window width.
		 * @param height New window height.
		 */
		void resize(int width, int height);

		/**
		 * Called when the user has hit a key.
		 *
		 * @return True if the program is quitting, false if we should keep running.
		 */ 
		bool update();

		void refresh();
};

#endif
