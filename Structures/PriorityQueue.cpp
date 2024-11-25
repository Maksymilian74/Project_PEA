#include "PriorityQueue.h"
#include <stdexcept>

using namespace std;

// Konstruktor wezla kolejki priorytetowej
PriorityQueue::PriorityQueueNode::PriorityQueueNode(Node* node) : data(node), next(nullptr) {}

// Destruktor wezla kolejki priorytetowej
PriorityQueue::PriorityQueueNode::~PriorityQueueNode() {
    data = nullptr; // Usuwanie wezla
}

// Konstruktor kolejki priorytetowej
PriorityQueue::PriorityQueue() : head(nullptr), queueSize(0) {}

// Destruktor kolejki priorytetowej
PriorityQueue::~PriorityQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Metoda dodajaca element do kolejki w odpowiednim miejscu
void PriorityQueue::enqueue(Node* node) {
    if (!node) {
        throw invalid_argument("Null pointer cannot be enqueued");
    }

    PriorityQueueNode* newNode = new PriorityQueueNode(node);

    if (!head || node->bound < head->data->bound) {
        // Dodanie na poczatek kolejki, jesli kolejka jest pusta lub nowy element ma nizsza granice
        newNode->next = head;
        head = newNode;
    } else {
        // Szukanie miejsca w kolejce
        PriorityQueueNode* current = head;
        while (current->next && current->next->data->bound <= node->bound) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    queueSize++;
}

// Metoda usuwajaca element o najnizszym koszcie
Node* PriorityQueue::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Attempted to dequeue from an empty priority queue");
    }
    PriorityQueueNode* temp = head;
    Node* node = temp->data;
    head = head->next;
    delete temp;
    queueSize--;
    return node;
}

// Metoda sprawdzajaca, czy kolejka jest pusta
bool PriorityQueue::isEmpty() const {
    return head == nullptr;
}

// Metoda zwracajaca liczbe elementow w kolejce
int PriorityQueue::size() const {
    return queueSize;
}

