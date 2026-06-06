class Solution {
    private:
    void dfs(int r,int c,vector<vector<int>> &visited,vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        visited[r][c] = 1;
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = r + delr[i];
            int nc = c + delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]==0 && board[nr][nc]=='O'){
                dfs(nr,nc,visited,board);
            }
        }


    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if((i==0 || i ==n-1 || j == 0 || j == m-1) && board[i][j] == 'O' && visited[i][j] == 0)
                {
                    dfs(i,j,visited,board);

                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(visited[i][j]==0){
                    board[i][j] = 'X';
                }
            }
        }

    }
};
