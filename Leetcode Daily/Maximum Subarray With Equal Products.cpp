class Solution {
public:

    const int MOD = 1e9;

    int gcd(int a, int b) {
        if (b < a) return gcd(b, a);
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            long long prod = 1ll;
            long long hf = 0;
            long long lm = 1;
            for (int j = i; j < n; j++) {
                prod = (prod  * nums[j]) % MOD;
                lm = lcm(lm, nums[j]) % MOD;
                hf = gcd(hf, nums[j]) % MOD;
                if (prod == lm * hf) maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};
