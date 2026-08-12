class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int i = 0;
        int j = 0;
        int n = nums.size();

        map<int,int> mp;

        int max_count = 0;

        while (j < n)
        {
            mp[nums[j]]++;

            auto it = mp.find(nums[j]);

            if (it->second <= k)
            {
                max_count = max(max_count, j - i + 1);
                j++;
            }
            else
            {
                while (mp[nums[j]] > k)
                {
                    mp[nums[i]]--;
                    i++;
                }

                max_count = max(max_count, j - i + 1);
                j++;
            }
        }

        return max_count;
    }
};
