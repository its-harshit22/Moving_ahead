/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  void helper(Node* node,vector<int>&list,vector<vector<int>>&ans){
      if(node!=NULL){
          list.push_back(node->data);
      }
      if(node->left ==NULL && node->right == NULL){
          ans.push_back(list);
          list.pop_back();
          return ;
      }
      if(node->left!=NULL)helper(node->left,list,ans);
      if(node->right!=NULL)helper(node->right,list,ans);
      list.pop_back();
  }
  
    vector<vector<int>> paths(Node* root) {
        vector<vector<int>>ans;
        vector<int>list;
        helper(root,list,ans);
        return ans;
        
    }
};
