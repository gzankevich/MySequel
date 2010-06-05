#include "windowInterface.h"
#include <iostream>

IWindow::~IWindow()
{
	delwin(this->window);
}

void IWindow::resize(int width, int height)
{
	this->refresh();
}

void IWindow::refresh()
{
	wrefresh(this->window);
}

WINDOW *IWindow::getCursesWindow()
{
	return this->window;
}
