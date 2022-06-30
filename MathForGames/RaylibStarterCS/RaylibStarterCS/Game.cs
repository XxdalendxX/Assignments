using System;
using System.Diagnostics;
using System.Numerics;
using Raylib_cs;
using static Raylib_cs.Raylib;

namespace Project2D
{
    class Game
    {
        //collects and assign nessesary variables required to run the demo
        Stopwatch stopwatch = new Stopwatch();

        private long currentTime = 0;
        private long lastTime = 0;
        private float timer = 0;
        private int fps = 1;
        private int frames;

        private float deltaTime = 0.005f;

        SceneObject tankObject = new SceneObject();
        SceneObject turretObject = new SceneObject();

        SpriteObject tankSprite = new SpriteObject();
        SpriteObject turretSprite = new SpriteObject();

        SceneObject bulletObject = new SceneObject();
        SpriteObject bulletSprite = new SpriteObject();


        Plane top;
        Plane right;
        Plane bottom;
        Plane left;

        AABB Original_aabb;
        AABB Transformed_aabb;
        MathClasses.Vector3 min;
        MathClasses.Vector3 max;

        bool intersects = false;

        MathClasses.Vector3 velocity;
        MathClasses.Vector3 acceleration;

        //performs initial actions to assign values to variables, parents and children and begin functions
        public void Init()
        {
            stopwatch.Start();
            lastTime = stopwatch.ElapsedMilliseconds;

            //establishes border planes
            top = new Plane(0, 1, 0);
            right = new Plane(-1, 0, -GetScreenWidth());
            bottom = new Plane(0, -1, -GetScreenHeight());
            left = new Plane(1, 0, 0);

            //loads sprite
            tankSprite.Load("../../../../tank/PNG/Tanks/tankBlue_outline.png");
            tankSprite.SetRotate(-90 * (float)(Math.PI / 180.0f));
            tankSprite.SetPosition(-tankSprite.Width / 2.0f, tankSprite.Height / 2.0f);

            //assigns aabb values
            min = new MathClasses.Vector3(0, 0, 1);
            max = new MathClasses.Vector3(tankSprite.Width, tankSprite.Height, 1);
            Original_aabb = new AABB(min, max);
            Transformed_aabb = new AABB(min, max);

            //loads turret sprite
            turretSprite.Load("../../../../tank/PNG/Tanks/barrelBlue.png");
            turretSprite.SetRotate(-90 * (float)(Math.PI / 180.0f));
            turretSprite.SetPosition(0, turretSprite.Width / 2.0f);

            //assigns children and position
            turretObject.AddChild(turretSprite);
            tankObject.AddChild(tankSprite);
            tankObject.AddChild(turretObject);

            bulletObject.AddChild(bulletSprite);
            
            turretObject.AddChild(bulletObject);

            tankObject.SetPosition(GetScreenWidth()/2.0f, GetScreenHeight()/2.0f);

            //assigns motion variables
            velocity = new MathClasses.Vector3(0, 0, 0);

            acceleration = new MathClasses.Vector3(0, 0, 0);

        }

        //closes program
        public void ShutDown()
        {

        }

        //keeps track of player input and elapsed time
        public void Update()
        {
            currentTime = stopwatch.ElapsedMilliseconds;
            deltaTime = (currentTime - lastTime) / 1000.0f;

            timer += deltaTime;
            if (timer >= 1)
            {
                fps = frames;
                frames = 0;
                timer -= 1;
            }
            frames++;

            //rotated tank body
            if (IsKeyDown(KeyboardKey.KEY_A))
            {
                tankObject.Rotate(-deltaTime);
            }
            if (IsKeyDown(KeyboardKey.KEY_D))
            {
                tankObject.Rotate(deltaTime);
            }

            acceleration = new MathClasses.Vector3(0, 0, 0);

            //moves tank forward relative to it's local transformation
            if (IsKeyDown(KeyboardKey.KEY_W))
            {
                acceleration = new MathClasses.Vector3(50, 0, 0);
            }
            if (IsKeyDown(KeyboardKey.KEY_S))
            {
                acceleration = new MathClasses.Vector3(-80, 0, 0);
            }

            //updates the movement values
            velocity += acceleration * deltaTime;
            MathClasses.Vector3 displacement = tankObject.GlobalTransform * velocity * deltaTime;
            tankObject.Translate(displacement.x, displacement.y);
            Transformed_aabb.SetToTransformedBox(Original_aabb, tankSprite.GlobalTransform);

            //rotates turret
            if (IsKeyDown(KeyboardKey.KEY_LEFT))
            {
                turretObject.Rotate(-deltaTime);
            }
            if (IsKeyDown(KeyboardKey.KEY_RIGHT))
            {
                turretObject.Rotate(deltaTime);
            }


            //tests if tank intersects border planes and assigns red colour if so otherwise it stays blue
            if (top.TestSide(Transformed_aabb) == Plane.ePlaneResult.INTERSECTS ||
               bottom.TestSide(Transformed_aabb) == Plane.ePlaneResult.INTERSECTS ||
               left.TestSide(Transformed_aabb) == Plane.ePlaneResult.INTERSECTS ||
               right.TestSide(Transformed_aabb) == Plane.ePlaneResult.INTERSECTS)
            {
                if (!intersects)
                {
                    tankSprite.Load("../../../../tank/PNG/Tanks/tankRed_outline.png");
                    turretSprite.Load("../../../../tank/PNG/Tanks/barrelRed.png");
                    intersects = true;
                }
            }
            else if (top.TestSide(Transformed_aabb) == Plane.ePlaneResult.FRONT &&
               bottom.TestSide(Transformed_aabb) == Plane.ePlaneResult.FRONT &&
               left.TestSide(Transformed_aabb) == Plane.ePlaneResult.FRONT &&
               right.TestSide(Transformed_aabb) == Plane.ePlaneResult.FRONT)
            {
                if (intersects)
                {
                    tankSprite.Load("../../../../tank/PNG/Tanks/tankBlue_outline.png");
                    turretSprite.Load("../../../../tank/PNG/Tanks/barrelBlue.png");
                    intersects = false;
                }
            }


            tankObject.Update(deltaTime);

            lastTime = currentTime;
        }

        
        //draws the Map, Fps Text and Tank
        public void Draw()
        {
            BeginDrawing();

            ClearBackground(Color.DARKGREEN);
            DrawText(fps.ToString(), 10, 10, 12, Color.RED);

            tankObject.Draw();

            EndDrawing();
        }
    }
}
