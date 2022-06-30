using System;
using MathClasses;

namespace Project2D
{
    class AABB
    {
        //builds min and max values 
        public Vector3 min = new Vector3(float.NegativeInfinity,
                                  float.NegativeInfinity,
                                  float.NegativeInfinity);

         public Vector3 max = new Vector3(float.PositiveInfinity,
                                  float.PositiveInfinity,
                                  float.PositiveInfinity);

        //builds component
        public AABB()
        {

        }

        public AABB(Vector3 min, Vector3 max)
        {
            this.min = min;
            this.max = max;
        }

        //colactes the center of aabb
        public Vector3 Center()
        {
            return (min + max) * 0.5f;
        }

        //
        public Vector3 Extents()
        {
            return new Vector3(Math.Abs(max.x - min.x) * 0.5f,
                               Math.Abs(max.y - min.y) * 0.5f,
                               Math.Abs(max.z - min.z) * 0.5f);
        }

        //checks if an object overlaps with the aabb
        //vector point
        public bool Overlaps(Vector3 p)
        {
            return !(p.x < min.x || max.y < min.y || p.x > max.x || p.y > max.y);
        }

        //another aabb
        public bool Overlaps(AABB other)
        {
            return !(min.x < other.min.x || min.y < other.min.y || max.x > other.max.x || max.y > other.max.y);
        }

        // finds closest point between vector point and aabb
        public Vector3 ClosestPoint(Vector3 p)
        {
            return Vector3.Clamp(p, min, max);
        }

        //locates the corners of the aabb
        public Vector3[] Corners()
        {
            Vector3[] corners = new Vector3[4];
            corners[0] = min;
            corners[1] = new Vector3(min.x, max.y, min.z);
            corners[2] = max;
            corners[3] = new Vector3(max.x, min.y, min.z);
            return corners;

        }

        //checks if min and max are empty
        public bool IsEmpty()
        {
            if (float.IsNegativeInfinity(min.x) &&
                float.IsNegativeInfinity(min.y) &&
                float.IsNegativeInfinity(min.z) &&
                float.IsInfinity(max.x) &&
                float.IsInfinity(max.y) &&
                float.IsInfinity(max.z))
                    return true;
            
            return false;
        }

        //makes the vector components empty
        public void Empty()
        {
            min = new Vector3(float.NegativeInfinity,
                              float.NegativeInfinity,
                              float.NegativeInfinity);

            max = new Vector3(float.PositiveInfinity,
                              float.PositiveInfinity,
                              float.PositiveInfinity);
        }

        //translates the aabb to be in line with target object
        public void SetToTransformedBox(AABB box, Matrix3 m)
        {
            if (box.IsEmpty())
            {
                Empty();
                return;
            }

            min = new Vector3();
            max = new Vector3();

            ///////////////////////////////
            /////////////////////////////// m00
            ///////////////////////////////
            if (m.m00 > 0.0f)
            {
                min.x += m.m00 * box.min.x;
                max.x += m.m00 * box.max.x;
            }
            else
            {
                min.x += m.m00 * box.max.x;
                max.x += m.m00 * box.min.x;
            }
            if (m.m01 > 0.0f)
            {
                min.y += m.m01 * box.min.x;
                max.y += m.m01 * box.max.x;
            }
            else
            {
                min.y += m.m01 * box.max.x;
                max.y += m.m01 * box.min.x;
            }
            if (m.m02 > 0.0f)
            {
                min.z += m.m02 * box.min.x;
                max.z += m.m02 * box.max.x;
            }
            else
            {
                min.z += m.m02 * box.max.x;
                max.z += m.m02 * box.min.x;
            }
            ///////////////////////////////
            /////////////////////////////// m10
            ///////////////////////////////
            if (m.m10 > 0.0f)
            {
                min.x += m.m10 * box.min.y;
                max.x += m.m10 * box.max.y;
            }
            else
            {
                min.x += m.m10 * box.max.y;
                max.x += m.m10 * box.min.y;
            }
            if (m.m11 > 0.0f)
            {
                min.y += m.m11 * box.min.y;
                max.y += m.m11 * box.max.y;
            }
            else
            {
                min.y += m.m11 * box.max.y;
                max.y += m.m11 * box.min.y;
            }
            if (m.m12 > 0.0f)
            {
                min.z += m.m12 * box.min.y;
                max.z += m.m12 * box.max.y;
            }
            else
            {
                min.z += m.m12 * box.max.y;
                max.z += m.m12 * box.min.y;
            }
            ///////////////////////////////
            /////////////////////////////// m20
            ///////////////////////////////
            if (m.m20 > 0.0f)
            {
                min.x += m.m20 * box.min.z;
                max.x += m.m20 * box.max.z;
            }
            else
            {
                min.x += m.m20 * box.max.z;
                max.x += m.m20 * box.min.z;
            }
            if (m.m21 > 0.0f)
            {
                min.y += m.m21 * box.min.z;
                max.y += m.m21 * box.max.z;
            }
            else
            {
                min.y += m.m21 * box.max.z;
                max.y += m.m21 * box.min.z;
            }
            if (m.m22 > 0.0f)
            {
                min.z += m.m22 * box.min.z;
                max.z += m.m22 * box.max.z;
            }
            else
            {
                min.z += m.m22 * box.max.z;
                max.z += m.m22 * box.min.z;
            }
            ///////////////////////////////
            ///////////////////////////////
            ///////////////////////////////
        }
    }
}