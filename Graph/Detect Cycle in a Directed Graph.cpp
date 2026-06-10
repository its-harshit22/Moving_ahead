class Solution {
  private:
    bool dfsCheck(int node, vector<vector<int>>& adj,
                  vector<int>& visited, vector<int>& pathVisited) {
        
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto val : adj[node]) {
            
            if (!visited[val]) {
                if (dfsCheck(val, adj, visited, pathVisited)) 
                    return true;
            }
            else if (pathVisited[val]) {
                return true;
            }
        }

        pathVisited[node] = 0;
        return false;
    }

  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);   // directed graph
        }

        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCheck(i, adj, visited, pathVisited))
                    return true;
            }
        }

        return false;
    }
};
