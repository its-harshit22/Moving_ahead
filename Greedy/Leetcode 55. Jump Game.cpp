class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int n = nums.size();
        if(n==1)return 1;
        for(int i=0;i<n;i++){
            if(maxJump<i)return 0;
            maxJump = max(maxJump, i+nums[i]);
            
        }
        if(maxJump>=n-1)return 1;
        return 0;
        
    }
};
