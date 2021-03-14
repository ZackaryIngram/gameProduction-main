#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include"SDL.h"
#include <iostream>

#include "PlayerBullet.h"
#define GRAVITY 6.0
using namespace std;


class Enemy : public Sprite
{
private:
	SDL_Rect m_src; // Source rectangle
	SDL_Rect m_rect;

	double m_angle = 0.0, m_speed;
	SDL_Point* m_pCenter = NULL;
	bool m_attack = false;
	SDL_RendererFlip m_flip = SDL_FLIP_NONE;
	int m_leftX, m_leftY, m_rightX, m_rightY, m_timer = 0;


public:
	Enemy(int, int, int, int);
	~Enemy();
	SDL_Rect* GetRect();// Source rectangle
	void Update();
	void Render(SDL_Renderer* rend);
	void Render(SDL_Renderer* rend, SDL_Texture* texture, SDL_RendererFlip flip);
	bool GetAttack() { return m_attack; }
	void SetAttack(bool a) { m_attack = a; }
};




#endif