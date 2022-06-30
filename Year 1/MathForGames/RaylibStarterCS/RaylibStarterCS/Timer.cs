using System;
using System.Diagnostics;

namespace Project2D
{
    public class Timer
    {
        //creates the stopwatch and establishes the nessesary variables
        Stopwatch stopwatch = new Stopwatch();

        private long currentTime = 0;
        private long lastTime = 0;

        private float deltaTime = 0.005f;

        //starts the stopwatch
        public Timer()
        {
            stopwatch.Start();
        }

        //resets the stopwatch
        public void Reset()
        {
            stopwatch.Reset();
        }

        //provides the stopwatch value in seconds
        public float Seconds()
        {
             return stopwatch.ElapsedMilliseconds / 1000.0f;
        }

        //provides a deltaTime variable 
        public float GetDeltaTime()
        {
            lastTime = currentTime;
            currentTime = stopwatch.ElapsedMilliseconds;
            deltaTime = (currentTime - lastTime) / 1000.0f;
            return deltaTime;
        }
    }
}