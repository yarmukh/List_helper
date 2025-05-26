#ifndef NOTE_H
#define NOTE_H

#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
struct Note {
    // для поля date необходимо подключить Boost
    boost::gregorian::date day_start;
    boost::gregorian::date day_deadline;
    std::string description;
    int priority;
    bool is_most_important = false;
};

#endif // NOTE_H