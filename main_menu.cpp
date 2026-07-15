#include "main_menu.h"
#include <ftxui/dom/elements.hpp>

using namespace std;
using namespace ftxui;

MainMenu::MainMenu(ScreenInteractive* screen) : screen_(screen) {}

Component MainMenu::RenderUI() {

    // 1. Main Menu
    Component menu = Menu(&menu_entries_, &selected_menu_entry_);

    Component main_menu_renderer = Renderer(menu, [menu] {
        return vbox({
            text("Astro Cargo Hauler") | bold | center,
            separator(),
            filler(),
            menu->Render() | center,
            filler()
            }) | border;
        });

    // 2. Character Creation
    // Does not actually instantiate the game but will be the constructor
    // for the Player class to be used in the main game.
    Component input_field = Input(&player_name_, "Enter Name...");

    Component new_game_renderer = Renderer(input_field, [input_field] {
        return vbox({
            text("New Game") | bold | center,
            separator(),
            filler(),
            input_field->Render() | center,
            filler(),
            text("Press Enter to Continue. Press Esc to go back to Main Menu.") | center
            }) | border;
        });

    // Main container for menu system
    auto container = Container::Tab({
        main_menu_renderer,
        new_game_renderer
        }, &active_tab_);

    // Handle events for navigation and input
    Component root = CatchEvent(container, [this](Event event) {

        // Main Menu navigation logic
        if (active_tab_ == 0 && event == Event::Return) {
            if (selected_menu_entry_ == 0) {
                active_tab_ = 1; // Go to Character Creation
                return true;
            }
            if (selected_menu_entry_ == 3) {
                if (screen_) screen_->ExitLoopClosure()();
                return true;
            }
            return true;
        }

        // New Game character screen logic
        if (active_tab_ == 1) {
            if (event == Event::Return) {
                if (!player_name_.empty()) {
                    // Exit loop for testing. Update to loop gameui
                    if (screen_) screen_->ExitLoopClosure()();
                }
                return true;
            }
            else if (event == Event::Escape) {
                active_tab_ = 0; // Return to main menu
                return true;
            }
        }

        return false;
        });

    return root;
}