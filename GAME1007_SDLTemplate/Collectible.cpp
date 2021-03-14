#include "Collectible.h"


Collectible::Collectible(SDL_Renderer* r, SDL_Texture* t, SDL_Rect src, SDL_Rect dest) :m_renderer(r),
m_texture(t), m_dest(dest), m_src(src), m_isCollected(false),m_blend(245),m_blendSpeed(5)
{
	
}

Collectible::~Collectible()
{
}

void Collectible::Render()
{
	SDL_SetTextureAlphaMod(m_texture, m_blend);
	if(!IsCollected())
		SDL_RenderCopy(m_renderer, m_texture, &m_src, &m_dest);
}

void Collectible::Update()
{
	
	if (m_blend <= 10 || m_blend >= 245)
		m_blendSpeed = -m_blendSpeed;

		m_blend += m_blendSpeed;

	
	//m_dest.x += 5;
}

void Collectible::setIsCollected(bool state)
{
	m_isCollected = state;
}
