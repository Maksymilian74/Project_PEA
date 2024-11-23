#ifndef PROJEKT_PEA_2_NODE_H
#define PROJEKT_PEA_2_NODE_H

#include <vector>

using namespace std;

class Node {
public:
    int level;  // Poziom drzewa
    int cost;  // Aktualny koszt trasy
    int bound;  // Dolna granica kosztu
    vector<int> path;  // Odwiedzone miasta
    bool* visited;  // Tablica odwiedzonych miast
    int size;  // Rozmiar problemu

    // Konstruktor
    Node(int n);

    // Destruktor
    ~Node();
};


#endif
