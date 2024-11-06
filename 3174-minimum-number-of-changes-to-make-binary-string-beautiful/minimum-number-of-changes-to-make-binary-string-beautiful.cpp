class Solution {
private:
    int helper(char a, char b){
        if(a != b) return 1;
        return 0;
    }
public:
    int minChanges(string s) {
        int quan = 0;
        long int size = s.size();
        for(long int i=0; i<size; i+=2){
            quan += helper(s[i], s[i+1]);
        }
        return quan;
    }
};