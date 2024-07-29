class Solution {
public:
    bool check(vector<int>& nums) {
        int peak = 0;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]) peak++;
        }
        
        if(nums[nums.size()-1] > nums[0]) peak++;
        return peak <= 1;
    }
};