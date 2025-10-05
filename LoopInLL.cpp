#include <iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
                this -> data = data;
                this -> next = NULL;
        }
};

void print(Node* head) {
        Node* temp = head; 
        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}

bool checkForLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return false;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                        //loop present
                        return true;
                }
        }
        //fast NULL hogya
        return false;

}

Node* startingPointLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return NULL;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                       slow = head;
                       break;
                }
        }

        while(slow != fast) {
                slow = slow -> next;
                fast =fast -> next;
        }

        return slow;
        

}

Node* removeLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return NULL;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                       slow = head;
                       break;
                }
        }

        Node* prev = fast;
        while(slow != fast) {
                prev = fast;
                slow = slow -> next;
                fast =fast -> next;
        }
        prev -> next = NULL;
        return slow;
}

 
int main() {
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);
  Node* sixth = new Node(60);
  Node* seventh = new Node(70);
  Node* eighth = new Node(80);
  Node* ninth = new Node(90);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = seventh;
  seventh -> next = eighth;
  eighth -> next = ninth;
  ninth -> next = fourth;

  cout << "Loop is Present or not: " << checkForLoop(head) << endl;
  cout << "Starting Point of LOOP is: " << startingPointLoop(head) -> data << endl;
  removeLoop(head);
  print(head);
  cout << "Loop is Present or not " << checkForLoop(head) << endl;


  return 0;
}


// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if (head == NULL || head->next == NULL) {
//             return NULL;
//         }

//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast != NULL && fast->next != NULL) {
//             fast = fast->next->next;
//             slow = slow->next;

//             if (fast == slow) {
//                 slow = head;
//                 while (slow != fast) {
//                     slow = slow->next;
//                     fast = fast->next;
//                 }
//                 return slow;
//             }
//         }

//         return NULL;
//     }
// };
