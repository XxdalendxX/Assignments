#pragma once
#include "Pathfind.h"
#include "raylib.h"

namespace AIForGames
{
	class Cat
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


		void CatStateCheck(NodeMap acsii);
		void UpdateCat(float deltaTime);
		void SwitchTarget();
		void Wander(NodeMap acsii);
		void Chase();
		void Draw();
		Node* GetNode();
		void SetSpeed(int speed);


	};
}