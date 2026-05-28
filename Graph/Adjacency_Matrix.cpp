// Adjacency Matrix Representation of Graph in C++
#include<bits/stdc++.h>
using namespace std;

int main(){
     cout<<"Enter the number of vertex and edges";
     int n,m;
     cin>>n>>m;
     int adjacency_matrix[n][n];
     for(int i = 0; i < n ; i++){
        for(int j = 0;j < n ;j++){
            adjacency_matrix[i][j] = 0;
        }
     }
     cout<<"Enter the edges between the vertices";
     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;
     }
     cout<<"The adjacency matrix is :"<<endl;
     for(int i = 0; i < n ; i++){
        for(int j = 0;j < n ;j++){
            cout<<adjacency_matrix[i][j]<<" ";
        }
        cout<<endl;
     }
     return 0;
}
