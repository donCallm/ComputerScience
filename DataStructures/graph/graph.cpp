#include "graph.hpp"
#include "node.hpp"
#include <iostream>
/*
    Функция должена принимать матрицу смежности
    Так же нужно сделать такую же функцию для весовой матрицы
*/

/*

    ` 1 2 3 4
    1 0 1 1 0
    2 1 0 0 1
    3 1 0 0 1
    4 0 1 1 0

    input:
        1 2
        1 3
        2 4
        3 4
*/

Graph
CreateGraph(AdjacencyMatrix matrix) {
    Graph gp;
    if (matrix.size() == 0)
        return gp;

    for (auto& row : matrix) {
        auto start = gp.AddOrGetNode(row.first);
        if (row.second == 0)
            continue;
        gp.AddOrGetNode(row.second, start);
    }

    return gp;
}

/*

    ` 1 2 3 4
    1   4 1
    2 4     3
    3 1     0
    4   3 0

    input:
        1 2 4
        1 3 1
        2 4 3
        3 4 0
*/

Graph
CreateGraph(WeightMatrix matrix) {
    Graph gp;
    if (matrix.size() == 0)
        return gp;

    for (std::array<int, 3>& row : matrix) {
        auto start = gp.AddOrGetNode(row[0]);
        if (row[1] == -1)
            continue;
        gp.AddOrGetNode(row[1], start, row[2]);
    }

    return gp;
}

NodePtr
Graph::AddOrGetNode(int value, NodePtr parent, size_t weight) {
    auto it = _nodes.find(value);
    if (it != _nodes.end()) {
        return it->second;
    }

    auto new_node = parent ? Node::MakeChild(value, parent, weight) 
        : std::make_shared<Node>(value);
    _nodes.insert({value, new_node});
    return new_node;    
}

// void
// Graph::DFSRecursive(Node /*, hash table for viwed nodes*/) {
    
// }

// void
// Graph::DFSWrapRecursive(/*some params*/) {
//     // for incoherent graph
// }

// void
// Graph::DFS(Node /*hash table for viwed nodes*/) {
//     // use stack for this
// }

// void
// Graph::DFS() {
//     // for incoherent graph
// }

// Path
// Graph::GetPath(Node start, Node end /*list<Node> path, HashTable<Node> passed*/) {

// }

// FullPath
// Graph::GetAllPath(Node start, Node end /*...*/) {

// }

// void
// Graph::BFS(Node /*, hash table for viwed nodes*/) {

// }

// void
// Graph::BFSWrap(Node /*...*/) {

// }

// bool /*change return type to list<Node>*/
// Graph::FindShortedPath(Node start, Node end /*...*/)
// {
//     // use bfs
// }

// bool
// Graph::FindShortedPathByWeight() {
//     /*
//         1. Сделать два контейнера - в один кладем непройденные узлы,
//             во второй узел и кратчайшее время до него
//         2. Всем узлам во втором контейнере устанавливаем минимальное время до него
//             максимально возможным
//         3. Идем по непройденным узлам к текущему узлу, что бы проверить
//             минимальное ли стоит время к текущему узлу, если нет, меняем на минимальное
//             если время везде осталось максимальным, значит пути к узлу нет
//         4. После этого, удаляем текущий узел из контейнера непройденных
//         5. Сохраняем конечный узел в начало пути
//         6. проверяем в контейнере со временем его родителей, если там их нет,
//             то мы их уже проверили и удалили
//         7. Складываем время от текущего узла до родительского + итоговое время от стартового узла до родительского
//     */
// }
