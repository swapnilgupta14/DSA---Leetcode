// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are cand idates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& temp, 
                    vector<vector<int>> &ans, int sum, int ind){
        if(sum  > target) return;
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, temp, ans, sum, i);
            temp.pop_back();
            sum -= candidates[i];
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(candidates, target, temp, ans, 0, 0);
        return ans;
    }
};