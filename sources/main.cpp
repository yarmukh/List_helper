#include <iostream>
#include <stdlib.h>

#define PDC_FORCE_UTF8  // Добавьте это перед включением curses.h
#include <ncurses.h>
#include <vector>
#include "../headers/View.h"
#include "../headers/Notebook.h"

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

    View menu(menu_items);

    int choice = menu.run();

    endwin();
    return 0;
}

//
// int main() {
//     /* Ncurses start */
//     initscr();
//     noecho();
//     cbreak();
//
//     //screen size
//     int yMax, xMax;
//     getmaxyx(stdscr, yMax, xMax);
//
//     //create a window
//     WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
//     box(menuwin, 0, 0);
//     refresh();
//     wrefresh(menuwin);
//
//     //add arrow keys
//     keypad(menuwin, true);
//
//     string choices[4] = {"Show list", "Add new note", "Remove note", "Exit"};
//     int solution;
//     int highlight = 0;
//
//     Notebook notebook;
//
//     while( true ) {
//         printw("Enter your solution:\n ");
//         for (int i = 0 ; i < 4 ; i++) {
//             if (i == highlight) {
//                 wattron(menuwin,A_REVERSE);
//             }
//             mvwprintw(menuwin, i+1, 1, choices[i].c_str());
//             wattroff(menuwin, A_REVERSE);
//         }
//         solution = wgetch(menuwin);
//         clear();
//         switch (solution) {
//             case KEY_UP:
//                 highlight--;
//                 if (highlight == -1) {
//                     highlight = 0;
//                 }
//                 break;
//             case KEY_DOWN:
//                 highlight++;
//             if (highlight == 4) {
//                 highlight = 3;
//             }
//             break;
//             default:
//                 break;
//         }
//         if (solution == 10) {
//             printw("The solution is == 10 \n");
//             break;
//         }
//
//
//         std::cin >> solution;
//         if( highlight == 1) {
//             notebook.print_list();
//         }
//
//         if( highlight == 2) {
//             Note note;
//             std::cout << "Enter your description: \n" << std::endl;
//             std::cin >> note.description;
//             std::cout << "Enter your priority: \n" << std::endl;
//             std::cin >> note.priority;
//             notebook.add_new_note(note);
//         }
//
//         if( highlight == 3 ) {
//             int nummer;
//             std::cout << "Enter the nummer: \n" << std::endl;
//             std::cin >> nummer;
//             notebook.remove_note(nummer);
//         }
//
//         if( highlight == 4) {
//             break;
//         }
//
//
//         getch();
//         endwin();
//
//         /* Ncurses end */
//
//     }
// }