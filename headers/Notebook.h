#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector>
#include <string>
#include "Note.h"


class Notebook {
public:

    Notebook();

    void add_new_note(Note note){
        //хотел сам реализовать
        if (1){
            std::getline(std::cin, note.description);
            std::cin >> note.priority;
        }
        //решение через <vector>
        m_notes.push_back(note);
    }

    void remove_note(int position);

    void print_list(){
        for (auto i = 0; i < m_notes.size(); i++) {
            std::cout << m_notes[i] << "\n";
        }
    }

    Note get_most_important_note();

    ~Notebook();

private:
    std::vector<Note> m_notes;
};


#endif // NOTEBOOK_H