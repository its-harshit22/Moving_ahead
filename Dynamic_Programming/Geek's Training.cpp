class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points) {
        // code here
    vector<int>dp(4,0);
    int n = points.size();
    
     dp[0]= max(points[0][1],points[0][2]);
     dp[1] = max(points[0][0],points[0][2]);
     dp[2] = max(points[0][1],points[0][0]);
     dp[3] = max(points[0][1],max(points[0][2],points[0][0]));

     for(int day=1;day<n;day++ )
     {
        vector<int>temp(4,0);
        for(int last =0;last<4;last++)
        {
            temp[last] = 0;
            
            for(int task = 0;task<=2;task++)
            {
                if(task!=last){
                    temp[last] = max(temp[last],points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
     }

     
     return dp[3];
    }
};
