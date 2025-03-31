#include <memory>

struct Node;

using NodePtr = std::shared_ptr<Node>;

/*
    Хранит в себе вес и ссылку на узел, на который оно ведет
*/
struct Edge {
    Edge(NodePtr end, NodePtr start = nullptr, size_t weight = 0)
        : _weight(weight),
        _end_node(end),
        _start_node(start)
    {}

private:
    size_t _weight;
    // Если указаны оба узла, то граф неориентированный
    NodePtr _end_node;
    NodePtr _start_node;
};