class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1)return -1;

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 1;

        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        int delr[8] = {-1,-1,-1,0,1,1,1,0};
        int delc[8] = {-1,0,1,1,1,0,-1,-1};

        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int wt = q.front().first;
            q.pop();

            for(int i=0;i<8;i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc]==0 && (dist[nr][nc]>wt + 1)){
                    dist[nr][nc] = wt + 1;
                    q.push({wt+1,{nr,nc}});
                }
            }
        }

        if(dist[n-1][m-1]==1e9)return -1;
        return dist[n-1][m-1];


    }
};
