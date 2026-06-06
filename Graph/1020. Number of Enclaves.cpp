class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j] == 1){
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        int delr[] = {-1,0,1,0}; 
        int delc[] = {0,1,0,-1}; 
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r +delr[i];
                int nc = c + delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]==0 && grid[nr][nc]==1){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }

        } 
        int counter = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    counter++;
                }
            }
        }
        return counter; 
    }
};
