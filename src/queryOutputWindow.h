#ifndef __QUERY_OUTPUT_WINDOW_H__
#define __QUERY_OUTPUT_WINDOW_H__

#include <string>
#include <vector>
#include <iostream>

#include "windowInterface.h"
#include "colourScheme.h"
#include "outputMessageBuffer.h"
#include "resultInterface.h"

/**
 * Output window for QueryMode.
 *
 * Displays previously entered commands and their output.
 *
 * \todo Scroll through the buffer.
 */
class QueryOutputWindow : public IWindow
{
	protected:
		int lineCounter;
		std::vector<QueryOutputMessage*> buffer;
		std::vector<IResult*> resultBuffer;

	public:
		/**
		 * Initialize the output window.
		 */
		QueryOutputWindow();
		~QueryOutputWindow();

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

		/**
		 * Print a message in the window.
		 * 
		 * @param message The text to print.
		 * @param type The type of the message - this dictates how the message should be presented.
		 */
		void print(std::string message, QueryOutputMessage::Type type = QueryOutputMessage::OUTPUT);
};

#endif
