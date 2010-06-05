#include "queryInputWindow.h"
#include <iostream>

QueryInputWindow::QueryInputWindow(MySQLConnector *connector, QueryOutputWindow *outputWindow)
{
	this->cursorOffset = 0;
	this->connector = connector;
	this->outputWindow = outputWindow;

	this->resize(0, 4);

	init_pair(COLOUR_SCHEME_INPUT, COLOUR_SCHEME_PRIMARY, COLOUR_SCHEME_SECONDARY);
	wbkgd(this->window, COLOR_PAIR(COLOUR_SCHEME_INPUT));

	// enabled so that when checking for esc (code 27) key presses, arrow keys,
	// page up/down, etc do not register
	// without it the right arrow key, for example, triggers escape because it 
	// outputs ^E
	keypad(this->window, true);
	// ncurses uses escape to start character sequences and so has a default delay
	// of 1000 milliseconds on the escape key
	ESCDELAY = 10;
}

QueryInputWindow::~QueryInputWindow()
{

}

bool QueryInputWindow::keyDown(int key)
{
	// key 10 is return
	if(key == 10)
	{
		try
		{
			// output returned as [row][column]
			vector<vector<string> > output = this->connector->execute(this->buffer.c_str());

			int counter = 2;
			string outputLine;

			for(vector<vector<string> >::const_iterator iter = output.begin(); iter != output.end(); ++iter)
			{
				for(vector<string>::const_iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); ++iter2)
				{
					outputLine += *iter2;
				}

				this->outputWindow->print(outputLine);
				outputLine = "";

				counter++;
			}
		}
		catch(const char *message)
		{
			this->outputWindow->print(message);
		}
		
		this->cursorOffset = 0;
		this->buffer.clear();
		wclear(this->window);
		this->refresh();
	}
	// quit on esc
	else if((int)key == 27)
	{
		return true;
	}
	else if(key == KEY_LEFT)
	{
		if(this->cursorOffset > 0)
		{
			this->cursorOffset--;
			this->refresh();
		}
	}
	else if(key == KEY_RIGHT)
	{
		if((unsigned int)this->cursorOffset < this->buffer.length())
		{
			this->cursorOffset++;
			this->refresh();
		}
	}
	else 
	{
		stringstream ss;
		ss<<(char)key;

		string character = ss.str();

		this->buffer.insert(this->cursorOffset, character.c_str());
		this->cursorOffset++;

		this->refresh();
	}

	return false;
}

bool QueryInputWindow::processInput()
{
	return false;
}

void QueryInputWindow::resize(int width, int height)
{
	this->window = newwin(height, COLS, LINES - height, 0);
	IWindow::resize(width, height);
}

bool QueryInputWindow::update()
{

	return false;
}

void QueryInputWindow::refresh()
{
	wclear(this->window);
	mvwprintw(this->window, 0, 0, this->buffer.c_str());
	wcolor_set(this->window, 1, NULL);
	mvwprintw(this->window, 0, this->cursorOffset, "|");
	wcolor_set(this->window, 2, NULL);

	IWindow::refresh();
}

