class Solution {
private:
    void backtrack(int i, vector<int>& nums, vector<int> &subset, int &sum){
        if(i >= nums.size()){
            int x = 0;
            for(auto it : subset){
                x ^= it;
            }
            sum += x;
            return;
        }
        subset.push_back(nums[i]);
        backtrack(i+1, nums, subset, sum);
        subset.pop_back();
        backtrack(i+1, nums, subset, sum);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        int sum = 0;
        backtrack(0, nums, subset, sum);
        return sum;
    }
};