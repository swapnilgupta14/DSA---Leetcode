class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int curr = 0;
        int count = 0;
        for(auto& it: nums){
            curr += it;
            if(curr == 0) count++;
        }
        return count;
    }
};