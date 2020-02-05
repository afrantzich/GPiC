
#include "Game.h"

const int thickness = 15;
int paddleLen = 120;

Game::Game()
{
	
}

bool Game::Initialize()
{
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);

	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow(
		"Game Programming in C++ (Chapter 1)", // Window Title
		100,	// Top left x-coordinate of window
		100,	// Top left y-coordinate of window
		1024,	// Width of window
		768,	// Height of window
		0		// Flags (0 for no flags set)
	);

	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(
		mWindow,	// Window to create renderer for
		-1,			// SDL chooses graphics driver
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	mPaddlePos.x = thickness * 1.5;
	mPaddlePos.y = 768 / 2;
	mBallPos.x = 1024 / 2;
	mBallPos.y = 768 / 2;
}

void Game::Shutdown()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
}

void Game::ProcessInput()
{
	SDL_Event event;
	// While there are still events in the queue
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}

		// Get state of keyboard
		const Uint8* state = SDL_GetKeyboardState(NULL);
		// If escape is pressed, also end loop
		if (state[SDL_SCANCODE_ESCAPE])
		{
			mIsRunning = false;
		}
	}
}

void Game::UpdateGame()
{

}

void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(
		mRenderer,
		0,			// R
		0,			// G
		0,			// B
		255			// A
	);
	// set back buffer to RenderDrawColor
	SDL_RenderClear(mRenderer);

	// ***********************************************
	// *************** draw game screen **************
	// ***********************************************

	//White
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

	// create wall
	SDL_Rect topWall{
		0,			// Top left x
		0,			// Top left y
		1024,		// Width
		thickness	// Height
	};
	SDL_Rect rightWall{
		1024 - thickness,	// Top left x
		0,					// Top left y
		thickness,			// Width
		768					// Height
	};
	SDL_Rect botWall{
		0,					// Top left x
		768 - thickness,	// Top left y
		1024,				// Width
		thickness			// Height
	};

	SDL_Rect paddle{
		static_cast<int>(mPaddlePos.x - thickness / 2),
		static_cast<int>(mPaddlePos.y - paddleLen / 2),
		thickness,
		paddleLen
	};

	SDL_Rect ball{
		static_cast<int>(mBallPos.x - thickness / 2),
		static_cast<int>(mBallPos.y - thickness / 2),
		thickness,
		thickness
	};

	// fill wall
	SDL_RenderFillRect(mRenderer, &topWall);
	SDL_RenderFillRect(mRenderer, &rightWall);
	SDL_RenderFillRect(mRenderer, &botWall);
	SDL_RenderFillRect(mRenderer, &paddle);
	SDL_RenderFillRect(mRenderer, &ball);
	
	// swap buffers
	SDL_RenderPresent(mRenderer);
}

void Game::RunLoop()
{
	mIsRunning = true;
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}