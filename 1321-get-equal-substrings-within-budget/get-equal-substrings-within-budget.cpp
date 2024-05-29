class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i{0}, j{0}, curCost{0}, maxLen{0};
        while (j < t.size()) {
            curCost += abs(t[j] - s[j]);
            while (curCost > maxCost) {
                curCost -= abs(t[i] - s[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
};