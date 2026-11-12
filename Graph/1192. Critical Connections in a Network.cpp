class Solution {

private:

    int timer = 1;

    void dfs(int node,int parent,vector<int>&vist,vector<int>adj[],int tin[],int low[],vector<vector<int>>&bridges){
        vist[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node]){
            if(it == parent)continue;
            if(!vist[it]){
                dfs(it,node,vist,adj,tin,low,bridges);
                low[node] = min(low[node],low[it]);

                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
        
    }


public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vist(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0,-1,vist,adj,tin,low,bridges);

        return bridges;


    }
};
