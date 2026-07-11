#pragma once

#include <ftxui/component/component.hpp>
#include <vector>

class Game_ui {
  private:
    std::vector<std::string> entries = {
      "New Game",
      "Load Game",
      "Quit Game"
    };
};
