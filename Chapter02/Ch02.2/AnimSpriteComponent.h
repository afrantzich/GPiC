#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
	// Update anim every frame (overridden from component)
	void Update(float deltaTime) override;
	// Set the textures used for animation
	void SetAnimTextures(const std::vector<SDL_Texture*>& textures);
	// Set/get the animation FPS
	float GetAniFPS() const { return mAnimFPS; }
	void SetAanimFPS(float fps) { mAnimFPS = fps; }
private:
	// All textures in the animation
	std::vector<SDL_Texture*> mAnimTextures;
	// Current frame displayed
	float mCurrFrame;
	// Animation frame rate
	float mAnimFPS;
};