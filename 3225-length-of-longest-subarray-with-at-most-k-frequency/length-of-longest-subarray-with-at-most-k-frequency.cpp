class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int length = 0, i = 0, j = 0, n = nums.size();
        while(j<n){
            m[nums[j]]++;
            while(m[nums[j]]>k){
                m[nums[i]]--;
                i++;
            }
            length = max(length, j-i+1);
            j++;
        }
        return length;
    }
};