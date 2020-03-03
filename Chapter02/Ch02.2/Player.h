#pragma once
#include "Actor.h"
#include "Game.h"
#include "AnimSpriteComponent.h"

class Player : public Actor
{
public:
	Player(class Game* game);
	void Stand(class Game* game);
	void Walk(class Game* game);
	void UpdateActor(float deltaTime) override;
	void ProcessKeyboard(const uint8_t* state, Game* game);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }
	void SetAnimSpriteComp(AnimSpriteComponent* comp) { animations = comp; }
private:
	AnimSpriteComponent* animations;
	float mRightSpeed;
	float mDownSpeed;
};