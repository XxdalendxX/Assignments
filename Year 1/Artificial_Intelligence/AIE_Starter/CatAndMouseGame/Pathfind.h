#pragma once

#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <iostream>

namespace AIForGames
{
    struct Node;

    struct Edge {
        Node* target;
        float cost;

        Edge();
        Edge(Node* _target, float _cost);
    };

    struct Node {
        glm::vec2 position;
        std::vector<Edge> connections;

        float gScore;
        float hScore;
        float fScore;
        Node* previous;

        void ConnectTo(Node* other, float cost);
        Node(float x, float y);
        Node();
    };

    class NodeMap
    {
        int m_width, m_height;
        float m_cellSize;

        Node** m_nodes;

    public:
        void Initialise(std::vector<std::string> asciiMap, int cellSize);
        Node* GetNode(int x, int y);
        Node* GetNode(glm::vec2 worldPosition);
        Node* GetClosestNode(glm::vec2 worldPos);
        void Draw();
        void DrawPath(std::vector<Node*> nodeMapPath, Color colour);
    };

    class PathAgent
    {
    private:
        glm::vec2 m_position;

        int m_currentIndex;
        Node* m_currentNode;
        Node* m_startpos;
        Node* m_secondaryStartpos;

        float m_speed;

        Color colour = { 255,165,0,255 };

    public:
        std::vector<Node*> m_path;
        bool chased = false;

        void Update(float deltaTime);
        void GoToNode(Node* node);
        void Draw();
        void SetNode(Node* node, Node* secondStartpos);
        void SetNode(Node* node);
        void SetSpeed(float speed);
        Node* GetNode();
        glm::vec2 GetPos();
    };

    std::vector<Node*> AStarSearch(Node* startNode, Node* endNode);

    float Heuristic(Node* target, Node* node);

    
}
