#include "Algorithms.h"
#include "../Structures/Stack.h"
#include <limits>
#include <iostream>

using namespace std;

// Metoda branch and bound BFS
int Algorithms::branchAndBoundBFS(const Matrix &matrix, vector<int> &bestPath) {
}

// Metoda branch and bound DFS
int Algorithms::branchAndBoundDFS(const Matrix &matrix, vector<int> &bestPath) {
    int n = matrix.getSize();
    int minCost = numeric_limits<int>::max();
    bestPath.clear();

    Stack stack;

    // Inicjalizacja pierwszego wezla
    Node* root = new Node(n);
    root->path.push_back(0);
    root->visited[0] = true;
    root->bound = calculateBound(matrix, *root);
    stack.push(root);
    while (!stack.isEmpty()) {
        Node* currentNode = stack.pop();
        // Jesli osiagnelismy lisc drzewa (pelna trasa)
        if (currentNode->level == n - 1) {
            int lastCity = currentNode->path.back();
            int returnCost = matrix.getCost(lastCity, 0);
            if (returnCost != -1) {
                int totalCost = currentNode->cost + returnCost;
                if (totalCost < minCost) {
                    minCost = totalCost;
                    bestPath = currentNode->path;
                    bestPath.push_back(0);
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (!currentNode->visited[i] && matrix.getCost(currentNode->path.back(), i) != -1) {
                    Node* child = new Node(n);
                    child->level = currentNode->level + 1;
                    child->cost = currentNode->cost + matrix.getCost(currentNode->path.back(), i);
                    child->path = currentNode->path;
                    child->path.push_back(i);
                    copy(currentNode->visited, currentNode->visited + n, child->visited);
                    child->visited[i] = true;

                    child->bound = calculateBound(matrix, *child);

                    // Dodanie dziecka do stosu tylko, jesli jego granica jest lepsza
                    if (child->bound < minCost) {
                        stack.push(child);
                    } else {
                        delete child;
                    }
                }
            }
        }

        delete currentNode; // Usuniecie przetworzonego wezla
    }
    return minCost;
}

// Metoda branch and bound best first search
int Algorithms::branchAndBoundBestFirstSearch(const Matrix &matrix, vector<int> &bestPath) {
}

// Funkcja do obliczania dolnej granicy
int Algorithms::calculateBound(const Matrix& matrix, const Node& node) {
    int n = matrix.getSize();
    int lowerBound = node.cost;

    // Dodawanie minimalnych kosztow z niewykorzystanych krawedzi
//    for (int i = 0; i < n; ++i) {
//        if (!node.visited[i]) {
//            int minCost = numeric_limits<int>::max();
//            for (int j = 0; j < n; ++j) {
//                if (i != j && !node.visited[j]) {
//                    int cost = matrix.getCost(i, j);
//                    if (cost < minCost) {
//                        minCost = cost;
//                    }
//                }
//            }
//            lowerBound += (minCost == numeric_limits<int>::max() ? 0 : minCost);
//        }
//    }
    for (int i = 0; i < n; ++i) {
        if (!node.visited[i]) {
            int minCost1 = numeric_limits<int>::max(); // Najtansza krawedz wychodzaca
            int minCost2 = numeric_limits<int>::max(); // Najtansza krawedz przychodzaca
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int cost = matrix.getCost(i, j);
                    if (!node.visited[j] && cost != -1) {
                        if (cost < minCost1) {
                            minCost2 = minCost1;
                            minCost1 = cost;
                        } else if (cost < minCost2) {
                            minCost2 = cost;
                        }
                    }
                }
            }
            // Dodajemy koszt dwoch najtanszych krawedzi
            lowerBound += (minCost1 == numeric_limits<int>::max() ? 0 : minCost1);
            lowerBound += (minCost2 == numeric_limits<int>::max() ? 0 : minCost2);
        }
    }
//    return lowerBound;
    return lowerBound/2;
}
