class Solution {
    
public:
     void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int ind, int tar) {
        if (tar == 0 ) {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            if(nums[i]>tar)break;
            ds.push_back(nums[i]);
            solve(nums,ans,ds,i+1,tar-nums[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
       vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(nums, ans, ds, 0, tar);
        return ans;
    }
};

