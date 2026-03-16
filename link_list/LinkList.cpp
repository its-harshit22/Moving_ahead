#include <iostream>
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
    Node* head;
    Node* tail;

public:
    LinkedList() 
    {
        head = tail = NULL;
    }

    void push_front(int val) 
    {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void Pop_Front() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;
    }

    void Pop_Back() {
        if (head == NULL) return;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

  void insert(int val, int index) {
    if (index == 0) {
        push_front(val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;

    for (int i = 1; i < index; i++) {
        if (temp == NULL) return; 
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) { // agar end me insert hua
        tail = newNode;
    }
}
     //Search()
     void Search(int key) {
        Node* temp = head;
        int tracker = 1;
        while(temp!=NULL){
            if(temp->data == key){
                cout<< "Key is found "<<tracker<<" node" <<endl;
                return;
            }
            else{
                temp = temp->next;
                tracker++;
            }
        }
        cout<< "Not Found!" <<endl;
        return;

     }
     //Deletion from position
     void delete_from_pos(int index){
        if(index==0){
            Pop_Front();
        }
        Node *temp = head;
        Node *temp2 = temp->next;
        for(int i=1;i<index;i++)
        {
            if(temp2==NULL ){
                cout<< "Invalid" <<endl;
                return;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp->next = temp->next->next;
        free(temp2);
    }
};

int main() {
    LinkedList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.insert(9,4);
    ll.print();
    ll.delete_from_pos(5);
    ll.print();
    return 0;
}
