/*
 * Klasa Queue odpowiedzialna jest za implementacje kolejki FIFO,
 * zapewnia potrzebne operacje dla kolejki.
 */

#ifndef PROJEKT_PEA_2_QUEUE_H
#define PROJEKT_PEA_2_QUEUE_H

#include "Node.h"

class Queue {
private:
    struct QueueNode {
        Node* data;  // Wskaznik na obiekt Node
        QueueNode* next;  // Wskaznik na kolejny wezel w kolejce

        QueueNode(Node* node);  // Konstruktor wezla kolejki
        ~QueueNode();  // Destruktor wezla kolejki
    };

    QueueNode* front;  // Wskaznik na poczatek kolejki
    QueueNode* rear;   // Wskaznik na koniec kolejki
    int queueSize;     // Rozmiar kolejki

public:
    // Konstruktor kolejki
    Queue();

    // Destruktor kolejki
    ~Queue();

    // Metoda dodajaca element do kolejki
    void enqueue(Node* node);

    // Metoda usuwajaca element z kolejki
    Node* dequeue();

    // Metoda sprawdzajaca, czy kolejka jest pusta
    bool isEmpty() const;

    // Metoda zwracajaca liczbe elementow w kolejce
    int size() const;
};

#endif
