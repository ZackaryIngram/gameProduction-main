#include "PlatformPlayer.h"
#include <algorithm>

#include "Engine.h"

void PlatformPlayer::Init(SDL_Renderer* r)
{
	m_pRend = r;
	m_srcRect = { 0,0,198,261 };
	m_dstRect = { 462,550,35,50 };
	m_grounded = true;

	m_accelerationX = m_accelerationY = m_velX = m_velY = 0.0;
	m_maxVelX = 15.0;
	m_maxVelY = JUMPFORCE;
	m_gravity = GRAVITY;
	m_drag = 0.80;
}

SDL_Rect* PlatformPlayer::GetDstRect()
{
	return &m_dstRect;
}

SDL_Rect* PlatformPlayer::GetSrcRect()
{
	return &m_srcRect;
}

void PlatformPlayer::Update()
{
	// X axis
	m_velX += m_accelerationX;
	m_velX *= (m_grounded ? m_drag : 0.91);
	m_velX = std::min(std::max(m_velX, -m_maxVelX), m_maxVelX);
	m_dstRect.x += (int)m_velX;
	// Y axis
	m_velY += m_accelerationY + m_gravity;
	m_velY = std::min(std::max(m_velY, -m_maxVelY), (m_gravity));
	m_dstRect.y += (int)m_velY;
	// Reset acceleration.
	m_accelerationX = m_accelerationY = 0.0;

	// Player animation controller
	if(m_attack == false)
	{
		m_timer++;
		if (FPS / m_timer == 6)
		{
			m_timer = 0;
			m_srcRect.x += 198;
		}


		if (m_srcRect.x == 990)
			m_srcRect.x = 0;
	}
	else
	{
		m_timer++;
		
		if (FPS / m_timer == 6)
		{
			m_timer = 0;
			m_srcRect.x += 198;
		}


		if (m_srcRect.x == 792)
			m_srcRect.x = 0;
	}
	
}

void PlatformPlayer::Render(SDL_Texture* texture, PlatformPlayer player, SDL_RendererFlip flip)
{
	
	SDL_RenderCopyEx(m_pRend, texture, &player.m_srcRect, &player.m_dstRect, m_angle, m_pCenter, flip);

}

void PlatformPlayer::Stop()
{
	StopX();
	StopY();
}

void PlatformPlayer::StopX() {	m_velX = 0.0; }

void PlatformPlayer::StopY() {	m_velY = 0.0; }

void PlatformPlayer::SetAccelX(double a) { m_accelerationX = a; }

void PlatformPlayer::SetAccelY(double a) { m_accelerationY = a; }

void PlatformPlayer::SetRunning(bool r)
{
	m_running = r;
}

bool PlatformPlayer::isGrounded() { return m_grounded; }

bool PlatformPlayer::getRunning() { return m_running; }

void PlatformPlayer::SetGrounded(bool g) { m_grounded = g; }

double PlatformPlayer::GetVelX() { return m_velX; }

double PlatformPlayer::GetVelY() { return m_velY; }

void PlatformPlayer::SetX(float x) { m_dstRect.x = x; }

void PlatformPlayer::SetY(float y) { m_dstRect.y = y; }

void PlatformPlayer::setAttack(bool a)
{
	m_attack = a;
}

bool PlatformPlayer::getAttack()
{
	return m_attack;
}
