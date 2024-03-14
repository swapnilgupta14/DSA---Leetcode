class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            int sum = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                sum += nums[j];
                if(sum == goal) count++;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == goal) count+=1;
        }
        return count;
    }
};