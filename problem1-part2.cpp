
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
//***********************Exercise 9*******************//
struct Node {
    int data;
    Node* next;
};

Node* createList() {
    Node* head = nullptr;

    for (int i = 1000; i >= 1; i--) {
        Node* newNode = new Node{i, head};
        head = newNode;
    }

    return head;
}

Node* insertFront(Node* head, int data) {
    Node* newNode = new Node{data, head};
    return newNode;
}

Node* insertMiddle(Node* head, int data) {
    if (head == nullptr) {
        return new Node{data, nullptr};
    }

    Node* current = head;

    for (int i = 1; i < 500 && current->next != nullptr; i++) {
        current = current->next;
    }

    Node* newNode = new Node{data, current->next};
    current->next = newNode;

    return head;
}

Node* insertBack(Node* head, int data) {
    Node* newNode = new Node{data, nullptr};

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    const int repetitions = 1000;
    long long frontTotal = 0;
    long long middleTotal = 0;
    long long backTotal = 0;

    for (int i = 0; i < repetitions; i++) {
        Node* head = createList();

        auto start = steady_clock::now();
        head = insertFront(head, 0);
        auto stop = steady_clock::now();

        frontTotal += duration_cast<nanoseconds>(
            stop - start
        ).count();

        deleteList(head);
    }

    for (int i = 0; i < repetitions; i++) {
        Node* head = createList();

        auto start = steady_clock::now();
        head = insertMiddle(head, 0);
        auto stop = steady_clock::now();

        middleTotal += duration_cast<nanoseconds>(
            stop - start
        ).count();

        deleteList(head);
    }

    for (int i = 0; i < repetitions; i++) {
        Node* head = createList();

        auto start = steady_clock::now();
        head = insertBack(head, 0);
        auto stop = steady_clock::now();

        backTotal += duration_cast<nanoseconds>(
            stop - start
        ).count();

        deleteList(head);
    }

    cout << "Average insertion time "
         << repetitions << " repetitions:\n";

    cout << "Front:  "
         << frontTotal / repetitions << " ns\n";

    cout << "Middle: "
         << middleTotal / repetitions << " ns\n";

    cout << "Back:   "
         << backTotal / repetitions << " ns\n";

    return 0;
}
