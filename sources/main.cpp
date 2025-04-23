#include <iostream>
#include <stdlib.h>

#define PDC_FORCE_UTF8  // Добавьте это перед включением curses.h
#include <curses.h>

#include "../headers/Notebook.h"
#include "../headers/ClearScreen.h"

using namespace std;

int main() {
    /* Ncurses start */
    initscr();
    noecho();
    cbreak();

    //screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //create a window
    WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //add arrow keys
    keypad(menuwin, true);

    string choices[4] = {"Show list", "Add new note", "Remove note", "Exit"};
    int solution;
    int highlight = 0;

    Notebook notebook;

    while( true ) {
        printw("Enter your solution:");
        for (int i = 0 ; i < 4 ; i++) {
            if (i == highlight) {
                wattron(menuwin,A_REVERSE);
            }
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        solution = wgetch(menuwin);

        switch (solution) {
            case KEY_UP:
                highlight--;
                if (highlight == -1) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
            if (highlight == 4) {
                highlight = 3;
            }
            break;
            default:
                break;
        }
        if (solution == 10) {
            break;
        }
        
                
        std::cin >> solution;
        if( highlight == 1) {
            notebook.print_list();
        }

        if( highlight == 2) {
            Note note;
            std::cout << "Enter your description:" << std::endl;
            std::cin >> note.description;
            clearScreen();
            std::cout << "Enter your priority:" << std::endl;
            std::cin >> note.priority;
            clearScreen();
            notebook.add_new_note(note);
        }
        
        if( highlight == 3 ) {
            int nummer;
            std::cout << "Enter the nummer:" << std::endl;
            std::cin >> nummer;
            notebook.remove_note(nummer);
            clearScreen();
        }

        if( highlight == 4) {
            break;
        }


        getch();
        endwin();

        /* Ncurses end */

        //clearScreen(); //очищает экран
        
    }
}