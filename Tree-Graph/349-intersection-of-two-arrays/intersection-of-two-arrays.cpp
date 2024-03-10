class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for (const auto& each : nums1) {
            mp[each]++;
        }
        set<int> st;
        for (int i : nums2) {
            if (mp.find(i) != mp.end()) {
                st.insert(i);
            }
        }
        vector<int> vc(st.begin(), st.end());
        return vc;
    }
};