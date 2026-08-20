//Here it is a question of segment but solve by brute the segment tree code and approach is in next question

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int fruit = fruits[i];
            bool check = true;
            for(int j=0;j<n;j++){
                if(fruit<=baskets[j]){
                    baskets[j] = -1;
                    check = false;
                    break;
                }
            }
            if(check)count++;
        }
        return count;
    }
};
