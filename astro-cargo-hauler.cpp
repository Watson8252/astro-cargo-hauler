// astro-cargo-hauler.cpp
// Author: Alexander S. Watson

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "gamestate.h"
#include "main_menu.h"
#include "game_ui.h"

using namespace std;
using namespace ftxui;

int main()
{
    auto screen = ScreenInteractive::Fullscreen();

    // Hides the terminal cursor
    screen.SetCursor(Screen::Cursor{ 0, 0, Screen::Cursor::Shape::Hidden });

    // Instantiate MainMenu and GameUI
    MainMenu main_menu(&screen);
    auto main_menu_view = main_menu.CreateView();

    // Check if the player name in main menu is not empty
    if (!main_menu.GetPlayerName().empty()) {

        // switch loop to game ui
        string player_name = main_menu.GetPlayerName();
        GameState state(player_name);
        GameUI gameui(&screen, state);
        auto gameui_view = gameui.CreateView();
        screen.Loop(gameui_view);
    }
    else {
        screen.Loop(main_menu_view);
    }

    return 0;
}