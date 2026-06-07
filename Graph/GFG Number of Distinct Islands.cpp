// User function Template for C++

class Solution {
    private:
    void bfs(int i, int j, int n, int m,
             vector<vector<int>>& visited,
             vector<vector<int>>& grid,
             set<vector<pair<int,int>>>& st) {

        visited[i][j] = 1;

        queue<pair<pair<int,int>,pair<int,int>>>que;
        que.push({{i, j},{i,j}});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<pair<int,int>>temp;

        while (!que.empty()) {
            int row = que.front().first.first;
            int col = que.front().first.second;
            int baser = que.front().second.first;
            int basec = que.front().second.second;
            temp.push_back({baser-row,basec-col});
            que.pop();

            for (int k = 0; k < 4; k++) {
                int neighbourRow = row + delRow[k];
                int neighbourCol = col + delCol[k];

                if (neighbourRow >= 0 && neighbourRow < n &&
                    neighbourCol >= 0 && neighbourCol < m &&
                    !visited[neighbourRow][neighbourCol] &&
                    grid[neighbourRow][neighbourCol] == 1) {

                    visited[neighbourRow][neighbourCol] = 1;
                    que.push({{neighbourRow, neighbourCol},{baser,basec}});
                }
            }
        }
            st.insert(temp);
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    bfs(i,j,n,m,visited,grid,st);
                }
            }
        }
        return st.size();
    }
};
