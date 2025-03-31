#include <memory>
#include <vector>
#include <list>
#include <unordered_map>

struct Node;

using NodePtr = std::shared_ptr<Node>;

using Path = std::list<NodePtr>;
using FullPath = std::list<Path>;

using AdjacencyMatrix = std::vector<std::pair<int, int>>;
using WeightMatrix = std::vector<std::array<int, 3>>;

/*
    Будет представлять из себя хештаблицу,
    где ключ это уникальное значение узла,
    а значение сам этот узел
*/
struct Graph {
    NodePtr AddOrGetNode(int value, NodePtr parent = nullptr, size_t weight = 0);
    // void DFSRecursive(Node /*, hash table for viwed nodes*/);
    // void DFSWrapRecursive(/*some params*/);
    // void DFS(Node /*hash table for viwed nodes*/);
    // void DFS();
    // Path GetPath(Node start, Node end /*list<Node> path, HashTable<Node> passed*/);
    // FullPath GetAllPath(Node start, Node end /*...*/);
    // void BFS(Node /*, hash table for viwed nodes*/);
    // void BFSWrap(Node /*...*/);
    // bool /*change return type to list<Node>*/ FindShortedPath(Node start, Node end /*...*/);
    // bool FindShortedPathByWeight();

private:
    std::unordered_map<int, NodePtr> _nodes;
};

Graph CreateGraph(AdjacencyMatrix matrix);
Graph CreateGraph(WeightMatrix matrix);