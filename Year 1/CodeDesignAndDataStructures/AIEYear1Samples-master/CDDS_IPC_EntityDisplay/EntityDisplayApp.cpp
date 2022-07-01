#include "EntityDisplayApp.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) : m_screenWidth(screenWidth), m_screenHeight(screenHeight) {
	h = OpenFileMapping(FILE_MAP_READ, FALSE, L"SharedMemory");
}

EntityDisplayApp::~EntityDisplayApp() {
	
}

bool EntityDisplayApp::Startup() {

	InitWindow(m_screenWidth, m_screenHeight, "EntityDisplayApp");
	SetTargetFPS(60);

	int* total = (int*)MapViewOfFile(h, FILE_MAP_READ, 0, 0, sizeof(int));
	m_entities.resize(*total);
	UnmapViewOfFile(total);

	total = (int*)MapViewOfFile(h, FILE_MAP_READ, 0, 0, m_entities.size() * sizeof(Entity) + sizeof(int));
	Entity* entities = (Entity*)&total[1];
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i] = entities[i];
	}
	UnmapViewOfFile(total);
	return true;
}

void EntityDisplayApp::Shutdown() {

	CloseWindow();        // Close window and OpenGL context
	CloseHandle(h);
}

void EntityDisplayApp::Update(float deltaTime) {
	int* total = (int*)MapViewOfFile(h, FILE_MAP_READ, 0, 0, m_entities.size() * sizeof(Entity) + sizeof(int));
	Entity* entities = (Entity*)&total[1];
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i] = entities[i];
	}
	UnmapViewOfFile(total);
}

void EntityDisplayApp::Draw() {
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	for (auto& entity : m_entities) {
		DrawRectanglePro(
			Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
			Vector2{ entity.size / 2, entity.size / 2 }, // origin
			entity.rotation,
			Color{ entity.r, entity.g, entity.b, 255 });
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}