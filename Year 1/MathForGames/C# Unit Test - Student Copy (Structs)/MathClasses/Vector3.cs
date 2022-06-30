using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MathClasses
{
    public struct Vector3
    {
        public float x, y, z;

        //constructs Vector3 struct variable
        public Vector3(float X, float Y, float Z)
        {
            this.x = X; this.y = Y; this.z = Z;
        }

        //finds the sum of 2 Vector3's
        public static Vector3 operator +(Vector3 lhs, Vector3 rhs)
        {
            Vector3 sum;
            sum.x = lhs.x + rhs.x;
            sum.y = lhs.y + rhs.y;
            sum.z = lhs.z + rhs.z;
            return sum;
        }

        //finds the difference between 2 Vector3's
        public static Vector3 operator -(Vector3 lhs, Vector3 rhs)
        {
            Vector3 sum;
            sum.x = lhs.x - rhs.x;
            sum.y = lhs.y - rhs.y;
            sum.z = lhs.z - rhs.z;
            return sum;
        }

        //allows the multiplcation of a Vector3 and a float
        public static Vector3 operator *(Vector3 lhs, float a)
        {
            Vector3 sum;
            sum.x = lhs.x * a;
            sum.y = lhs.y * a;
            sum.z = lhs.z * a;
            return sum;
        }

        //allows the division of a Vector3 and a float
        public static Vector3 operator *(float a, Vector3 rhs)
        {
            Vector3 sum;
            sum.x = a * rhs.x;
            sum.y = a * rhs.y;
            sum.z = a * rhs.z;
            return sum;
        }

        //allows the addition of 2 Vector3's
        public static Vector3 operator /(Vector3 lhs, Vector3 rhs)
        {
            Vector3 sum;
            sum.x = lhs.x / rhs.x;
            sum.y = lhs.y / rhs.y;
            sum.z = lhs.z / rhs.z;
            return sum;
        }

        //finds the dot product of 2 Vector3's
        public float Dot(Vector3 rhs)
        {
            return x * rhs.x + y * rhs.y + z * rhs.z;
        }

        //finds the cross product of 2 Vector3's
        public Vector3 Cross(Vector3 rhs)
        {
            return new Vector3(
                y * rhs.z - z * rhs.y,
                z * rhs.x - x * rhs.z,
                x * rhs.y - y * rhs.x);
        }

        //finds the Magnitude of a Vector3
        public float Magnitude()
        {
            return (float)Math.Sqrt(x * x + y * y + z * z);
        }

        //finds the normalised magnitude of a Vector3
        public Vector3 Normalize()
        {
            float m = Magnitude();
            this.x /= m;
            this.y /= m;
            this.z /= m;
            return this;
        }

        //grabs the minimum values for an AABB
        public static Vector3 Min (Vector3 a, Vector3 b)
        {
            return new Vector3(Math.Min(a.x, b.x), Math.Min(a.y, b.y), Math.Min(a.z, b.z));
        }

        //Grabs the maximum values for an AABB
        public static Vector3 Max(Vector3 a, Vector3 b)
        {
            return new Vector3(Math.Max(a.x, b.x), Math.Max(a.y, b.y), Math.Max(a.z, b.z));
        }

        //restrains the distance of a vector point to be within a range
        public static Vector3 Clamp(Vector3 t, Vector3 a, Vector3 b)
        {
            return Max(a, Min(b, t));
        }

        //calculates the distance between vector points
        public float Distance(Vector3 p)
        {
            return (float)Math.Sqrt(p.x * p.x + p.y * p.y);
        }
    }
}
