#include <bits/stdc++.h>
using namespace std;

// Definition for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    // Function to delete tail node of linked list
    Node* deleteTail(Node* head) {
        // If list is empty or has one node
        if (head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }

        // Traverse to the second last node
        Node* curr = head;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        // Delete tail node
        delete curr->next;
        curr->next = NULL;

        // Return updated head
        return head;
    }
};

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Solution obj;
    head = obj.deleteTail(head);

    // Print list after deletion
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
