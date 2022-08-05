#include "Mouse.h"
#include <cstdlib>

//AI system designed as a Behaviour Tree

namespace AIForGames
{

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

    Node* Mouse::GetNode()
    {
        return m_currentNode;
    }

    Node* Mouse::GetTargetNode()
    {
        return targetNode;
    }

    glm::vec2 Mouse::GetPos()
    {
        return m_position;
    }

    void Mouse::SetSpeed(int speed)
    {
        m_speed = speed;
    }

    void Mouse::UpdateMouse(float deltaTime)
    {
        if (m_path.empty())
        {
            return;
        }

        float distance = glm::distance(m_path[m_currentIndex]->position, m_position);
        glm::vec2 unitVector = m_path[m_currentIndex]->position - m_position;
        unitVector = glm::normalize(unitVector);

        distance = distance - m_speed * deltaTime;
        if (distance > 0)
        {
            m_position += m_speed * deltaTime * unitVector;
            m_currentNode = m_path[m_currentIndex];
        }
        else
        {
            m_currentIndex++;
            if (m_currentIndex == m_path.size())
            {
                m_position = m_path.back()->position;
                m_path.clear();
                travelling = false;
            }
            else
            {
                distance = -(distance - (m_speed * deltaTime));
                m_position = m_path[m_currentIndex - 1]->position;
                unitVector = m_path[m_currentIndex]->position - m_position;
                unitVector = glm::normalize(unitVector);
                m_position += distance * unitVector;
            }
        }
    }

    void Mouse::MouseStateCheck(NodeMap acsii, Food food)
    {
        if (food.placedNode != nullptr)
        {
            CollectFood(acsii, food);
        }
        else
        {
            Wander(acsii);
        }
    }

    void Mouse::CollectFood(NodeMap acsii, Food food)
    {
        Node* end = nullptr;
        while (m_path.empty())
        {
            while (end == nullptr)
            {
                glm::vec2 foodPos = food.placedNode->position;
                end = acsii.GetNode(foodPos);
            }
            m_path = AStarSearch(m_currentNode, end);
        }
        m_currentIndex = 0;
        travelling = true;
        targetNode = end;
    }

    void Mouse::Wander(NodeMap acsii)
    {
        Node* end = nullptr;
        while (m_path.empty())
        {
            while (end == nullptr)
            {
                int x = (rand() % 19 + 1);
                int y = (rand() % 9 + 1);
                end = acsii.GetNode(x, y);
            }
            m_path = AStarSearch(m_currentNode, end);
        }
        m_currentIndex = 0;
        travelling = true;

    }
}