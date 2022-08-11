#pragma once
#include "Pathfind.h"
#include "raylib.h"

namespace AIForGames
{
	class Food
	{
		glm::vec2 m_position;

		Color colour = { 255,215,0,255 };


	public:
		Node* placedNode;

		Food();
		~Food();
		void Generate(NodeMap& acsii);
		void Destroy();
		void Draw();
	};

	class Mouse
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
		bool travelling = false;
		bool chased = false;


		Mouse();
		Mouse(Node* startpos, Node* secondStartpos);
		~Mouse();

		void MouseStateCheck(NodeMap& acsii, Food food);
		void UpdateMouse(float deltaTime);
		void CollectFood(NodeMap& acsii, Food food);
		void Wander(NodeMap& acsii);
		void Flee();
		void Draw();
		Node* GetNode();
		Node* GetTargetNode();
		glm::vec2 GetPos();
		void SetSpeed(int speed);
		void SetNode(Node* node);

	};

	
}
