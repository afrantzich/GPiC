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
	void SetAnimFPS(float fps) { mAnimFPS = fps; }
	// get current frame
	float GetCurrFrame() const { return mCurrFrame; }

	bool GetLoop() const { return mLoop; }
	void SetLoop(bool loop) { mLoop = loop; }
	int GetStart() const { return mStart; }
	int GetStop() const { return mStop; }
	void SetStart(int start) { mStart = start; }
	void SetStop(int stop) { mStop = stop; }
	int GetDefaultFrame() const { return mDefaultFrame; }
private:
	// All textures in the animation
	std::vector<SDL_Texture*> mAnimTextures;
	// Current frame displayed
	float mCurrFrame;
	// Animation frame rate
	float mAnimFPS;
	// loop option
	bool mLoop;
	// Start and stop points
	int mStart;
	int mStop;
	int mDefaultFrame;
};