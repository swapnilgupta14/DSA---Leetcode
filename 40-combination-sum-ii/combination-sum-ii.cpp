class Solution {
private:
    void backtrack(int idx, int sum, int target, vector<int>& candidates,
                   vector<int>& temp, set<vector<int>>& ans) {
        int n = candidates.size();
        
        if (sum > target) return;        
        if (sum == target) {
            ans.insert(temp);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            temp.push_back(candidates[i]);
            backtrack(i + 1, sum + candidates[i], target, candidates, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        set<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, target, candidates, temp, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};