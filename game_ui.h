#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "gamestate.h"

using namespace std;
using namespace ftxui;

class GameUI {

private:

	//Screen pointer
	ScreenInteractive* screen_;
	GameState& state_;

	//Need all game elements to be displayed here

public:

	//Constructor, add in game elements to be displayed
	GameUI(ScreenInteractive* screen, GameState& state);
	
	// Returns Component UI tree
	Component CreateView();
	int active_tab = 0;

};