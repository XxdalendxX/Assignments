using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace MathClasses
{
    public struct Matrix4
    {
        public float m00, m01, m02, m03;
        public float m10, m11, m12, m13;
        public float m20, m21, m22, m23;
        public float m30, m31, m32, m33;

        //constructs a Matrix4
        public Matrix4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, 
            float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
        {
            this.m00 = m00;
            this.m01 = m01;
            this.m02 = m02;
            this.m03 = m03;
            this.m10 = m10;
            this.m11 = m11;
            this.m12 = m12;
            this.m13 = m13;
            this.m20 = m20;
            this.m21 = m21;
            this.m22 = m22;
            this.m23 = m23;
            this.m30 = m30;
            this.m31 = m31;
            this.m32 = m32;
            this.m33 = m33;
        }

        //multiplies 2 Matrix4's
        public static Matrix4 operator *(Matrix4 M1, Matrix4 M2)
        {
            return new Matrix4(
                M1.m00 * M2.m00 + M1.m10 * M2.m01 + M1.m20 * M2.m02 + M1.m30 * M2.m03,
                M1.m01 * M2.m00 + M1.m11 * M2.m01 + M1.m21 * M2.m02 + M1.m31 * M2.m03,
                M1.m02 * M2.m00 + M1.m12 * M2.m01 + M1.m22 * M2.m02 + M1.m32 * M2.m03,
                M1.m03 * M2.m00 + M1.m13 * M2.m01 + M1.m23 * M2.m02 + M1.m33 * M2.m03,

                M1.m00 * M2.m10 + M1.m10 * M2.m11 + M1.m20 * M2.m12 + M1.m30 * M2.m13,
                M1.m01 * M2.m10 + M1.m11 * M2.m11 + M1.m21 * M2.m12 + M1.m31 * M2.m13,
                M1.m02 * M2.m10 + M1.m12 * M2.m11 + M1.m22 * M2.m12 + M1.m32 * M2.m13,
                M1.m03 * M2.m10 + M1.m13 * M2.m11 + M1.m23 * M2.m12 + M1.m33 * M2.m13,

                M1.m00 * M2.m20 + M1.m10 * M2.m21 + M1.m20 * M2.m22 + M1.m30 * M2.m23,
                M1.m01 * M2.m20 + M1.m11 * M2.m21 + M1.m21 * M2.m22 + M1.m31 * M2.m23,
                M1.m02 * M2.m20 + M1.m12 * M2.m21 + M1.m22 * M2.m22 + M1.m32 * M2.m23,
                M1.m03 * M2.m20 + M1.m13 * M2.m21 + M1.m23 * M2.m22 + M1.m33 * M2.m23,

                M1.m00 * M2.m30 + M1.m10 * M2.m31 + M1.m20 * M2.m32 + M1.m30 * M2.m33,
                M1.m01 * M2.m30 + M1.m11 * M2.m31 + M1.m21 * M2.m32 + M1.m31 * M2.m33,
                M1.m02 * M2.m30 + M1.m12 * M2.m31 + M1.m22 * M2.m32 + M1.m32 * M2.m33,
                M1.m03 * M2.m30 + M1.m13 * M2.m31 + M1.m23 * M2.m32 + M1.m33 * M2.m33);

        }

        //multiplies a Matrix4 and a Vector4
        public static Vector4 operator *(Matrix4 M, Vector4 V)
        {
            return new Vector4(
                V.x * M.m00 + V.y * M.m10 + V.z * M.m20 + V.w * M.m30,
                V.x * M.m01 + V.y * M.m11 + V.z * M.m21 + V.w * M.m31,
                V.x * M.m02 + V.y * M.m12 + V.z * M.m22 + V.w * M.m32,
                V.x * M.m03 + V.y * M.m13 + V.z * M.m23 + V.w * M.m33);

        }

        //rotates the Matrix4 along the X axis
        public void SetRotateX(double radians)
        {
            m00 = 1; m01 = 0; m02 = 0; m03 = 0;
            m10 = 0; m11 = (float)Math.Cos(radians); m12 = (float)Math.Sin(radians); m13 = 0;
            m20 = 0; m21 = (float)-Math.Sin(radians); m22 = (float)Math.Cos(radians); m23 = 0;
            m30 = 0; m31 = 0; m32 = 0; m33 = 1;
        }

        //rotates the Matrix4 along the Y axis
        public void SetRotateY(double radians)
        {
            m00 = (float)Math.Cos(radians); m01 = 0; m02 = (float)-Math.Sin(radians); m03 = 0;
            m10 = 0; m11 = 1; m12 = 0; m13 = 0;
            m20 = (float)Math.Sin(radians); m21 = 0; m22 = (float)Math.Cos(radians); m23 = 0;
            m30 = 0; m31 = 0; m32 = 0; m33 = 1;
        }

        //rotates the Matrix4 along the Z axis
        public void SetRotateZ(double radians)
        {
            m00 = (float)Math.Cos(radians); m01 = (float)Math.Sin(radians); m02 = 0; m03 = 0;
            m10 = (float)-Math.Sin(radians); m11 = (float)Math.Cos(radians); m12 = 0; m13 = 0;
            m20 = 0; m21 = 0; m22 = 1; m23 = 0;
            m30 = 0; m31 = 0; m32 = 0; m33 = 1;
        }

        //moves the Matrix4
        public void SetTranslation(float x, float y, float z)
        {
            m30 = x; m31 = y; m32 = z; m33 = 1;
        }

        //allows transformations of the Matrix
        public void Translate(float x, float y, float z)
        {
            m20 += x; m21 += y; m22 += z;
        }

        //assigns variables to scale object
        public void SetScaled(Vector4 v)
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

        //scales object in size
        public void Scale(float x, float y, float z)
        {
            Matrix4 m = new Matrix4();
            m.SetScaled(x, y, z);

        }

        //rotates the object
        public void Rotate(double radians)
        {
            Matrix4 m = new Matrix4();
            m.SetRotateX(radians);
        }
    }
}
