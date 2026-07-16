// astro-cargo-hauler.cpp
// Author: Alexander S. Watson

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
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

    // Instantiate Main Menu class
    MainMenu mainMenuController(&screen);
    GameUI gameUIController(&screen);
    Component main_menu_component = mainMenuController.RenderUI();
    Component gameUI_component = gameUIController.RenderUI();

    int active = 0;

    auto global = Container::Tab({
        main_menu_component,
        gameUI_component
    }, &active);

    auto router = CatchEvent(global, [&](Event event) {
        if (active == 0) {
            string player_name = mainMenuController.GetPlayerName();
            if (!player_name.empty()) {
                active = 1;
                return true;
            }
        }
        return false;
    });

    screen.Loop(router);

    return 0;
}