using MathClasses;
using System;

namespace Project2D
{
    class Ray
    {
        Vector3 origin;
        Vector3 direction;
        float length;

        //establishes the ray
        public Ray()
        {

        }

        public Ray(Vector3 start, Vector3 direction, float length = float.MaxValue)
        {
            this.origin = start;
            this.direction = direction;
            this.length = length;
        }

        //binds the values to the range of the ray
        float Clamp(float value, float min, float max)
        {
            return Math.Max(min, Math.Min(max, value));
        }

        //finds the closest point between the ray and the vector
        public Vector3 closestPoint(Vector3 point)
        {
            Vector3 p = point - origin;
            float t = Clamp(p.Dot(direction), 0, length);
            return origin + direction * t;
        }

        //finds if there is an intersect between the ray and a sphere
        public bool Intersects( Sphere sphere, Vector3? I = null)
        {
            Vector3 L = sphere.center - origin;
            float t = L.Dot(direction);
            float dd = L.Dot(L) - t * t;
            t -= (float)Math.Sqrt(sphere.radius * sphere.radius - dd);
            if (t >= 0 && t <= length)
            {
                if (I != null)
                {
                    I = origin + direction * t;
                }

            //    if (R != null)
            //    {
            //        Vector3 N = ((origin + direction * t) - sphere.center);
            //        N.x /= sphere.radius;
            //        N.y /= sphere.radius;
            //        N.z /= sphere.radius;

            //        Vector3 P = direction * (length - t);

            //        float p = P.Dot(N);

            //        R = N * -2 * p + P;
            //    }

                return true;
            }
            return false;
        }

        //finds if there is an intersect between the ray and a plane
        public bool Intersects(Plane plane, Vector3? I = null)
        {
            float t = direction.Dot(plane.N);
            if (t > 0)
            {
                return false;
            }
            float d = origin.Dot(plane.N) + plane.d;
            if (t == 0 && d != 0)
            {
                return false;
            }
            t = d == 0 ? 0 : -(d / t);
            if (t >= 0 && t <= length)
            {
                if (I != null)
                {
                    I = origin + direction * t;
                }

          //      if(R != null)
          //      {
          //          Vector3 P = direction * (length - t);
          //          float p = P.Dot(plane.N);
          //          R = plane.N * p + P;
          //      }
                
                return true;
            }
            return false;
        }

        //finds if there is an intersect between the ray and an aabb
        public bool Intersects(AABB aabb, Vector3? I = null)
        {
            float xmin, xmax, ymin, ymax;

            if (direction.x < 0)
            {
                xmin = (aabb.max.x - origin.x) / direction.x;
                xmax = (aabb.min.x - origin.x) / direction.x;
            }
            else
            {
                xmin = (aabb.min.x - origin.x) / direction.x;
                xmax = (aabb.max.x - origin.x) / direction.x;
            }

            if (direction.y < 0)
            {
                ymin = (aabb.max.y - origin.y) / direction.y;
                ymax = (aabb.min.y - origin.y) / direction.y;
            }
            else
            {
                ymin = (aabb.min.y - origin.y) / direction.y;
                ymax = (aabb.max.y - origin.y) / direction.y;
            }

            if (xmin > ymax || ymin > xmax)
            {
                return false;
            }

            float t = Math.Max(xmin, ymin);

            if (t >= 0 && t <= length)
            {
                if (I != null)
                {
                    I = origin + direction * t;
                }

                //if (R != null)
                //{
                //    Vector3 N;
                //    if (t == xmin)
                //    {
                //        if (direction.x < 0)
                //        {
                //            N = new Vector3(1, 0, 1);
                //        }
                //        else
                //        {
                //            N = new Vector3(-1, 0, 1);
                //        }
                //    }
                //    else
                //    {
                //        if (direction.y < 0)
                //        {
                //            N = new Vector3(0, 1, 1);
                //        }
                //        else
                //        {
                //            N = new Vector3(0, -1, 1);
                //        }
                //    }

                //    Vector3 P = direction * (length - t);
                //    float p = P.Dot(N);
                //    R = N * -2 * p + P;
                //}

                return true;
            }
            return false;
        }
    }
}