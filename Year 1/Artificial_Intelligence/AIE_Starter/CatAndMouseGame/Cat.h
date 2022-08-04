#pragma once
#include "Pathfind.h"
#include "raylib.h"

namespace AIForGames
{
	class Cat : PathAgent
	{
		glm::vec2 m_position;

		int m_currentIndex;
		Node* m_currentNode;
		Node* targetNode;

		float m_speed;

		Color colour = { 135, 206, 235, 255 };

	public:
		std::vector<Node*> m_path;

		Cat();
		Cat(Node* startpos);
		~Cat();


		void UpdateCat();
		void SwitchTarget();
		void Wander();
		void Chase();
		void Draw();

	};
}