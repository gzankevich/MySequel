#include "queryMode.h"
#include <iostream>

QueryMode::QueryMode(MySQLConnector *connector)
{
	this->connector = connector;
	this->outputWindow = new QueryOutputWindow();
	this->inputWindow = new QueryInputWindow(connector, this->outputWindow);
	this->focusedWindow = this->inputWindow;
	//nodelay(this->inputWindow->getCursesWindow(), true);
	//nodelay(this->outputWindow->getCursesWindow(), true);
}

QueryMode::~QueryMode()
{
	delete this->inputWindow;
	delete this->outputWindow;
}

bool QueryMode::update()
{
	this->inputWindow->update();
	this->outputWindow->update();

	int key = wgetch(this->focusedWindow->getCursesWindow());
	
	bool done = false;

	if(key > 1)
		done = this->focusedWindow->keyDown(key);

	return done;
	/*if(character == 10)
	{
		string input = this->input;
		this->input = "";
		this->inputCharacterCounter = 0;
		this->inputLineCounter = 1;
		this->createWindows();

		mvwprintw(this->outputWindow, 0, 0, input.c_str());

		try
		{
			vector<vector<string> > output = connector->execute(input.c_str());
			int counter = 2;
			string outputLine;
			for(vector<vector<string> >::const_iterator iter = output.begin(); iter != output.end(); ++iter)
			{
				for(vector<string>::const_iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); ++iter2)
				{
					outputLine += *iter2;
				}

				mvwprintw(this->outputWindow, counter, 0, outputLine.c_str());
				outputLine = "";

				counter++;
			}
		}
		catch(const char *message)
		{
			mvwprintw(this->outputWindow, 2, 0, message);
		}

		wrefresh(this->outputWindow);
	}
	else
	{
		mvwprintw(this->outputWindow, 0, 0, "%i", character);
		wrefresh(this->outputWindow);
		this->inputCharacterCounter++;
		if(this->inputCharacterCounter == COLS)
		{
			this->inputLineCounter++;
			this->inputCharacterCounter = 0;

			this->createWindows();

			// redraw text already written in the input window since
			// recreating the window will wipe it out
			mvwprintw(this->inputWindow, 0, 0, this->input.c_str());
		}	
	}


	

	*/
	return false;
}
