// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
# include "CircleComponent.h"

class Ship : public Actor
{
public:
	Ship(class Game* game);

	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;

	float GetDeathTimer() { return mDeathTimer; }
	void SetDeathTimer(float timer) { mDeathTimer = timer; }

	class CircleComponent* GetCircle() { return mCircle; }
private:
	CircleComponent* mCircle;
	float mLaserCooldown;
	float mDeathTimer;
};