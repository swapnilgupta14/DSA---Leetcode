class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(const auto& each : nums){
            mp[each]++;
        }
        int m = 0;
        int count = 0;
        for(int i=0; i<mp.size(); i++){
            if(mp[i] > m) m = mp[i];
        }
        for(int i=0; i<mp.size(); i++){
            if(mp[i] == m) count+=mp[i];
        }
        return count;
    }
};