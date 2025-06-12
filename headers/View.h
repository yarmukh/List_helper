#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include <memory>
#include "Notebook.h"


using std::vector;
using std::string;
using std::unique_ptr;


class View
{
private:
    vector<string> m_items;
    unique_ptr<WINDOW, decltype(&delwin)> m_window;
    unique_ptr<Notebook> m_notebook;

    void run_show_menu();

    void draw_show_menu(int highlight);

    void draw_main_menu(int highlight);

    void run_remove_menu();

    void draw_remove_menu(int highlight);

    void run_input_menu();

    void draw_input_menu(int highlight);
public:

    void set_notebook(Notebook* notebook);

    View(const vector<string>& items, int height = 100, int width = 150, int y = 0, int x = 0);
    
    int run();

    ~View();
};
