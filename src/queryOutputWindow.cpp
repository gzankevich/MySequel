#include "queryOutputWindow.h"

QueryOutputWindow::QueryOutputWindow()
{
	this->resize(0, LINES - 4);
	this->lineCounter = 0;

	init_pair(COLOUR_SCHEME_OUTPUT, COLOUR_SCHEME_SECONDARY, COLOUR_SCHEME_PRIMARY);
	wbkgd(this->window, COLOR_PAIR(COLOUR_SCHEME_OUTPUT));
}

QueryOutputWindow::~QueryOutputWindow()
{
	this->buffer.clear();
}

bool QueryOutputWindow::keyDown(int key)
{
	return false;
}

void QueryOutputWindow::resize(int width, int height)
{
	this->window = newwin(height, COLS, 0, 0);
	IWindow::resize(width, height);
}

bool QueryOutputWindow::update()
{
	this->refresh();

	return false;
}

void QueryOutputWindow::print(std::string message, QueryOutputMessage::Type type)
{
	this->buffer.push_back(new QueryOutputMessage(message, type));

	mvwprintw(this->window, this->lineCounter, 0, message.c_str());
	this->update();
	this->lineCounter++;
}
