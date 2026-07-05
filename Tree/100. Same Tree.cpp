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
    bool checker(TreeNode* p, TreeNode* q) {
        
        
        if(p == NULL && q == NULL)
            return true;

        // one null and one not null
        if(p == NULL || q == NULL)
            return false;

        // values not equal
        if(p->val != q->val)
            return false;

        // check left and right subtree
        return checker(p->left, q->left) &&
               checker(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checker(p, q);
    }
};
