class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int small = min(word1.size(), word2.size());
        //word1 == 1 and word2 == 0
        int which = word1.size()<=word2.size() ? word2.size()-word1.size() : word1.size()-word2.size();
        string ans = "";
        int i;
        for(i =0; i<small ; i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if(word2.size() > word1.size()){
            while(i < word2.size()){ 
                ans.push_back(word2[i]);
                i++;
            }
        }else if(word1.size() > word2.size()){
            while(i < word1.size()){ 
                ans.push_back(word1[i]);
                i++;
            }
        }
        return ans;
    }
};