class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0;
        int j=1;
        int n = nums.size();
        int maxSize = 1;
        while(j<n){
            if(nums[j]>nums[j-1]){
                j++;
                maxSize =  max(maxSize,j-i);
            }
            else{
                i = j;
                j = j + 1;
            }
        }
        i=0;
        j=1;
        int minSize = 1;
        while(j<n){
            if(nums[j]<nums[j-1]){
                j++;
                minSize =  max(minSize,j-i);
            }
            else{
                i = j;
                j = j + 1;
            }
        }
        return max(maxSize,minSize);
    }
};
