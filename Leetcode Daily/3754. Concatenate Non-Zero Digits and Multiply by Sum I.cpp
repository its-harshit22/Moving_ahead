class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long result = 0;
        while(n>0){
            int temp = n%10;
            n = n/10;
            if(temp!=0){
                result += temp;
                sum = (sum*10) + temp;
            }
        }
        long long realSum = 0;
        while(sum>0){
            realSum = (realSum*10)+(sum%10);
            sum = sum/10;
        }
        long long ans = result * realSum;
        return ans;
    }
};
