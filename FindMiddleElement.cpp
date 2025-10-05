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


Node* getMiddle(Node* &head){ 
    //if LL is empty
    if(head==NULL){
        return head;
    }
    //single node in LL
    if(head->next == NULL){
        return head;
    }
    //creation of 2 pointers
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast!= NULL){
        //move first step
        fast = fast->next;
        if(fast !=NULL){
            // total 2 steps
            fast = fast->next; //move 1 step
            slow = slow->next; //move 1 step
        }
    }
    return slow; // as slow will be on the middle element
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

    head-> next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    cout << "The Middle element is: " << getMiddle(head)->data << endl;
    
    return 0;
}
