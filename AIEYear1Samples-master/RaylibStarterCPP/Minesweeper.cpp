#include "Minesweeper.h"
#include "raylib.h"
#include <conio.h>
#include <string>

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
	for (int j = 0; j < m_rows; j++)
	{
		for (int i = 0; i < m_cols; i++)
		{
			m_tiles[i][j] = 0;
			tileState[i][j] = 0;
		}
	}
}

void Minesweeper::Unload()
{
	
}

void Minesweeper::Update(float dt)
{
	char userInput;

	while (firstClick == false)
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			Vector2 mousePos = GetMousePosition();

			int xPos = floor(mousePos.x / 32);
			int yPos = floor(mousePos.y / 32);
			if (yPos < 25)
			{
				FirstClick(xPos, yPos);
				firstClick = true;
			}
		}
		Draw();
	}
	
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		int xPos = floor(mousePos.x / 32);
		int yPos = floor(mousePos.y / 32);
		if (yPos < 25)
		{
			UpdateTile(xPos, yPos);
		}
	}

	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		int xPos = floor(mousePos.x / 32);
		int yPos = floor(mousePos.y / 32);
		if (yPos < 26)
		{
			FlagTile(xPos, yPos);
		}
	}

	winCondition = CheckWinState();
}

void Minesweeper::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	
	
	for (int j = 0; j < m_rows; j++)
	{
		for (int i = 0; i < m_cols; i++)
		{
			if (tileState[i][j] == 1)
			{
				int state = CalculateTileState(i, j); // pass in the tilevalue

				if (state == 0) //blank tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);

				}
				else if (state == 1) //1 tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);
					DrawText("1", i * 32 + 14, j * 32 + 6, 24, BLUE);
				}
				else if (state == 2) //2 tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);
					DrawText("2", i * 32 + 14, j * 32 + 6, 24, GREEN);
				}
				else if (state == 3) //3 tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);
					DrawText("3", i * 32 + 14, j * 32 + 6, 24, DARKGREEN);
				}
				else if (state == 4) //4 tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);
					DrawText("4", i * 32 + 14, j * 32 + 6, 24, PURPLE);
				}
				else if (state == 5) //5 tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);
					DrawText("5", i * 32 + 14, j * 32 + 6, 24, YELLOW);
				}
				else if (state == 6) //6 tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);
					DrawText("6", i * 32 + 14, j * 32 + 6, 24, RED);
				}
				else if (state == 7) //7 tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);
					DrawText("7", i * 32 + 14, j * 32 + 6, 24, WHITE);
				}
				else if (state == 8) //8 tile
				{
					DrawRectangle(i * 32 * 32, j * 32, 32, 32, GRAY);
					DrawText("8", i * 32 + 14, j * 32 + 6, 24, BEIGE);
				}
				else if (state == 9) //bomb tile
				{
					DrawRectangle(i * 32, j * 32, 32, 32, GRAY);
					DrawText("*", i * 32 + 14, j * 32 + 6, 24, BLACK);
					loseCondition = true;
				}
			}

			if (tileState[i][j] == 2)
			{
				DrawRectangle(i * 32, j * 32, 32, 32, RAYWHITE);
				DrawText("!", i * 32 + 14, j * 32 + 6, 24, BLACK);
			}

			if (tileState[i][j] == 3)
			{
				DrawRectangle(i * 32, j * 32, 32, 32, RAYWHITE);
				DrawText("X", i * 32 + 9, j * 32 + 6, 24, RED);
			}

			if (tileState[i][j] == 4)
			{
				DrawRectangle(i * 32, j * 32, 32, 32, DARKGREEN);
			}
		}
	}

	for (int y = 1; y < m_rows + 1; y++)
	{
		DrawLine(0, y * 32, (32 * 32), y * 32, DARKGRAY);
	}

	for (int x = 1; x < m_cols; x++)
	{
		DrawLine(x * 32, 0, x * 32, (25 * 32), DARKGRAY);
	}

	if (firstClick == true)
	{
		DrawText("Total Bombs: ", 14, 32 * 26, 24, BLACK);
		DrawText(std::to_string(bombTotal).c_str(), 14 + (32 * 5), 32 * 26, 24, BLACK);

		DrawText("Flags Left: ", (32 * 26), 32 * 26, 24, BLACK);
		DrawText(std::to_string(flagsLeft).c_str(), 14 + (32 * 30), 32 * 26, 24, BLACK);
	}

	if (loseCondition == true)
	{
		DrawText("You Lost", (32 * 15), (32 * 25), 24, BLACK);
		DrawText("Press Escape to Close The Application", (32 * 9), (32 * 26), 24, BLACK);

		for (int j = 0; j < m_rows; j++)
		{
			for (int i = 0; i < m_cols; i++)
			{
				if (tileState[i][j] == 0)
				{
					tileState[i][j] = 1;
				}
				if (tileState[i][j] == 2)
				{
					if (CalculateTileState(i, j) != 9)
					{
						tileState[i][j] = 3;
					}
				}
			}
		}
	}

	if (winCondition == true)
	{
		DrawText("You Win!", (32 * 15), (32 * 25), 24, BLACK);
		DrawText("Press Escape to Close The Application", (32 * 9), (32 * 26), 24, BLACK);

		for (int j = 0; j < m_rows; j++)
		{
			for (int i = 0; i < m_cols; i++)
			{
				if (tileState[i][j] == 2 || tileState[i][j] == 0)
				{
					if (CalculateTileState(i, j) == 9)
					{
						tileState[i][j] = 4;
					}
				}
			}
		}
	}
	
	EndDrawing();
}

