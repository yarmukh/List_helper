#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector>
#include <string>
#include "Note.h"


class Notebook {
public:

    Notebook();

    void add_new_note(Note note);//ready


    void remove_note(int position);//ready

    void print_list();//ready

    Note get_most_important_note();

    void make_most_important_note(int position);

    ~Notebook();

private:
    std::vector<Note> m_notes;
};


#endif // NOTEBOOK_H