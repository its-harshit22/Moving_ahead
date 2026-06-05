//It is through BFS algorithm
class Solution {
private:
    bool detect(int st, vector<int>& visited, vector<vector<int>>& edges) {
        visited[st] = 1;

        queue<pair<int,int>> q;
        q.push({st, -1});

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto neighbour : edges[node]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push({neighbour, node});
                }
                else if(neighbour != parent) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> visited(V, 0);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(detect(i, visited, edges))
                    return true;
            }
        }

        return false;
    }
};
