 void reverse(){
        Node * prev = NULL;
        while(head != NULL){
            Node* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head = prev;
    }
