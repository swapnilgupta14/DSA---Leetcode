class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto it : details){
            string s; s+= it[11]; s+= it[12];
            int n = stoi(s); if(n > 60) count += 1;
        }
        return count;
    }
};