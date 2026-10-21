class Solution {
public:

    bool sortCheck(string s){
        int n = s.size();
        for(int i=1;i<n;i++){
            if(s[i]<s[i-1])return false;
        }
        return true;
    }

    int minOperations(string s) {
        if(sortCheck(s))return 0;
        int n = s.size();
        if(n<3)return -1;
        int i = 0;
        int j = 1;
        int count = 0;
        while(j<n){
            if(s[i]<s[j]){
                i++;j++;
            }
            else{
                while(s[i]>s[j]){
                    j++;
                }count++;
                i = j;
                j = i+1;
            }

        }
        return count;
    }
};
