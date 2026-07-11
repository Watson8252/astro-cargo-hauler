// Game UI code

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

using namespace std;
using namespace ftxui;

// --------------------------------------------------------
// Components & Renderers
// --------------------------------------------------------

// Main Menu
vector<string> main_menu_entries = {
  "New Game",
  "Load Game",
  "Settings",
  "Quit"
};
int main_menu_entry_selected = 0;
Component main_menu = Menu(&main_menu_entries, &main_menu_entry_selected);

Component main_menu_renderer = Renderer(main_menu, [] {
    return vbox({
        text("Astro Cargo Hauler") | bold | center,
        separator(),
        filler(),
        main_menu->Render() | center,
        filler()
        }) | border;
    });

// Character Creation New Game
string player_name = "";
string placeholder = "Enter Name...";
Component input_field = Input(&player_name, placeholder);

Component new_game = Renderer(input_field, [] {
    return vbox({
        text("New Game") | bold | center,
        separator(),
        filler(),
        input_field->Render() | center,
        text("Press Enter to Continue. Press Esc to go back to Main Menu.") | center,
        filler()
        }) | border;
    });

// Load Game
// TODO: Create load game component and tie parser logic to it

// Settings
vector<string> settings_tabs = {
  "Display",
  "Palette"
};
int settings_tab_selected = 0;
Component settings_tab_menu = Menu(&settings_tabs, &settings_tab_selected);

vector<string> display_options = {
  "Windowed",
  "Fullscreen"
};



// --------------------------------------------------------
// State holder
// --------------------------------------------------------
// Active tab and the associated container.
// Keep these two together.
int active_tab = 0;
auto container = Container::Tab({
      //Add Components here
      main_menu,
      new_game
    } , &active_tab);
