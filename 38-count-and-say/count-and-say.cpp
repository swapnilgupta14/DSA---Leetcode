class Solution {
private:
    void rle(string& ans) {
        int n = ans.size();
        string result;
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (ans[i] == ans[i - 1]) {
                ++count;
            } else {
                result += to_string(count) + ans[i - 1];
                count = 1;
            }
        }
        result += to_string(count) + ans[n - 1];
        ans = result;
    }
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string ans = "11";
        int x = n;
        while(x - 2){
            rle(ans);
            x --;
        }
        return ans;
    }
};