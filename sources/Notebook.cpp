#include "../headers/Notebook.h"

#include <iostream>


Notebook::Notebook()
{

}


void Notebook::add_new_note(Note note)
{
    m_notes.push_back( note );
}


void Notebook::remove_note(int position)
{
    m_notes.erase( m_notes.begin() + position );
}


void Notebook::print_list(){
    for (auto i = 0; i < m_notes.size(); i++) {
        std::cout << m_notes[i].description << "\n";
    }
}


Note Notebook::get_most_important_note()
{
    return Note();
}


Notebook::~Notebook()
{

}