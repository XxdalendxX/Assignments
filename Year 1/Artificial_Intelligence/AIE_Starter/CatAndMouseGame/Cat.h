#pragma once
#include "Pathfind.h"
#include "raylib.h"

namespace AIForGames
{
	class Cat : public PathAgent
	{
		glm::vec2 m_position;

		int m_currentIndex;
		Node* m_currentNode;
		Node* targetNode;

		

		float m_speed;

		Color colour = { 135, 206, 235, 255 };

	public:
		std::vector<Node*> m_path;
		bool travelling = false;

		Cat();
		Cat(Node* startpos);
		~Cat();


		void UpdateCat(NodeMap acsii);
		void SwitchTarget();
		void Wander(NodeMap acsii);
		void Chase();
		void Draw();

	};
}