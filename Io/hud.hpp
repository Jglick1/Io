//
//  hud.hpp
//  Io
//
//  Created by Jonah Glick on 6/4/18.
//  Copyright © 2018 Jonah Glick. All rights reserved.
//

#ifndef hud_h
#define hud_h


#include "sprite.hpp"
#include "player.hpp"
#include <vector>

class Graphics;

class HUD {
public:
	HUD();
	HUD(Graphics &graphics, Player &player);
	void update(int elapsedTime, Player &player);
	void draw(Graphics &graphics);
	
private:
	Player _player;
	
	//Health sprites
	Sprite _fullHeart;
	Sprite _halfHeart;
	Sprite _emptyHeart;
	
	//std::vector<Sprite> _numbers;
	
	Sprite _n0;
	Sprite _n1;
	Sprite _n2;
	Sprite _n3;
	Sprite _n4;
	Sprite _n5;
	Sprite _n6;
	Sprite _n7;
	Sprite _n8;
	Sprite _n9;
	
	Sprite _itemFrame;
	
	
	
	
};





#endif /* hud_h */
