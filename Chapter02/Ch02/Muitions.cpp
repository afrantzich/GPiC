#include "Munitions.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Munitions::Munitions(Game* game, const Vector2 mPosition)
	:Actor(game)
	, mShotSpeed(300.0f)
{
	SetPosition(mPosition);
	// Create an animated sprite component
	AnimSpriteComponent* shot = new AnimSpriteComponent(this, 50);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Laser.png")
	};
	shot->SetAnimTextures(anims);
}

void Munitions::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mShotSpeed * deltaTime;
	// Restrict position to left half of screen
	if (pos.x > 1050.0f)
	{
		SetState(EDead);
	}
	SetPosition(pos);
}