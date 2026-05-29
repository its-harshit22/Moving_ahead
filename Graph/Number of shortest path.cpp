#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n];

    // Input graph
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX);
    vector<int> ways(n, 0);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[0] = 0;
    ways[0] = 1;

    pq.push({0, 0});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;

            // Shorter path found
            if(d + wt < dist[adjNode])
            {
                dist[adjNode] = d + wt;

                ways[adjNode] = ways[node];

                pq.push({dist[adjNode], adjNode});
            }

            // Another shortest path found
            else if(d + wt == dist[adjNode])
            {
                ways[adjNode] = ways[adjNode] + ways[node];
            }
        }
    }

    cout << ways[n-1];

    return 0;
}
