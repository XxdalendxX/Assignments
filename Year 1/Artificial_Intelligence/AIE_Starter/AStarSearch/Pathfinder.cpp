#include "Pathfinder.h"
#include "raygui.h"
#include <algorithm>

namespace AIForGames
{

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////Edge Struct/////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    Edge::Edge()
    {
        target = nullptr; cost = 0;
    }
    Edge::Edge(Node* _target, float _cost)
    {
        target = _target;
        cost = _cost;
    }

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////Node Struct/////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////


    Node::Node(float x, float y) : position(x, y) {}
    Node::Node()
    {

    }

    void Node::ConnectTo(Node* other, float cost)
    {
        connections.push_back(Edge(other, cost));
    }


    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////Node Map Class//////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    void NodeMap::Initialise(std::vector<std::string> asciiMap, int cellSize)
    {
        m_cellSize = cellSize;
        const char emptySquare = '0';

        m_height = asciiMap.size();
        m_width = asciiMap[0].size();

        m_nodes = new Node * [m_width * m_height];

        for (int y = 0; y < m_height; y++)
        {
            std::string& line = asciiMap[y];
            if (line.size() != m_width)
            {
                std::cout << "Mismatched line #" << y << " in ASCII map (" << line.size() << " intead of " << m_width << ")" << std::endl;
            }

            for (int x = 0; x < m_width; x++)
            {
                char tile = x < line.size() ? line[x] : emptySquare;

                m_nodes[x + m_width * y] = tile == emptySquare ? nullptr
                    : new Node(((float)x + 0.5f) * m_cellSize, ((float)y + 0.5f) * m_cellSize);
            }
        }

        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                Node* node = GetNode(x, y);
                if (node)
                {
                    Node* nodeWest = x == 0 ? nullptr : GetNode(x - 1, y);
                    if (nodeWest)
                    {
                        node->ConnectTo(nodeWest, 1);
                        nodeWest->ConnectTo(node, 1);
                    }

                    Node* nodeSouth = y == 0 ? nullptr : GetNode(x, y - 1);
                    if (nodeSouth)
                    {
                        node->ConnectTo(nodeSouth, 1);
                        nodeSouth->ConnectTo(node, 1);
                    }
                }
            }
        }

    }

    Node* NodeMap::GetNode(int x, int y)
    {
        return m_nodes[x + m_width * y];
    }

    Node* NodeMap::GetClosestNode(glm::vec2 worldPos)
    {
        int i = (int)(worldPos.x / m_cellSize);
        if (i < 0 || i >= m_width) return nullptr;

        int j = (int)(worldPos.y / m_cellSize);
        if (j < 0 || j >= m_height) return nullptr;

        return GetNode(i, j);
    
    }

    void NodeMap::Draw()
    {
        Color cellColor;
        cellColor.a = 100;
        cellColor.r = 0;
        cellColor.g = 255;
        cellColor.b = 0;

        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                Node* node = GetNode(x, y);
                if (node == nullptr)
                {
                    // draw a solid block in empty squares without a navigation node
                    DrawRectangle(x * m_cellSize, y * m_cellSize,
                        m_cellSize - 1, m_cellSize - 1, cellColor);
                }
                else
                {
                    // draw the connections between the node and its neighbours
                    for (int i = 0; i < node->connections.size(); i++)
                    {
                        Node* other = node->connections[i].target;
                        DrawLine((x + 0.5f) * m_cellSize, (y + 0.5f) * m_cellSize,
                            (int)other->position.x, (int)other->position.y,
                            GRAY);
                    }
                }
            }
        }
    }

    void NodeMap::DrawPath(std::vector<Node*> nodeMapPath, Color colour)
    {
        for (int i = 1; i < nodeMapPath.size(); i++)
        {
            Node* currentNode = nodeMapPath[i];
            Node* previousNode = nodeMapPath[i-1];

            DrawLine((currentNode->position.x), (currentNode->position.y),
                (int)previousNode->position.x, (int)previousNode->position.y,
                colour);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////Path Agent class/////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    void PathAgent::Update(float deltaTime)
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
            }
            else
            {
                distance = -(distance - (m_speed * deltaTime));
                m_position = m_path[m_currentIndex-1]->position;
                unitVector = m_path[m_currentIndex]->position - m_position;
                unitVector = glm::normalize(unitVector);
                m_position += distance * unitVector;
            }
        }
    }
    
    void PathAgent::GoToNode(Node* node)
    {
        m_path = AStarSearch(m_currentNode, node);
        m_currentIndex = 0;
    }

    void PathAgent::Draw()
    {
        DrawCircle((int)m_position.x, (int)m_position.y, 16, { 255,255,0,255 });
    }

    void PathAgent::SetNode(Node* node)
    {
        m_currentNode = node;
        m_position = (node->position);
    }

    void PathAgent::SetSpeed(float speed)
    {
        m_speed = speed;
    }

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////Other///////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    std::vector<Node*> AStarSearch(Node* startNode, Node* endNode)
    {
        if (startNode == nullptr || endNode == nullptr)
        {
            std::vector<Node*> empty;
            return empty;
        }

        if (startNode == endNode)
        {
            std::vector<Node*> empty;
            return empty;
        }
    
        startNode->gScore = 0;
        startNode->previous = nullptr;

        std::vector<Node*> openList;
        std::vector<Node*> closedList;

        openList.push_back(startNode);

        while (openList.empty() == false)
        {
            std::sort(openList.begin(), openList.end(), [](Node* a, Node* b) {
                return a->fScore < b->fScore;
                });

            Node* currentNode = openList.front();

            if (currentNode == endNode)
            {
                break;
            }

            openList.erase(openList.begin());
            closedList.push_back(currentNode);

            for (int i = 0; i < currentNode->connections.size(); i++)
            {
                Edge& c = currentNode->connections[i];

                //looks for connection target in the closed list
                if (std::find(closedList.begin(), closedList.end(), c.target) == closedList.end())
                {
                    float gScore = currentNode->gScore + c.cost;
                    float hScore = Heuristic(c.target, endNode);
                    float fScore = gScore + hScore;
                    
                    //looks for connection target in the open list
                    if (std::find(openList.begin(), openList.end(), c.target) == openList.end())
                    {
                        c.target->gScore = gScore;
                        c.target->fScore = fScore;
                        c.target->previous = currentNode;
                        openList.push_back(c.target);
                    }
                    else if(fScore < c.target->fScore)
                    {
                        c.target->gScore = gScore;
                        c.target->fScore = fScore;
                        c.target->previous = currentNode;
                    }
                }

                
            }

        }

        std::vector<Node*> path;
        Node* currentNode = endNode;

        while (currentNode != nullptr)
        {
            path.push_back(currentNode);
            currentNode = currentNode->previous;
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    float Heuristic(Node* target, Node* destination)
    {
        float distance = ((target->position.x - destination->position.x) + (target->position.y - destination->position.y));
        return distance;
    }


}