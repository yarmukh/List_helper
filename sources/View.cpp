#include "../headers/View.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

View::View(const vector<string>& items, int height, int width, int y, int x)
    : m_items(items), m_window(newwin(height, width, y, x), delwin), m_notebook(new Notebook())
{
    keypad(m_window.get(), TRUE);
    curs_set(0);
    leaveok(m_window.get(), TRUE);
}


void View::run_show_menu(){
    int c;
    int highlight = 0;
    while (true) {
        draw_show_menu(highlight);
        c = wgetch(m_window.get());

        switch(c) {
            case KEY_UP:
                highlight = (highlight == 0) ? (m_notebook->get_size() - 1) : (highlight - 1);
                break;
            case KEY_DOWN:
                highlight = (highlight == static_cast<int>(m_notebook->get_size()) - 1) ? ( 0 ) : (highlight + 1);
                break;
            case 10: // Enter

            case 27: // ESC
                return;
            default:
                break;
        }
    }
    return;
}


void View::draw_show_menu(int highlight){
    werase(m_window.get());

    for (size_t i = 0; i < m_notebook->get_size(); ++i) {
        Note note = m_notebook->get_elem_by_indx(i);
        if (highlight == static_cast<int>(i)) {
            wattron(m_window.get(), A_REVERSE);
            mvwprintw(m_window.get(), i + 1, 1, "[%2d]", note.priority);
            mvwprintw(m_window.get(), i + 1, 4 + std::to_string(note.priority).length(), "%s", note.description.c_str());
            mvwprintw(m_window.get(), i + 1, 1 + 4 + std::to_string(note.priority).length() + note.description.length(), "%s", boost::gregorian::to_simple_string(note.day_start).c_str());
            mvwprintw(m_window.get(), i + 1, 1 + 4 + std::to_string(note.priority).length() + note.description.length() + boost::gregorian::to_simple_string(note.day_start).length() + 2, "%s", boost::gregorian::to_simple_string(note.day_deadline).c_str());
            wattroff(m_window.get(), A_REVERSE);
        } else {
            mvwprintw(m_window.get(), i + 1, 1, "[%2d]", note.priority);
            mvwprintw(m_window.get(), i + 1, 4 + std::to_string(note.priority).length(), "%s", note.description.c_str());
            mvwprintw(m_window.get(), i + 1, 1 + 4 + std::to_string(note.priority).length() + note.description.length(), "%s", boost::gregorian::to_simple_string(note.day_start).c_str());
            mvwprintw(m_window.get(), i + 1, 1 + 4 + std::to_string(note.priority).length() + note.description.length() + boost::gregorian::to_simple_string(note.day_start).length() + 2, "%s", boost::gregorian::to_simple_string(note.day_deadline).c_str());
        }
    }
    wrefresh(m_window.get());
}


void View::draw_main_menu(int highlight) {
    werase(m_window.get());
    
    for (size_t i = 0; i < m_items.size(); ++i) {
        if (highlight == static_cast<int>(i)) {
            wattron(m_window.get(), A_REVERSE);
            mvwprintw(m_window.get(), i + 1, 1, "%s", m_items[i].c_str());
            wattroff(m_window.get(), A_REVERSE);
        } else {
            mvwprintw(m_window.get(), i + 1, 1, "%s", m_items[i].c_str());
        }
    }
    wrefresh(m_window.get());
}


void View::run_remove_menu() {
    int c;
    int highlight = 0;
    while (true) {
        draw_remove_menu(highlight);
        c = wgetch(m_window.get());
        switch(c) {
            case KEY_UP:
                highlight = (highlight == 0) ? (m_notebook->get_size() - 1) : (highlight - 1);
                break;
            case KEY_DOWN:
                highlight = (highlight == static_cast<int>(m_notebook->get_size()) - 1) ? ( 0 ) : (highlight + 1);
                break;
            case 10: // Enter
                m_notebook->remove_note(highlight);
                break;
            case 27: // ESC
                return;
            default:
                break;
        }
    }
    return;
}


