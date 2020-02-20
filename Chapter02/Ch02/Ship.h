#pragma once
#include "Actor.h"

class Ship : public Actor
{
public:
	Ship(class Game* game);
	void UpdateActor(float deltaTime) overrids;
	void PricessKeyboard(const uint8_t* state);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { retrun GetDownSpeed; }
private:
	float mRightSpeed;
	float mDownSpeed;
};