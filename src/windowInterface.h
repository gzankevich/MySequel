#ifndef __WINDOW_INTERFACE_H__ 
#define __WINDOW_INTERFACE_H__

#include <ncurses.h>

/**
 * NCurses window interface.
 */
class IWindow
{
	protected:
		WINDOW *window;

	public:
		virtual ~IWindow();

		/**
		 * Handle user input.
		 *
		 * @param key ASCII keycode of the key pressed.
		 */
		virtual bool keyDown(int key) = 0;

		/**
		 * Resize the window to new dimensions.
		 *
		 * @param width New window width.
		 * @param height New window height.
		 *
		 * \todo Check for dimensions which are too small/large
		 * \todo return value should be a bool
		 */
		virtual void resize(int width, int height);


		/**
		 * Update the window state.
		 *
		 * Usually called on user input.
		 *
		 * @return True if the program is quitting, false if we should keep running.
		 */
		virtual bool update() = 0;

		/**
		 * Refresh (redraw) the NCurses window.
		 *
		 * This is required when, for example, resizing or initializing a window.
		 */
		virtual void refresh();

		/**
		 * Get the NCurses window handle for this window.
		 *
		 * @return NCurses window handle.
		 */
		WINDOW *getCursesWindow();
};

#endif