void View::draw_remove_menu(int highlight) {
    werase(m_window.get());

    for (size_t i = 0; i < m_notebook->get_size(); ++i) {
        Note note = m_notebook->get_elem_by_indx(i);
        if (highlight == static_cast<int>(i)) {
            wattron(m_window.get(), A_REVERSE);
            mvwprintw(m_window.get(), i + 1, 1, "[%2d]", note.priority);
            mvwprintw(m_window.get(), i + 1, 4 + std::to_string(note.priority).length(), "%s", note.description.c_str());
            mvwprintw(m_window.get(), i + 1, 1 + 4 + std::to_string(note.priority).length() + note.description.length(), "%s", boost::gregorian::to_simple_string(note.day_start).c_str());
            mvwprintw(m_window.get(), i + 1, 1 + 4 + std::to_string(note.priority).length() + note.description.length() + boost::gregorian::to_simple_string(note.day_start).length() + 2, "%s", boost::gregorian::to_simple_string(note.day_deadline).c_str());

            wattroff(m_window.get(), A_REVERSE);
        } else {
            mvwprintw(m_window.get(), i + 1, 1, "[%2d]", note.priority);
            mvwprintw(m_window.get(), i + 1, 4 + std::to_string(note.priority).length(), "%s", note.description.c_str());
            mvwprintw(m_window.get(), i + 1, 1 + 4 + std::to_string(note.priority).length() + note.description.length(), "%s", boost::gregorian::to_simple_string(note.day_start).c_str());
            mvwprintw(m_window.get(), i + 1, 1 + 4 + std::to_string(note.priority).length() + note.description.length() + boost::gregorian::to_simple_string(note.day_start).length() + 2, "%s", boost::gregorian::to_simple_string(note.day_deadline).c_str());

        }
    }
    wrefresh(m_window.get());
}


