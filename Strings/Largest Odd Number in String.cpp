class Solution {
public:
    string largestOddNumber(string nums) {
        string ans = "";
        int index = -1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]%2!=0){
                index = i;
                break;
            }
        }
        if(index==-1){return ans;}
        for(int i = 0;i<=index;i++){
            ans += nums[i];
        }
        return ans;
    }
};
