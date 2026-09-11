class Solution {
public:

    int height(TreeNode * root){
        if(root==NULL)return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh == -1 || rh == -1 )return -1;
        if(abs(rh-lh)>1)return -1;
        return 1 + max(lh,rh);
    }


    bool isBalanced(TreeNode* root) {
        int count = height(root);

        return count != -1;
    }
};
