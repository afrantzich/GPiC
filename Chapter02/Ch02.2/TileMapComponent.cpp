#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include "TileMapComponent.h"
#include "Actor.h"
#include "SDL_image.h"


TileMapComponent::TileMapComponent(class Actor* owner, int drawOrder, int size)
	:SpriteComponent(owner, drawOrder)
	, mTiles(nullptr)
	, pngHeight(0)
	, pngWidth(0)
{
	tileSize = size;
}

void TileMapComponent::Draw(SDL_Renderer* renderer)
{
	int col = 0;
	int row = 0;
	const int tilesInRow = 1024 / tileSize;
	int target;


	while (col * row < mMap.size())
	{
		col = 0;
		while (col < 1024 / tileSize)
		{
			target = mMap[col * row];
			if (target > -1)
			{
				SDL_Rect src;
				// Original Tile Set rect
				src.w = tileSize;
				src.h = tileSize;
				// position will start at 0, 0
				src.x = mMap[col * row] ;
				src.y = 0;
				SDL_Rect r;
				// Scale the width/height by owner's scale
				r.w = static_cast<int>(tileSize * mOwner->GetScale());
				r.h = static_cast<int>(tileSize * mOwner->GetScale());
				// position will start at 0, 0
				r.x = static_cast<int>((row * tilesInRow + col) % tilesInRow * tileSize);
				r.y = static_cast<int>((row * tilesInRow + col) / tilesInRow * tileSize);

				// Draw (have to convert angle from radians to degrees, and clockwise to counter)
				SDL_RenderCopyEx(renderer,
					mTiles,
					&src,
					&r,
					-Math::ToDegrees(mOwner->GetRotation()),
					nullptr,
					SDL_FLIP_NONE);
				}
			col++;
		}
		row++;
	}
}

void TileMapComponent::LoadTileSet(const std::string& fileName, SDL_Renderer* renderer, int wid, int ht)
{
	pngWidth = wid;
	pngHeight = ht;

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
	//Load CSV
	std::ifstream in(fileName);
	std::string line, num;

	while (std::getline(in, line))
	{
		std::stringstream lineStream(line);
		while (std::getline(lineStream, num, ','))
		{
			//std::cout << num << '\n';
			mMap.push_back(std::stoi(num));
		}
	}
}