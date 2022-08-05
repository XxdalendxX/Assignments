#include "Mouse.h"
#include <cstdlib>

//AI system designed as a Behaviour Tree

namespace AIForGames
{

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////Mouse Class/////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////


    Mouse::Mouse()
    {

    }

    Mouse::Mouse(Node* startpos, Node* secondStartpos)
    {
        m_currentNode = startpos;
        m_position = startpos->position;
        m_startpos = startpos;
        m_secondaryStartpos = secondStartpos;
    }

    Mouse:: ~Mouse()
    {

    }

    void Mouse::Draw()
    {
        DrawCircle((int)m_position.x, (int)m_position.y, 16, colour);
    }

    ////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////Food Class/////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    
    Food::Food()
    {

    }

    Food::~Food()
    {

    }
    
    void Food::Generate(NodeMap acsii)
    {
        while (placedNode == nullptr)
        {
        int x = (rand() % 19 + 1);
        int y = (rand() % 9 + 1);
        Node* node = acsii.GetNode(x, y);
        placedNode = node;
        }
        m_position = placedNode->position;
    }

    void Food::Destroy()
    {
        placedNode = nullptr;
        Food::~Food();
    }

    void Food::Draw()
    {
        DrawCircle((int)m_position.x, (int)m_position.y, 9, colour);
    }

}