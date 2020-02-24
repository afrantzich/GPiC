#include "Ship.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "Munitions.h"

Ship::Ship(Game* game)
	:Actor(game)
	, mRightSpeed(0.0f)
	, mDownSpeed(0.0f)
	, mReloadSpeed(0.5f)
{
	// Create an animated sprite component
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png")
	};
	asc->SetAnimTextures(anims);
}

void Ship::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;

	SetReloadTimer( GetReloadTimer() - deltaTime);
	// Restrict position to left half of screen
	if (pos.x < 25.0f)
	{
		pos.x = 25.0f;
	}
	else if (pos.x > 500.0f)
	{
		pos.x = 500.0f;
	}
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f)
	{
		pos.y = 743.0f;
	}
	SetPosition(pos);
}

void Ship::ProcessKeyboard(const uint8_t* state, Game* game)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
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
	if (state[SDL_SCANCODE_K])
	{
		SetReloadSpeed(GetReloadSpeed() - 0.05f);
	}
	if (state[SDL_SCANCODE_L])
	{
		SetReloadSpeed(GetReloadSpeed() + 0.05f);
	}
	// shoot laser
	if (state[SDL_SCANCODE_SPACE])
	{
		if (GetReloadTimer() <= 0.0f)
		{
			Munitions* laser = new Munitions(game, GetPosition());
			Reload();
		}
		//std::vector<SDL_Texture*> anims = {
		//	game->GetTexture("Assets/Laser.png"),
		//};
		//laser->SetAnimTextures(anims);
	}
}
