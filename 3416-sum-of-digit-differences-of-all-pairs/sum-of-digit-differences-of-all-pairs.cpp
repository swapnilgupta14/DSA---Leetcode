class Solution {
public:
    long long sumDigitDifferences(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int max_digit = 0;
        for (int num : nums) {
            max_digit = max(max_digit, (int)log10(num) + 1);
        }
        vector<vector<int>> digitCount(max_digit, vector<int>(10, 0));
        for (int num : nums) {
            for (int i = 0; i < max_digit; ++i) {
                int digit = num % 10;
                digitCount[i][digit]++;
                num /= 10;
            }
        }
        
        long long totalDifference = 0;
        for (int pos = 0; pos < max_digit; ++pos) {
            for (int digit = 0; digit < 10; ++digit) {
                for (int otherDigit = 0; otherDigit < 10; ++otherDigit) {
                    if (digit != otherDigit) {
                        totalDifference += digitCount[pos][digit] * digitCount[pos][otherDigit];
                    }
                }
            }
        }
        return totalDifference / 2;
    }
};