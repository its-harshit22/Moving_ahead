//Intution behind this code is simple there is fix number of character needed to make a ballon so lets store the freq of that elements they are neeeded only

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        int minCount = INT_MAX;
        for(int i=0;i<text.size();i++)
        {
            char word = text[i];
            if(word=='b' || word =='a' || word == 'l'|| word == 'o' ||word == 'n'){
                mp[word]++;
            }
        }
        for(auto val:mp){
            if(val.first=='l' || val.first=='o'){
                minCount = min(minCount,val.second/2);
            }
            else{
                minCount = min(minCount,val.second);

            }

        }
        if(mp.size()!=5)return 0;
        return minCount;
    }
};
