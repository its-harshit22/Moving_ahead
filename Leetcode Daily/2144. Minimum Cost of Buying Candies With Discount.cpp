class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n==2)return cost[0]+cost[1];
        if(n==1)return cost[0];
        sort(cost.begin(),cost.end());
        int amt = 0;
        int count = 1;
        for(int i=n-1;i>=0;i--){
            if(count%3==0){
                count++;
                continue;
            }
            amt += cost[i];
            count++;
            
        }
        return amt;
    }
};
