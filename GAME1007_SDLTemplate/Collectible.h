#pragma once
#ifndef _COLLECTIBLE_H_
#define _COLLECTIBLE_H_

//#include "Engine.h"
#include <SDL.h>

class Collectible
{
private:
	SDL_Rect m_dest,m_src;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	bool m_isCollected;
	int m_blendSpeed;
	Uint8 m_blend;
public:
	Collectible(SDL_Renderer*,SDL_Texture*,SDL_Rect,SDL_Rect);
	~Collectible();
	void Render();
	void Update();

	bool IsCollected() { return m_isCollected; }
	void setIsCollected(bool);
	SDL_Rect* getDest() { return &m_dest; }
};

#endif


