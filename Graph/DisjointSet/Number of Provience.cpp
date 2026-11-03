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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j] == 1 && i != j){
    ds.unionBySize(i+1,j+1);
}
            }
        }
        int count = 0;

        for(int i=0;i<n;i++){
            if(ds.findUParent(i+1)==i+1)count++;
        }

        return count;


    }
};
