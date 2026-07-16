#include "game_ui.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace ftxui;

GameUI::GameUI(ScreenInteractive* screen) : screen_(screen) {}

Component GameUI::RenderUI() {

	// TODO:
	// 1. Tab Matrix that carries all the views for the game
	// 2. Overview matrix that has either floating windows or flex windows for game elements
	//	  Overview will contain market data for current locations
	//    Overview will contain nearby market data
	//    Overview will contain nearby systems and next jump systems/regions
	//    Overview will contain quest data
	// 3. Individual tabs for each game element with more detailed information

	// Main View Tabs
	vector<string> game_tabs{
		"Overview",
		"Player",
		"Ship",
		"Inventory",
		"Factions",
		"Systems",
		"Stations",
		"Wallet",
	};
	int game_tab_selected = 0;
	auto tab_toggle = Toggle(&game_tabs, &game_tab_selected);

	// Tab Container holds the game windows.
	auto tab_container = Container::Tab(
		{
			//Tab Windows here
		}, &game_tab_selected);
	
	// Container holds the toggler and the windows.
	auto container = Container::Vertical({
		tab_toggle,
		tab_container
		});

	//Renderer outputs the game window
	auto renderer = Renderer(container, [&] {
		return vbox({
			hbox({tab_toggle->Render()}),
				separator(),
				tab_container->Render(),
			}) | border;
	});

	// Make available to the main()
	return renderer;
}