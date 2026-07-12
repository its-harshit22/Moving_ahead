class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int>temp;
       int duplicate = 0;
       int n = arr.size();
       if(n==0)return temp;
       for(int i=0;i<n;i++){
        temp.push_back(arr[i]);
       } 
       sort(arr.begin(),arr.end());
       map<int,int>mp;
       int assign = 1;
       mp[arr[0]] = assign;
       assign++;
       for(int i=1;i<n;i++){
         if(arr[i]!=arr[i-1]){
            mp[arr[i]] = assign;
            assign++;
         }
       }
       for(int i=0;i<n;i++){
        auto rank = mp.find(temp[i]);
        temp[i] = rank->second;
       }
       return temp;
    }
};
