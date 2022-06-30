using System;
using System.Collections.Generic;
using System.Diagnostics;
using MathClasses;

namespace Project2D
{
    public class SceneObject
    {
        //establishes and build all nessesary values and components
        protected SceneObject parent = null;
        protected List<SceneObject> children = new List<SceneObject>();

        protected Matrix3 localTransform = new Matrix3(1);
        protected Matrix3 globalTransform = new Matrix3(1);

        public SceneObject Parent
        {
            get { return parent; }
        }

        public SceneObject()
        {
            //initialises with the identity matrix
            localTransform = new Matrix3(1);
        }

        //manages children through counting the number, identifying, adding and removing children.
        public int GetChildCount()
        {
            return children.Count;
        }

        public SceneObject GetChild(int index)
        {
            return children[index];
        }

        public void AddChild(SceneObject child)
        {
            Debug.Assert(child.parent == null);
            child.parent = this;
            children.Add(child);
        }

        public void RemoveChild(SceneObject child)
        {
            if(children.Remove(child) == true)
            {
                child.parent = null;
            }
        }

        ~SceneObject()
        {
            if(parent != null)
            {
                parent.RemoveChild(this);
            }
            foreach(SceneObject so in children)
            {
                so.parent = null;
            }
        }

        //empty voids to be overwritten
        public virtual void OnUpdate(float deltaTime)
        {
            
        }

        public virtual void OnDraw()
        {

        }

        //updates information regarding the child or SceneObject
        public void Update(float delatTime)
        {
            OnUpdate(delatTime);

            foreach(SceneObject child in children)
            {
                child.Update(delatTime);
            }
        }

        //draws the parent and children
        public void Draw()
        {
            OnDraw();

            foreach(SceneObject child in children)
            {
                child.Draw();
            }
        }

        //establishes the local and global transforms
        public Matrix3 LocalTransform
        {
            get { return localTransform; }
        }
        public Matrix3 GlobalTransform
        {
            get { return globalTransform; }
        }

        //updates the global and local transformations
        public void UpdateTransform()
        {
            if(parent != null)
            {
                globalTransform = parent.globalTransform * localTransform;
            }
            else
            {
                globalTransform = localTransform;
            }
            foreach(SceneObject child in children)
            {
                child.UpdateTransform();
            }
        }

        //sets the variables to either set the position, scale or rotation
        public void SetPosition(float x, float y)
        {
            localTransform.SetTranslation(x, y);
            UpdateTransform();
        }

        public void SetRotate(float radians)
        {
            localTransform.SetRotateZ(radians);
            UpdateTransform();
        }

        public void SetScale(float width, float height)
        {
            localTransform.SetScaled(width, height, 1);
            UpdateTransform();
        }

        //actually translates, rotates or scales
        public void Translate(float x, float y)
        {
            localTransform.Translate(x, y);
            UpdateTransform();
        }

        public void Rotate(float radians)
        {
            localTransform.RotateZ(radians);
            UpdateTransform();
        }

        public void Scale(float width, float height)
        {
            localTransform.Scale(width, height, 1);
            UpdateTransform();
        }


    }
}