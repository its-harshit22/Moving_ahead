
class Solution {
public:
    void dfs(int node, vector<vector<int>>& ans,
             vector<int>& temp, vector<vector<int>>& graph,
             int target) {

        temp.push_back(node);

        if(node == target) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        for(auto it : graph[node]) {
            dfs(it, ans, temp, graph, target);
        }

        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;

        int n = graph.size();
        dfs(0, ans, temp, graph, n - 1);

        return ans;
    }
};
