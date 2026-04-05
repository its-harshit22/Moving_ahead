#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//Brute Force Approach
vector<int> Finder(vector<int> num,int target){
    vector<int>ans;
    for(int i=0;i<num.size();i++){
        for(int j=i+1;j<num.size();j++){
             if(num[i]+num[j]==target){
                ans.push_back(i);
                ans.push_back(j);
             }
        }
    
    }return ans;
}
//Better approach
vector<int> Better(vector<int> num, int target) {
    vector<pair<int,int>> arr;  // {value, index}
    for(int i=0; i<num.size(); i++) {
        arr.push_back({num[i], i});
    }
    sort(arr.begin(), arr.end());

    int st = 0, end = arr.size() - 1;
    while(st < end) {
        int sum = arr[st].first + arr[end].first;
        if(sum == target) {
            return {arr[st].second, arr[end].second}; // original indices
        }
        else if(sum > target) {
            end--;
        } else {
            st++;
        }
    }
    return {-1, -1}; // not found
}
//Optimise

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int>m;
//         vector<int>ans;
//         int first;
//         int second;
//         for(int i=0;i<nums.size();i++){
//             first = nums[i];
//             second = target-first;
//             if(m.find(second) != m.end()){
//                 ans.push_back(i);
//                 ans.push_back(m[second]);
//                 return ans;
//             }
//             else{
//                 m[first] = i;
//             }
//         }
//     return ans;}
// };

int main(){
    vector<int> num = {3,4,8,2,5};
    int target = 5;
    vector<int>real = Better(num,target);
    cout<< real[0] <<endl;
    cout<< real[1] <<endl;
     return 0;
}
