class Solution {
public:
    string capitalizeFirstLast(string s) {
        string ans = s;
        int n = s.size();
        if(ans[0]>'Z'){
            ans[0] = s[0] - 32;
        }
        if(ans[n-1]>'Z'){
            ans[n-1] = s[n-1] - 32;
        }
        
        for(int i=1;i<n-1;i++){
            char ch = ans[i];
            if(s[i-1]==' ' || s[i + 1]==' '){
                if(ch>='A' && ch<='Z'){
                    continue;
                }

                ans[i] = ans[i] - 32;
            }
        }
        return ans;
        
    }
};
