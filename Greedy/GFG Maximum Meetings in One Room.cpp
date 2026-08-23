class Data {
public:
    int start;
    int end;
    int position;
};

class Solution {
public:
    static bool compare(Data a, Data b) {
        return a.end < b.end;
    }

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        vector<int>ans;
        Data arr[n];

        for (int i = 0; i < n; i++) {
            arr[i].start = s[i];
            arr[i].end = f[i];
            arr[i].position = i + 1;
        }

        sort(arr, arr + n, compare);
        ans.push_back(arr[0].position);
        int freeTime = arr[0].end;
        for(int i=1;i<n;i++){
            if(freeTime < arr[i].start){
                ans.push_back(arr[i].position);
                freeTime =  arr[i].end;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
        
    }
};
