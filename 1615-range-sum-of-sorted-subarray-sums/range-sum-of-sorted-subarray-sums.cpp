class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        const int mod = 1e9 + 7;
        for(int j=0; j<n; j++){
            int sum = nums[j];
            sums.push_back(sum);
            for(int i=j+1; i<n; i++){
                sum += nums[i];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        int count = 0;
        for(int i=left-1; i<right; i++){
            count = (count + sums[i]) % mod;
        }
        return count ;
    }
};