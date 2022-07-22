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
        Node* GetClosestNode(glm::vec2 worldPos);
        void Draw();
        void DrawPath(std::vector<Node*> nodeMapPath, Color colour);
    };

    std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode);

    
}
