#pragma once

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

        Edge() { target = nullptr; cost = 0; };
        Edge(Node* _target, float _cost) : target(_target), cost(_cost) {}
    };

    struct Node {
        glm::vec2 position;
        std::vector<Edge> connections;

        void ConnectTo(Node* other, float cost);
        Node(float x, float y) : position(x, y) {}
    };

    class NodeMap
    {
        int m_width, m_height;
        float m_cellSize;

        Node** m_nodes;

    public:
        void Initialise(std::vector<std::string> asciiMap, int cellSize);
        Node* GetNode(int x, int y) { return m_nodes[x + m_width * y]; }
    };
}
