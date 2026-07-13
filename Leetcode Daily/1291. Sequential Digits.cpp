class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>ans;
        for(int i=2;i<10;++i){
            for(int start=0;start<=s.length()-i;++start){
                int digit = stoi(s.substr(start,i));
                if(digit>=low && digit<=high){
                    ans.push_back(digit);
                }
            }
        }
        return ans;
    }
};
