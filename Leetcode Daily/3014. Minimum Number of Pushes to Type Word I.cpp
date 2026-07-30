class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n<=8)return n;
        int counter = 8;
        for(int i=9;i<=n;i++){
            if(i<17)counter += 2;
            else if(i<25)counter += 3;
            else counter += 4;
        }
        return counter;
    }
};
