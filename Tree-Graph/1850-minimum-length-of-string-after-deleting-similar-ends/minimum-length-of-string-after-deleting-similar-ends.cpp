class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i<j){
            if(s[i]!=s[j]) break;
            while(i<j-1 && s[i+1]==s[i]) i++, n--;
            while(j>i+1 && s[j-1]==s[j]) j--, n--;
            n-=2;
            i++, j--;
        }
        return n;
    }
};