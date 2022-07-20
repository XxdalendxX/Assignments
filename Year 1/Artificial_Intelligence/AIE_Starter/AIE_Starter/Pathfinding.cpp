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
}

void AIForGames::Node::ConnectTo(Node* other, float cost)
{
	connections.push_back(Edge(other, cost));
}
