class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')count++;
            if(s[j]=='a'||s[j]=='A'||s[j]=='e'||s[j]=='E'||s[j]=='i'||s[j]=='I'||s[j]=='o'||s[j]=='O'||s[j]=='u'||s[j]=='U')count--;

            i++;
            j--;
            
        }
        return count==0;

        
    }
};
