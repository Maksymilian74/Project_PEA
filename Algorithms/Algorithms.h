/*
 * Klasa Algorithms odpowiedzialna jest za implementacje trzech
 * algorytmow rozwiazywania problemu komiwojazera oraz metody pomocniczej
 * do obliczania granicy
 */

#ifndef PROJEKT_PEA_2_ALGORITHMS_H
#define PROJEKT_PEA_2_ALGORITHMS_H

#include "../Structures/Matrix.h"
#include "../Structures/SymmetricMatrix.h"
#include "../Structures/Node.h"
#include "../Structures/Stack.h"
#include "../Structures/Queue.h"
#include <vector>

using namespace std;

class Algorithms {
public:
    // Metoda branch and bound BFS dla macierzy asymetrycznej
    int AsymmetricBranchAndBoundBFS(const Matrix& matrix, vector<int>& bestPath);

    // Metoda branch and bound DFS dla macierzy asymetrycznej
    int AsymmetricBranchAndBoundDFS(const Matrix& matrix, vector<int>& bestPath);

    // Metoda branch and bound best first search dla macierzy asymetrycznej
    int AsymmetricBranchAndBoundBestFirstSearch(const Matrix& matrix, vector<int>& bestPath);

    // Metoda branch and bound BFS dla macierzy symetrycznej
    int SymmetricBranchAndBoundBFS(const SymmetricMatrix& matrix, vector<int>& bestPath);

    // Metoda branch and bound DFS dla macierzy symetrycznej
    int SymmetricBranchAndBoundDFS(const SymmetricMatrix& matrix, vector<int>& bestPath);

    // Metoda branch and bound best first search dla macierzy symetrycznej
    int SymmetricBranchAndBoundBestFirstSearch(const SymmetricMatrix& matrix, vector<int>& bestPath);
private:
    // Metoda odpowiedzialna za obliczanie granic dla macierzy asymetrycznej
    int AsymmetricCalculateBound(const Matrix& matrix, const Node& node);

    // Metoda odpowiedzialna za obliczanie granic dla macierzy symetrycznej
    int SymmetricCalculateBound(const SymmetricMatrix& matrix, const Node& node);
};


#endif
