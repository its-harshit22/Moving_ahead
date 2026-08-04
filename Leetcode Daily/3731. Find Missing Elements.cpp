class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0];
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            smallest = min(smallest,nums[i]);
            largest = max(largest,nums[i]);
        }
        for(int i = smallest+1;i<largest;i++){
            bool flag = true;
            for(int j=0;j<n;j++){
                if(i==nums[j]){
                    flag = false;
                }
            }
            if(flag){
                ans.push_back(i);
            }
        }
        return ans;

    }
};
