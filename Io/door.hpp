//
//  door.hpp
//  Io
//
//  Created by Jonah Glick on 12/23/17.
//  Copyright © 2017 Jonah Glick. All rights reserved.
//

#ifndef door_h
#define door_h

#include "rectangle.hpp"
#include "globals.hpp"

#include <string>

class Door : public Rectangle {

public:
	Door() {}
	Door(Rectangle r, std::string destination) :
	Rectangle(r.getLeft() * globals::SPRITE_SCALE, r.getTop() * globals::SPRITE_SCALE, r.getWidth() * globals::SPRITE_SCALE, r.getHeight() * globals::SPRITE_SCALE),
	_destination(destination)
	{}
	
	const inline Rectangle getRectangle() const {return this->getRect(); }
	const std::string getDestination() const {return this->_destination; }
	
private:
	std::string _destination;
	
};




#endif /* door_h */
