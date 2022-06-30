using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MathClasses
{
    public struct Vector4
    {
        public float x, y, z, w;

        //constructs a Vector4
        public Vector4(float X, float Y, float Z, float W)
        {
            this.x = X; this.y = Y; this.z = Z; this.w = W;
        }

        //allows the addition of 2 Vector4's
        public static Vector4 operator +(Vector4 lhs, Vector4 rhs)
        {
            Vector4 sum;
            sum.x = lhs.x + rhs.x;
            sum.y = lhs.y + rhs.y;
            sum.z = lhs.z + rhs.z;
            sum.w = lhs.w + rhs.w;
            return sum;
        }

        //allows the subtraction of 2 Vector4's
        public static Vector4 operator -(Vector4 lhs, Vector4 rhs)
        {
            Vector4 sum;
            sum.x = lhs.x - rhs.x;
            sum.y = lhs.y - rhs.y;
            sum.z = lhs.z - rhs.z;
            sum.w = lhs.w - rhs.w;
            return sum;
        }

        //allows the multiplcation of a Vector4 and a float
        public static Vector4 operator *(float a, Vector4 rhs)
        {
            Vector4 sum;
            sum.x = a * rhs.x;
            sum.y = a * rhs.y;
            sum.z = a * rhs.z;
            sum.w = a * rhs.w;
            return sum;
        }

        //allows the division of a Vector4 and a float
        public static Vector4 operator *(Vector4 lhs, float a)
        {
            Vector4 sum;
            sum.x = lhs.x * a;
            sum.y = lhs.y * a;
            sum.z = lhs.z * a;
            sum.w = lhs.w * a;
            return sum;
        }

        //allows the division of 2 Vector4's
        public static Vector4 operator /(Vector4 lhs, Vector4 rhs)
        {
            Vector4 sum;
            sum.x = lhs.x / rhs.x;
            sum.y = lhs.y / rhs.y;
            sum.z = lhs.z / rhs.z;
            sum.w = lhs.w / rhs.w;
            return sum;
        }

        //finds the dot product of 2 Vector4's
        public float Dot(Vector4 rhs)
        {
            return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
        }

        //finds the cross product of 2 Vector4's
        public Vector4 Cross(Vector4 rhs)
        {
            return new Vector4(
                y * rhs.z - z * rhs.y,
                z * rhs.x - x * rhs.z,
                x * rhs.y - y * rhs.x,
                0) ;
        }

        //find the magnitude of a Vector4
        public float Magnitude()
        {
            return (float)Math.Sqrt(x * x + y * y + z * z + w * w);
        }

        //finds the normalised form of the magnitude of a Vector4
        public void Normalize()
        {
            float m = Magnitude();
            this.x /= m;
            this.y /= m;
            this.z /= m;
            this.w /= m;
        }

        //calculates the distance of a vector
        public float Distance(Vector4 p)
        {
            return (float)Math.Sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
        }
    }
}
