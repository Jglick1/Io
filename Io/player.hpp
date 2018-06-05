//
//  player.hpp
//  Io
//
//  Created by Jonah Glick on 6/4/17.
//  Copyright © 2017 Jonah Glick. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include "animatedsprite.hpp"
#include "globals.hpp"
#include "level.hpp"


class Graphics;

class Player : public AnimatedSprite {

public:
	Player();
	Player(Graphics &graphics, Vector2 spawnPoint);
	void draw(Graphics &graphics);
	void update(float elapsedTime);
	
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	
	void stopMoving();
	
	
	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
	
	void handleTileCollisions(std::vector<Rectangle> &others);
	void handleDoorCollision(std::vector<Door> &others, Level &level, Graphics &graphics);
	
	const float getX() const;
	const float getY() const;
	
private:
	float _dx, _dy;
	
	Direction _facing;
	
};

#endif /* player_hpp */
