//Doubly Linked List....
#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class Doubly_Linked_List{
    private:
    Node * head;
    public:
    Doubly_Linked_List(){
        head = NULL;
    }
    void push_front(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = n;
        }
        else{
            n->next = head;
            head->prev = n;
            head = n;
        }
        
    }
     void pop_front() {
        if (head == NULL) {   
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {   // check if list still has nodes
            head->prev = NULL;
        }
        delete temp;
    }
    void push_back(int val){
        Node * n = new Node(val);
        if(head == NULL){
            head = n;
        }
        else{
            Node*temp = head;
            while(temp->next !=NULL){
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
            // delete(temp);
        }
       

        

} void pop_back() {
    if (head == NULL) {   // empty list
        cout << "List is empty\n";
        return;
    }
    if (head->next == NULL) {  // only one node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

   void print(){
    Node * temp = head;

    cout << "Forward: ";
    while(temp != NULL){
        cout << temp->data << "-> ";
        if(temp->next == NULL) break;  
        temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "Backward: ";
    while(temp != NULL){
        cout << temp->data << "-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}
     
                                              

};
int main(){
    Doubly_Linked_List ddl;
    ddl.push_front(1); 
    ddl.push_front(2); 
    ddl.push_front(3); 
    ddl.push_front(4); 
    ddl.push_back(5); 
    ddl.pop_back(); 
    ddl.print(); 
     return 0; 
}
