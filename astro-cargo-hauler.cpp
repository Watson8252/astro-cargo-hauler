// astro-cargo-hauler.cpp
// Author: Alexander S. Watson

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "main_menu.h"
#include "player.h"

using namespace std;
using namespace ftxui;

int main()
{
    auto screen = ScreenInteractive::Fullscreen();

    // Hides the terminal cursor
    screen.SetCursor(Screen::Cursor{ 0, 0, Screen::Cursor::Shape::Hidden });

    // Instantiate Main Menu class
    MainMenu mainMenuController(&screen);
    Component main_menu_component = mainMenuController.RenderUI();

    // Run the UI loop (will block here until ExitLoopClosure is called)
    screen.Loop(main_menu_component);

    // Placeholder for player return
    // TODO: Implement game loop and player initialization
    // into the game loop from the main menu. 
    string chosen_name = mainMenuController.GetPlayerName();

    if (!chosen_name.empty()) {
        // TODO: Transition to Gameplay Loop
    }

    return 0;
}