#include "headers/View.h"


View::View(const vector<string>& items, int height, int width, int y, int x)
    : m_items(items), m_window(newwin(height, width, y, x), delwin)
{
    keypad(m_window.get(), TRUE);
    curs_set(0);
    leaveok(m_window.get(), TRUE);
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


void View::run_settings_menu() {
    int highlight = 0;
    int c;
    
    while (true) {
        draw_settings_menu(highlight);
        c = wgetch(m_window.get());
        
        switch(c) {
            case KEY_UP:
                highlight = (highlight == 0) ? 11 : (highlight - 1);
                break;
            case KEY_DOWN:
                highlight = (highlight == 11) ? 0 : (highlight + 1);
                break;
            case 10: // Enter - edit setting
                //edit_setting(highlight);
                break;
            case 27: // ESC - exit settings
                return;
            default:
                break;
        }
    }
}


void View::draw_settings_menu(int highlight) {
    werase(m_window.get());
    
    // Display all settings with their current values
    mvwprintw(m_window.get(), 1, 1, "Settings Menu (Use UP/DOWN to navigate, ENTER to edit, ESC to save)");
    
    std::vector<std::string> settings = {
        "Number of targets: " + std::to_string(Settings::g_num_targets),
        "Min velocity [km/h]: " + std::to_string(Settings::g_min_velocity),
        "Max velocity [km/h]: " + std::to_string(Settings::g_max_velocity),
        "Update period [s]: " + std::to_string(Settings::g_time_period),
        "Min range [km]: " + std::to_string(Settings::g_min_range),
        "Max range [km]: " + std::to_string(Settings::g_max_range),
        "Min altitude [m]: " + std::to_string(Settings::g_min_alt),
        "Max altitude [m]: " + std::to_string(Settings::g_max_alt),
        "Range error [m]: " + std::to_string(Settings::g_rho_std),
        "Azimuth error [deg]: " + std::to_string(Settings::g_theta_std),
        "False alarm probability [0-1]: " + std::to_string(Settings::prob_false_meas),
        "Missed detection probability [0-1]: " + std::to_string(Settings::prob_skip_meas)
    };
    
    for (size_t i = 0; i < settings.size(); ++i) {
        if (highlight == static_cast<int>(i)) {
            wattron(m_window.get(), A_REVERSE);
            mvwprintw(m_window.get(), i + 3, 1, "%s", settings[i].c_str());
            wattroff(m_window.get(), A_REVERSE);
        } else {
            mvwprintw(m_window.get(), i + 3, 1, "%s", settings[i].c_str());
        }
    }
    
    wrefresh(m_window.get());
}


void View::edit_settings() {

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
                if (highlight == 2) { // Assuming settings is the 3rd item (index 2)
                    run_settings_menu();
                }
                return highlight;
            case 27: // ESC
                return -1;
            default:
                break;
        }
    }
    return 0;
}


View::~View() {
}