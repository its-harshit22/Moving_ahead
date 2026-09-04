class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix_max(n,INT_MIN);
        vector<int>suffix_min(n,INT_MAX);
        prefix_max[0] = nums[0];
        suffix_min[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            prefix_max[i] = max(prefix_max[i-1],nums[i]);
        }
        for(int j = n-2;j>=0;j--){
            suffix_min[j] = min(suffix_min[j+1],nums[j]);
        }
        for(int i=0;i<n;i++){
            
            if(prefix_max[i]-suffix_min[i]<=k)return i;
        }
        return -1;

    }
};
