class Solution {
public:
    int result;
    void solve(int index,vector<int>&nums,int k,unordered_map<int,int>&mp)
    {
        if(index>=nums.size())
        {
            result++;
            return;
        }
        // Exclude

        solve(index+1,nums,k,mp);

        // Include

        if(!mp[nums[index]-k] && !mp[nums[index]+k])
        {
            mp[nums[index]]++;
            solve(index+1,nums,k,mp);
            mp[nums[index]]--;
        }

    }

    int beautifulSubsets(vector<int>& nums, int k) {
        result=0;
        unordered_map<int,int>mp;
        solve(0,nums,k,mp);
        return result-1;
    }
};
// class Solution {
// private:
//     bool isBeautiful(int n, vector<int> &temp, int k) {
//         unordered_set<int> s(temp.begin(), temp.end());
//         if (s.find(n + k) == s.end() && s.find(n - k) == s.end()) {
//             return true;
//         }
//         return false;
//     }

//     void backtrack(int i, vector<int>& nums, int k, vector<int>& temp, int& count) {
//         int n = nums.size();
//         if (i >= n) {
//             count++;
//             return;
//         }
//         if (isBeautiful(nums[i], temp, k)) {
//             temp.push_back(nums[i]);
//             backtrack(i + 1, nums, k, temp, count);
//             temp.pop_back();
//         }
//         backtrack(i + 1, nums, k, temp, count);
//     }

// public:
//     int beautifulSubsets(vector<int>& nums, int k) {
//         vector<int> temp;
//         int count = 0;
//         backtrack(0, nums, k, temp, count);
//         return count - 1;
//     }
// };
