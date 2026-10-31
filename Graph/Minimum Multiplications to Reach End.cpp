class Solution {
  public:
  
    int MOD = 1000;
  
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int>dist(1000,1e9);
        queue<pair<int,int>>q;
        dist[start] = 0;
        q.push({0,start});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int val = it.second;
            for(int i=0;i<arr.size();i++){
                int newVal =  (val * arr[i]) % MOD;
                if(dist[newVal]>steps+1){
                    dist[newVal] = steps+1;
                    q.push({steps+1,newVal});
                }
            }
        }
        if(dist[end]==1e9)return -1;
        return dist[end];
        
    }
};
