class Solution {
public:

    bool isValid(int n){
        bool valid = false;
        while(n>0){
            int rem = n%10;
            n = n/10;
            if(rem == 3 || rem == 4 || rem == 7){
                return false;
            }
            if(rem == 2 || rem == 5 || rem == 6 || rem == 9){
                valid = true;
            }
        }
        return valid;
    }

    int rotatedDigits(int n) {
        int count = 0;
        for(int i=2;i<=n;i++){
            if(isValid(i))count++;
        }
        return count;
    }
};
