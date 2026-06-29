class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int counter = 0;
        for(int i=0;i<patterns.size();i++){
            string s = patterns[i];
            int pos = word.find(s);
            if(pos == string::npos)continue;
            counter++;
        }
        return counter;

        
             
    }
};
