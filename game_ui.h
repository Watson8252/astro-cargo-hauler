#ifndef GAME_UI_H
#define GAME_UI_H

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace std;
using namespace ftxui;

class GameUI {

private:

	//Screen pointer
	ScreenInteractive* screen_;

	//Need all game elements to be displayed here

public:

	//Constructor, add in game elements to be displayed
	GameUI(ScreenInteractive* screen);
	
	// Returns Component UI tree
	Component RenderUI();

};

#endif