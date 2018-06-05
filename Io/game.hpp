//
//  Game.hpp
//  Io
//
//  Created by Jonah Glick on 5/14/17.
//  Copyright © 2017 Jonah Glick. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "player.hpp"
#include "level.hpp"
#include "graphics.hpp"
#include "hud.hpp"
#include "inventory.hpp"


class Game {
public:
	Game();
	~Game();
	
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);
	
	Player _player;
	
	Level _level;
	
	HUD _hud;
	
	Inventory _inventory;
	
	Graphics _graphics;
	
	bool _inventory_menu_active = 0;
	
	
};

#endif /* Game_hpp */
