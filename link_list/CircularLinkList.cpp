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

class Circular_List {
private:
    Node* head;
public:
    Circular_List() {
        head = NULL;
    }

    void push_at_head(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // points to itself
        } else {
            Node* temp = head;
            // go to last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void push_at_end(int val) {
        Node* newNode = new Node(val);
         if (head == NULL) {
            head = newNode;
            newNode->next = head;  // points to itself
        }
        else{
            Node*temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }

    }

    void print() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
    void delete_at_head(){
        if(head==NULL){
            cout<< "Empty list" <<endl;
            return;
        }
        if(head->next == head){
            delete(head);
            return;
        }
        Node* temp1 = head;
        Node* temp2 = head;
        head = head->next;
        while(temp2->next != temp1){
            temp2 = temp2->next;
        }
        temp2->next = head;
        delete(temp1);

    }
};

int main() {
    Circular_List Cl;
    Cl.push_at_head(1);
    Cl.push_at_head(2);
    Cl.push_at_head(3);
    Cl.push_at_head(4);
    Cl.push_at_end(5);
    Cl.delete_at_head();
    Cl.delete_at_head();
    Cl.print();
    return 0;
}
