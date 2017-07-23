#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

class window
{
	public:
		window();
		WINDOW* draw_window(int _h, int _w, int _y, int _x);
		void create_header();
		void create_output();
		void create_friends_list();
		void create_input();
		void put_str_to_win(WINDOW *_w, int _y, int _x, const std::string &msg);
		std::string get_str_from_win(WINDOW *_w);
		void clr_win_lines(WINDOW *_w, int begin, int lines);
		~window();
	public:
		WINDOW *header;
		WINDOW *output;
		WINDOW *friends_list;
		WINDOW *input;
};

#endif
