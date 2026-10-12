class Solution {
public:

    int MOD = 1e9+7;

    int maxSum(vector<int>& nums, int k) {
        vector<int>count(32,0);
        for(int &num : nums){
            for(int b=0;b<32;b++){
                if(num & (1<<b)){
                    count[b]++;
                }
            }
        }
        long long ans = 0;
        while(k--){
            long long cur = 0;
            for(int b=0;b<32;b++){
                if(count[b]>0){
                    count[b]--;
                    cur = (cur|(1<<b));
                }
            }
            ans = (ans +  (cur*cur))%MOD;
        }
        return ans;
    }
};
