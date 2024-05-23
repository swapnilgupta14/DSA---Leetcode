class Solution {
    
     bool isPalindrome(string s){
        if(s.size() <= 1)
            return true;
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
     };

     void bkT(string curr, vector<vector<string>>& res, vector<string>& currRes){

            if(curr.empty()){
                res.push_back(currRes);
                return;
            }

            for(int i=0; i < curr.size(); ++i){
                string pre = curr.substr(0, i+1);
                string suff = curr.substr(i+1);
                if(pre.empty() || !isPalindrome(pre)){
                    cout << "not palin" << endl;
                    continue;
                }
                currRes.push_back(pre);
                bkT(suff, res, currRes);
                currRes.pop_back();
            }
    };

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currRes;
        bkT(s, res, currRes);


        return res;


    }
};