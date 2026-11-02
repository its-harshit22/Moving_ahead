class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        int m = edges[0].size();
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    mat[i][j] = 0;
                }
            }
        }
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for(int via = 0;via< n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][via]!=1e9 && mat[via][j]!=1e9 && (mat[i][j]>mat[i][via]+mat[via][j])){
                        mat[i][j] = mat[i][via]+mat[via][j];
                    }
                }
            }
        }
        int miniCity = INT_MIN;
        int counter = 0;
        int Maxcounter = INT_MAX;

        for(int i=0;i<n;i++){
            counter = 0;
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j]<=k){
                    counter++;
                }
            }
            if(Maxcounter>=counter){
                Maxcounter = counter;
                miniCity = i;

            }

        }
        return miniCity;
        
    }
};
