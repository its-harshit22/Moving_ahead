class Solution {
public:
    int lcs(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2] = 1 + lcs(ind1-1,ind2-1,s1,s2,dp);
        }
        return dp[ind1][ind2] = max(lcs(ind1-1,ind2,s1,s2,dp),lcs(ind1,ind2-1,s1,s2,dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int lcs1 = lcs(n-1,m-1,word1,word2,dp);
        int ans = n - lcs1;
        ans += m - lcs1;
        return ans;
        
        
    }
};
