//
//  Graphics.hpp
//  Io
//
//  Created by Jonah Glick on 5/14/17.
//  Copyright © 2017 Jonah Glick. All rights reserved.
//

#ifndef Graphics_hpp
#define Graphics_hpp

#include <map>
#include <string>
#include <SDL2/SDL.h>

struct SDL_Window;
struct SDL_Renderer;


class Graphics {
	
public:
	Graphics();
	~Graphics();
	SDL_Surface* loadImage(const std::string &filePath);
	
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	
	void flip();
	
	void clear();
	
	SDL_Renderer* getRenderer() const;
	
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	
	std::map<std::string, SDL_Surface*> _spriteSheets;
	
	
};

#endif /* Graphics_hpp */

