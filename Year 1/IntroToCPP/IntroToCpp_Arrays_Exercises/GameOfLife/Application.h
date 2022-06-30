#pragma once

#include <array>

class Application
{
public:
	Application();
	~Application();

	void Run();

	void Load();
	void Unload();

	void Update(float dt);
	void Draw();

	int CalculateTileState(int index, int* currentState);

protected:
private:

	int m_windowWidth = 4000;
	int m_windowHeight = 1010;
	
	int m_cols = 400;
	int m_rows = 101;

	int* m_grid = nullptr;
	int* m_gridBuffer = nullptr;

};
