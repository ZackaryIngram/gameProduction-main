#pragma once
#ifndef _PLATFORMPLAYER_H_
#define _PLATFORMPLAYER_H_
#define GRAVITY 5
#define JUMPFORCE 40
#include "SDL.h"


class PlatformPlayer
{

private:
	bool m_grounded;//is the player in grounded or in the air
	double m_accelerationX,
		m_accelerationY,
		m_velX,
		m_maxVelX,
		m_velY,
		m_maxVelY,
		m_drag,
		m_gravity;
	SDL_Rect m_dstRect;
	SDL_Rect m_srcRect;
	SDL_Renderer* m_pRend;

	int m_timer = 0;
	double m_angle = 0.0;
	SDL_Point* m_pCenter = NULL;
	bool m_running = false;
	bool m_attack = false;

public:
	
	void Init(SDL_Renderer* r);
	SDL_Rect* GetDstRect();
	SDL_Rect* GetSrcRect();
	void Update();
	void Render(SDL_Texture* texture, PlatformPlayer player, SDL_RendererFlip flip);
	void Stop();
	void StopX();
	void StopY();
	void SetAccelX(double a);
	void SetAccelY(double a);
	void SetRunning(bool r);
	bool isGrounded();
	bool getRunning();
	void SetGrounded(bool g);
	double GetVelX();
	double GetVelY();
	void SetX(float x);
	void SetY(float y);
	void setAttack(bool a);
	bool getAttack();
};

#endif // !_PLATFORMPLAYER_H_
