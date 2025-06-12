#include "../headers/Notebook.h"

#include <iostream>


Notebook::Notebook(const std::string& filename): m_storage(filename)
{

}


void Notebook::add_new_note(Note note)
{
    m_notes.push_back( note );
    m_storage.add_item(note);
}


void Notebook::remove_note(int position)
{
    if ((position >= 0) & (position < m_notes.size()))
    {
        m_storage.remove_item(m_notes[position]);
        m_notes.erase( m_notes.begin() + position );
    }
}


void Notebook::print_list()
{
    //std::cout << m_notes.size() << std::endl;
    for (auto i = 0; i < m_notes.size(); i++)
    {
        std::cout << m_notes[i].priority << "\n";
        std::cout << m_notes[i].description << "\n";
    }
}


int Notebook::get_size() {
    return m_notes.size();
}


Note Notebook::get_elem_by_indx(int index) {
    return m_notes[index];
}


Note Notebook::get_most_important_note()
{
    for (auto i = 0; i < m_notes.size(); i++) {
        if (m_notes[i].is_most_important == true) {
            return m_notes[i];
        }
    }
    throw std::runtime_error("There is no most important note");
    // UB - undefined behavior - неопределённое поведение 
}

void Notebook::make_most_important_note(int position) {

}

Notebook::~Notebook()
{

}