#pragma once

#include "raylib.h"
#include <array>

class Minesweeper
{
public:

	Minesweeper();
	~Minesweeper();

	void Run();

private:

	void Load();
	void Unload();

	void Update(float deltaTime);
	void Draw();

	int CalculateTileState(int index, int* currentState);

protected:

	int m_tileSize = 32;

private:

	int m_windowWidth = m_tileSize * 32;
	int m_windowHeight = m_tileSize * 25;

	static const int m_cols = 25;
	static const int m_rows = 32;

	int m_tiles[m_cols * m_rows];

	int* m_grid = nullptr;
	int* m_gridBuffer = nullptr;
};