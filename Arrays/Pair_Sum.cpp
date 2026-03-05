#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec = {2,4,5,11,15};
    int targetSum = 20;
    int index[2] = {-1,-1};
    int j = 0;
    int k = vec.size() - 1;
    while(j<k)
    {
       if(vec[j] + vec[k] == targetSum)
       {
        index[0] = j;
        index[1] = k;
        break;
       }
       else if(vec[j] + vec[k] > targetSum)
       {
        k--;
       }
       else
       {
        j++;
       }
    }
    
    
    for(int i = 0;i<2;i++)
    {
        cout<< index[i] <<" ";
    }
     return 0;
}
