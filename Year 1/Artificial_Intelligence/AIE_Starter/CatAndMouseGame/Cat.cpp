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

	void Cat::CatStateCheck(NodeMap acsii)
	{
		if (m_path.empty())
		{
			Wander(acsii);
		}
	}

	void Cat::UpdateCat(float deltaTime)
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

	void Cat::Wander(NodeMap acsii)
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
		travelling = true;
		m_currentIndex = 0;
		
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

	Node* Cat::GetNode()
	{
		return m_currentNode;
	}

	void Cat::SetSpeed(int speed)
	{
		m_speed = speed;
	}

}