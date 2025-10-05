#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

bool CircularOrNot(Node* head) {
    if (head == NULL) {
        return false; // An empty list is not considered circular.
    }

    Node* slow = head;
    Node* fast = head;

    // Traverse the list with two pointers.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, then the list is circular.
        if (slow == fast) {
            return true;
        }
    }

    // If the end of the list is reached without meeting, it is not circular.
    return false;
}

void Print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;

    cout << "Is the list circular? " << CircularOrNot(head)<< endl;
    // cout << "Is the list circular? " << (CircularOrNot(head) ? "Yes" : "No") << endl;

    return 0;
}
