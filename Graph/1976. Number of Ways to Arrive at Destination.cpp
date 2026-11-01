class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<pair<int,int>> adjList[n];

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n,0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            long long dis = it.first;
            int node = it.second;

            if(dis > dist[node]) continue;

            for(auto adjNode : adjList[node]){

                int v = adjNode.first;
                long long wt = adjNode.second;

                long long newDist = dis + wt;

                if(newDist < dist[v]){

                    dist[v] = newDist;
                    pq.push({newDist,v});

                    ways[v] = ways[node];
                }

                else if(newDist == dist[v]){

                    ways[v] = (ways[v] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
