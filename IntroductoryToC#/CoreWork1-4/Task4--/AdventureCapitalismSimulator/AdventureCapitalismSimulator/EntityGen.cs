using System;
using ItemGen;
using WorldGen;

namespace EntityGen
{
    public abstract class character : GameObject
    {
        //basic variables for the player and enemy
        protected int attack;
        protected int defense;
        protected int health;

        public bool IsAlive()
        {
            bool IsAlive = true;
            if (health <= 0)
            {
                IsAlive = false;
            }
            else
            {
                IsAlive = true;
            }
            return IsAlive;
        }
    }

    class player : character
    {
        //establishes the player and assigning parameters. 
        public player()
        {
            attack = 1; defense = 1; health = 1;
        }

        public override void Draw()
        {
            Console.Write("X");
        }
        
    }

    class enemy : character
    {
        //establishes enemy through base stats and custom stats along with different states
        public enemy()
        {
            attack = 1; defense = 1; health = 1;
        }

        public enemy(int atk, int def, int hth)
        {
            this.attack = atk; this.defense = def; this.health = hth;
        }
        
        public override void Draw()
        {
            if (health > 10)
            {
                Console.Write("O");
            }
            else
            {
                Console.Write("o");
            }
        }

        
    }
}