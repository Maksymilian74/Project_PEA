#include "Node.h"

// Konstruktor
Node::Node(int n) : level(0), cost(0), bound(0), size(n) {
    visited = new bool[n]();
    path.clear();
}

// Destruktor
Node::~Node() {
    delete[] visited;
}
