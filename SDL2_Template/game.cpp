#include "game.h"
#include <random>
#include <iostream>
#include "utils.h"

Game::Game(SDL_Renderer* renderer)
	: grid(renderer), renderer(renderer), blocks(GetAllBlocks(renderer)),
	currentBlock(GetRandomBlock()), nextBlock(GetRandomBlock()),
	gameOver(false), score(0)
{
	// Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
	}

	// Load music and sound effects
	music = LoadMusic("Sounds/music.mp3");
	if (music == nullptr)
	{
		std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
	}

	rotateSound = LoadSound("Sounds/rotate.wav");
	if (rotateSound == nullptr)
	{
		std::cerr << "Failed to load rotate sound! SDL_mixer Error: " << Mix_GetError() << std::endl;
	}

	clearSound = LoadSound("Sounds/clear.wav");
	if (clearSound == nullptr) // Corrected from rotateSound to clearSound
	{
		std::cerr << "Failed to load clear sound! SDL_mixer Error: " << Mix_GetError() << std::endl;
	}

	// Play music
	if (Mix_PlayMusic(music, -1) == -1)
	{
		std::cerr << "Failed to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
	}
}

Game::~Game()
{
	// Free the music and sound effects
	Mix_FreeMusic(music);
	Mix_FreeChunk(rotateSound);
	Mix_FreeChunk(clearSound);

	// Quit SDL_mixer
	Mix_CloseAudio();
}

Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks(renderer);
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks(SDL_Renderer* renderer)
{
	return { IBlock(renderer), JBlock(renderer), LBlock(renderer), OBlock(renderer), SBlock(renderer), TBlock(renderer), ZBlock(renderer) };
}

void Game::Draw()
{
	grid.Draw();
	currentBlock.Draw(11, 11);
	switch (nextBlock.id)
	{
	case 3:
		nextBlock.Draw(255, 290);
		break;
	case 4:
		nextBlock.Draw(255, 280);
		break;
	default:
		nextBlock.Draw(270, 270);
		break;
	}
}

void Game::HandleInput(SDL_Event& event)
{

	if (event.type == SDL_QUIT)
	{
		gameOver = true;
	}
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			MoveBlockLeft();
			break;
		case SDLK_RIGHT:
			MoveBlockRight();
			break;
		case SDLK_DOWN:
			MoveBlockDown();
			if (!gameOver)
				UpdateScore(0, 1);
			break;
		case SDLK_UP:
			RotateBlock();
			break;
		}
	}

}

void Game::MoveBlockLeft()
{
	if (!gameOver)
	{
		currentBlock.Move(0, -1);
		if (IsBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight()
{
	if (!gameOver)
	{
		currentBlock.Move(0, 1);
		if (IsBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown()
{
	if (!gameOver)
	{
		currentBlock.Move(1, 0);
		if (IsBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::IsBlockOutside()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellOutside(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

void Game::RotateBlock()
{
	if (!gameOver)
	{
		currentBlock.Rotate();
		if (IsBlockOutside() || BlockFits() == false)
		{
			currentBlock.UndoRotation();
		}
		else
		{
			Mix_PlayChannel(-1, rotateSound, 0);
		}
	}
}

void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (BlockFits() == false)
	{
		gameOver = true;
	}
	nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearFullRows();
	if (rowsCleared > 0)
	{
		Mix_PlayChannel(-1, clearSound, 0);
		UpdateScore(rowsCleared, 0);
	}
}

bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::Reset()
{
	grid.Initialize();
	blocks = GetAllBlocks(renderer);
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;
	}

	score += moveDownPoints;
}
