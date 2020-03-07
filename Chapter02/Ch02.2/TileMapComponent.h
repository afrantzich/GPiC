#pragma once
#include "SpriteComponent.h"
#include "SDL.h"
#include <string>

class TileMapComponent : public SpriteComponent
{
public:
	TileMapComponent(class Actor* owner, int drawOrder = 100);

	void Draw(SDL_Renderer* renderer) override;
	void LoadTileSet(const std::string& fileName, SDL_Renderer* renderer);
	void LoadCSV(const std::string& fileName)

protected:
	SDL_Texture* mTiles;
	const float tileSize;
};