#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int maxWater = 0;
    int lp = 0;
    int rp = height.size()-1;
    while(lp<rp){
        int wt = rp-lp;
        int ht = min(height[lp],height[rp]);
        int currWater = wt * ht;
        maxWater = max(maxWater,currWater);
        height[lp]<height[rp] ?lp++:rp--;
    }

    cout<< maxWater <<endl;
    return 0;
}
