#include "../headers/Storage.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../headers/Notebook.h"


void Storage::load_from_file()
{
    // ifstream - input file stream
    std::ifstream in_file(m_filename);
    if (in_file.is_open())
        {
        m_notes.clear();
        std::string line;
        while (std::getline(in_file, line))
            {
            if (!line.empty()) {
                Note note;
                std::istringstream iss(line);
                std::string priority_str;
                std::getline(iss, priority_str, '|');
                note.priority = std::stoi(priority_str);
                std::getline(iss, note.description, '|');
                std::string data_start_str;
                std::getline(iss, data_start_str, '|');
                note.day_start = boost::gregorian::from_simple_string(data_start_str);
                std::string data_end_str;
                std::getline(iss, data_end_str, '\n');
                note.day_deadline = boost::gregorian::from_simple_string(data_end_str);
                m_notes.push_back(note);
            }
        }
        in_file.close();
    }
}



void Storage::save_2_file() {
    // ofstream - output file stream
    std::ofstream outFile(m_filename);
    if (outFile.is_open())
        {
        for (const auto& note : m_notes)
            {
            outFile << note.priority << '|'
            << note.description << '|'
            << boost::gregorian::to_simple_string(note.day_start) << '|'
            << boost::gregorian::to_simple_string(note.day_deadline) << "\n";
        }
        outFile.close();
    }
}


Storage::Storage(const std::string& fname) : m_filename(fname)
{
    // Загружаем данные из файла при инициализации
    load_from_file();
}

void Storage::add_item(const Note& note)
{
    m_notes.push_back(note);
    save_2_file();
}

bool Storage::remove_item(const Note& note)
{
    auto it = std::find(m_notes.begin(), m_notes.end(), note);
    if (it != m_notes.end())
        {
        m_notes.erase(it);
        save_2_file();
        return true;
    }
    return false;
}

const std::vector<Note>& Storage::get_all_items() const
{
    return m_notes;
}

void Storage::clear_all()
{
    m_notes.clear();
    save_2_file();
}

Storage::~Storage()
{
    save_2_file();
}