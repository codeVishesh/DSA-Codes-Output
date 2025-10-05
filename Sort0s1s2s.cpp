#include <iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
                this->data = data;
                this->next = NULL;
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

void sortZeroOneTwo(Node* &head) {
        //step1: find count of zeroes, ones and twos
        int zero = 0;
        int one = 0;
        int two = 0;

        Node* temp = head;
        while(temp != NULL) {
                if(temp -> data == 0)
                        zero++;
                else if(temp -> data == 1)
                        one++;
                else if(temp -> data == 2)
                        two++;
                temp = temp -> next;
        }

        //step2: fill 0, 1 and 2s in the original ll
        temp = head;
                // fill zeroes
                while(zero--) {
                        temp -> data = 0;
                        temp = temp -> next;
                }

                //fill ones
                while(one--) {
                        temp -> data = 1;
                        temp = temp -> next;
                }

                //fill 2s
                while(two--) {
                        temp -> data = 2;
                        temp = temp -> next;
                }
}

int main() {
  Node* head = new Node(2);
  Node* second = new Node(2);
  Node* third = new Node(1);
  Node* fourth = new Node(1);
  Node* fifth = new Node(0);
  Node* sixth = new Node(0);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;

  cout << "input LL: ";
  print(head);

  sortZeroOneTwo(head);
  print(head);

  return 0;
}
