#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include <memory>
#include "Settings.h"

using std::vector;
using std::string;
using std::unique_ptr;


class View
{
private:
    vector<string> m_items;
    unique_ptr<WINDOW, decltype(&delwin)> m_window;


    void draw_main_menu(int highlight);

    
    void run_settings_menu();


    void draw_settings_menu(int highlight);


    void edit_settings();

public:
    View(const vector<string>& items, int height = 100, int width = 150, int y = 0, int x = 0);
    
    int run();

    ~View();
};
