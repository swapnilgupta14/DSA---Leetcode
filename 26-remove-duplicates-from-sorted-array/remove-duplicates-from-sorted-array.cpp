class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> s(nums.begin(), nums.end());
        int i = 0;
        for(int it : s){
            nums[i] = it;
            i++;
        }
        return i;
    }
};