#pragma once
#include "SpriteComponent.h"
#include "SDL.h"
#include <string>
#include <vector>

class TileMapComponent : public SpriteComponent
{
public:
	TileMapComponent(class Actor* owner, int drawOrder = 100, int size = 32);

	void Draw(SDL_Renderer* renderer) override;
	void LoadTileSet(const std::string& fileName, SDL_Renderer* renderer, int wid, int ht);
	void LoadCSV(const std::string& fileName);
	int GetPNGWidth()const { return pngWidth; }
	int GetPNGHeight()const { return pngHeight; }
	void SetPNGWidth(int wid){ pngWidth = wid; }
	void SetPNGHeight(int height) { pngHeight = height; }
	float GetTileSize() const { return tileSize; }

protected:
	SDL_Texture* mTiles;
	std::vector<int> mMap;
	float tileSize;
	int pngWidth;
	int pngHeight;
};