using MathClasses;

namespace Project2D
{
    class Sphere
    {
        //establishes and collects nessesary values and variables
        public Vector3 center;
        public float radius;

        public Sphere()
        {

        }

        public Sphere(Vector3 p, float r)
        {
            this.center = p;
            this.radius = r;
        }

        

        //makes it so the points fit within the circle or sphere
        public void Fit(Vector3[] points)
        {
            Vector3 min = new Vector3(float.MaxValue, float.MaxValue, float.MaxValue);
            Vector3 max = new Vector3(float.MinValue, float.MinValue, float.MinValue);

            for (int i = 0; i < points.Length; i++)
            {
                min = Vector3.Min(min, points[i]);
                max = Vector3.Max(max, points[i]);
            }

            center = (min + max) * 0.5f;
            radius = center.Distance(max);
        }

        //determins whether the sphere or circle is overlapping with another collider
        //vector point
        public bool Overlaps(Vector3 p)
        {
            Vector3 toPoint = p - center;
            return toPoint.Magnitude() <= (radius * radius);
        }

        //sphere
        public bool Overlaps(Sphere other)
        {
            Vector3 diff = other.center - center;
            float r = radius + other.radius;
            return diff.Magnitude() <= (r * r);
        }

        //aabb
        public bool Overlaps(AABB aabb)
        {
            Vector3 diff = aabb.ClosestPoint(center) - center;
            return diff.Dot(diff) <= (radius * radius);
        }

        //finds the closest point on the sphere or circle from the end point of the vector
        Vector3 ClosestPoint(Vector3 p)
        {
            Vector3 toPoint = p - center;
            if (toPoint.Magnitude() > radius * radius)
            {
                toPoint = toPoint.Normalize();
                toPoint = toPoint * radius;
            }
            return center + toPoint;
        }
    }
}