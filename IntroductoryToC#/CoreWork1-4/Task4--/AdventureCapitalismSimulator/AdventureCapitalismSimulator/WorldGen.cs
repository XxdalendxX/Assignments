using System;
using ItemGen;
using EntityGen;

namespace WorldGen
{
    public class Room
    {
        //new array used for special spaces
        GameObject[] objects = new GameObject[3];


        public void AddGameObject(GameObject go)
        {
            //implements special space varients in next available space and if not is ignored
            if (objects[0] == null)
            {
                objects[0] = go;
            }
            else if (objects[1] == null)
            {
                objects[1] = go;
            }
            else if (objects[2] == null)
            {
                objects[2] = go;
            }
            else
            {

            }
        }

        public void RemoveGameObject(GameObject go)
        {
   //checks where desired object is and moves null to the last position
            if (objects[0] == go)
            {
                objects[0] = objects[1];
                objects[1] = objects[2];
                objects[2] = null;
                return;
            }
            else if (objects[1] == go)
            {
                objects[1] = objects[2];
                objects[2] = null;
                return;
            }
            else if (objects[2] == go)
            {
                objects[2] = null;
                return;
            }
            else
            {

            }
        }

        public void Draw()
        {
            //checks and applies empty rooms/ non unique spaces
            if(objects[0] == null)
            {
                Console.Write("_");
            }
            else
            {
                objects[0].Draw();
            }
        }
    }
}