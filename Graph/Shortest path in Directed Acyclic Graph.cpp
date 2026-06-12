class Solution {
  private:
    void topoSort(int node, vector<int>& vis, stack<int>& st,
                  vector<vector<pair<int,int>>>& adj) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            int v = it.first;

            if(!vis[v]) {
                topoSort(v, vis, st, adj);
            }
        }

        st.push(node);
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                topoSort(i, vis, st, adj);
            }
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0;

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(dist[node] != 1e9) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;

                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
