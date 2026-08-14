class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char,int>mp;
        int max_len = 0;
        int i=0;
        int j=0;
        int n = s.size();
        while(j<n){
            char c = s[j];
            mp[c]++;
            
            while(mp[c]>2){
                mp[s[i]]--;
                i++;
                  
            }
            max_len = max(max_len,j-i+1);
            j++;
            
        }
        return max_len;
    }
};
