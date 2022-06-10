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
        if (GuiValueBox(Rectangle{ 25, 40, 125, 30 }, NULL, &valueBoxValue, 0, 69420, valueBoxEditMode)) valueBoxEditMode = !valueBoxEditMode;
        DrawText("Position", 25, 80, 24, BLACK);
        if (GuiValueBox(Rectangle{ 25, 100, 125, 30 }, NULL, &positionBoxValue, 0, 69420, positionBoxEditMode)) positionBoxEditMode = !positionBoxEditMode;

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
            m_node.ReturnHeadValue();
            m_node.ReturnTailValue();
        }

        if (GuiButton(Rectangle{ 295, 150, 125, 30 }, GuiIconText(RICON_STAR, "Check node total")))
        {
            m_node.NodeCount();
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