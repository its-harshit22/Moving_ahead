#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    Node* getHead() {
        return head;
    }void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    } 
    bool detect_cycle(){
      Node* slow = head;
      Node* fast = head;
      while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        if(slow==fast){
            return true;
        }
      }return false;
    }
};

int main() {
    LinkedList ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    
    Node* newNode1 = new Node(5);
    Node* newNode2 = new Node(6);

    Node* temp = ll.getHead()->next->next; 
    temp->next = newNode1;
    newNode1->next = newNode2;
    ll.print();
    
    
    newNode2->next = temp;  // cycle created (6 -> 1)
    cout<< ll.detect_cycle() <<endl;

    cout << "Cycle created successfully!" << endl;

    return 0;
}
