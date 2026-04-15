#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(5);  // duplicate, ignored

    cout << "Set elements: ";
    for(auto x : s) {
        cout << x << " ";
    }

    cout << "\nCheck if 2 exists: " << (s.count(2) ? "Yes" : "No");

    s.erase(2); // remove element
    cout << "\nAfter erase: ";
    for(auto x : s) cout << x << " ";

    return 0;
}
