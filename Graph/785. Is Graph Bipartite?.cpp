//There may be components and for them we use the check function if not u can write all the things inside the main as simple BFS algorithm with the color array or vector it is your choice 
class Solution {
    private:
    bool check(int start,vector<int>&color,vector<vector<int>>& graph){
        int n = graph.size();
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto val : graph[node]){
                if(color[val] == -1){
                    color[val] = !color[node];
                    q.push(val);
                }
                else if(color[val]==color[node]){
                    return 0;
                }
            }
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,color,graph)==0){
                    return 0;
                }
            }
        }

        return 1;
    }
};
