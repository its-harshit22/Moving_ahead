class DisjointSet{
    private:
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i] = i;


    }

    int findUParent(int node){
        if(node==parent[node])return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }


    }void unionBySize(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)return;

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
      return nr >=0 && nr < n && nc >= 0 && nc < m;
  }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>>vist(n,vector<int>(m,0));
        int cnt = 0;
        vector<int>ans;
        for(auto it : operators){
            int r = it[0];
            int c = it[1];
            if(vist[r][c]==1){
                ans.push_back(cnt);
                continue;
            }
            
            vist[r][c] = 1;
            cnt++;
            
            int delr[] = {-1,0,1,0};
            int delc[] = {0,1,0,-1};
            
            for(int i = 0;i < 4;i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                
                if(isValid(nr,nc,n,m) && vist[nr][nc]==1 && (ds.findUParent(r*m+c) != ds.findUParent(nr*m+nc))){
                    cnt--;
                    ds.unionBySize(r*m+c,nr*m+nc);
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};
