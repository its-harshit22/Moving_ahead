class Solution {
public:
    string smallestPalindrome(string s) {
      int n = s.size();
      if(n==1)return s;
      int freq[26] = {0};
      for(int i=0;i<n/2;i++){
        char c = s[i];
        freq[c-'a']++;
      } 
      int idx = 0;
      for(int i = 0; i < 26; i++){
    while(freq[i] > 0){
        s[idx++] = char(i + 'a');
        freq[i]--;
    }
}
      for(int i=0;i<n/2;i++){
        s[n-1-i] = s[i];
      }
      return s;
    }
};
