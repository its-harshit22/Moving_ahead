#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find quadruplets with sum = target
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        // Get size of array
        int n = arr.size();
        // Use set to avoid duplicate quadruplets
        set<vector<int>> st;

        // First loop - pick first element
        for (int i = 0; i < n; i++) {
            // Second loop - pick second element
            for (int j = i + 1; j < n; j++) {
                // Third loop - pick third element
                for (int k = j + 1; k < n; k++) {
                    // Fourth loop - pick fourth element
                    for (int l = k + 1; l < n; l++) {
                        // Calculate sum of four chosen numbers
                        long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                        // Check if sum matches target
                        if (sum == target) {
                            // Store quadruplet in sorted order
                            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                            sort(temp.begin(), temp.end());
                            // Insert into set to ensure uniqueness
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        // Convert set into vector of quadruplets
        return vector<vector<int>>(st.begin(), st.end());
    }
};

int main() {
    // Input array
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    // Target sum
    int target = 0;

    // Create object
    Solution obj;
    // Get all quadruplets
    vector<vector<int>> ans = obj.fourSum(arr, target);

    // Print result
    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}
