class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<INT_MAX;i++){
            int element = 1;
            int temp = i;
            while(temp>0){
                element = element * (temp%10);
                temp = temp/10;
            }
            if(element%t==0)return i;
        }
        return 0;
    }
};
