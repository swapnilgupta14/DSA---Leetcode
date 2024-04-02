class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // intution - 
        // HashMap ds:       // HashMap dt:
        // r: 3              // e: 3     
        // e: 2              // l: 2
        // a: 1              // i: 1        
        // p: 0              // t: 0
        unordered_map<char, int> ds, dt;
        for (auto& c : s) {
            if (ds.count(c) != 0) continue;
            ds[c] = ds.size();
        }
        for (auto& c : t) {
            if (dt.count(c) != 0) continue;
            dt[c] = dt.size();
        }

        for (int i = 0; i < s.size(); i++) {
            if (ds[s[i]] != dt[t[i]]) return false;
        }
        return true;
    }
};
