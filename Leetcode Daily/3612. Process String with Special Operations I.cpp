class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                int n = ans.size();
                if(n==0)continue;
                ans.erase(ans.size() - 1);
            }
            else if(s[i]=='#'){
                ans = ans+ans;
            }
            else if(s[i]=='%'){
                int i = 0;
                int j = ans.size()-1;
                while(i<j){
                    char temp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = temp;
                    i++;
                    j--;
                }
            }
            else{
                ans = ans+s[i];
            }
        }
        

        return ans;
    }
};
