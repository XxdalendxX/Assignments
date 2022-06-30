using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;




namespace MathClasses
{
   
    public struct Matrix3
    {
        //m(column,row)
        public float m00, m01, m02;
        public float m10, m11, m12;
        public float m20, m21, m22;

        //constructs a Matrix3
        public Matrix3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
        {
            this.m00 = m00;
            this.m01 = m01;
            this.m02 = m02;
            this.m10 = m10;
            this.m11 = m11;
            this.m12 = m12;
            this.m20 = m20;
            this.m21 = m21;
            this.m22 = m22;
        }

        //constructs a Identity Matrix3
        public Matrix3 (float uniformScale)
        {
            m00 = m11 = m22 = uniformScale;
            m01 = m02 = m10 = m12 = m20 = m21 = 0;
        }

        //multiplies 2 Matrix3's
        public static Matrix3 operator *(Matrix3 M1, Matrix3 M2)
        {
            return new Matrix3(
                M1.m00 * M2.m00 + M1.m10 * M2.m01 + M1.m20 * M2.m02,
                M1.m01 * M2.m00 + M1.m11 * M2.m01 + M1.m21 * M2.m02,
                M1.m02 * M2.m00 + M1.m12 * M2.m01 + M1.m22 * M2.m02,

                M1.m00 * M2.m10 + M1.m10 * M2.m11 + M1.m20 * M2.m12,
                M1.m01 * M2.m10 + M1.m11 * M2.m11 + M1.m21 * M2.m12,
                M1.m02 * M2.m10 + M1.m12 * M2.m11 + M1.m22 * M2.m12,

                M1.m00 * M2.m20 + M1.m10 * M2.m21 + M1.m20 * M2.m22,
                M1.m01 * M2.m20 + M1.m11 * M2.m21 + M1.m21 * M2.m22,
                M1.m02 * M2.m20 + M1.m12 * M2.m21 + M1.m22 * M2.m22);    
        }

        //multiplies a Matrix3 and a Vector3
        public static Vector3 operator *(Matrix3 M, Vector3 V)
        {
            return new Vector3(
                V.x * M.m00 + V.y * M.m10 + V.z * M.m20,
                V.x * M.m01 + V.y * M.m11 + V.z * M.m21,
                V.x * M.m02 + V.y * M.m12 + V.z * M.m22);
                
        }

        //rotates the Matrix3 along the X axis
        public void SetRotateX(double radians)
        {
            m00 = 1; m01 = 0; m02 = 0;
            m10 = 0; m11 = (float)Math.Cos(radians); m12 = (float)Math.Sin(radians);
            m20 = 0; m21 = (float)-Math.Sin(radians); m22 = (float)Math.Cos(radians);
        }

        //rotates the Matrix3 along the Y axis
        public void SetRotateY(double radians)
        {
            m00 = (float)Math.Cos(radians); m01 = 0; m02 = (float)-Math.Sin(radians);
            m10 = 0; m11 = 1; m12 = 0;
            m20 = (float)Math.Sin(radians); m21 = 0; m22 = (float)Math.Cos(radians);
        }

        //rotates the Matrix3 along the Z axis
        public void SetRotateZ(double radians)
        {
            m00 = (float)Math.Cos(radians); m01 = (float)Math.Sin(radians); m02 = 0;
            m10 = (float)-Math.Sin(radians); m11 = (float)Math.Cos(radians); m12 = 0;
            m20 = 0; m21 = 0; m22 = 1;
        }

        //moves the the Matrix3
        public void SetTranslation(float x, float y)
        {
            m20 = x; m21 = y;
        }

        //allows transformations of the matrix
        public void Translate(float x, float y)
        {
            m20 += x; m21 += y;
        }

        //assigns variables to scale object
        public void SetScaled(Vector3 v)
        {
            m00 = v.x; m01 = 0; m02 = 0;
            m10 = 0; m11 = v.y; m12 = 0;
            m20 = 0; m21 = 0; m22 = v.z;
        }

        //assigns variables to scale object
        public void SetScaled(float _x, float _y, float _z)
        {
            m00 = _x; m01 = 0; m02 = 0;
            m10 = 0; m11 = _y; m12 = 0;
            m20 = 0; m21 = 0; m22 = _z;
        }

        //Scales the object in size
        public void Scale(float x, float y, float z)
        {
            Matrix3 m = new Matrix3();
            m.SetScaled(x, y, z);

            this = this * m;

        }

        //rotates matrix on the X axis
        public void RotateX(double radians)
        {
            Matrix3 m = new Matrix3();
            m.SetRotateX(radians);

            this = this * m;
        }

        //rotates matrix on the Y axis
        public void RotateY(double radians)
        {
            Matrix3 m = new Matrix3();
            m.SetRotateY(radians);

            this = this * m;
        }

        //rotates matrix on the Z axis
        public void RotateZ(double radians)
        {
            Matrix3 m = new Matrix3();
            m.SetRotateZ(radians);

            this = this * m;
        }
    }
}