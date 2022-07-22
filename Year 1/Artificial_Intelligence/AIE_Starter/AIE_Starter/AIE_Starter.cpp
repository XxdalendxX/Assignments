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
#include "Pathfinding.h"
#include <string>

using namespace AIForGames;

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1080;
    int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Gustavo Fring, Jesse Pinkman and Walter White walk into a bar...");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------



    std::vector<std::string> asciiMap;
    asciiMap.push_back("100000000001");
    asciiMap.push_back("111111111111");
    asciiMap.push_back("000010010000");
    asciiMap.push_back("011110011110");
    asciiMap.push_back("010011110010");
    asciiMap.push_back("010010010010");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("000000000000");

    NodeMap map;
    map.Initialise(asciiMap, 90);

    Node* start = map.GetNode(1, 1);
    Node* end = map.GetNode(10, 1);
    std::vector<Node*> nodeMapPath = DijkstrasSearch(start, end);
    Color lineColour = { 255, 255, 255, 255 };

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
         if (IsMouseButtonPressed(0))
         {
            Vector2 mousePos = GetMousePosition();
            start = map.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
            nodeMapPath = DijkstrasSearch(start, end);
         }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        map.Draw();
        map.DrawPath(nodeMapPath, lineColour);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}