#include <iostream>
#include <memory>
#include <vector>
#include <list>

struct Node;
struct Edge;

using NodePtr = std::shared_ptr<Node>;

/*
    Хранит в себе значение, ссылки на ребра и его родителей
*/



struct Node
            : std::enable_shared_from_this<Node>
{
    Node(int value)
        : _value(value)
    {}

    static NodePtr MakeChild(int value, NodePtr parent, size_t weight = 0) {
        auto new_node = std::make_shared<Node>(value);
        if (!parent)
            throw std::runtime_error("Parent Is Null");
        new_node->SetParent(parent);
        parent->AddEdgeToChild(new_node, weight);
        return new_node;
    }

    void AddEdgeToChild(NodePtr child, size_t weight);

private:
    void SetParent(NodePtr parent) { _parents.push_back(parent); }

private:
    std::vector<NodePtr> _parents;
    std::vector<std::shared_ptr<Edge>> _edges;
    int _value = 0;
};
