#include <iostream>
#include <ncurses.h>
#include <vector>
#include "../headers/View.h"
#include "../headers/Notebook.h"
#include "../headers/Storage.h"
using namespace std;

int main(int argc, char** argv)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    vector<string> menu_items = {
        "Show list",
        "Add new note",
        "Remove note",
        "Exit"
    };
    Notebook notebook("notes.dat");
    View menu(menu_items);
    menu.set_notebook(&notebook);

    int choice = menu.run();

    endwin();
    return 0;
}