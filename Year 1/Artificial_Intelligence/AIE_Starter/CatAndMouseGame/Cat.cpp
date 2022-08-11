#include "Cat.h"
#include <cmath>
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

	void Cat::CatStateCheck(NodeMap& acsii, Mouse mouse, PathAgent player)
	{
		float mousedist = MouseDistance(mouse);
		float playerdist = MouseDistance(player);

		if (chasingMouse == false)
			{
				if (mousedist <= (float)350)
				{
					if (playerdist > mousedist)
					{
						chasingPlayer = false;
						travelling = false;
						m_path.clear();
						Chase(acsii, mouse);
					}
				}
			}
		else if (mousedist > (float)350)
		{
			chasingMouse = false;
		}
		if (chasingPlayer == false)
			{
				if (playerdist <= (float)350)
				{
					if (playerdist < mousedist)
					{
						chasingMouse = false;
						travelling = false;
						m_path.clear();
						Chase(acsii, player);
					}
				}
			}
		else if (playerdist > (float)350)
		{
			chasingPlayer = false;
		}

		if (chasingMouse == true)
		{
			if (playerdist > mousedist)
			{
				chasingMouse = false;
				Chase(acsii, mouse);
			}
		}
		if (chasingPlayer == true)
		{
			if (playerdist < mousedist)
			{
				chasingPlayer = false;
				Chase(acsii, player);
			}
		}
		else if(m_path.empty())
		{
			m_path.clear();
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

	void Cat::Wander(NodeMap& acsii)
	{
		Node* end = nullptr;
		if (m_path.empty())
		{
			while (end == nullptr || m_currentNode == end)
			{
				int x = (rand() % 19 + 1);
				int y = (rand() % 9 + 1);
				end = acsii.GetNode(x, y);
			}
			m_path = AStarSearch(m_currentNode, end);
			m_currentIndex = 0;
		}
		travelling = true;
		
		
	}

	void Cat::Chase(NodeMap& acsii, PathAgent player)
	{
		chasingPlayer = true;

		Node* end = nullptr;
		int x = (int)floor(player.GetPos().x / (float)90);
		int y = (int)floor(player.GetPos().y / (float)90);
		end = acsii.GetNode(x, y);

		if (m_path.empty())
		{
			m_path = AStarSearch(m_currentNode, end);
			if (m_path.empty())
			{
				m_path.push_back(end);
			}
			m_currentIndex = 0;
		}
		travelling = true;

	}

	void Cat::Chase(NodeMap& acsii, Mouse mouse)
	{
		chasingMouse = true;

		Node* end = nullptr;
		int x = (int)floor(mouse.GetPos().x / (float)90);
		int y = (int)floor(mouse.GetPos().y / (float)90);
		end = acsii.GetNode(x, y);

		if (m_path.empty())
		{
			m_path = AStarSearch(m_currentNode, end);
			if (m_path.empty())
			{
				m_path.push_back(end);
			}
			m_currentIndex = 0;
		}
		travelling = true;
		

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

	float Cat::MouseDistance(Mouse mouse)
	{
		int x = mouse.GetPos().x - m_position.x;
		int y = mouse.GetPos().y - m_position.y;
		float h = (sqrt(pow(x,2) + pow(y,2)));
		return h;
	}

	float Cat::MouseDistance(PathAgent player)
	{
		int x = player.GetPos().x - m_position.x;
		int y = player.GetPos().y - m_position.y;
		float h = (sqrt(pow(x, 2) + pow(y, 2)));
		return h;
	}

	glm::vec2 Cat::GetPos()
	{
		return m_position;
	}


}