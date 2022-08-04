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

	void Cat::UpdateCat()
	{

	}

	void Cat::Wander()
	{

	}

	void Cat::Chase()
	{

	}

	void Cat::SwitchTarget()
	{

	}

	void Cat::Draw()
	{
		DrawCircle((int)m_position.x, (int)m_position.y, 18, colour);
	}

}