class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n = arr.size();
        int i = 0;
        int j = 0;
        int maxIntersection = 1;
        while(i<n){
            if(arr[i]<=dep[j]){
               i++; 
            }
            else{
                j++;
            }
            maxIntersection = max(maxIntersection,i-j);
        }
        return maxIntersection;
    }
};
