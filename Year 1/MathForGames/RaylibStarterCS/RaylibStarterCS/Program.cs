using System;
using Raylib_cs;

namespace Project2D
{
	class Program
	{
		static void Main(string[] args)
        {
            Game game = new Game();

            //establishes window size and title
            Raylib.SetTargetFPS(240);
            Raylib.InitWindow(1500, 800, "Hey, you. You're finally awake. You were trying to cross the border, right? Walked right into that imperial ambush, same as us, and that theif over there... D**n you Stormcloaks. Skyrim was fine until you came along. Empire was nice and lazy. If they hadn't been looking for you, i could've stolen that horse and been half way to Hammerfell.");

            game.Init();

            //runs the demo
            while (!Raylib.WindowShouldClose())
            {
                game.Update();
                game.Draw();
            }

            //closes the demo
            game.ShutDown();
            Raylib.CloseWindow();
        }
	}
}
