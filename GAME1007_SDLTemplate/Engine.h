#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "SDL.h"
#include <iostream>
#include <string>
#include <SDL_mixer.h>
#include <vector>


#include "Collectible.h"
#include "PlatformPlayer.h"
#include "PlayerBullet.h"
#include "Enemy.h"
#define FPS 60
#define WIDTH 1024
#define HEIGHT 768
#define LEVEL_WIDTH 1500
#define LEVEL_HEIGHT 768


using namespace std;

class Engine
{
private: // private properties.
	bool m_running = false, pPressed = false, enterPressed = false;
	Uint32 m_start, m_end, m_delta, m_fps, score = 0, gameState = 0;
	// gameState 0 = title state, 1 = gameplay state, 2 = game paused state, 3 = win state, 4 = game over state
	string scoreString;
	const Uint8* m_keystates;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;		// FIRTS
	SDL_Rect m_Platforms[4] = {



		// third
		 {0,300,140,20}, // TOP LEFT GROUND


		//four
		 {200,170,250,20},
		 //FIFT


		 {0,720,300,50},// Ground left

			{960, 720, 70, 50}, // top down right








	}; //Position X and y, width and height
	SDL_Rect m_Obstacles[20]
	{
		//First
	 {0,570,170,20},////first jump ground + enemies
	{0,470,50	,100},// first jump ground WALL
	{50,520,60	,70}, //first jump ground OBSTACLE - REMEMBER CHANGE TEXTURES OF OBSTACLES
	//SECOND
	{210,440,120,20},// 2 jump ground
	{330,440,100,20},// 2 jump ground
	{430,240,20,220},// 2 jump WALL
	{230,325,30,30},// 2 jump OBSTACLE
	{310,365,30,30},
	{400,410,30,30},// 2 jump OBSTACLE

	//third
	{120,210,20,20}, // TOP LEFT GROUND JUMP OBSTACLE

	//FIFT
	{640,340,70,20},
	{750,240,20,20},
	{850,190,20,20},


	//GROUND
	{400,650,100,20},//initial structure

	{200,670,50,50},// obstacle Ground left
	{600, 720, 200, 50}, // Ground right
	{600, 680, 100, 50},//Ground right second level
	{600, 630, 50, 50},// Ground right
	{600, 530, 50, 50},

//GOAL
						{940,100,120,20},// goal
	};
	//size of the ground texture for rendering
	SDL_Rect textureSrc = { 0, 0, 225, 225 }; //NOT CURRENTLY USING THIS VARIABLE

	Mix_Music* m_pMusic;
	Mix_Chunk* m_pBullet, *m_pCheer, *m_pGameOver, *m_pJump, *m_pEnemy, *m_pWin;
	vector<Mix_Chunk*> m_vSounds;
	//SDL_Rect m_Camera = { 100, 0, WIDTH, HEIGHT };
	PlatformPlayer m_player;
	vector<Bullet*> m_playerbullet;
	vector<LeftBullet*> m_playerleftbullet;
	SDL_Texture* m_playerIdleTexture, * m_playerRunTexture, * m_playerAttackTexture, * m_groundTexture, * m_obstacletexture;
	SDL_Texture* m_yellowEnemyWalkTexture, * m_redEnemyWalkTexture, * m_yellowEenemyAttackTexture;
	SDL_Texture* heartTexture, * m_pBGTexture, * m_titleScreen, *m_gameOverScreen, *m_winScreen,* m_pCupTexture, * m_pgoal;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_RendererFlip flipEnemy = SDL_FLIP_NONE;
	Sprite m_yellowEnemy, m_bg1;
	vector<Enemy*> m_yellowEnemyCreation;
	int m_EnemyTimer;

	Collectible* m_pCollectible, *m_pGoal;

	// Textures
	SDL_Texture* m_pTexture;


private: // private method prototypes.
	int Init(const char* title, int xPos, int yPos, int width, int height, int flags);
	void Clean();
	void Wake();
	void HandleEvents();
	bool KeyDown(const SDL_Scancode c);
	void CheckCollision();
	void Update();
	void Render();
	void Sleep();

public: // public method prototypes.
	int Run();
};

#endif

// Reminder: you can ONLY have declarations in headers, not logical code
