#ifndef NOTE_H
#define NOTE_H

#include <filesystem>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
struct Note {
    boost::gregorian::date day_start;
    boost::gregorian::date day_deadline;
    std::string description;
    int priority;
    bool is_most_important = false;
    bool operator == (const Note& other) const
    {
        return description == other.description &&
            priority == other.priority &&
            day_start == other.day_start &&
            day_deadline == other.day_deadline;
    }
};

#endif // NOTE_H