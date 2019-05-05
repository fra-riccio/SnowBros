/*
 * Actor.h
 *
 *  Created on: 17 mar 2019
 *      Author: francesco
 */

#ifndef ACTOR_H_
#define ACTOR_H_
#include <allegro5/allegro.h>
#include "Entity.h"

const int screenWidth = 800;
const int screenHeight = 600;

class Actor : public Entity {
protected:
	bool jumping = false;
	bool falling = false;
	float speed;
	float max_height;
	float f_speed; //falling speed
	float j_speed; //jumping speed
	ALLEGRO_BITMAP* bitmap;

public:
	Actor(float x, float y, Dimensions d, float s, float h, float f_s, float j_s,
			ALLEGRO_BITMAP* bit, Action* a) :
			Entity(x, y, d, a), speed(s), max_height(h), f_speed(f_s), j_speed(
					j_s), bitmap(bit) {
	}
	virtual ~Actor() { al_destroy_bitmap(bitmap); }
	void onRedraw() override { al_draw_bitmap(bitmap, pos_x, pos_y, 0); }

	Action* getAction() const {
		return action;
	}

	void setAction(Action*& action) {
		this->action = action;
	}

	/*const ALLEGRO_BITMAP*& getBitmap() const {
		return bitmap;
	}

	void setBitmap(const ALLEGRO_BITMAP*& bitmap) {
		this->bitmap = bitmap;
	}*/

	float get_f_speed() const {
		return f_speed;
	}

	void set_f_speed(float speed) {
		f_speed = speed;
	}

	bool isFalling() const {
		return falling;
	}

	void setFalling(bool falling = false) {
		this->falling = falling;
	}

	float get_j_speed() const {
		return j_speed;
	}

	void set_j_speed(float speed) {
		j_speed = speed;
	}

	bool isJumping() const {
		return jumping;
	}

	void setJumping(bool jumping = false) {
		this->jumping = jumping;
	}

	float getMaxHeight() const {
		return max_height;
	}

	void setMaxHeight(float maxHeight) {
		max_height = maxHeight;
	}

	float getSpeed() const {
		return speed;
	}

	void setSpeed(float speed) {
		this->speed = speed;
	}
};

#endif /* ACTOR_H_ */
