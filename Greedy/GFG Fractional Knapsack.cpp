class Item {
public:
    int value;
    int weight;
};

class Solution {
public:

    static bool comp(Item a, Item b) {
        return (double)a.value / a.weight >
               (double)b.value / b.weight;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

        int n = val.size();

        vector<Item> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i].value = val[i];
            arr[i].weight = wt[i];
        }

        sort(arr.begin(), arr.end(), comp);

        double ans = 0.0;

        for (int i = 0; i < n; i++) {

            if (capacity >= arr[i].weight) {
                ans += arr[i].value;
                capacity -= arr[i].weight;
            }
            else {
                ans += (double)arr[i].value / arr[i].weight * capacity;
                break;
            }
        }

        return ans;
    }
};
