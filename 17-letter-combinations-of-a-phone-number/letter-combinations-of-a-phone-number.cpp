class Solution {
private:
    void backtrack(int index, const vector<string>& arr, vector<string>& ans, string& temp) {
    if (index == arr.size()) {
        ans.push_back(temp);
        return;
    }

    for (char letter : arr[index]) {
        temp.push_back(letter);
        backtrack(index + 1, arr, ans, temp);
        temp.pop_back();
    }
}
public:
    

vector<string> letterCombinations(const string& digits) {
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    if (digits.empty()) return {};
    
    vector<string> arr;
    for (char digit : digits) {
        int x = digit - '0';
        if (x < 2 || x > 9) continue; // Skip invalid digits
        arr.push_back(map[x]);
    }
    
    vector<string> ans;
    string temp;
    backtrack(0, arr, ans, temp);
    return ans;
}
};