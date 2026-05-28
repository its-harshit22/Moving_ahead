#include<bits/stdc++.h>
using namespace std;
vector<int>BFS(int start, vector<int> adjList[], int n){
    int visited[n] = {0};
    visted[start] = 1;
    queue<int>q;
    q.push(start);
    vector<int>bfsOrder;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfsOrder.push_back(node);
        for(int i=0;i<adjList[node].size();i++){
            int node1 = adjList[node][i];
            if(!visited[node1]){
                visited[node1] = 1;
                q.push(node1);
            }
        }
    }
    return bfsOrder;
}

int main(){
     int n, m;

    cout << "Enter the number of vertices and edges: ";

    cin >> n >> m;

    vector<int> adjList[n];

    // Input edges
    for(int i = 0; i < m; i++) {

        int u, v;

        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }
    

     return 0;
}
