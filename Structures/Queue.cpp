#include "Queue.h"
#include <stdexcept>

// Konstruktor wewnetrznego wezla kolejki
Queue::QueueNode::QueueNode(Node* node) : data(node), next(nullptr) {}

// Destruktor wewnetrznego wezla kolejki
Queue::QueueNode::~QueueNode() {
    data = nullptr;
}

// Konstruktor kolejki
Queue::Queue() : front(nullptr), rear(nullptr), queueSize(0) {}

// Destruktor kolejki
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Metoda odpowiedzialna za dodanie wezla do kolejki
void Queue::enqueue(Node* node) {
    if (!node) {
        throw std::invalid_argument("Null pointer cannot be enqueued");
    }
    QueueNode* newNode = new QueueNode(node);
    if (rear) {
        rear->next = newNode;
    }
    rear = newNode;
    if (!front) {
        front = rear;
    }
    ++queueSize;
}

// Metoda odpowiedzialna za usuniecie wezla z kolejki
Node* Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Attempted to dequeue from an empty queue");
    }
    QueueNode* temp = front;
    Node* node = temp->data;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
    --queueSize;
    return node;
}

// Metoda sprawdzajaca, czy kolejka jest pusta
bool Queue::isEmpty() const {
    return front == nullptr;
}

// Metoda zwracajaca rozmiar kolejki
int Queue::size() const {
    return queueSize;
}
