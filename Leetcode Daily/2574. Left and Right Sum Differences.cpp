class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
        int leftsum = 0;
        int rightsum = 0;
            for(int j=n-1;j>=0;j--){
                if(i==j)break;
                rightsum += nums[j];
            }
            for(int k=0;k<n;k++){
                if(i==k)break;
                leftsum += nums[k];
            }
            ans.push_back(abs(leftsum-rightsum));
        }
        return ans;
    }
};
