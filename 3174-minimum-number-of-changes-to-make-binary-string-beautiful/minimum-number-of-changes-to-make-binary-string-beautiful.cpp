class Solution {
public:
    int minChanges(string s) {
        int quan = 0;
        long int size = s.size();
        for(long int i=0; i<size; i+=2){
            quan += (s[i] != s[i+1] ? 1 : 0);
        }
        return quan;
    }
};