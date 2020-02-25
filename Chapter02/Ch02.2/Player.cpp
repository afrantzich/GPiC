#include "Player.h"
#include "Game.h"
#include "AnimSpriteComponent.h"

Player::Player(Game* game)
	:Actor(game)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
{
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Character02.png")
	};
	asc->SetAnimTextures(anims);
}

void Player::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;

	SetPosition(pos);
}

void Player::ProcessKeyboard(const uint8_t* state, Game* game)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	// find out how to overload the draw function to change
	// movement animations
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
	}
}