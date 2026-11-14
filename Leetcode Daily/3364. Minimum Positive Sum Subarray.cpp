class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                int size = j-i+1;
                if(size>= l && size <= r && sum > 0){
                    mini = min(mini,sum);
                }
            }
        }
        
        if(mini == INT_MAX)return -1;
        return mini;
    }
};
