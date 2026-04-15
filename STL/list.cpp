#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    // Insertion
    l.push_back(10);  // end me add
    l.push_back(20);
    l.push_front(5);  // front me add

    cout << "List elements: ";
    for(auto x : l) cout << x << " ";

    // Deletion
    l.pop_front();  // remove first
    l.pop_back();   // remove last

    cout << "\nAfter pop: ";
    for(auto x : l) cout << x << " ";

    // Insert at specific position
    auto it = l.begin();
    advance(it, 1);   // iterator ko move karo
    l.insert(it, 15);

    cout << "\nAfter insert: ";
    for(auto x : l) cout << x << " ";

    // Erase
    l.erase(l.begin());

    cout << "\nAfter erase: ";
    for(auto x : l) cout << x << " ";

    return 0;
}
