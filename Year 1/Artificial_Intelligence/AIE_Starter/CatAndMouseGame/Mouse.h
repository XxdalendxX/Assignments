#pragma once
#include "Pathfind.h"
#include "raylib.h"

namespace AIForGames
{
	class Mouse : public PathAgent
	{
		glm::vec2 m_position;

		int m_currentIndex;
		Node* m_currentNode;
		Node* targetNode;
		Node* m_startpos;
		Node* m_secondaryStartpos;

		float m_speed;

		Color colour = { 128,64,0,255 };

	public:
		std::vector<Node*> m_path;

		Mouse();
		Mouse(Node* startpos, Node* secondStartpos);
		~Mouse();

		void UpdateMouse();
		void CollectFood();
		void Wander();
		void Flee();
		void Draw();


	};

	class Food
	{
		glm::vec2 m_position;

		Color colour = { 255,215,0,255 };


	public:
		Node* placedNode;

		Food();
		~Food();
		void Generate(NodeMap acsii);
		void Destroy();
		void Draw();
	};
}
