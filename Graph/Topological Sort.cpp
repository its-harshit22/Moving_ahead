class Solution {
    private:
    void dfs(int node,vector<int>&visited,vector<vector<int>>&adj,stack<int>&st){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj,st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>visited(V,0);
        vector<vector<int>>adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};
