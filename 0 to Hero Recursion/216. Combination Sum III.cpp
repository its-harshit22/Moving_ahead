class Solution {

public:

    void helper(int ind,vector<int>&data,vector<int>&ds,int tar,vector<vector<int>>&ans,int k){
        if(tar==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<data.size();i++){
            if(data[i]>tar)return;
            ds.push_back(data[i]);
            helper(i+1,data,ds,tar-data[i],ans,k);
            ds.pop_back();
        }
    }


    vector<vector<int>> combinationSum3(int k, int tar) {
        vector<vector<int>>ans;
        if(k>tar)return ans;
        vector<int>data = {1,2,3,4,5,6,7,8,9};
        vector<int>ds;
        helper(0,data,ds,tar,ans,k);
        return ans;
    }
};
