//
//  Game.cpp
//  Io
//
//  Created by Jonah Glick on 5/14/17.
//  Copyright © 2017 Jonah Glick. All rights reserved.
//

#include "game.hpp"
#include <SDL2/SDL.h>
#include "graphics.hpp"
#include "input.hpp"
#include <iostream>
#include <algorithm>
#include "globals.hpp"


namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 1000 / FPS;
}


Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);	//							maybe change this
	this->gameLoop();
	
}

Game::~Game() {
	
}

void Game::gameLoop() {
	Graphics graphics;
	SDL_Event event;
	Input input;
	
	//this->_player = Player(graphics, 100, 100);
	//this->_level = Level("map 1", Vector2(100,100), graphics);
	
	//this->_level = Level("/Users/jonahglick/Documents/Io/newTestMap", Vector2(100,100), graphics);
	this->_player = Player(graphics, this->_level.getPlayerSpawnPoint());
	this->_level = Level("/Users/jonahglick/Documents/Io/TestMap", graphics);
	this->_hud = HUD(graphics, this->_player);
	this->_inventory = Inventory(graphics, this->_player);
	
	int LAST_UPDATE_TIME = SDL_GetTicks();
	
	Direction inPower;
	
	bool keyInPower = 0;
	
	
	
	while(true) {
		
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
			//else if (event.type == SDL_SCANCODE_I) {
			else if (input.isKeyHeld(SDL_SCANCODE_I)) {
				this->_inventory_menu_active = !this->_inventory_menu_active;
			}
		}
		
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
			return;
		}
		
		if(keyInPower) {
			switch (inPower) {
				case UP:
					if (!input.isKeyHeld(SDL_SCANCODE_UP)) {
						keyInPower = 0;
					}
					break;
				case DOWN:
					if (!input.isKeyHeld(SDL_SCANCODE_DOWN)) {
						keyInPower = 0;
					}
					break;
				case RIGHT:
					if (!input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
						keyInPower = 0;
					}
					break;
				case LEFT:
					if (!input.isKeyHeld(SDL_SCANCODE_LEFT)) {
						keyInPower = 0;
					}
					break;
			}
		}
		else {
			if (input.isKeyHeld(SDL_SCANCODE_UP) == true) {
				inPower = UP;
				keyInPower = 1;
				this->_player.moveUp();
			}
			else if (input.isKeyHeld(SDL_SCANCODE_DOWN) == true) {
				inPower = DOWN;
				keyInPower = 1;
				this->_player.moveDown();
			}
			else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
				inPower = RIGHT;
				keyInPower = 1;
				this->_player.moveRight();
			}
			else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
				inPower = LEFT;
				keyInPower = 1;
				this->_player.moveLeft();
			}
			else {
				this->_player.stopMoving();
			}
		}
		
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		
		
		this->_graphics = graphics;
		
		//this is a test message
		if(!this->_inventory_menu_active) {					//if it is not paused
			this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		}
		
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		
		if (ELAPSED_TIME_MS < MAX_FRAME_TIME) {
			//std::cout << "delay: " << MAX_FRAME_TIME - ELAPSED_TIME_MS << "\n";
			SDL_Delay(MAX_FRAME_TIME - ELAPSED_TIME_MS);
		}

		this->draw(graphics);

	}
	
}

void Game::draw(Graphics &graphics) {
	graphics.clear();
	
	this->_level.draw(graphics);
	this->_player.draw(graphics);
	
	this->_hud.draw(graphics);

	if(this->_inventory_menu_active) {
		this->_inventory.draw(graphics);
	}
	//std::cout << this->_inventory_menu_active << std::endl;
	
	graphics.flip();


}

void Game::update(float elapsedTime) {
	
	this->_player.update(elapsedTime);
	this->_level.update(elapsedTime);
	this->_hud.update(elapsedTime, this->_player);
	
	std::vector<Rectangle> others;
	if((others = this->_level.checkTileCollisions(this->_player.getBoundingBox())).size() > 0) {
		this->_player.handleTileCollisions(others);
	}
	
	std::vector<Door> otherDoors;
	if((otherDoors = this->_level.checkDoorCollisions(this->_player.getBoundingBox())).size()  > 0) {
		this->_player.handleDoorCollision(otherDoors, this->_level, this->_graphics); 
	}
	
}
