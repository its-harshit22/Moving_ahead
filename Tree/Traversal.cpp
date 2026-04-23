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

void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(TreeNode *root){
    if(root==NULL)return;

    postorder(root->left);
    postorder(root->right);
    cout<< root->data <<" ";
}

void preorder(TreeNode *root){
    if(root==NULL)return;
    cout<< root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

struct TreeNode

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    preorder(root);

    return 0;
}
