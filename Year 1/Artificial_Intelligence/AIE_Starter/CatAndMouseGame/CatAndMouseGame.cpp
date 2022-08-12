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
#include "Pathfind.h"
#include "Cat.h"
#include "Mouse.h"
#include <string>

using namespace AIForGames;

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1900;
    int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "The first followed the path of the stars. The next, a path of gold and riches. And the third, the deepest pits of tartarus await for him.");

    SetTargetFPS(240);
    //--------------------------------------------------------------------------------------


    //map initialisation
    std::vector<std::string> asciiMap;
    asciiMap.push_back("000000000000000000000");
    asciiMap.push_back("010000000001110001110");
    asciiMap.push_back("011111011111011111010");
    asciiMap.push_back("010001010010110001000");
    asciiMap.push_back("000111010111101111010");
    asciiMap.push_back("001101110101001001110");
    asciiMap.push_back("011001000101001001000");
    asciiMap.push_back("010011011111011111110");
    asciiMap.push_back("010010000101001001010");
    asciiMap.push_back("011111011111001111010");
    asciiMap.push_back("000000000000000000000");

    NodeMap map;
    map.Initialise(asciiMap, 90);

    Node* start = map.GetNode(1, 1);
    Node* end = map.GetNode(11, 0);
    std::vector<Node*> nodeMapPath = AStarSearch(start, end);
    Color lineColour = { 255, 0, 255, 255 };

    Node* secondaryStartpos = map.GetNode(19, 9);

    //player initialisation
    PathAgent agent;
    agent.SetNode(start, secondaryStartpos);
    agent.SetSpeed(750);

    //cat initialisation
    Node* catStart = map.GetNode(19, 2);
    Cat cat(catStart);
    cat.SetSpeed(300);

    //food initialisation
    Food food;
    bool placedFood = false;
    bool eatenFood = false;
    food.Generate(map);
    placedFood = true;

    //mouse initialisation
    Node* mouseStart = map.GetNode(1, 3);
    ActionDecision trueAction([&map, &food](Mouse& mouse, float deltaTime)
        {
            mouse.CollectFood(map, food);
        });
    ActionDecision falseAction([&map](Mouse& mouse, float deltaTime)
        {
            mouse.Wander(map);
        });
    ABDecision foodDetection(&trueAction, &falseAction, [&food](Mouse& mouse)
        {
            bool foodPresent = food.placedNode != nullptr;
            return foodPresent;
        });
    Mouse mouse(mouseStart, secondaryStartpos, &foodDetection);
    mouse.SetSpeed(250);
    

    float time = (float)GetTime();
    float deltaTime;
    float foodDestroyed = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;

        // Update
        //----------------------------------------------------------------------------------
        
        //food placement and functionality
        glm::vec2 agentPosition = agent.GetPos();
        glm::vec2 mousePosition = mouse.GetPos();
        float timeSinceFoodDestroyed = time - foodDestroyed;
        if (placedFood == false && timeSinceFoodDestroyed >= 10)
        {
            do
            {
                food.placedNode = nullptr;
                food.Generate(map);
            } while (food.placedNode == map.GetNode(agentPosition) || food.placedNode == map.GetNode(mousePosition));
            placedFood = true;
            mouse.travelling = false;
            mouse.m_path.clear();
        }
        
        if (food.placedNode == map.GetNode(agentPosition) && eatenFood == false)
        {
            food.Destroy();
            placedFood = false;
            eatenFood = true;
            foodDestroyed = time;
            mouse.travelling = false;
            mouse.m_path.clear();
        }
        else if (food.placedNode == map.GetNode(mousePosition) && eatenFood == false)
        {
            food.Destroy();
            placedFood = false;
            eatenFood = true;
            foodDestroyed = time;
            mouse.travelling = false;
            mouse.m_path.clear();
        }
        else
        {
            eatenFood = false;
        }

        //player movement
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

        //cat capture
        if (map.GetNode(cat.GetPos()) == map.GetNode(mousePosition))
        {
            if (cat.GetNode() == mouseStart)
            {
                mouse.SetNode(secondaryStartpos);
                mouse.m_path.clear();
                mouse.travelling = false;
                cat.m_path.clear();
                cat.travelling = false;
                cat.chasingMouse = false;
                cat.chasingPlayer = false;
            }
            else
            {
                mouse.SetNode(mouseStart);
                mouse.m_path.clear();
                mouse.travelling = false;
                cat.m_path.clear();
                cat.travelling = false;
                cat.chasingMouse = false;
                cat.chasingPlayer = false;
            }
        }
        if (map.GetNode(cat.GetPos()) == map.GetNode(agentPosition))
        {
            if (cat.GetNode() == start)
            {
                agent.SetNode(secondaryStartpos);
                agent.m_path.clear();
                cat.m_path.clear();
                cat.travelling = false;
                cat.chasingPlayer = false;
                cat.chasingMouse = false;
            }
            else
            {
                agent.SetNode(start);
                agent.m_path.clear();
                cat.m_path.clear();
                cat.travelling = false;
                cat.chasingPlayer = false;
                cat.chasingMouse = false;
            }
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        map.Draw();
        map.DrawPath(agent.m_path, lineColour);

        if (food.placedNode != nullptr)
        {
            food.Draw();
        }

        agent.Update(deltaTime);
        agent.Draw();

        if (mouse.travelling == false)
        {
            mouse.MouseStateCheck(map, food, deltaTime);
        }

        mouse.UpdateMouse(deltaTime);
        mouse.Draw();
        mouse.Draw();
       
        cat.CatStateCheck(map, mouse, agent);
        cat.UpdateCat(deltaTime);
        cat.Draw();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}