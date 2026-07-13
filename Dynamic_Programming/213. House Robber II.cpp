// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed.
// All houses at this place are arranged in a circle.
// That means the first house is the neighbor of the last one.
// Meanwhile, adjacent houses have a security system connected, 
// and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& arr) {
        
        int n = arr.size();
        if(n==1)return arr[0];

       
        int take = 0;
        int notTake = 0;
        
        int prev = arr[0];
        int prev2 = 0;

        for(int i=1;i<n-1;i++){
            take = arr[i];if(i>1)take += prev2;
            notTake = prev;
            int curi = max(take,notTake);
            prev2 = prev;
            prev = curi;
        }

        take = 0;
        notTake = 0;
        
        int dprev = arr[1];
        int dprev2 = 0;
        for(int i=2;i<n;i++){
            take = arr[i];if(i>1)take += dprev2;
            notTake = dprev;
            int curi = max(take,notTake);
            dprev2 = dprev;
            dprev = curi;
        }
        return max(prev,dprev);
    }
};
