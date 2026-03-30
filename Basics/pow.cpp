class Solution {
public:
    double myPow(double x, int n) {
        if(x==0){return 0;}
        if(x==1){return 1;}
        if(n==0){return 1;}
        double ans = 1;
        long binaryNo = n;
        if(binaryNo < 0)
        {
            x = 1/x;
            binaryNo = -binaryNo;
        }
        while(binaryNo>0)
        {
               if(binaryNo % 2==1)
               {
                ans *= x;
                binaryNo /= 2;
                x = x*x;
               }
               else
               {
                x = x*x;
                binaryNo /= 2;
               }

        }
    
    return ans;
    }
};
