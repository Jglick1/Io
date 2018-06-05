//
//  globals.h
//  Io
//
//  Created by Jonah Glick on 5/29/17.
//  Copyright © 2017 Jonah Glick. All rights reserved.
//

#ifndef globals_h
#define globals_h


namespace globals {

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	//const float SPRITE_SCALE = 2.0f;
	
	const int SPRITE_SCALE = 2;
	
}

namespace sides {
	enum Side {
		TOP,
		BOTTOM,
		LEFT,
		RIGHT,
		NONE
	};
	
	inline Side getOppositeSide(Side side) {
		return
			side == TOP ? BOTTOM :
			side == BOTTOM ? TOP :
			side == LEFT ? RIGHT :
			side == RIGHT ? LEFT :
			NONE;
	}
}


enum Direction {
	LEFT, RIGHT, UP, DOWN
};


struct Vector2 {
	int x, y;
	Vector2() : x(0), y(0) {}
	Vector2(int x, int y) : x(x), y(y) {}
	Vector2 zero() {
		return Vector2(0, 0);
	}
};




#endif /* globals_h */