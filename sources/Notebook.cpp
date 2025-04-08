#include "../headers/Notebook.h"


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


Note Notebook::get_most_important_note()
{
    return Note();
}


Notebook::~Notebook()
{

}