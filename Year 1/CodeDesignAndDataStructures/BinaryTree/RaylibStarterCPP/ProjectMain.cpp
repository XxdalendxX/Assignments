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

#include "TreeNode.h"
#include "BinaryTree.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1800;
    int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, b...lack. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Coming! Hang on a second. Hello? -barry? -Adam? -Can you believe this is happening? -I can't. I'll pick you up. Looking sharp...");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    int valueBoxValue = 0;
    bool valueBoxEditMode = false;
    BinaryTree tree;
    TreeNode* selectedNode = nullptr;

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


        DrawText("Value", 25, 15, 24, BLACK);
        if (GuiValueBox(Rectangle{ 25, 35, 125, 30 }, NULL, &valueBoxValue, 0, 9999, valueBoxEditMode)) valueBoxEditMode = !valueBoxEditMode;

        if (GuiButton(Rectangle{ 160, 20, 125, 30 }, GuiIconText(RICON_OK_TICK, "Add value node")))
        {
            tree.Add(valueBoxValue);
        }

        if (GuiButton(Rectangle{ 160, 55, 125, 30 }, GuiIconText(RICON_CROSS, "Remove value node")))
        {
            tree.Remove(valueBoxValue);
        }

        tree.Draw(selectedNode);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}