void View::run_input_menu() {
    enum class State { ENTER_TEXT, ENTER_PRIORITY, ENTER_DAYS };
    State current_state = State::ENTER_TEXT;
    bool editing = true;
    string input_str;
    string input_str_priority;
    string input_days_str;
    int cursor_pos = 0;

    int height = 7;
    int width = 50;
    int y = (LINES - height) / 2;
    int x = (COLS - width) / 2;
    unique_ptr<WINDOW, decltype(&delwin)> edit_win(newwin(height, width, y, x), delwin);
    keypad(edit_win.get(), TRUE);
    curs_set(1);

    while (editing) {
        werase(edit_win.get());
        box(edit_win.get(), 0, 0);
        switch (current_state) {
            case State::ENTER_TEXT:
                mvwprintw(edit_win.get(), 1, 1, "Enter note text:");
                mvwprintw(edit_win.get(), 2, 1, "Text: %s", input_str.c_str());
                wmove(edit_win.get(), 1, 7 + cursor_pos);
            case State::ENTER_PRIORITY:
                mvwprintw(edit_win.get(), 1, 1, "Note text: %s", input_str.c_str());
                mvwprintw(edit_win.get(), 2, 1, "Enter priority: ");
                mvwprintw(edit_win.get(), 3, 1, "Priority: %s", input_str_priority.c_str());
                wmove(edit_win.get(), 3, 10 + input_str_priority.length());
            case State::ENTER_DAYS:
                mvwprintw(edit_win.get(), 1, 1, "Note text: %s", input_str.c_str());
                mvwprintw(edit_win.get(), 2, 1, "Priority: %s", input_str_priority.c_str());
                mvwprintw(edit_win.get(), 3, 1, "Date start task: %s", boost::gregorian::to_simple_string(boost::gregorian::day_clock::local_day()).c_str());
                mvwprintw(edit_win.get(), 4, 1, "Days before deadline: %s", input_days_str.c_str());
                wmove(edit_win.get(), 4, 22 + input_days_str.length());
        }
        wrefresh(edit_win.get());

        int ch = wgetch(edit_win.get());
        switch (ch)
        {
            case 10: // Enter - confirm edit
                if(current_state == State::ENTER_TEXT && !input_str.empty())
                {
                    current_state = State::ENTER_PRIORITY;
                    cursor_pos = 0;
                }
                else if (current_state == State::ENTER_PRIORITY && !input_str_priority.empty())
                {
                    current_state = State::ENTER_DAYS;
                    cursor_pos=0;
                }
                else if(current_state == State::ENTER_DAYS && !input_days_str.empty())
                {
                    Note note;
                    note.day_start = boost::gregorian::day_clock::local_day();
                    note.day_deadline = note.day_start + boost::gregorian::days(stoi(input_days_str));
                    note.description = input_str;
                    note.priority = stoi(input_str_priority);
                    m_notebook->add_new_note(note);
                    editing = false;
                }
                break;
            case 27: // ESC - cancel editing
                case KEY_F(1):
                case KEY_F(2):
                    editing = false;
                    break;
            case KEY_BACKSPACE:
            case 127:
            case 8:
                if(current_state == State::ENTER_TEXT) {
                    if(!input_str.empty() && cursor_pos > 0) {
                        input_str.erase(cursor_pos - 1, 1);
                        cursor_pos--;
                    }
                }
                else if (current_state == State::ENTER_PRIORITY)
                {
                    if(!input_str_priority.empty())
                    {
                        input_str_priority.pop_back();
                    }
                }
                else if (current_state == State::ENTER_DAYS)
                {
                    if (!input_days_str.empty())
                    {
                        input_days_str.pop_back();
                    }
                }
                break;
            case KEY_DC: // Delete key
                if (!input_str.empty() && cursor_pos < static_cast<int>(input_str.size()))
                {
                    input_str.erase(cursor_pos, 1);
                }
                break;
            case KEY_LEFT:
                if ((current_state == State::ENTER_TEXT) && (cursor_pos > 0))
                {
                    cursor_pos--;
                }
                break;
            case KEY_RIGHT:
                if ((current_state == State::ENTER_TEXT) && (cursor_pos < static_cast<int>(input_str.size())))
                 {
                    cursor_pos++;
                }
                break;
            default:
                if(current_state == State::ENTER_TEXT) {
                   if(isprint(ch)) {
                       input_str.insert(cursor_pos, 1, static_cast<char>(ch));
                       cursor_pos++;
                   }
               }
               else if (current_state == State::ENTER_PRIORITY){
                   if(isdigit(ch)) {
                       input_str_priority += static_cast<char>(ch);
                   }
               }
               else if (current_state == State::ENTER_DAYS)
               {
                    if (isdigit(ch)) {
                        input_days_str += static_cast<char>(ch);
                    }
               }
               break;
        }
    }
    curs_set(0);
}


void View::draw_input_menu(int highlight) {

}


int View::run() {
    int c;
    int highlight = 0;
    while (true) {
        draw_main_menu(highlight);
        c = wgetch(m_window.get());
        
        switch(c) {
            case KEY_UP:
                highlight = (highlight == 0) ? (m_items.size() - 1) : (highlight - 1);
                break;
            case KEY_DOWN:
                highlight = (highlight == static_cast<int>(m_items.size()) - 1) ? ( 0 ) : (highlight + 1);
                break;
            case 10: // Enter
                if (highlight == 0) { // Assuming settings is the 3rd item (index 2)
                    run_show_menu();
                } else if (highlight == 1){
                     static int i = 0;
                    run_input_menu();

                } else if(highlight == 2){
                    run_remove_menu();
                }
                else if(highlight == 3){
                    return -1;
                }

                break;
            default:
                break;
        }
    }
    return 0;
}


View::~View() {
}