int Minesweeper::CalculateTileState(int xPos, int yPos)
{

	// Calculate the row/col index
	int col = xPos;
	int row = yPos;
	
	

	bool isBomb = m_tiles[xPos][yPos] != 0;

	int count = 0;

	if (m_tiles[xPos][yPos] == 1)
	{
		return count = 9;
	}

	//top left
	if (col - 1 >= 0 && row - 1 >= 0)
	{
		if (m_tiles[col - 1][row - 1] == 1)
		{
			count++;
		}
	}
	//top
	if (row - 1 >= 0)
	{
		if (m_tiles[col][row - 1] == 1)
		{
			count++;
		}
	}
	//top right
	if (col + 1 < m_cols && row - 1 >= 0)
	{
		if (m_tiles[col + 1][row - 1] == 1)
		{
			count++;
		}
	}
	//left
	if (col - 1 >= 0)
	{
		if (m_tiles[col - 1][row] == 1)
		{
			count++;
		}
	}
	//right
	if (col + 1 < m_cols)
	{
		if (m_tiles[col + 1][row] == 1)
		{
			count++;
		}
	}
	//bottom left
	if (col - 1 >= 0 && row + 1 < m_rows)
	{
		if (m_tiles[col - 1][row + 1] == 1)
		{
			count++;
		}
	}
	//bottom
	if (row + 1 < m_rows)
	{
		if (m_tiles[col][row + 1] == 1)
		{
			count++;
		}
	}
	//bottom right
	if (col + 1 < m_cols && row + 1 < m_rows)
	{
		if (m_tiles[col + 1][row + 1] == 1)
		{
			count++;
		}
	}

	return count;
}
	
void Minesweeper::UpdateTile(int xPos, int yPos)
{
	int i = xPos;
	int j = yPos;
	if (tileState[i][j] == 0)
	{
		tileState[i][j] = 1;
	}
}

void Minesweeper::FlagTile(int xPos, int yPos)
{
	int i = xPos;
	int j = yPos;
	if (tileState[i][j] == 0 && flagsLeft > 0)
	{
		tileState[i][j] = 2;
		flagsLeft--;
	}
	else if (tileState[i][j] == 2)
	{
		tileState[i][j] = 0;
		flagsLeft++;
	}
}

bool Minesweeper::CheckWinState()
{
	if (loseCondition == true)
	{
		return false;
	}
	for (int j = 0; j < m_rows; j++)
	{
		for (int i = 0; i < m_cols; i++)
		{
			if (tileState[i][j] == 0 || tileState[i][j] == 2)
			{
				if (CalculateTileState(i, j) != 9)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void Minesweeper::FirstClick(int xPos, int yPos)
{
	for (int j = 0; j < m_rows; j++)
	{
		for (int i = 0; i < m_cols; i++)
		{
			m_tiles[i][j] = rand() % 800 < 150;

			if (i == xPos && j == yPos)
			{
				tileState[i][j] = 1;
			}

			if (m_tiles[i][j] == 1)
			{
				bombTotal++;
			}
		}
	}
	flagsLeft = bombTotal;
}
