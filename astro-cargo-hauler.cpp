// astro-cargo-hauler.cpp
// Author: Alexander S. Watson

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "gamestate.h"
#include "main_menu.h"
#include "game_ui.h"
#include "player.h"

using namespace std;
using namespace ftxui;

int main()
{
    auto screen = ScreenInteractive::Fullscreen();

    // Hides the terminal cursor
    screen.SetCursor(Screen::Cursor{ 0, 0, Screen::Cursor::Shape::Hidden });

    GameState state();

    // Instantiate Main Menu class
    MainMenu main_menu(&screen);
    GameUI gameui(&screen, state); //Why this error? makes no sense
    auto main_menu_view = main_menu.CreateView();
    Component gameui_view = gameui.CreateView();


    screen.Loop(main_menu_view);

    return 0;
}