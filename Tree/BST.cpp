#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* root = NULL;

void insert(int x)
{
    TreeNode* newNode = new TreeNode(x);

    if(root == NULL){
        root = newNode;
        return;
    }

    TreeNode* temp = root;

    while(true){
        if(x <= temp->data){
            if(temp->left == NULL){
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else{
            if(temp->right == NULL){
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

void find(int x){
    TreeNode* temp = root;

    while(temp != NULL){
        if(temp->data == x){
            cout<< "Found" <<endl;
            return;
        }
        else if(x < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    cout<< "Not Found" <<endl;

}

void deleteElement(int x){
    
    TreeNode* temp = root;
    TreeNode* parent = NULL;

    while(temp != NULL){
        if(temp->data == x){
            
            break;
        }
        else if(x < temp->data){
            parent = temp;
            temp = temp->left;
        }
        else{
            parent = temp;
            temp = temp->right;
        }
    }

    if(temp == NULL){
        cout<< "Node not found" <<endl;
        return;
    }

    
    if(temp->left == NULL && temp->right == NULL){
        if(parent == NULL){
            root = NULL;
        }
        else if(parent->left == temp){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
        delete(temp);
    }
    
    else if(temp->left == NULL || temp->right == NULL){
        TreeNode* child = (temp->left != NULL) ? temp->left : temp->right;

        if(parent == NULL){
            root = child;
        }
        else if(parent->left == temp){
            parent->left = child;
        }
        else{
            parent->right = child;
        }
        delete(temp);
    }
    
    else{
        TreeNode* successor = temp->right;
        TreeNode* successorParent = temp;

        while(successor->left != NULL){
            successorParent = successor;
            successor = successor->left;
        }

        temp->data = successor->data;

        if(successorParent->left == successor){
            successorParent->left = successor->right;
        }
        else{
            successorParent->right = successor->right;
        }
        delete(successor);
    }
}

int main(){
    insert(10);
    insert(5);
    insert(15);
    find(6);
    deleteElement(5);
    return 0;
}
