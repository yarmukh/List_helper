#ifndef NOTE_H
#define NOTE_H

#include <string>

struct Note {
    // для поля date необходимо подключить Boost
    // boost::date day_start;
    // boost::date day_deadline;
    std::string description;
    int priority;
    bool is_most_important = false;
};

#endif // NOTE_H