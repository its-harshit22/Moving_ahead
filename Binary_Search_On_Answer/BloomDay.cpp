class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long need = 1LL * m * k;
        if(need > bloomDay.size()) return -1;

        int left = INT_MAX;
        int right = INT_MIN;
        int ans = -1;

        for(int i=0;i<bloomDay.size();i++){
            left = min(left,bloomDay[i]);
            right = max(right,bloomDay[i]);
        }

        while(left <= right){

            int mid = left + (right - left)/2;

            int counter = 0;
            int bDay = 0;

            for(int i=0;i<bloomDay.size();i++){

                if(bloomDay[i] <= mid){
                    counter++;
                }
                else{
                    bDay += counter / k;
                    counter = 0;
                }

            }

            bDay += counter / k;

            if(bDay >= m){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }

        }

        return ans;
    }
};
