class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int,int>mp;
        for(auto &it : s){
            mp[it]++;
        }
        string ans="";
        for(auto &it : order){
            if(mp.find(it) != mp.end()){
                ans.append(mp[it], it);
                mp.erase(it);
            }
        }
        for(auto &it: mp){
            ans.append(it.second, it.first);
        }
        return ans;
    }
};