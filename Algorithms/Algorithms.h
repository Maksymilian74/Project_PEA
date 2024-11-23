/*
 * Klasa Algorithms odpowiedzialna jest za implementacje trzech
 * algorytmow rozwiazywania problemu komiwojazera oraz metody pomocniczej
 * do obliczania granicy
 */

#ifndef PROJEKT_PEA_2_ALGORITHMS_H
#define PROJEKT_PEA_2_ALGORITHMS_H

#include "../Structures/Matrix.h"
#include "../Structures/Node.h"
#include "../Structures/Stack.h"
#include "../Structures/Queue.h"
#include <vector>

using namespace std;

class Algorithms {
public:
    // Metoda branch and bound BFS
    int branchAndBoundBFS(const Matrix& matrix, vector<int>& bestPath);

    // Metoda branch and bound DFS
    int branchAndBoundDFS(const Matrix& matrix, vector<int>& bestPath);

    // Metoda branch and bound best first search
    int branchAndBoundBestFirstSearch(const Matrix& matrix, vector<int>& bestPath);
private:
    // Metoda odpowiedzialna za obliczanie granic
    int calculateBound(const Matrix& matrix, const Node& node);
};


#endif
