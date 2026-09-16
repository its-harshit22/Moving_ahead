/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:

    void know_your_parent(Node* root, unordered_map<Node*, Node*>& parent_track) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr_node = q.front();
            q.pop();
            if (curr_node->left != NULL) {
                parent_track[curr_node->left] = curr_node;
                q.push(curr_node->left);
            }
            if (curr_node->right != NULL) {
                parent_track[curr_node->right] = curr_node;
                q.push(curr_node->right);
            }
        }
    }

    int minTime(Node* root, int target) {
        // Step 1: find the target node
        queue<Node*> q;
        q.push(root);
        Node* tar = NULL;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* cur = q.front();
                q.pop();
                if (cur->data == target) {
                    tar = cur;
                }
                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
        }

        // Step 2: build parent map
        unordered_map<Node*, Node*> parent_track;
        know_your_parent(root, parent_track);

        // Step 3: BFS burning simulation from target
        unordered_map<Node*, bool> visited;
        queue<Node*> que;
        que.push(tar);
        visited[tar] = true;

        int dist = 0;
        while (!que.empty()) 
        {
            int size = que.size();
            bool burnedSomething = false;

            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();

                if (node->left != NULL && !visited[node->left]) {
                    visited[node->left] = true;
                    que.push(node->left);
                    burnedSomething = true;
                }
                if (node->right != NULL && !visited[node->right]) {
                    visited[node->right] = true;
                    que.push(node->right);
                    burnedSomething = true;
                }
                if (parent_track[node] != NULL && !visited[parent_track[node]]) {
                    visited[parent_track[node]] = true;
                    que.push(parent_track[node]);
                    burnedSomething = true;
                }
            }

            if (burnedSomething) dist++;
        }

        return dist;
    }
};
