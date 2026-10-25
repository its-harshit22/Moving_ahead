class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        int n = mat.size();
        int m = mat[0].size();
        if(mat[src[0]][src[1]]==0 || mat[dest[0]][dest[1]]==0)return -1;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[src[0]][src[1]] = 0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src[0],src[1]}});
        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int wt = q.front().first;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr >= 0 && nr < n && nc >=0 && nc < m && mat[nr][nc]==1 && (dist[nr][nc] > wt + 1)){
                    dist[nr][nc] = wt + 1;
                    q.push({wt+1,{nr,nc}});
                }
            }
        }
        if(dist[dest[0]][dest[1]] == 1e9)return -1;
        return dist[dest[0]][dest[1]];
        
    
    }
};
