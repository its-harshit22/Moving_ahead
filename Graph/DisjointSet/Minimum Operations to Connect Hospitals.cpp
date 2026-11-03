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
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        DisjointSet ds(V);
        int n = edges.size();
        for(int i=0;i<n;i++){
            
                int u = edges[i][0];
                int v = edges[i][1];
                if(ds.findUParent(u)!=ds.findUParent(v)){
                    ds.unionBySize(u,v);
                }
            
        }
        int cnt = -1;
        if(n<V-1)return -1;
        
        for(int i=0;i<V;i++){
            if(ds.findUParent(i)==i)cnt++;
        }
        return cnt;
        
        
    }
};
