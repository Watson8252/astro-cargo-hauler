#pragma once

//include game items here
#include "player.h"

class GameState {
private:

	//Game Items here
	Player player_;
	//Ship ship_;

public:
	
	explicit GameState(std::string& player_name) : player_(player_name) {};

	//References
	Player& GetPlayer() { return player_; }

	// Update states here
	void Tick();

};