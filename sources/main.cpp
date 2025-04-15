#include <iostream>
#include <stdlib.h>
#include "../headers/Notebook.h"
#include "../headers/ClearScreen.h"


int main() {
    
    
    int solution;
    Notebook notebook;

    while( true ) {
        std::cout << "Menu" << std::endl
                << "1. Show list" << std::endl
                << "2. Add new note" << std::endl
                << "3. Remove note" << std::endl
                << "4. Exit" << std::endl
                << "Enter your answer:" << std::endl;
        
                
        std::cin >> solution;
        
        if( solution == 1) {
            notebook.print_list();
        }

        if( solution == 2) {
            Notebook MyNotebook;
            MyNotebook.add_new_note(Note note);
        }
        
        if( solution == 3 ) {

        }

        if( solution == 4) {
            break;
        }

        clearScreen(); //очищает экран
        
    }
}