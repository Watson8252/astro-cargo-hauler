// astro-cargo-hauler.cpp
// @author Alexander S. Watson

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include "player.h"

using namespace std;
using namespace ftxui;

// This is the entry point of the application
// TODO: Move main menu logic to a separate class. Create headers for it.

int main()
{
    auto screen = ScreenInteractive::Fullscreen();
    
    // KEEP THIS! It hides the terminal cursor
    screen.SetCursor(Screen::Cursor{ 0, 0, Screen::Cursor::Shape::Hidden });

    // --------------------------------------------------------
    // 1. MAIN MENU SCREEN
    // --------------------------------------------------------
    vector<string> menu_entries = {
        "New Game",
        "Load Game",
        "Quit"
    };
    int menu_selected = 0;
    Component menu = Menu(&menu_entries, &menu_selected);

    Component menu_renderer = Renderer(menu, [&] {
        return vbox({
            text("Astro Cargo Hauler") | bold | center,
            separator(),
            filler(),
            menu->Render() | center,
            filler(),
            }) | border;
        });

    // --------------------------------------------------------
    // 2. NEW GAME SCREEN
    // --------------------------------------------------------
    string char_name = "";
    string placeholder = "Enter name...";
    Component input_field = Input(&char_name, placeholder);

    Component new_game_renderer = Renderer(input_field, [&] {
        return vbox({
            text("Character Creation") | bold | center,
            separator(),
            filler(),
            vbox({
                text("Enter Character Name:"),
                input_field->Render()
            }) | size(WIDTH, LESS_THAN, 40) | center,
            filler()
            }) | border;
        });

    // --------------------------------------------------------
    // 3. LOAD GAME SCREEN
    // TODO: Implement Load Game Functionality
    // --------------------------------------------------------

    // --------------------------------------------------------
    // 4. Game Screen
    // --------------------------------------------------------
    Component game_renderer = Renderer([&]{
        return vbox({
            filler(),
            text("Player name here."),
            filler()
            }) | border;
        });

    // --------------------------------------------------------
    // N. TAB CONTROLLER & STATE MANAGEMENT
    // --------------------------------------------------------
    // The active_tab index is our screens and what we want to render:
    // 0 = Menu, 1 = NewGame
    int active_tab = 0;

    auto main_container = Container::Tab({
        menu_renderer,
        new_game_renderer
        }, &active_tab);

    // Intercept events globally for screen navigation upon user input of Return key.
    Component root = CatchEvent(main_container, [&](Event event) {

        // Handle Menu screen actions
        if (active_tab == 0 && event == Event::Return) {
            if (menu_selected == 0) {
                active_tab = 1; // Switch to New Game tab
                return true;
            }
            if (menu_selected == 1) {
                // TODO: Load Game Logic
                return true;
            }
            if (menu_selected == 2) {
                screen.ExitLoopClosure()();
                return true;
            }
        }

        // Handle New Game screen actions
        if (active_tab == 1 && event == Event::Return) {
            if (!char_name.empty()) {
                // TODO: Transition to actual gameplay state here
                Player player = Player(char_name, 1000.00); // Create player for testing
                screen.ExitLoopClosure()(); // Temporarily exit for testing
            }
            return true;
        }

        return false;
        });

    // Start the game loop
    screen.Loop(root);

    return 0;
}