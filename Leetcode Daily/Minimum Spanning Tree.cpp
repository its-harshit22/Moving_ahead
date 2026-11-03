
class Solution {
  public:
    int primMST(vector<vector<vector<int>>> &adj) {
        int n = adj.size();

        vector<pair<int,int>> adjList[n];

        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                int v = it[0];
                int wt = it[1];

                adjList[i].push_back({v, wt});
            }
        }

        int sum = 0;
        vector<int> vist(n, 0);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> q;

        q.push({0, 0});

        while(!q.empty()){
            auto it = q.top();
            q.pop();

            int value = it.first;
            int node = it.second;

            if(vist[node]) continue;

            vist[node] = 1;
            sum += value;

            for(auto itr : adjList[node]){
                int v = itr.first;
                int wt = itr.second;

                if(!vist[v]){
                    q.push({wt, v});
                }
            }
        }

        return sum;
    }
};
