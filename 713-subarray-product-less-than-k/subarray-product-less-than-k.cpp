class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        long k1 = k, prod = 1, count = 1;
        int en = 0, st = 0, n = nums.size(), res = 0;
        while (en < n) {
            prod *= nums[en];
            if (prod < k) {
                res += en - st + 1;
            } else {
                while (prod >= k) {
                    prod /= nums[st];
                    st++;
                    if (st > en)
                        break;
                }
                res += (en - st + 1);
            }
            en++;
        }
        return res;
    }

private:
    int numSubarrayProductLessThanK1(vector<int>& nums, int k) {
        // O(n^n) solution - TLE (Testcases passed, but took too long.)
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k)
                count += 1;
            double prod = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                prod *= nums[j];
                if (prod < k)
                    count += 1;
            }
        }
        return count;
    }
};