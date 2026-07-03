class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int captial = 0;
        bool flag = false;
        if(word[0]<'a')flag = true;
        for(int i=0;i<n;i++){
            if('a' - word[i] > 0){
                captial++;
            }
        }
        if(captial==n)return true;
        if(captial==1 && flag)return true;
        if(captial==0)return true;
        return false;
    }
};
