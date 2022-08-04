#include "Cat.h"

//AI system designed as a State Machine

namespace AIForGames
{

	Cat::Cat()
	{

	}
	
	Cat::Cat(Node* startpos)
	{
		m_currentNode = startpos;
		m_position = startpos->position;
	}

	Cat::~Cat()
	{

	}

	void Cat::UpdateCat(NodeMap acsii)
	{
		if (m_path.empty())
		{
			Wander(acsii);
		}
	}

	void Cat::Wander(NodeMap acsii)
	{
		Node* end = nullptr;
		while (m_path.empty())
		{
			int x = (rand() % 19 + 1);
			int y = (rand() % 9 + 1);
			end = acsii.GetNode(x, y);
			m_path = AStarSearch(m_currentNode, end);
		}
		travelling = true;
		
	}

	void Cat::Chase()
	{

	}

	void Cat::SwitchTarget()
	{

	}

	void Cat::Draw()
	{
		DrawCircle((int)m_position.x, (int)m_position.y, 24, colour);
	}

}