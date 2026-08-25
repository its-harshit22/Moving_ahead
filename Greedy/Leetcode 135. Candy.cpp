//Extreme naive solution....................................
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();

//         vector<int> left(n, 1);
//         vector<int> right(n, 1);

        
//         for (int i = 1; i < n; i++) {
//             if (ratings[i] > ratings[i - 1]) {
//                 left[i] = left[i - 1] + 1;
//             }
//         }

        
//         for (int i = n - 2; i >= 0; i--) {
//             if (ratings[i] > ratings[i + 1]) {
//                 right[i] = right[i + 1] + 1;
//             }
//         }

//         int sum = 0;

//         for (int i = 0; i < n; i++) {
//             sum += max(left[i], right[i]);
//         }

//         return sum;
//     }
// };
class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        int sum = 1;
        
        int i = 1;
        while(i<n){
            if(arr[i]==arr[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && arr[i]>arr[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i<n && arr[i]<arr[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak){
                sum = sum + down - peak;
            }
        }
        return sum;

    }
};
