class Solution {
public:
    bool checkString(string s) {
        bool checkB = false;
        int n = s.size();
        int ind = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){checkB = true;ind = i;break; }
        }
        if(ind == n-1)return true;
        if(!checkB)return true;

        while(ind<n){
            if(s[ind]=='a')return false;
            else ind++;
        }
        return true;
    }
};
