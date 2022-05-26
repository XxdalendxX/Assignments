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

	int CalculateTileState(int xPos, int yPos);
	void UpdateTile(int xPos, int yPos);
	void FlagTile(int xPos, int yPos);

protected:

	int m_tileSize = 32;

private:

	int m_windowWidth = m_tileSize * 32;
	int m_windowHeight = m_tileSize * 25;

	static const int m_cols = 32;
	static const int m_rows = 25;

	int m_tiles[m_cols][m_rows];
	int tileState[m_cols][m_rows]; //0 = hidden, 1 = revealed, 2 = flagged

};