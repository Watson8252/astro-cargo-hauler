#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace ftxui;

class MainMenu {

private:
    ScreenInteractive* screen_;

    // State Variables
    int active_tab_ = 0;
    int selected_menu_entry_ = 0;
    string player_name_ = "";
    vector<string> menu_entries_ = { "New Game", "Load Game", "Settings", "Quit" };

public:
    // Constructor accepts a pointer to the main interactive screen
    MainMenu(ScreenInteractive* screen);

    // Returns the fully constructed, interactive UI component tree
    Component RenderUI();

    // Accessors
    string GetPlayerName() const { return player_name_; }

};

#endif