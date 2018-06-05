//
//  inventory.cpp
//  Io
//
//  Created by Jonah Glick on 6/4/18.
//  Copyright © 2018 Jonah Glick. All rights reserved.
//


#include "inventory.hpp"
#include "graphics.hpp"
#include <iostream>

Inventory::Inventory() {}

Inventory::Inventory(Graphics &graphics, Player &player) {
	
	this->_player = player;
	this->_equipementPanel = Sprite(graphics, "/Users/jonahglick/Documents/Io/inventory.png", 152, 264, 80, 72, 40, 40);
	
	//int sourceX, int sourceY, int width, int height, float posX, float posY
	
}

void Inventory::update(int elapsedTime, Player &player) {
	
	this->_player = player;
	
	
}

void Inventory::draw(Graphics &graphics) {
	//this->_itemFrame.draw(graphics, this->_itemFrame.getX(), this->_itemFrame.getY());
	this->_equipementPanel.draw(graphics, this->_equipementPanel.getX(), this->_equipementPanel.getY());
	//std::cout << "draw called " << this->_equipementPanel.getX() << " " << this->_equipementPanel.getY() << std::endl;
	
}





