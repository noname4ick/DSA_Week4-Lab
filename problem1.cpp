#include "iostream"
#include "forward_list"
#include "algorithm"

using namespace std;
//*****************Exercise 1*****************//
struct Node {
    int data;
    Node* next;
};
//*****************Exercise 2*****************//
void printList(Node* head) {
        Node *current = head;
        while(current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
}

//*****************Exercise 3*****************//
Node* createList(){
    Node* head = nullptr;
    for(int i = 100; i>=1; i--)
    {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }
    return head;
}
//*****************Exercise 4*****************//
Node* insertFront(Node *head, int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}


void insertMiddle(Node* head, int data) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;

    for (int i = 0; i < 49 && current->next != nullptr; i++) {
        current = current->next;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
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

//*****************Exercise 5*****************//
Node* deleteFront(Node* head) {
    if(head == nullptr){
        return nullptr;
    }
    Node* newHead = head->next;
    delete head;
    return newHead;
}

Node* deleteBack(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* current = head;

    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;

    return head;
}

void deleteMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = head;

    for (int i = 0; i < 49 && current->next != nullptr; i++) {
        current = current->next;
    }

    Node* nodeToDelete = current->next;

    if (nodeToDelete == nullptr) {
        return;
    }

    current->next = nodeToDelete->next;
    delete nodeToDelete;
}
//*****************Exercise 6*****************//
int sumList(Node* head){
    int sum = 0;
    Node *current = head;
    while(current !=nullptr){
        sum +=current->data;
        current=current->next;
    }
    return sum;
}

//*****************Exercise 7s*****************//
Node* reverseList(Node* head) {
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

int main() {
//*****************Exercise 1*****************//
Node node1;
Node node2;
Node node3;
Node node4;
Node node5;
node1.data = 10;
node1.next = &node2;
node2.data = 20;
node2.next = &node3;
node3.data = 30;
node3.next = &node4;
node4.data = 40;
node4.next = &node5;
node5.data = 50;
node5.next = nullptr;
//*****************Exercise 2*****************//
//printList(&node1);
//*****************Exercise 3*****************//
//printList(createList());
//*****************Exercise 4*****************//
Node* head = createList();
//Execrise 6 : Used list with 100 elements
// cout<<sumList(head);
//*****************Exercise 7*****************//
// head = reverseList(head);
// cout << "After reversing: ";
// printList(head);
//*****************Exercise 8*****************//
// forward_list<int> numbers = {10, 20, 30, 40, 50};

// cout << "Original list: ";
// for (int x : numbers) {
    // cout << x << " ";
// }
// cout << endl;

// Adding 5 to the beginning
// numbers.push_front(5);

// Finding 30 and insert 35 after it
// auto it = find(numbers.begin(), numbers.end(), 30);

// if (it != numbers.end()) {
    // numbers.insert_after(it, 35);
// }

// cout << "Final list: ";
// for (int x : numbers) {
    // cout << x << " ";
// }
// cout << endl;

//*****************Exercise 4&5*****************//
// head = insertFront(head, 0);
// cout << endl;
//
// insertBack(head, 0);
// cout << endl;
//
// insertMiddle(head, 0);
// cout << endl;
//
// cout<<"After the insertion" << endl;
// printList(head);
// cout << endl;
//
// head = deleteFront(head);
//
// cout << "After deleting front:" << endl;
// printList(head);
// cout << endl;
//
// head = deleteBack(head);
//
// cout << "After deleting back:" << endl;
// printList(head);
// cout << endl;
//
// deleteMiddle(head);
//
// cout << "After deleting middle:" << endl;
// printList(head);
// cout << endl;

    return 0;

}
