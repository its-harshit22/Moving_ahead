class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxElement = -1;
        int second_max = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=maxElement){
                second_max = maxElement;
                maxElement = nums[i];
            }
            else if(nums[i]>second_max){
                second_max = nums[i];
            }
        }
        return (maxElement-1)*(second_max-1);
    }
};
