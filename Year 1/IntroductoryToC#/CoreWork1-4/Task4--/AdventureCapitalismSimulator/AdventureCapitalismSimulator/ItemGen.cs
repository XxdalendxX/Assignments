using System;

namespace ItemGen
{
    public abstract class GameObject
    {
        //allows position navagating in the map
        protected int xPos;
        protected int yPos;

        public abstract void Draw();
    }

    class PowerUp : GameObject
    {
        public override void Draw()
        {
            //special symbol for power up spaces
            Console.Write("?");
        }
    }
}