#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector>

#include "Note.h"


class Notebook {
public:

    Notebook();

    void add_new_note(Note note);

    void remove_note(int position);

    Note get_most_important_note();

    ~Notebook();

private:
    std::vector<Note> m_notes;
};


#endif // NOTEBOOK_H