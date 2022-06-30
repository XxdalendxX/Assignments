using Raylib_cs;
using System;
using static Raylib_cs.Raylib;

namespace Project2D
{
    public class SpriteObject : SceneObject
    {
        //establishes and collects nessesary values and variables
        Texture2D texture = new Texture2D();
        Image image = new Image();

        public float Width
        {
            get { return texture.width; }
        }

        public float Height
        {
            get { return texture.height; }
        }

        public SpriteObject()
        {
            
        }
        //locates and loads image
        public void Load(string filename)
        {
            image = LoadImage(filename);
            texture = LoadTextureFromImage(image);
        }

        //draws image for use in the program
        public override void OnDraw()
        {
            //local x-axis y and x get passed into Atan2
            float rotation = (float)Math.Atan2(globalTransform.m01, globalTransform.m00);

            DrawTextureEx(texture,
                new System.Numerics.Vector2(globalTransform.m20, globalTransform.m21),
                //translation x and y
                rotation * (float)(180.0f / Math.PI),
                1, 
                Color.WHITE);
        }
    }
}