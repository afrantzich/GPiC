#pragma once
#include "Actor.h"

class Munitions : public Actor
{
public:
	Munitions(class Game* game, const Vector2 mPosition);
	void UpdateActor(float deltaTime) override;
	float GetShotSpeed() const { return mShotSpeed; }
	void SetShotSpeed(float speed) { mShotSpeed = speed; }
private:
	float mShotSpeed;
};