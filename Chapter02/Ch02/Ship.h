#pragma once
#include "Actor.h"
#include "Game.h"

class Ship : public Actor
{
public:
	Ship(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ProcessKeyboard(const uint8_t* state, Game* game);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }
	void SetReloadSpeed(float reload) { mReloadSpeed = reload; }
	float GetReloadSpeed() const { return mReloadSpeed; }
	void Reload() { mReloadTimer = mReloadSpeed; }
	float GetReloadTimer() const { return mReloadTimer; }
	void SetReloadTimer(float timer) { mReloadTimer = timer; }
private:
	float mRightSpeed;
	float mDownSpeed;
	float mReloadSpeed;
	float mReloadTimer;
};