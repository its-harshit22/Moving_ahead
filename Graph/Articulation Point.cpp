class Solution {
    
    
  public:
  
    int timer = 1;
  
    void dfs(int node,int parent,vector<int>&vist,vector<int>adj[],int tin[],int low[],int mark[]){
        vist[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it==parent)continue;
            if(!vist[it]){
                dfs(it,node,vist,adj,tin,low,mark);
                low[node] = min(low[it],low[node]);
                if(low[it]>=tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child>1 && parent==-1){
            mark[node] = 1;
        }
    }
  
  
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>adjList[V];
        for(int i=0;i<n;i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vist(V,0);
        
        int tin[V];
        int low[V];
        int mark[V] = {0};
        vector<int>ans;
        
        for(int i=0;i<V;i++){
            if(!vist[i]){
                dfs(i,-1,vist,adjList,tin,low,mark);
            }
        }
        bool check = true;
        for(int i=0;i<V;i++){
            if(mark[i]==1){ans.push_back(i);check = false;}
        }
        if(check)ans.push_back(-1);
        
        return ans;
    }
};
