//
//  hud.cpp
//  Io
//
//  Created by Jonah Glick on 6/4/18.
//  Copyright © 2018 Jonah Glick. All rights reserved.
//

#include "hud.hpp"
#include "graphics.hpp"

HUD::HUD() {}

HUD::HUD(Graphics &graphics, Player &player) {
	
	this->_player = player;
	this->_fullHeart = Sprite(graphics,"/Users/jonahglick/Documents/Io/hud.png",0,0,0,0,0,0);
	this->_halfHeart = Sprite(graphics,"/Users/jonahglick/Documents/Io/hud.png",0,0,0,0,0,0);
	this->_emptyHeart = Sprite(graphics,"/Users/jonahglick/Documents/Io/hud.png",0,0,0,0,0,0);
	
	this->_n0 = Sprite(graphics, "/Users/jonahglick/Documents/Io/hud.png", 0,0,0,0,0,0);
	
	this->_itemFrame = Sprite(graphics, "/Users/jonahglick/Documents/Io/hud.png", 0, 28, 22, 22, 10, 10);
	
	//int sourceX, int sourceY, int width, int height, float posX, float posY
	
}

void HUD::update(int elapsedTime, Player &player) {
	
	this->_player = player;
	
	
}

void HUD::draw(Graphics &graphics) {
	this->_itemFrame.draw(graphics, this->_itemFrame.getX(), this->_itemFrame.getY());
	
	
}

