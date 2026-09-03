class Solution {
public:

    int helper(int ind1,int ind2,string &s,string &t,vector<vector<int>>&dp){
        if(ind2<0)return 1;
        if(ind1<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        

        if(s[ind1]==t[ind2]){
            int pick = helper(ind1-1,ind2-1,s,t,dp);
            int not_pick = helper(ind1-1,ind2,s,t,dp);
            return dp[ind1][ind2] = pick+not_pick;
        }
        else{
            return dp[ind1][ind2]=helper(ind1-1,ind2,s,t,dp);
        }
        

    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,s,t,dp);
    }
};
