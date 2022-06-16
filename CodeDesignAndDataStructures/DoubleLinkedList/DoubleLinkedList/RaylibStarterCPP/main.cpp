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
#include <conio.h>
#include <string>

#include "Node.h"
int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1900;
    int screenHeight = 950;

    InitWindow(screenWidth, screenHeight, "Have you ever looked at someone and wondered... \"What is going on inside their head?\"");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    int valueBoxValue = 0;
    bool valueBoxEditMode = false;
    int positionBoxValue = 0;
    bool positionBoxEditMode = false;

    Node m_node;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);

        DrawText("Value", 25, 20, 24, BLACK);
        if (GuiValueBox(Rectangle{ 25, 40, 125, 30 }, NULL, &valueBoxValue, 0, 9999, valueBoxEditMode)) valueBoxEditMode = !valueBoxEditMode;
        DrawText("Position", 25, 80, 24, BLACK);
        if (GuiValueBox(Rectangle{ 25, 100, 125, 30 }, NULL, &positionBoxValue, 0, 9999, positionBoxEditMode)) positionBoxEditMode = !positionBoxEditMode;

        if (GuiButton(Rectangle{ 160, 25, 125, 30 }, GuiIconText(RICON_OK_TICK, "Insert at head")))
        {
            m_node.InsertHeadNode(valueBoxValue);
        }

        if (GuiButton(Rectangle{ 160, 60, 125, 30 }, GuiIconText(RICON_OK_TICK, "Insert at tail")))
        {
            m_node.InsertTailNode(valueBoxValue);
        }

        if (GuiButton(Rectangle{ 160, 95, 125, 30 }, GuiIconText(RICON_OK_TICK, "Insert at position")))
        {
            m_node.InsertArbitraryNode(positionBoxValue, valueBoxValue);
        }

        if (GuiButton(Rectangle{ 295, 25, 125, 30 }, GuiIconText(RICON_CROSS, "Delete from head")))
        {
            m_node.DeleteHeadNode();
        }

        if (GuiButton(Rectangle{ 295, 60, 125, 30 }, GuiIconText(RICON_CROSS, "Delete from tail")))
        {
            m_node.DeleteTailNode();
        }

        if (GuiButton(Rectangle{ 295, 95, 125, 30 }, GuiIconText(RICON_CROSS, "Delete at position")))
        {
            m_node.DeleteArbitraryNode(positionBoxValue);
        }

        if (GuiButton(Rectangle{ 25, 150, 125, 30 }, GuiIconText(RICON_ARROW_RIGHT_FILL, "Sort List")))
        {
            m_node.ListSort();
        }

        if (GuiButton(Rectangle{ 160, 150, 125, 30 }, GuiIconText(RICON_HEART, "Head & tail values")))
        {
            m_node.headVal = m_node.ReturnHeadValue();
            m_node.tailVal = m_node.ReturnTailValue();
        }

        if (GuiButton(Rectangle{ 295, 150, 125, 30 }, GuiIconText(RICON_STAR, "Check node total")))
        {
            m_node.nodeTot = m_node.NodeCount();
        }

        Node* currentNode = m_node.head->next;
        int count = 0;
        while (currentNode->next != nullptr)
        {
            if (count >= 25 && count < 50)
            {
                count++;
                int numb = (count % 25);
                if (numb == 0)
                {
                    numb = 25;
                }
                DrawCircle(((numb * 1.25) * 60) - 30, 470, 30, SKYBLUE);
                DrawText(std::to_string(currentNode->_value).c_str(), ((numb * 2.5) * 30) - 56, 460, 24, BLACK);
                currentNode = currentNode->next;
            }
            else if (count >= 50 && count < 75)
            {
                count++;
                int numb = (count % 25);
                if (numb == 0)
                {
                    numb = 25;
                }
                DrawCircle(((numb * 1.25) * 60) - 30, 540, 30, GREEN);
                DrawText(std::to_string(currentNode->_value).c_str(), ((numb * 2.5) * 30) - 56, 530, 24, BLACK);
                currentNode = currentNode->next;
            }
            else if (count >= 75 && count < 100)
            {
                count++;
                int numb = (count % 25);
                if (numb == 0)
                {
                    numb = 25;
                }
                DrawCircle(((numb * 1.25) * 60) - 30, 610, 30, BROWN);
                DrawText(std::to_string(currentNode->_value).c_str(), ((numb * 2.5) * 30) - 56, 600, 24, BLACK);
                currentNode = currentNode->next;
            }
            else if (count >= 100 && count < 125)
            {
                count++;
                int numb = (count % 25);
                if (numb == 0)
                {
                    numb = 25;
                }
                DrawCircle(((numb * 1.25) * 60) - 30, 680, 30, RED);
                DrawText(std::to_string(currentNode->_value).c_str(), ((numb * 2.5) * 30) - 56, 670, 24, BLACK);
                currentNode = currentNode->next;
            }
            else if (count >= 125 && count < 150)
            {
                count++;
                int numb = (count % 25);
                if (numb == 0)
                {
                    numb = 25;
                }
                DrawCircle(((numb * 1.25) * 60) - 30, 750, 30, YELLOW);
                DrawText(std::to_string(currentNode->_value).c_str(), ((numb * 2.5) * 30) - 56, 740, 24, BLACK);
                currentNode = currentNode->next;
            }
            else if (count >= 150 && count < 175)
            {
                count++;
                int numb = (count % 25);
                if (numb == 0)
                {
                    numb = 25;
                }
                DrawCircle(((numb * 1.25) * 60) - 30, 820, 30, PINK);
                DrawText(std::to_string(currentNode->_value).c_str(), ((numb * 2.5) * 30) - 56, 810, 24, BLACK);
                currentNode = currentNode->next;
            }
            else if (count >= 175 && count < 200)
            {
                count++;
                int numb = (count % 25);
                if (numb == 0)
                {
                    numb = 25;
                }
                DrawCircle(((numb * 1.25) * 60) - 30, 890, 30, LIGHTGRAY);
                DrawText(std::to_string(currentNode->_value).c_str(), ((numb * 2.5) * 30) - 56, 880, 24, BLACK);
                currentNode = currentNode->next;
            }
            else
            {
                count++;
                DrawCircle(((count * 1.25) * 60) - 30, 400, 30, BLUE);
                DrawText(std::to_string(currentNode->_value).c_str(), ((count * 2.5) * 30) - 56, 390, 24, BLACK);
                currentNode = currentNode->next;
            }
        }
        
        
        DrawText("Head value: ", 25, 200, 24, BLACK);
        DrawText(std::to_string(m_node.headVal).c_str(), 200, 200, 24, BLACK);

        DrawText("Tail value: ", 25, 260, 24, BLACK);
        DrawText(std::to_string(m_node.tailVal).c_str(), 200, 260, 24, BLACK);

        DrawText("Node Total: ", 25, 320, 24, BLACK);
        if (m_node.nodeTot == 0)
        {
            DrawText("There are currenetly no nodes", 200, 320, 24, BLACK);
        }
        else
        {
            DrawText(std::to_string(m_node.nodeTot).c_str(), 200, 320, 24, BLACK);

        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}