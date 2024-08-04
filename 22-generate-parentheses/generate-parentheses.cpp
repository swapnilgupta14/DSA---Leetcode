class Solution {
private:
    void backtrack(int opening, int closing, vector<string>& ans, string& temp) {
        cout << opening << ", " << closing << " \n";
        if (opening > closing) return;
        if (opening == 0 && closing == 0) {
            ans.push_back(temp);
            return;
        }
        if (opening) {
            temp += "(";
            backtrack(opening - 1, closing, ans, temp);
            temp.pop_back();
        }
        if (closing) {
            temp += ")";
            backtrack(opening, closing - 1, ans, temp);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        backtrack(n, n, ans, temp);
        return ans;
    }
};