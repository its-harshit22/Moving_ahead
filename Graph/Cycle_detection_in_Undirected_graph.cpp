//It is using DFS
class Solution {
private:
    bool detect(int start,int parent, vector<int>& visited, vector<vector<int>>& adj) {
        

        visited[start] = 1;
        for(auto it : adj[start]){
            if(visited[it]==0){
                if(detect(it,start,visited,adj) == true){
                    return true;
                }
                
            }
            else if(it != parent){
                    return true;
                }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        // Build adjacency list from edge list
        vector<vector<int>> adj(V);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(detect(i,-1, visited, adj))
                    return true;
            }
        }

        return false;
    }
};
