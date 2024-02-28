class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        map<int, int> mp;
        for(auto i: trust){
            mp[i[1]]++;
            mp[i[0]]--;
        }
        for(int i=0; i<mp.size(); i++){
            // i -> town Judge
            if(mp[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};