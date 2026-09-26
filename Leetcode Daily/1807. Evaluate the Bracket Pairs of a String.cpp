class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        string ans;

        for (auto it : knowledge) {
            mp[it[0]] = it[1];
        }

        for (int i = 0; i < s.size();) {
            string temp = "";

            if (s[i] == '(') {
                i++;  

                while (s[i] != ')') {
                    temp += s[i];
                    i++;
                }
                i++;  

                if (mp.count(temp)) {
                    ans += mp[temp];
                }
                else {
                    ans += "?";
                }
            }
            else {
                while (i < s.size() && s[i] != '(') {
                    ans += s[i];
                    i++;
                }
            }
        }

        return ans;
    }
};
