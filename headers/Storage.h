#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "../headers/Note.h"

class Storage {
private:
    std::string m_filename;
    std::vector<Note> m_notes;

    void load_from_file();

    void save_2_file();

public:
    Storage(const std::string& fname);

    void add_item(const Note& note);

    bool remove_item(const Note& note);

    const std::vector<Note>& get_all_items() const;

    void clear_all();

    ~Storage();
};

#endif // STORAGE_H