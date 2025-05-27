#include "../headers/Storage.h"

void Storage::load_from_file() {
    // ifstream - input file stream
    std::ifstream in_file(m_filename);
    if (in_file.is_open()) {
        m_items.clear();
        std::string line;
        while (std::getline(in_file, line)) {
            if (!line.empty()) {
                m_items.push_back(line);
            }
        }
        in_file.close();
    }
}

void Storage::save_2_file() {
    // ofstream - output file stream
    std::ofstream outFile(m_filename);
    if (outFile.is_open()) {
        for (const auto& item : m_items) {
            outFile << item << "\n";
        }
        outFile.close();
    }
}


Storage::Storage(const std::string& fname) : m_filename(fname) {
    // Загружаем данные из файла при инициализации
    load_from_file();
}

void Storage::add_item(const std::string& item) {
    m_items.push_back(item);
    save_2_file();
}

bool Storage::remove_item(const std::string& item) {
    auto it = std::find(m_items.begin(), m_items.end(), item);
    if (it != m_items.end()) {
        m_items.erase(it);
        save_2_file();
        return true;
    }
    return false;
}

const std::vector<std::string>& Storage::get_all_items() const {
    return m_items;
}

void Storage::clear_all() {
    m_items.clear();
    save_2_file();
}

Storage::~Storage() {
    save_2_file();
}