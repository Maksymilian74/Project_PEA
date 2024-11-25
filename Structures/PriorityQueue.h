/*
 * Klasa PriorityQueue odpowiedzialna jest za implementacje kolejki priorytetowej,
 * zapewnia potrzebne operacje dla tej kolejki.
 */

#ifndef PROJEKT_PEA_2_PRIORITYQUEUE_H
#define PROJEKT_PEA_2_PRIORITYQUEUE_H

#include "Node.h"

class PriorityQueue {
private:
    struct PriorityQueueNode {
        Node* data; // Dane przechowywane w wezle
        PriorityQueueNode* next; // Wskaznik na kolejny wezel

        PriorityQueueNode(Node* node);
        ~PriorityQueueNode();
    };

    PriorityQueueNode* head; // Wskaznik na poczatek kolejki
    int queueSize; // Rozmiar kolejki

public:
    PriorityQueue();
    ~PriorityQueue();

    // Dodaje element do kolejki w odpowiednim miejscu
    void enqueue(Node* node);

    // Usuwa element o najnizszym koszcie
    Node* dequeue();

    // Sprawdza, czy kolejka jest pusta
    bool isEmpty() const;

    // Zwraca liczbe elementow w kolejce
    int size() const;
};
#endif
