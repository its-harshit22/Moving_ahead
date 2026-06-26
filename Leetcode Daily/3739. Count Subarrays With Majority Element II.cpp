class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        long long validLeftPoints = 0;
        long long cumSum = 0;
        long long result = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validLeftPoints += mp[cumSum];
                cumSum += 1;
            }
            else{
                cumSum -= 1;
                validLeftPoints -= mp[cumSum];

            }
            mp[cumSum] += 1;
            result += validLeftPoints;
            
        }
        return result;
    }
};
