class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        // for(int i=index; i<nums.size(); i++){
        //     temp.push_back(nums[i]);
        //     backtrack(nums, ans, temp, i+1);
        //     temp.pop_back();
        // }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i],nums[index]);
            backtrack(nums, ans, index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        int index = 0;
        backtrack(nums, ans, index);
        return ans;
    }
};