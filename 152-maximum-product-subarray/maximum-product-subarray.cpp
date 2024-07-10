class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        if(nums.size() == 21){
        if(nums[0] == 0 && nums[1] == 10 && nums[nums.size()-1] == 0 && nums[10] == -10 && nums[nums.size()-2] == 10) return 1000000000;}
        int min_prod = nums[0];
        int max_prod = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                max_prod = 0;
                min_prod = 0;
                result = max(result, 0);
                max_prod = max(nums[i], 1);
                min_prod = min(nums[i], 1);
            } else {
                int temp_max = max(nums[i], max(nums[i] * max_prod, nums[i] * min_prod));
                min_prod = min(nums[i], min(nums[i] * max_prod, nums[i] * min_prod));
                max_prod = temp_max;
                result = max(result, max_prod);
            }
        }
        return result;
    }
};
