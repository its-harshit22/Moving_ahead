class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int>st;
        for(int i=0;i<n;i++){
            if(nums[i]%k==0)st.insert(nums[i]);
        }
        int i = 1;
        for(auto it : st){
            if(i*k!=it){
                return i*k;
            }
            else{
                i++;
            }
        }
        int m = st.size()+1;
        return k*m;
        
        

    }
};
