#include "Algorithms.h"
#include "../Structures/PriorityQueue.h"
#include <limits>
#include <iostream>

using namespace std;

// Metoda branch and bound BFS dla macierzy asymetrycznej
int Algorithms::AsymmetricBranchAndBoundBFS(const Matrix &matrix, vector<int> &bestPath) {
    int n = matrix.getSize();
    int minCost = std::numeric_limits<int>::max();
    bestPath.clear();

    Queue queue;

    Node* root = new Node(n);
    root->path.push_back(0);
    root->visited[0] = true;
    root->bound = AsymmetricCalculateBound(matrix, *root);
    queue.enqueue(root);

    while (!queue.isEmpty()) {
        Node* currentNode = queue.dequeue();

        if (currentNode->bound < minCost) {
            if (currentNode->level == n - 1) {
                int lastCity = currentNode->path.back();
                int cost = matrix.getCost(lastCity, 0);
                if (cost != -1) {
                    int totalCost = currentNode->cost + cost;
                    if (totalCost < minCost) {
                        minCost = totalCost;
                        bestPath = currentNode->path;
                        bestPath.push_back(0);  // Powrot do miasta startowego
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if (!currentNode->visited[i] && matrix.getCost(currentNode->path.back(), i) != -1) {
                        Node* child = new Node(n);
                        child->level = currentNode->level + 1;
                        child->cost = currentNode->cost + matrix.getCost(currentNode->path.back(), i);
                        child->path = currentNode->path;
                        child->path.push_back(i);
                        std::copy(currentNode->visited, currentNode->visited + n, child->visited);
                        child->visited[i] = true;

                        child->bound = AsymmetricCalculateBound(matrix, *child);

                        if (child->bound < minCost) {
                            queue.enqueue(child);
                        } else {
                            delete child;
                        }
                    }
                }
            }
        }

        delete currentNode;
    }

    return minCost;
}

// Metoda branch and bound DFS dla macierzy asymetrycznej
int Algorithms::AsymmetricBranchAndBoundDFS(const Matrix &matrix, vector<int> &bestPath) {
    int n = matrix.getSize();
    int minCost = numeric_limits<int>::max();
    bestPath.clear();

    Stack stack;

    Node* root = new Node(n);
    root->path.push_back(0);
    root->visited[0] = true;
    root->bound = AsymmetricCalculateBound(matrix, *root);
    stack.push(root);
    while (!stack.isEmpty()) {
        Node* currentNode = stack.pop();
        // Jesli osiagnelismy lisc drzewa
        if (currentNode->level == n - 1) {
            int lastCity = currentNode->path.back();
            int cost = matrix.getCost(lastCity, 0);
            if (cost != -1) {
                int totalCost = currentNode->cost + cost;
                if (totalCost < minCost) {
                    minCost = totalCost;
                    bestPath = currentNode->path;
                    bestPath.push_back(0);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (!currentNode->visited[i] && matrix.getCost(currentNode->path.back(), i) != -1) {
                    Node* child = new Node(n);
                    child->level = currentNode->level + 1;
                    child->cost = currentNode->cost + matrix.getCost(currentNode->path.back(), i);
                    child->path = currentNode->path;
                    child->path.push_back(i);
                    copy(currentNode->visited, currentNode->visited + n, child->visited);
                    child->visited[i] = true;

                    child->bound = AsymmetricCalculateBound(matrix, *child);

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

// Metoda branch and bound best first search dla macierzy asymetrycznej
int Algorithms::AsymmetricBranchAndBoundBestFirstSearch(const Matrix &matrix, vector<int> &bestPath) {
    int n = matrix.getSize();
    int minCost = std::numeric_limits<int>::max();
    bestPath.clear();

    PriorityQueue queue;

    Node* root = new Node(n);
    root->path.push_back(0);
    root->visited[0] = true;
    root->bound = AsymmetricCalculateBound(matrix, *root);
    queue.enqueue(root);

    while (!queue.isEmpty()) {
        Node* currentNode = queue.dequeue();

        if (currentNode->bound < minCost) {
            if (currentNode->level == n - 1) {
                int lastCity = currentNode->path.back();
                int cost = matrix.getCost(lastCity, 0);
                if (cost != -1) {
                    int totalCost = currentNode->cost + cost;
                    if (totalCost < minCost) {
                        minCost = totalCost;
                        bestPath = currentNode->path;
                        bestPath.push_back(0);
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if (!currentNode->visited[i] && matrix.getCost(currentNode->path.back(), i) != -1) {
                        Node* child = new Node(n);
                        child->level = currentNode->level + 1;
                        child->cost = currentNode->cost + matrix.getCost(currentNode->path.back(), i);
                        child->path = currentNode->path;
                        child->path.push_back(i);
                        std::copy(currentNode->visited, currentNode->visited + n, child->visited);
                        child->visited[i] = true;

                        child->bound = AsymmetricCalculateBound(matrix, *child);

                        if (child->bound < minCost) {
                            queue.enqueue(child);
                        } else {
                            delete child;
                        }
                    }
                }
            }
        }

        delete currentNode;
    }

    return minCost;
}

// Metoda branch and bound BFS dla macierzy symetrycznej
int Algorithms::SymmetricBranchAndBoundBFS(const SymmetricMatrix &matrix, vector<int> &bestPath) {
    int n = matrix.getSize();
    int minCost = std::numeric_limits<int>::max();
    bestPath.clear();

    Queue queue;

    Node* root = new Node(n);
    root->path.push_back(0); // Start od miasta 0
    root->visited[0] = true;
    root->bound = SymmetricCalculateBound(matrix, *root); // Wyliczenie dolnej granicy
    queue.enqueue(root);

    while (!queue.isEmpty()) {
        Node* currentNode = queue.dequeue();

        // Sprawdzenie, czy granica jest lepsza od najlepszego znalezionego rozwiazania
        if (currentNode->bound < minCost) {
            if (currentNode->level == n - 1) { // Jesli osiagnelismy ostatni poziom
                int lastCity = currentNode->path.back();
                int cost = matrix.getCost(lastCity, 0);
                if (cost != -1) {
                    int totalCost = currentNode->cost + cost;
                    if (totalCost < minCost) { // Jesli znaleziono lepsze rozwiązanie
                        minCost = totalCost;
                        bestPath = currentNode->path;
                        bestPath.push_back(0);
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if (!currentNode->visited[i] && matrix.getCost(currentNode->path.back(), i) != -1) {
                        Node* child = new Node(n);
                        child->level = currentNode->level + 1;
                        child->cost = currentNode->cost + matrix.getCost(currentNode->path.back(), i);
                        child->path = currentNode->path;
                        child->path.push_back(i);
                        copy(currentNode->visited, currentNode->visited + n, child->visited);
                        child->visited[i] = true;

                        // Wyliczanie dolnej granicy dla dziecka
                        child->bound = SymmetricCalculateBound(matrix, *child);

                        // Dodanie dziecka do kolejki, jesli jego granica jest lepsza
                        if (child->bound < minCost) {
                            queue.enqueue(child);
                        } else {
                            delete child; // Jesli granica jest gorsza, usuwamy wezel
                        }
                    }
                }
            }
        }
        delete currentNode;
    }

    return minCost;
}

// Metoda branch and bound DFS dla macierzy symetrycznej
int Algorithms::SymmetricBranchAndBoundDFS(const SymmetricMatrix &matrix, vector<int> &bestPath) {
    int n = matrix.getSize();
    int minCost = std::numeric_limits<int>::max();
    bestPath.clear();

    Stack stack;

    Node* root = new Node(n);
    root->path.push_back(0); // Start od miasta 0
    root->visited[0] = true;
    root->bound = SymmetricCalculateBound(matrix, *root); // Wyliczenie dolnej granicy
    stack.push(root);

    while (!stack.isEmpty()) {
        Node* currentNode = stack.pop();

        // Sprawdzenie, czy granica jest lepsza od najlepszego znalezionego rozwiazania
        if (currentNode->bound < minCost) {
            if (currentNode->level == n - 1) { // Jesli osiagnelismy ostatni poziom
                int lastCity = currentNode->path.back();
                int cost = matrix.getCost(lastCity, 0);
                if (cost != -1) {
                    int totalCost = currentNode->cost + cost;
                    if (totalCost < minCost) { // Jesli znaleziono lepsze rozwiazanie
                        minCost = totalCost;
                        bestPath = currentNode->path;
                        bestPath.push_back(0);
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if (!currentNode->visited[i] && matrix.getCost(currentNode->path.back(), i) != -1) {
                        Node* child = new Node(n);
                        child->level = currentNode->level + 1;
                        child->cost = currentNode->cost + matrix.getCost(currentNode->path.back(), i);
                        child->path = currentNode->path;
                        child->path.push_back(i);
                        std::copy(currentNode->visited, currentNode->visited + n, child->visited);
                        child->visited[i] = true;

                        // Wyliczanie dolnej granicy dla dziecka
                        child->bound = SymmetricCalculateBound(matrix, *child);

                        // Dodanie dziecka do stosu, jesli jego granica jest lepsza
                        if (child->bound < minCost) {
                            stack.push(child);
                        } else {
                            delete child; // Jesli granica jest gorsza, usuwamy wezel
                        }
                    }
                }
            }
        }
        delete currentNode;
    }

    return minCost;
}

// Metoda branch and bound best first search dla macierzy symetrycznej
int Algorithms::SymmetricBranchAndBoundBestFirstSearch(const SymmetricMatrix &matrix, vector<int> &bestPath) {
    int n = matrix.getSize();
    int minCost = std::numeric_limits<int>::max();
    bestPath.clear();

    PriorityQueue queue;

    Node* root = new Node(n);
    root->path.push_back(0);
    root->visited[0] = true;
    root->bound = SymmetricCalculateBound(matrix, *root);
    queue.enqueue(root);

    while (!queue.isEmpty()) {
        Node* currentNode = queue.dequeue();

        // Jesli dolna granica wezla jest wieksza od aktualnego minimalnego kosztu, pomijamy go
        if (currentNode->bound >= minCost) {
            delete currentNode;
            continue;
        }

        if (currentNode->level == n - 1) { // Jesli osiagnelismy ostatni poziom
            int lastCity = currentNode->path.back();
            int cost = matrix.getCost(lastCity, 0);
            if (cost != -1) {
                int totalCost = currentNode->cost + cost;
                if (totalCost < minCost) { // Jesli znaleziono lepsze rozwiazanie
                    minCost = totalCost;
                    bestPath = currentNode->path;
                    bestPath.push_back(0);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (!currentNode->visited[i] && matrix.getCost(currentNode->path.back(), i) != -1) {
                    Node* child = new Node(n);
                    child->level = currentNode->level + 1;
                    child->cost = currentNode->cost + matrix.getCost(currentNode->path.back(), i);
                    child->path = currentNode->path;
                    child->path.push_back(i);
                    std::copy(currentNode->visited, currentNode->visited + n, child->visited);
                    child->visited[i] = true;

                    // Wyliczanie dolnej granicy dla dziecka
                    child->bound = SymmetricCalculateBound(matrix, *child);

                    // Dodanie dziecka do kolejki priorytetowej, jesli jego granica jest lepsza
                    if (child->bound < minCost) {
                        queue.enqueue(child);
                    } else {
                        delete child; // Jesli granica jest gorsza, usuwamy wezel
                    }
                }
            }
        }

        delete currentNode;
    }

    return minCost;
}

// Funkcja do obliczania dolnej granicy
int Algorithms::AsymmetricCalculateBound(const Matrix& matrix, const Node& node) {
    int n = matrix.getSize();
    int lowerBound = node.cost;

    // Dodawanie minimalnych kosztow z niewykorzystanych krawedzi
    for (int i = 0; i < n; i++) {
        if (!node.visited[i]) {
            int minCost1 = numeric_limits<int>::max(); // Najtansza krawedz
            int minCost2 = numeric_limits<int>::max(); // Druga najtansza krawedz
            for (int j = 0; j < n; j++) {
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
    return lowerBound/2;
}

// Funkcja do obliczania dolnej granicy
int Algorithms::SymmetricCalculateBound(const SymmetricMatrix& matrix, const Node& node) {
    int n = matrix.getSize();
    int lowerBound = node.cost;

    for (int i = 0; i < n; i++) {
        if (!node.visited[i]) {
            int minCost = std::numeric_limits<int>::max();
            for (int j = 0; j < n; j++) {
                if (i != j && !node.visited[j]) {
                    int cost = matrix.getCost(i, j);
                    if (cost < minCost) {
                        minCost = cost;
                    }
                }
            }
            lowerBound += (minCost == std::numeric_limits<int>::max() ? 0 : minCost);
        }
    }

    return lowerBound;
}
