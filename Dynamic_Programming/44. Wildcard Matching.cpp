class Solution {
public:

    bool helper(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        if(ind1<0 && ind2<0)return 1;
        if(ind1<0 && ind2>=0)return 0;
        if(ind2<0 && ind1>=0){
            for(int i=0;i<=ind1;i++){
                if(s1[i]!='*')return 0;
            }
            return 1;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2] || s1[ind1]=='?'){
            return dp[ind1][ind2] = helper(ind1-1,ind2-1,s1,s2,dp);
        }
        if(s1[ind1]=='*'){
            return dp[ind1][ind2] = (helper(ind1-1,ind2,s1,s2,dp) || helper(ind1,ind2-1,s1,s2,dp));
        }
        return false;
    }

  

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,p,s,dp);
        
    }
};
