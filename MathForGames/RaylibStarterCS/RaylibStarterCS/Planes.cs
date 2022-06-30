using MathClasses;
using System;

namespace Project2D
{
    class Plane
    {
        public Vector3 N;
        public float d;

        //establishes the enumerator and its 3 variables
        public enum ePlaneResult : int
        {
            FRONT = 1,
            BACK = -1,
            INTERSECTS = 0
        };
        
        //constructs the plane through taking in a variety of variables
        //no variables
        public Plane()
        {

        }

        //x,y and distance floats
        public Plane(float x, float y, float d)
        {
            this.N = new Vector3(x, y, 0);
            this.d = d;
        }

        //vector point and distance
        public Plane(Vector3 n, float d)
        {
            this.N = n;
            this.d = d;
        }

        //2 vector points
        public Plane(Vector3 p1, Vector3 p2)
        {
            Vector3 v = p2 - p1;
            v.Normalize();

            N.x = -v.y;
            N.y = v.x;

            d = -p1.Dot(N);
        }

         //3 vector points
        public Plane(Vector3 p1, Vector3 p2, Vector3 p3)
        {
            Vector3 v1 = (p2 - p1).Normalize();
            Vector3 v2 = (p3 - p1).Normalize();

            N = v1.Cross(v2);

            d = -p1.Dot(N);
        }

        //determines the displacement between the vector and the plane
        public float DistanceTo(Vector3 p)
        {
            return p.Dot(N) - d;
        }

        //finds the closest point to the plane
        public Vector3 ClosestPoint(Vector3 p)
        {
            return p - N * DistanceTo(p);
        }

        //tests the plane to see whether an object is beyond, intersecting or within the area of the plane
        //vector point
        public ePlaneResult TestSide(Vector3 p)
        {
            float t = DistanceTo(p);

            if (t < 0)
            {
                return ePlaneResult.BACK;
            }
            else if (t > 0) 
            {
                return ePlaneResult.FRONT;
            }
            return ePlaneResult.INTERSECTS;
        }

        //sphere
        public ePlaneResult TestSide(Sphere sphere)
        {
            float t = DistanceTo(sphere.center);

            if (t < -sphere.radius)
            {
                return ePlaneResult.BACK;
            }
            else if (t > sphere.radius)
            {
                return ePlaneResult.FRONT;
            }
            return ePlaneResult.INTERSECTS;
        }

        //aabb
        public ePlaneResult TestSide(AABB aabb)
        {
            bool[] side = new bool[2] {false, false};

            foreach (Vector3 c in aabb.Corners())
            {
                ePlaneResult result = TestSide(c);
                if (result == ePlaneResult.FRONT)
                {
                    side[0] = true;
                }
                else if (result == ePlaneResult.BACK)
                {
                    side[1] = true;
                }
            }

            if (side[0] && !side[1])
            {
                return ePlaneResult.FRONT;
            }
            else if (!side[0] && side[1])
            {
                return ePlaneResult.BACK;
            }
            return ePlaneResult.INTERSECTS;
        }
    }
}