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
    LinkedList() {
        head = tail = NULL;
    }

    // Insert at back
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print list
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 🔹 Linked List → Number
    int listToNum() {
        int num = 0;
        Node* temp = head;

        while (temp != NULL) {
            num = num * 10 + temp->data;
            temp = temp->next;
        }
        return num;
    }

    // 🔹 Number → Linked List
    void numToList(int num) {
        if (num == 0) {
            push_back(0);
            return;
        }

        int digits[20];
        int idx = 0;

        // store digits in reverse
        while (num > 0) {
            digits[idx++] = num % 10;
            num /= 10;
        }

        // insert in correct order
        for (int i = idx - 1; i >= 0; i--) {
            push_back(digits[i]);
        }
    }
};

int main() {
    LinkedList l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    cout << "Linked List: ";
    l1.print();

    int number = l1.listToNum();
    cout << "List to Number: " << number << endl;

    LinkedList l2;
    l2.numToList(4567);

    cout << "Number to List: ";
    l2.print();

    return 0;
}
