#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


class Storage {
private:
    std::string m_filename;
    std::vector<std::string> m_items;

    void load_from_file();

    void save_2_file();

public:
    
    Storage(const std::string& fname);

    void add_item(const std::string& item);

    bool remove_item(const std::string& item);

    const std::vector<std::string>& get_all_items() const;

    // std::vector<std::string> get_all_items() const;

    void clear_all();

    ~Storage();
};

#endif // STORAGE_H