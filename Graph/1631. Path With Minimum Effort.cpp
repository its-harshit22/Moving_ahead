class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col == m-1)return dis;
            for(int i=0;i<4;i++){
                int nr = row + delr[i];
                int nc = col + delc[i];

                if(nr>=0 && nr < n && nc >= 0 && nc < m){
                    int nd = max(abs(height[row][col] - height[nr][nc]),dis);
                    if(nd < dist[nr][nc]){
                        dist[nr][nc] = nd;
                        pq.push({nd,{nr,nc}});
                    }
                }
            }


        }
        return 0;


    }
};
