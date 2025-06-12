#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector>
#include <string>
#include "Note.h"
#include "../headers/Storage.h"


class Notebook {
public:

    explicit Notebook(const std::string& filename);

    void add_new_note(Note note);//ready

    void remove_note(int position);//ready

    void print_list();//ready

    int get_size();

    Note get_elem_by_indx(int index);

    Note get_most_important_note();

    void make_most_important_note(int position);

    ~Notebook();

private:
    std::vector<Note> m_notes;
    Storage m_storage;
};


#endif // NOTEBOOK_H