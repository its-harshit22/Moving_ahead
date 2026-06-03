//Flood fill algorithm
class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>&image,vector<vector<int>> &ans,int color,int iniCol){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow < n && ncol >=0 && ncol<m && image[nrow][ncol] == iniCol &&ans[nrow][ncol] != color){
                dfs(nrow,ncol,image,ans,color,iniCol);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int iniCol = image[sr][sc];
        dfs(sr,sc,image,ans,color,iniCol);
        return ans;
    }
};
