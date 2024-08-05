class Solution {
    // Input: k = 3, n = 9
    // Output: [[1,2,6],[1,3,5],[2,3,4]]
private:
    void backtrack(int i, int sum, int k, int& n, vector<vector<int>>& ans,
                   vector<int>& temp) {
        if (sum > n || temp.size() > k)
            return;
        if (sum == n && temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int it = i; it <= 9; it++) {
            temp.push_back(it);
            backtrack(it + 1, sum + it, k, n, ans, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(1, 0, k, n, ans, temp);
        return ans;
    }
};