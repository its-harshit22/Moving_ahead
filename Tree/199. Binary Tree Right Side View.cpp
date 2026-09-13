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
class Solution {
public:

    void helper(TreeNode * node , int level,stack<int>&st){
        if(node==NULL)return;
        if(level==st.size()){
            st.push(node->val);
        }
        helper(node->right,level+1,st);
        helper(node->left,level+1,st);

    }

    vector<int> rightSideView(TreeNode* root) {
        stack<int>st;
        int level = 0;
        helper(root,level,st);
        int n = st.size();
        vector<int>ans(n);
        int size = n-1;
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            ans[size] = ele;
            size--;

        }
        return ans;
    }
};
