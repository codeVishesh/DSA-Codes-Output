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

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* reverseWithRecursion(Node* &prev, Node* &curr){
    //base case
    if(curr==NULL){
        return prev;
    }
    Node* forward = curr->next;
    curr->next = prev;

    //recursive call
    return reverseWithRecursion(curr,forward);
}

Node* reverseWithIteration(Node* &prev, Node* &curr){
    while(curr!=NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev; // new head of the reverse LL
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
    Node* head = NULL; 
    Node* tail = NULL;
    
    insertAtTail(head, tail, 1); 
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    Print(head); 

    Node* prev = NULL;
    Node* curr = head;

    // cout << endl;

    // head = reverseWithRecursion(prev,curr);
    // Print(head);

    cout << endl;

    head = reverseWithIteration(prev,curr);
    Print(head);
    
    return 0;
}
