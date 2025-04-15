#ifndef NOTE_H
#define NOTE_H

#include <string>

struct Note {
    // для поля date необходимо подключить Boost
    // boost::date day_start;
    // boost::date day_deadline;
    std::string description;
    int priority;
    Note* prev;
    Note* next;
};

#endif // NOTE_H