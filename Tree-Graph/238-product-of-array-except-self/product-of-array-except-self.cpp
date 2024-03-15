class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int wo_zero = 1;
        int zero_count = 0;
        for(auto& i: nums){
            if(i == 0) zero_count +=1;
            if(i != 0) wo_zero *= i;
            prod *= i;
        }
        int n = nums.size();
        vector<int> vec(n,0);
        for(int i=0 ;i <n; i++){
            if(nums[i] == 0){
                if(zero_count > 1) vec[i] = 0;
                else if(zero_count = 1)vec[i] = wo_zero;
            }else{
                vec[i] = prod/nums[i];
            }
            
        }
        return vec;
    }
};