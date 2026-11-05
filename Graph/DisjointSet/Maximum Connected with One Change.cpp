class DisjointSet{
public:
    vector<int>rank,parent,size;

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int findUParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    bool isValid(int nr,int nc,int n,int m){
        return nr>=0 && nr<n && nc>=0 && nc<m;
    }

public:
    int maxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DisjointSet ds(n*m);

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==0) continue;

                for(int k=0;k<4;k++){
                    int nr = i + delr[k];
                    int nc = j + delc[k];

                    if(isValid(nr,nc,n,m) && grid[nr][nc]==1){

                        int node = i*m+j;
                        int adjNode = nr*m+nc;

                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }

       
        int maxArea = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1) continue;

                unordered_set<int>st;

                for(int k=0;k<4;k++){
                    int nr = i + delr[k];
                    int nc = j + delc[k];

                    if(isValid(nr,nc,n,m) && grid[nr][nc]==1){
                        st.insert(ds.findUParent(nr*m+nc));
                    }
                }

                int sum = 1;

                for(auto it:st){
                    sum += ds.size[it];
                }

                maxArea = max(maxArea,sum);
            }
        }

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxArea = max(maxArea,ds.size[ds.findUParent(i*m+j)]);
            }
        }

        return maxArea;
    }
};
