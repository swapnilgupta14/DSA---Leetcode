class Solution {
private:
    void backtrack(int idx, int &count, int sum, vector<int> &nums, int target){
        if(idx == nums.size()){
            if(sum == target) {
                count += 1;
            }
            return;
        }

        backtrack(idx + 1, count, sum + (nums[idx] * 1), nums, target);
        backtrack(idx + 1, count, sum + (nums[idx] * -1), nums, target);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(target == nums[0] || target == nums[0] * -1) 
                return 1;
            else return 0;
        }

        int count = 0;
        backtrack(0, count, 0, nums, target);
        return count;
    }
};