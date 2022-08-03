/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Pathfind.h"
#include "Cat.h"
#include "Mouse.h"
#include <string>

using namespace AIForGames;

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1080;
    int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "The first followed the path of the stars. The next, a path of gold and riches. And the third, the deepest pits of tartarus await for him.");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------



    std::vector<std::string> asciiMap;
    asciiMap.push_back("100000000000");
    asciiMap.push_back("111110111110");
    asciiMap.push_back("000010100100");
    asciiMap.push_back("011110101110");
    asciiMap.push_back("010011101010");
    asciiMap.push_back("010010001010");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("000000000000");

    NodeMap map;
    map.Initialise(asciiMap, 90);

    Node* start = map.GetNode(0, 0);
    Node* end = map.GetNode(11, 0);
    std::vector<Node*> nodeMapPath = AStarSearch(start, end);
    Color lineColour = { 255, 0, 255, 255 };

    PathAgent agent;
    agent.SetNode(start);
    agent.SetSpeed(750);

    float time = (float)GetTime();
    float deltaTime;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;
        
        // Update
        //----------------------------------------------------------------------------------
         if (IsKeyPressed(KEY_LEFT))
         {
                 Node* node = agent.GetNode();
                 int x = (int)floor(node->position.x / (float)90) - 1;
                 int y = (int)floor(node->position.y / (float)90);
                 Node* end = map.GetNode(x, y);
                 agent.GoToNode(end);
         }
         if (IsKeyPressed(KEY_UP))
         {
                 Node* node = agent.GetNode();
                 int x = (int)floor(node->position.x / (float)90);
                 int y = (int)floor(node->position.y / (float)90) - 1;
                 Node* end = map.GetNode(x, y);
                 agent.GoToNode(end);
         }
         if (IsKeyPressed(KEY_RIGHT))
         {
                 Node* node = agent.GetNode();
                 int x = (int)floor(node->position.x / (float)90) + 1;
                 int y = (int)floor(node->position.y / (float)90);
                 Node* end = map.GetNode(x, y);
                 agent.GoToNode(end);
         }
         if (IsKeyPressed(KEY_DOWN))
         {
                 Node* node = agent.GetNode();
                 int x = (int)floor(node->position.x / (float)90);
                 int y = (int)floor(node->position.y / (float)90) + 1;
                 Node* end = map.GetNode(x, y);
                 agent.GoToNode(end);
         }
        //----------------------------------------------------------------------------------
        /*
        Vector2 mousePos = GetMousePosition();
        end = map.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
        agent.GoToNode(end);
        */

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        map.Draw();
        map.DrawPath(agent.m_path, lineColour);

        agent.Update(deltaTime);
        agent.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}