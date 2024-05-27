class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), j = 0, ans = 0;
        for(int i=0; i<=n; i++){
            while(j < nums.size() && nums[j] < i) j++;
            ans = n - j;
            if(ans == i) return i;
        }
        return -1;
    }
};