class Solution {
public:
    // Input: n = 4, k = 2
    // Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
    void backtrack(int n, int k, vector<vector<int>> &result, vector<int> &temp, int index){
        // base case
        if(temp.size() == k) {
            result.push_back(temp);
            return;
        }
        for(int i=index; i<=n; i++){
            temp.push_back(i);
            backtrack(n, k, result, temp, i+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(n, k, result, temp, 1);
        return result;
    }
};
