#include "Minesweeper.h"
#include "raylib.h"
#include <conio.h>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

Minesweeper::Minesweeper()
{

}

Minesweeper::~Minesweeper()
{

}

void Minesweeper::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Minesweeper");

	SetTargetFPS(240);


	Load();

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		float dt = GetFrameTime();
		Update(dt);
		Draw();
	}

	Unload();
	CloseWindow();
}

void Minesweeper::Load()
{
	m_grid = new int[m_rows * m_cols];
	m_gridBuffer = new int[m_rows * m_cols];

	for (int i = 0; i < m_cols * m_rows; i++)
	{
		m_tiles[i] = rand() % 800 < 150;
		m_gridBuffer[i] = m_tiles[i];
	}
}

void Minesweeper::Unload()
{
	delete[] m_grid;
	m_grid = nullptr;

	delete[] m_gridBuffer;
	m_gridBuffer = nullptr;
}

void Minesweeper::Update(float dt)
{
	memcpy(m_gridBuffer, m_grid, sizeof(int) * m_rows * m_cols);

	for (int i = 0; i < m_rows * m_cols; i++)
	{
		
	}

}

void Minesweeper::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	
	//DrawRectangle(32, 64, 32, 32, RAYWHITE);
	//DrawText("!", 46, 70, 24, BLACK);
	

	for (int i = 0; i < (m_cols * m_rows); i++)
	{
		float xPos = floor(i / m_cols) * m_tileSize;
		float yPos = (i % m_cols) * m_tileSize;
		int state = CalculateTileState(i, m_tiles); // pass in the tilevalue

		if (state == 0) //blank tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
		}
		else if (state == 1) //1 tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("1", xPos+14, yPos+6, 24, BLUE);
		}
		else if (state == 2) //2 tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("2", xPos + 14, yPos + 6, 24, GREEN);
		}
		else if (state == 3) //3 tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("3", xPos + 14, yPos + 6, 24, DARKGREEN);
		}
		else if (state == 4) //4 tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("4", xPos + 14, yPos + 6, 24, PURPLE);
		}
		else if (state == 5) //5 tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("5", xPos + 14, yPos + 6, 24, YELLOW);
		}
		else if (state == 6) //6 tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("6", xPos + 14, yPos + 6, 24, RED);
		}
		else if (state == 7) //7 tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("7", xPos + 14, yPos + 6, 24, WHITE);
		}
		else if (state == 8) //8 tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("8", xPos + 14, yPos + 6, 24, BEIGE);
		}
		else if (state == 9) //bomb tile
		{
			DrawRectangle(xPos, yPos, 32, 32, GRAY);
			DrawText("*", xPos + 14, yPos + 6, 24, BLACK);
		}
	}

	for (int y = 1; y < m_cols; y++)
	{
		DrawLine(0, y * 32, (32 * 32), y * 32, DARKGRAY);
	}

	for (int x = 1; x < m_rows; x++)
	{
		DrawLine(x * 32, 0, x * 32, (25 * 32), DARKGRAY);
	}


	EndDrawing();
}

int Minesweeper::CalculateTileState(int index, int* grid)
{

	// Calculate the row/col index
	int col = index % m_cols;
	int row = index / m_cols;


	bool isBomb = grid[index] != 0;

	int count = 0;

	if (grid[index] == 1)
	{
		return count = 9;
	}

	//top left
	if (col - 1 > 0 && row - 1 > 0)
	{
		if (grid[(row - 1) * m_cols + (col - 1)] == 1)
		{
			count++;
		}
	}
	//top
	if (row - 1 > 0)
	{
		if (grid[(row - 1) * m_cols + col] == 1)
		{
			count++;
		}
	}
	//top right
	if (col + 1 < m_cols && row - 1 > 0)
	{
		if (grid[(row - 1) * m_cols + (col + 1)] == 1)
		{
			count++;
		}
	}
	//left
	if (col - 1 > 0)
	{
		if (grid[(row)*m_cols + (col - 1)] == 1)
		{
			count++;
		}
	}
	//right
	if (col + 1 < m_cols)
	{
		if (grid[(row)*m_cols + (col + 1)] == 1)
		{
			count++;
		}
	}
	//bottom left
	if (col - 1 > 0 && row + 1 < m_rows)
	{
		if (grid[(row + 1) * m_cols + (col - 1)] == 1)
		{
			count++;
		}
	}
	//bottom
	if (row + 1 < m_rows)
	{
		if (grid[(row + 1) * m_cols + col] == 1)
		{
			count++;
		}
	}
	//bottom right
	if (col + 1 < m_cols && row + 1 < m_rows)
	{
		if (grid[(row + 1) * m_cols + (col + 1)] == 1)
		{
			count++;
		}
	}

	return count;
}
	