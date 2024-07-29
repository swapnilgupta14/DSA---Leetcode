class Solution {
private:
    vector<int> majorityElement_(vector<int>& nums) {
        // brute - using Hashmap
        int n = nums.size();

        vector<int> ans;
        unordered_map<int, int> mp;

        for (int it : nums) {
            mp[it] += 1;
        }
        for (pair it : mp) {
            if (it.second > n / 3)
                ans.push_back(it.first);
        }
        return ans;
    }

public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        if (n < 3) {
            if (n == 2) {
                if (nums[0] == nums[1]) {
                    ans.push_back(nums[0]);
                    return ans;
                }
            }
            return nums;
        }

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;

        while (i < n && j < n) {
            if (nums[i] != nums[j]) {
                i++;
                j++;
            } else {
                while (j < n && nums[j] == nums[i]) j++;
                if ((j - i ) > n / 3)
                    ans.push_back(nums[i]);
                i = j;
                j ++;
            }
        }
        return ans;
    }
};