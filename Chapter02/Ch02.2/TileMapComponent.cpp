#include <algorithm>
#include "TileMapComponent.h"
#include "Actor.h"
#include "SDL_image.h"


TileMapComponent::TileMapComponent(class Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, tileSize(32)
	, mTiles(nullptr)
{
	

}

void TileMapComponent::Draw(SDL_Renderer* renderer)
{
	if (mTiles)
	{
		SDL_Rect r;
		// Scale the width/height by owner's scale
		r.w = static_cast<int>(tileSize * mOwner->GetScale());
		r.h = static_cast<int>(tileSize * mOwner->GetScale());
		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
		r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2);

		// Draw (have to convert angle from radians to degrees, and clockwise to counter)
		SDL_RenderCopyEx(renderer,
			mTiles,
			nullptr,
			&r,
			-Math::ToDegrees(mOwner->GetRotation()),
			nullptr,
			SDL_FLIP_NONE);
	}
}

void TileMapComponent::LoadTileSet(const std::string& fileName, SDL_Renderer* renderer)
{
	SDL_Texture* tex = nullptr;

	// Load from file
	SDL_Surface* surf = IMG_Load(fileName.c_str());
	if (!surf)
	{
		SDL_Log("Failed to load texture file %s", fileName.c_str());
	}

	// Create texture from surface
	mTiles = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	if (!mTiles)
	{
		SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
	}
}

void TileMapComponent::LoadCSV(const std::string& fileName)
{
	std::vector<int> values;

	//Load CSV
	// http://forums.codeguru.com/showthread.php?396459-Reading-CSV-file-into-an-array
	// while (getline(ss, int, ',')) and keep the 1D array I think
}