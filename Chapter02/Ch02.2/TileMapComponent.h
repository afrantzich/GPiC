#pragma once
#include "SpriteComponent.h"

class TileMapComponent : public SpriteComponent()
{
public:
	TileMapComponent(class Actor* owner, int drawOrder = 100);
	~TileMapComponent();


protected:

}