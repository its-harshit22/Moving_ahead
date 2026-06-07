class Solution {
    bool dfs(int start,vector<int>&color,vector<vector<int>>& graph,int col){
        color[start] = col;
        for(auto it:graph[start]){
            if(color[it]==-1){
                if(dfs(it,color,graph,!col)==false){
                    return false;
                }
            }
            else if(color[it]==color[start]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,color,graph,0)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
