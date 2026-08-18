class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i + k <= n; i++) {
            set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                mp[x]++;
            }
        }

        int ans = -1;

        for (auto it : mp) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};
