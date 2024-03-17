class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count =0;
        for(int i=1; i<nums.size(); i++){
            nums[i] += nums[i-1];
            if(nums[i] == 0) count++;
        }return count;
    }
private:
    int returnToBoundaryCount1(vector<int>& nums) {
        int curr = 0;
        int count = 0;
        for(auto& it: nums){
            curr += it;
            if(curr == 0) count++;
        }
        return count;
    }
};