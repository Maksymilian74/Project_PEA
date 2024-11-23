/*
 * Klasa Stack odpowiedzialna jest za implementacje stosu,
 * zapewnia potrzebne operacje.
 */

#ifndef PROJEKT_PEA_2_STACK_H
#define PROJEKT_PEA_2_STACK_H

#include "Node.h"

class Stack {
private:
    struct StackNode {
        Node* data;
        StackNode* next;

        StackNode(Node* node);
        ~StackNode();
    };

    StackNode* top;  // Wskaznik na szczyt stosu
    int stackSize;   // Rozmiar stosu

public:
    // Konstruktor
    Stack();

    // Destruktor
    ~Stack();

    // Dodanie elementu na stos
    void push(Node* node);

    // Usuniecie elementu ze stosu
    Node* pop();

    // Sprawdzenie szczytu stosu
    Node* peek() const;

    // Sprawdzenie, czy stos jest pusty
    bool isEmpty() const;

    // Pobranie rozmiaru stosu
    int size() const;
};


#endif
