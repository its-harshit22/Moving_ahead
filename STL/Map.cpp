#include<iostream>
#include<map>
using namespace std;
//Map me data sorted hota hai key ke bases pe or every key is unqiue.
int main(){
    map<string ,int>m; 
    m["Tv"] = 100;
    m["Laptop"] = 80;
    m["Headphones"] = 50;
    m["Tablets"] = 120;
    m["Watch"] = 50;
    m["Kayu"] = 150;

    for(auto p: m)
    {
        cout<< p.first<<" "<<p.second <<endl;
    }
     return 0; 
}
