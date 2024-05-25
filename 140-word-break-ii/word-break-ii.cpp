class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int len = s.length();
        string sent = "";
        backTrack(sent, s, dict, len, 0);
        return ans;
    }
private:
    vector<string> ans;
    void backTrack(string& sent, string& s, unordered_set<string>& dict, int len, int idx) {
        if (idx == len) {
            ans.push_back(sent);
            return;
        }
        for (int j = idx + 1; j <= idx + 10 && j <= len; j++) {
            string w = s.substr(idx, j - idx);
            if (dict.find(w) != dict.end()) {
                if (sent.length() == 0)
                    sent = w;
                else
                    sent += " " + w;
                cout << sent << endl;
                backTrack(sent, s, dict, len, j);
                int n = w.length();
                for (int i = 0; i < n; i++) {
                    sent.pop_back();
                }
                if (sent.length() > 0)
                    sent.pop_back();
            }
        }
    }
};