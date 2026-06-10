class Solution {
    private:
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            topo.push_back(n);
            for(auto it : adj[n]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
        
    }
};
