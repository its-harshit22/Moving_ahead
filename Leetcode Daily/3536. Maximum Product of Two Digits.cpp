class Solution {
public:
    int maxProduct(int n) {
        int maxi = INT_MIN;
        int second_max = 0;
        while(n>0){
            int element = n%10;
            n = n/10;
            if(element >= maxi){second_max = maxi;maxi = element;}
            else if(element < maxi && element > second_max)second_max = element;
        }
        return maxi*second_max;



    }
};
