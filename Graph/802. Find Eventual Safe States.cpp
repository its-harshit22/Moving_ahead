class Solution {
private:
    bool dfsCheck(int node,vector<int>&visited,vector<int>&pathV,vector<vector<int>>&graph,vector<int>&check){
        visited[node] = 1;
        pathV[node] = 1;
        check[node]= 0;
        for(auto it : graph[node]){
            if(!visited[it]){
                if(dfsCheck(it,visited,pathV,graph,check)==true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathV[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathV[node] = 0;
        return false;

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>visited(v,0);
        vector<int>check(v,0);
        vector<int>pathV(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfsCheck(i,visited,pathV,graph,check);
            }
        }
        vector<int>safeNode;
        for(int i=0;i<v;i++){
            if(check[i]){
                safeNode.push_back(i);
            }
        }
        return safeNode;

        
    }
};
