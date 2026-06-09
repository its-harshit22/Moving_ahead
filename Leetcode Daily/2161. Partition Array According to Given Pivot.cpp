class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int count = 0;
        vector<int>small;
        vector<int>large;
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                large.push_back(nums[i]);
            }else if(nums[i]<pivot){
                small.push_back(nums[i]);
            }else{
                count++;
            }
        }
        while(count>0){
            small.push_back(pivot);
            count--;
        }
        for(int i=0;i<large.size();i++){
            small.push_back(large[i]);
        }
        return small;
        }
};
