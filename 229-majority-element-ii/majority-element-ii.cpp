class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // brute - MLE 
        int n = nums.size();

        vector<int>ans;
        unordered_map<int, int> mp;

        for (int it: nums){
            mp[it] +=1;
        }
        for(auto it: mp){
            if(it.second > n/3) ans.push_back(it.first);
        }
        return ans;
    }
};