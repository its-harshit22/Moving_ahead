/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Stack Based Approach....
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        TreeNode * cur = root;
        stack<TreeNode *>st;
        st.push(cur);
        while(!st.empty()){
            cur = st.top();
            st.pop();
            if(cur->right!=NULL)st.push(cur->right);
            if(cur->left!=NULL)st.push(cur->left);
            if(!st.empty())cur -> right = st.top();
            cur->left = NULL;
        }
    }
};

//Recursive Mooris Algorithm 


class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};

