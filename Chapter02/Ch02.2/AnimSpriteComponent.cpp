#include "AnimSpriteComponent.h"
#include "Math.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurrFrame(0.0f)
	, mAnimFPS(24.0f)
	, mLoop(1)
	, mStart(0)
	, mStop(0)
	, mDefaultFrame(0)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (mAnimTextures.size() > 0)
	{
		// Update the current frame based on frame rate
		// and delta time
		mCurrFrame += mAnimFPS * deltaTime;

		// Start new animations
		if (mCurrFrame < mStart)
		{
			mCurrFrame = mStart;
		}

		// Wrap current frame if needed
		if (mCurrFrame > GetStop())
		{
			if (GetLoop())
			{
				mCurrFrame = GetStart();
			}
			else
			{
				mCurrFrame = GetDefaultFrame();
				SetStart(mCurrFrame);
				SetStop(mCurrFrame);
			}
		}

		
		// Set the current texture
		SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
	}
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}

