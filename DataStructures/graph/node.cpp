#include "node.hpp"
#include "edge.hpp"

void
Node::AddEdgeToChild(NodePtr child, size_t weight) {
    _edges.push_back(std::make_shared<Edge>(child, nullptr, weight));
}
