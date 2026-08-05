class Solution {
public:
    void helper(int i,vector<vector<int>>& adj , vector<int>& visited){
        visited[i] = 1;
        for(auto val : adj[i]){
            if(visited[val]==0){
                helper(val,adj,visited);
            }
        }
    }
    void helper1(int i,vector<vector<int>>& adj , vector<int>& visited,bool & flag){
        visited[i] = 2;
        for(auto val : adj[i]){
            if(visited[val]==0){
                helper1(val,adj,visited,flag);
            }
            if(visited[val]==1){
                flag = true;
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> visited(n, 0);
        vector<int>ans;

        // Adjacency list
        vector<vector<int>> adj(n);
        for (auto &edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }
        helper(k,adj,visited);
        bool flag = false;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                helper1(i,adj,visited,flag);
            }
        }
        if(flag==true){
            for(int i = 0;i<n;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==2){
                ans.push_back(i);
            }
        }
        
        
        return ans;

        
    }
};
