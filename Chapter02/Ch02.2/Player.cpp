#include "Player.h"
#include "Game.h"
#include "AnimSpriteComponent.h"

Player::Player(Game* game)
	:Actor(game)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
{
	AnimSpriteComponent* playerAnimations = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Character02.png")
		,game->GetTexture("Assets/Character03.png")
		,game->GetTexture("Assets/Character04.png")
		,game->GetTexture("Assets/Character05.png")
		,game->GetTexture("Assets/Character06.png")
		,game->GetTexture("Assets/Character07.png")
		,game->GetTexture("Assets/Character08.png")
		,game->GetTexture("Assets/Character09.png")
		,game->GetTexture("Assets/Character10.png")
		,game->GetTexture("Assets/Character11.png")
		,game->GetTexture("Assets/Character12.png")
		,game->GetTexture("Assets/Character13.png")
		,game->GetTexture("Assets/Character14.png")
		,game->GetTexture("Assets/Character15.png")
		,game->GetTexture("Assets/Character16.png")
		,game->GetTexture("Assets/Character17.png")
		,game->GetTexture("Assets/Character18.png")
	};
	playerAnimations->SetAnimTextures(anims);
	playerAnimations->SetStart(0);
	playerAnimations->SetStop(0);
	playerAnimations->SetLoop(1);
	SetAnimSpriteComp(playerAnimations);
}


void Player::Stand(Game* game)
{
	animations->SetStart(0);
	animations->SetStop(0);
	animations->SetLoop(1);
}

void Player::Walk(Game* game)
{
	animations->SetStart(0);
	animations->SetStop(5);
	animations->SetLoop(1);
}

void Player::Jump(Game* game)
{
	animations->SetStart(6);
	animations->SetStop(14);
	animations->SetLoop(0);
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
	// modify AnimSpriteComponent to allow non looping option
	if (state[SDL_SCANCODE_SPACE])
	{
		Jump(game);
		if (state[SDL_SCANCODE_D])
		{
			mRightSpeed += 250.0f;
		}
		if (state[SDL_SCANCODE_A])
		{
			mRightSpeed -= 250.0f;
		}
	}
	if (state[SDL_SCANCODE_D] && animations->GetStart() < 6)
	{
		mRightSpeed += 250.0f;
		Walk(game);
	}
	if (state[SDL_SCANCODE_A] && animations->GetStart() < 6)
	{
		mRightSpeed -= 250.0f;
		Walk(game);
	}
	if (!(state[SDL_SCANCODE_D] || state[SDL_SCANCODE_A]) && animations->GetStart() < 6)
	{
		Stand(game);
	}

	// up/down
	//if (state[SDL_SCANCODE_S])
	//{
	//	mDownSpeed += 300.0f;
	//}
	//if (state[SDL_SCANCODE_W])
	//{
	//	mDownSpeed -= 300.0f;
	//}
}