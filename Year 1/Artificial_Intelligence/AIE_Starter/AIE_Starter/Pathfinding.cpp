#include "Pathfinding.h"

void AIForGames::NodeMap::Initialise(std::vector<std::string> asciiMap, int cellSize)
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

void AIForGames::Node::ConnectTo(Node* other, float cost)
{
	connections.push_back(Edge(other, cost));
}

void AIForGames::NodeMap::Draw()
{
    Color cellColor;
    cellColor.a = 255;
    cellColor.r = 255;
    cellColor.g = 0;
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
                        lineColor);
                }
            }
        }
    }
}
