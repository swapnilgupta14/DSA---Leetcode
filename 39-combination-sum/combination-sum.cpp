class Solution {
private:
    void backtrack(int idx, int sum, vector<int>& candidates, int target,
                   vector<vector<int>>& ans, vector<int>& temp) {
        int n = candidates.size();
        if (sum > target || idx >= n)
            return;
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        for(int it = idx; it < n; it ++){
            temp.push_back(candidates[it]);
            backtrack(it, sum + candidates[it], candidates, target, ans, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(0, 0, candidates, target, ans, temp);
        return ans;
    }
};