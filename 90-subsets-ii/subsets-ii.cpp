class Solution {
private:
    void backtrack(int i, vector<int>& nums, multiset<int> &subset, set<vector<int>> &ans){
        int n = nums.size();
        if( i >= n){
            ans.insert(vector<int>(subset.begin(), subset.end()));
            return;
        }
        subset.insert(nums[i]);
        backtrack(i+1, nums, subset, ans);
        subset.erase(subset.find(nums[i]));
        backtrack(i+1, nums, subset, ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        multiset<int>subset;
        set<vector<int>> ans;
        backtrack(0, nums, subset, ans);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};