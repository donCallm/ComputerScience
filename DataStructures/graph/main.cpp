#include <iostream>
#include "graph.hpp"

int main() {
    std::cout << "Hello, Its graph\n";

    AdjacencyMatrix amatrix = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 3}
    };

    WeightMatrix wmatrix = {
        {1, 2, 4},
        {1, 3, 1},
        {2, 4, 3},
        {3, 4, 0}

    };

    std::cout << "A Create: ";
    Graph agp = CreateGraph(amatrix);
    std::cout << "complete\n";

    std::cout << "W Create: ";
    Graph wgp = CreateGraph(wmatrix);
    std::cout << "complete\n";
    
    return 0;
}
