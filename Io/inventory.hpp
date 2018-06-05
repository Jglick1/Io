//
//  inventory.hpp
//  Io
//
//  Created by Jonah Glick on 6/4/18.
//  Copyright © 2018 Jonah Glick. All rights reserved.
//

#ifndef inventory_hpp
#define inventory_hpp

#include "sprite.hpp"
#include "player.hpp"

class Graphics;

class Inventory {
public:
	Inventory();
	Inventory(Graphics &graphics, Player &player);
	void update(int elapsedTime, Player &player);
	void draw(Graphics &graphics);
	
private:
	Player _player;
	Sprite _equipementPanel;
	

};









#endif /* inventory_hpp */
