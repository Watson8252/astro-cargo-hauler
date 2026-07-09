// astro-cargo-hauler.cpp : Defines the entry point for the application.
// @author Alexander S. Watson

#include "astro-cargo-hauler.h"

//These could go into a separate header file, but for now, they are here for testing purposes.
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace std;
using namespace ftxui;

int main()
{
	// Create a terminal screen for interactive components.
	auto screen = ScreenInteractive::TerminalOutput();

	// Create a menu with options for the user to select from.
	std::vector<std::string> menu_times = {
		"New Game",
		// TODO: Add logic to hide/show this options based on existence of a saved game file.
		"Load Game",
		"Quit"
	};

	// Track the selected menu option.
	int selected = 0;

	// Create a menu component with the menu options and selected index.
	Component menu = Menu(&menu_times, &selected);

	// Create a renderer component that displays the title and the menu.
	Component renderer = Renderer(menu, [&]{
		return vbox({
			text("Astro Cargo Hauler") | bold | center,
			separator(),
			menu->Render() | center
		}) | border;
	});

	// Create a catch event component that listens for the return key.
	Component root = CatchEvent(renderer, [&](Event event) {
		if (event == Event::Return) {
			// TODO: Add logic to start a new game.
			if (selected == 0) {}
			// TODO: Add logic to open a menu for saved games.
			if (selected == 1) {}
			// Exit the application on the "Quit" option.
			if (selected == 2) {
				screen.ExitLoopClosure()();
			}
			return true;
		}
		return false;
	});

	// Start the main loop of the application with the root component.
	screen.Loop(root);
	

	return 0;
}
