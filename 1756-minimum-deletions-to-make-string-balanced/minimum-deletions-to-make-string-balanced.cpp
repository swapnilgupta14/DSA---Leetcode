class Solution {
public:
    int minimumDeletions(string s) {
        int cntb=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b') cntb++;
            if(cntb!=0 && s[i]=='a'){
                cntb--;
                cnt++;
            }
        }
        return cnt;
    }
};