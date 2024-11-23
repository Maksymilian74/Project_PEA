#include "Stack.h"
#include <stdexcept>

using namespace std;

// Implementacja wezla stosu
Stack::StackNode::StackNode(Node* node) : data(node), next(nullptr) {}

// Destruktor wezla stosu
Stack::StackNode::~StackNode() {
    data = nullptr;
}

// Konstruktor stosu
Stack::Stack() : top(nullptr), stackSize(0) {}

// Destruktor stosu
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Dodanie elementu na stos
void Stack::push(Node* node) {
    if (!node) {
        throw invalid_argument("Null pointer cannot be pushed onto the stack");
    }
    StackNode* newNode = new StackNode(node);
    newNode->next = top;
    top = newNode;
    ++stackSize;
}

// Usuniecie elementu ze stosu
Node* Stack::pop() {
    if (isEmpty()) {
        throw out_of_range("Attempted to pop from an empty stack");
    }
    StackNode* temp = top;
    Node* node = temp->data;
    top = top->next;
    delete temp;
    --stackSize;
    return node;
}

// Sprawdzenie szczytu stosu
Node* Stack::peek() const {
    if (isEmpty()) {
        throw out_of_range("Stos jest pusty");
    }
    return top->data;
}

// Sprawdzenie, czy stos jest pusty
bool Stack::isEmpty() const {
    return top == nullptr;
}

// Pobranie rozmiaru stosu
int Stack::size() const {
    return stackSize;
}
