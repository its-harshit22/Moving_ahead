#include<bits/stdc++.h>
using namespace std;

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

int main(){
     DisjointSet ds(7);
     ds.unionBySize(1,2);
     ds.unionBySize(2,3);
     ds.unionBySize(4,5);
     ds.unionBySize(6,7);
     ds.unionBySize(5,6);

     if(ds.findUParent(3) == ds.findUParent(7)){
        cout<< "They are connected" <<endl;
     }else{
        cout<< "Not connected" <<endl;
     }
     ds.unionBySize(3,7);
     if(ds.findUParent(3) == ds.findUParent(7)){
        cout<< "They are connected" <<endl;
     }else{
        cout<< "Not connected" <<endl;
     }
     return 0;
}
