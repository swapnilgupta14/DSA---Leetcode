#include <string>
#include <algorithm>

class Solution {
public:
    std::string maximumOddBinaryNumber(std::string s) {
        int ones = std::count(s.begin(), s.end(), '1');
        int zeros = s.size() - ones;
        if (ones == 0) return "";
        if (ones == 1) {
            std::string ans(s.size(), '0');
            ans[ans.size() - 1] = '1';
            return ans;
        }
        std::string ans(s.size(), '0');
        int i;
        for (i = 0; i < ones-1; i++) {
            ans[i] = '1';
        }
        ans[ans.size()-1] = '1';
        return ans;
    }
};
