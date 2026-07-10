class Solution {
public:
    set<vector<int>>s;
    void helper(vector<int>& arr,int idx,vector<int>&combine,vector<vector<int>>&ans,int tar){
        if(idx==arr.size() || tar < 0){
            return;
        }
        if (tar == 0) {
            if (s.find(combine) == s.end()) {   // 
                ans.push_back(combine);
                s.insert(combine);             
            }
            return;
        }

        combine.push_back(arr[idx]);
        helper(arr,idx+1,combine,ans,tar-arr[idx]);
        helper(arr,idx,combine,ans,tar-arr[idx]);
        combine.pop_back();
        helper(arr,idx+1,combine,ans,tar);
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combin;
        helper(candidates,0,combin,ans,target);
        return ans;
        
    }
};
